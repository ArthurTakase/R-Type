/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <algorithm>
#include <iostream> //TODO:A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"
#include "FdSetFactory.hpp"
#include "SocketFactory.hpp"

[[nodiscard]] Server::Server(Address::Port port)
    : socket_(SocketFactory::createSocket(port))
    , readFds_(FdSetFactory::createFdSet())
    , writeFds_(FdSetFactory::createFdSet())
{
    readFds_->add(socket_->getSocketFd());
    writeFds_->add(socket_->getSocketFd());

    std::cout << "Server created" << std::endl; // TODO: remove when code is functionnal
}

void Server::stop() noexcept
{
    looping_ = false;
}

void Server::reset() noexcept
{
    looping_ = true;
}

void Server::run()
{
    while (looping_) {
        // TODO: understand why i can't call &writeFds_ in select
        int status = readFds_->select(socket_->getSocketFd() + 1);
        if (status < 0) { throw NetworkExecError("Error while using the socket with select."); }
        if (readFds_->isSet(socket_->getSocketFd())) { receive(); }
        if (writeFds_->isSet(socket_->getSocketFd())) { send(); }
    }
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
        if (!isKnownClient(infoReceived.address)) {
            std::cout << "NEW CLIENT" << std::endl; // TODO: A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL
            addClient(infoReceived.address);
        }
        handleData(infoReceived);
        std::cout << "END OF RECEPTION" << std::endl; // TODO: remove
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Server::send() noexcept
{
    for (auto client : clients_) {
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
    std::cout << "PREPARING DATA" << std::endl;
    // TODO: traiter les données reçues pour notre logique de jeu
}