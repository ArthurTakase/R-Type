/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

#include <iostream>
#include <memory>

#include "Deserializer.hpp"
#include "DrawableComponent.hpp"
#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

[[nodiscard]] UdpClient::UdpClient(Address serverAddress, Address::Port clientPort)
    : serverAddress_(serverAddress)
    , socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector())
    , deserializer_(std::make_unique<Deserializer>())
    , game_(dataReceived_, mutexForPacket_)
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

void UdpClient::stop() noexcept
{
    looping_ = false;
}

void UdpClient::reset() noexcept
{
    looping_ = true;
}

void UdpClient::run()
{
    gameThread_.join();
    networkThread_.join();
}

void UdpClient::communicate() noexcept
{
    RawData data = { 12 };
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
        if (input != 0) { dataToSend_.push({ (uint8_t)input }); }
        game_.run();
    }

    dataToSend_.push({ CLOSE_VALUE });
    lib.getWindow().close();
}

void UdpClient::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        handleData(infoReceived);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

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

RawData UdpClient::getDataFromQueue() noexcept
{
    RawData blob = dataToSend_.front();
    dataToSend_.pop();
    return (blob);
}

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
