/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <algorithm>
#include <iostream>

#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

[[nodiscard]] Server::Server(Address::Port port)
    : socket_(SocketFactory::createSocket(port))
    , selector_(SocketSelectorFactory::createSocketSelector(socket_->getSocketFd() + 1))
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

void Server::stop() noexcept
{
    looping_ = false;
    gameInstance_.stop();
}

void Server::reset() noexcept
{
    looping_ = true;
}

void Server::run()
{
    gameThread_.join();
    networkThread_.join();
}

void Server::communicate() noexcept
{
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

void Server::gameLoop() noexcept
{
    // TODO : insert game loop
    std::cout << "game loop start" << std::endl;
    while (looping_) {
        if (looping_ == false && clients_.size() == 0) {
            // TODO: changer la condition pour qu'une instruction envoyée par le client ou le jeu me dise quand la
            // window est fermée
            stop();
        } else {
            // std::cout << "coucou" << std::endl;
            // auto&   entities = gameInstance_.getManager()->getEntities();
            // RawData dataToSend;
            // for (auto& entities : entities) { dataToSend.emplace_back(10); }
            for (auto& client : clients_) { client.dataToSend.push({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }); }

            // gameInstance_.run();
        }
        // TODO: reset de l'instance de jeu dans le cas ou on veut juste recommencer une partie // une partie (reset le
        // jeu)
    }
    std::cout << "game loop end" << std::endl;
}

bool Server::isKnownClient(Address address) const
{
    auto iterator = std::find_if(
        clients_.begin(), clients_.end(), [&address](const Client& client) { return (address == client.address); });
    return (iterator != clients_.end());
}

void Server::addClient(Address address) noexcept
{
    Client client{ .address = address };
    clients_.push_back(client);
}

void Server::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        if (!isKnownClient(infoReceived.address)) { addClient(infoReceived.address); }
        handleData(infoReceived);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Server::send() noexcept
{
    for (auto& client : clients_) {
        if (client.dataToSend.size() != 0) { sendToClient(client, getDataFromQueue(client)); }
    }
}

void Server::sendToClient(Client& client, RawData blob) // blob : binary large object
{
    try {
        socket_->send(blob.data(), blob.size(), client.address);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
        client.dataToSend.push(blob);
    }
}

RawData Server::getDataFromQueue(Client& client) noexcept
{
    RawData blob = client.dataToSend.front();
    client.dataToSend.pop();
    return (blob);
}

void Server::handleData(ReceivedInfos infos) const noexcept
{
    for (auto& data : infos.data) { std::cout << (int)data << " "; }
    std::cout << std::endl;
}