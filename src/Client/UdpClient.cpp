/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include <Client/UdpClient.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/SocketFactory.hpp>
#include <NetworkLib/SocketSelectorFactory.hpp>
#include <iostream>
#include <memory>

/**
 * It creates a socket, a selector, a deserializer, a game, and two threads.
 *
 * @param serverAddress The address of the server to connect to.
 * @param clientPort The port that the client will use to communicate with the
 * server.
 */
[[nodiscard]] UdpClient::UdpClient(Address serverAddress, Address::Port clientPort)
    : serverAddress_(serverAddress)
    , socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector())
    , game_(dataReceived_, mutexForPacket_)
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

/**
 * It stops the looping_ variable from being true.
 */
void UdpClient::stop() noexcept
{
    looping_ = false;
}

/**
 * It resets the looping_ variable to true.
 */
void UdpClient::reset() noexcept
{
    looping_ = true;
}

/**
 * The run function joins the game and network threads
 */
void UdpClient::run()
{
    gameThread_.join();
    networkThread_.join();
}

/**
 * It waits for data to be received or sent, and then calls the appropriate
 * function
 */
void UdpClient::communicate() noexcept
{
    RawData data = {CONNECT};
    dataToSend_.push(data);

    while (looping_) {
        try {
            selector_->select(true, true, false);
        } catch (const NetworkExecError& message) {
            std::cerr << message.what() << std::endl;
        }
        if (selector_->isSet(*socket_, SocketSelector::Operation::READ)) { receive(); }
        if (selector_->isSet(*socket_, SocketSelector::Operation::WRITE)) { send(); }
    }
}

/**
 * It runs the game loop, and when the user presses the escape key, it sends a
 * CLOSE_VALUE to the server
 */
void UdpClient::gameLoop() noexcept
{
    auto& lib = game_.getLib();
    lib.getWindow().open(256, 256, "Client RTYPE");

    while (looping_) {
        auto input = lib.getWindow().getKeyPressed();
        if (input == 255 || input == 36) {
            looping_ = false;
            break;
        }
        if (input != 0) { dataToSend_.push({(uint8_t)input}); }
        game_.run();
    }

    dataToSend_.push({CLOSE_VALUE});
    lib.getWindow().close();
}

/**
 * It receives data from the socket and handles it
 */
void UdpClient::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        handleData(infoReceived);
    } catch (const Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * If there's data to send, send it
 */
void UdpClient::send()
{
    if (dataToSend_.size() != 0) {
        auto blob = getDataFromQueue();
        try {
            socket_->send(blob.data(), blob.size(), serverAddress_);
        } catch (const Error& e) {
            std::cerr << e.what() << std::endl;
            dataToSend_.push(blob);
        }
    }
}

/**
 * It returns the first element of the queue and removes it from the queue.
 *
 * @return A RawData object.
 */
RawData UdpClient::getDataFromQueue() noexcept
{
    RawData blob = dataToSend_.front();
    dataToSend_.pop();
    return (blob);
}

/**
 * It takes a vector of bytes, and if the size of the vector is a multiple of 12,
 * it will create a GamePacket for each 12 bytes, and push it into a queue
 *
 * @param infos the data received
 *
 * @return A vector of bytes
 */
void UdpClient::handleData(ReceivedInfos infos) noexcept
{
    {
        if (infos.data.size() == 0) { return; }
        if (infos.data.size() == 1) {
            int value = infos.data[0];
            if (value == ESCAPE || value == WINDOW_CLOSE) {
                stop();
                auto& lib = game_.getLib();
                lib.getWindow().close();
            }
            if (value == CONNECT) { dataToSend_.push({CONNECT}); }
        } else {
            if (infos.data.size() % PACKET_SIZE == 0) {
                for (int i = 0; i < infos.data.size(); i += PACKET_SIZE) {
                    // TODO call the real method deserialize
                    // GamePacket entity = Deserializer::deserialize(infos.data);
                    GamePacket packet;
                    packet.x        = infos.data[i + PacketName::X1] | (infos.data[i + PacketName::X2] << 8);
                    packet.y        = infos.data[i + PacketName::Y1] | (infos.data[i + PacketName::Y2] << 8);
                    packet.x        = infos.data[i + PacketName::XPOSITIVE] ? packet.x : -packet.x;
                    packet.y        = infos.data[i + PacketName::YPOSITIVE] ? packet.y : -packet.y;
                    packet.idSprite = infos.data[i + PacketName::ID_SPRITE];
                    packet.width    = infos.data[i + PacketName::WIDTH];
                    packet.height   = infos.data[i + PacketName::HEIGHT];
                    packet.scaleX   = infos.data[i + PacketName::SCALE_X] / 10;
                    packet.scaleY   = infos.data[i + PacketName::SCALE_Y] / 10;
                    packet.offsetX  = infos.data[i + PacketName::OFFSET_X];
                    packet.offsetY  = infos.data[i + PacketName::OFFSET_Y];
                    packet.id       = infos.data[i + PacketName::ID];
                    packet.destroyed = infos.data[i + PacketName::DESTROYED];
                    {
                        std::lock_guard<std::mutex> lock(mutexForPacket_);
                        dataReceived_.push(packet);
                    }
                }
            }
        }
    }
}
