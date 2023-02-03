/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

#include <iostream>

#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

[[nodiscard]] UdpClient::UdpClient(Address serverAddress, Address::Port clientPort)
    : serverAddress_(serverAddress)
    , socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector(socket_->getSocketFd() + 1))
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });

    std::cout << "UdpClient created" << std::endl;
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
    // TODO : send a connection request to the server
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
    // while (looping_) {
    //     // TODO : insert game loop
    // }
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

void UdpClient::handleData(ReceivedInfos infos) const noexcept
{
    std::cout << "PREPARING DATA" << std::endl;
    // TODO: traiter les données reçues pour notre logique de jeu
}
