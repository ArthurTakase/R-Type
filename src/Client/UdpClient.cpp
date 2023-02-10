/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

#include <Components/DrawableComponent.hpp>
#include <iostream>
#include <memory>

#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

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
    RawData data = {12};
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
    } catch (const NetworkExecError& e) {
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
        } catch (const NetworkExecError& e) {
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
    if (infos.data.size() < 2) return;

    if (infos.data.size() % 12 == 0) {
        for (int i = 0; i < infos.data.size(); i += 12) {
            GamePacket packet;
            packet.x         = infos.data[i];
            packet.xpositive = infos.data[i + 1];
            packet.y         = infos.data[i + 2];
            packet.ypositive = infos.data[i + 3];
            packet.idSprite  = infos.data[i + 4];
            packet.width     = infos.data[i + 5];
            packet.height    = infos.data[i + 6];
            packet.scaleX    = infos.data[i + 7];
            packet.scaleY    = infos.data[i + 8];
            packet.offsetX   = infos.data[i + 9];
            packet.offsetY   = infos.data[i + 10];
            packet.id        = infos.data[i + 11];
            {
                std::lock_guard<std::mutex> lock(mutexForPacket_);
                dataReceived_.push(packet);
            }
        }
    }
}
