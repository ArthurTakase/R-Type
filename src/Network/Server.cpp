/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <iostream> //TODO:A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Server::Server(uint16_t port)
    : socket_(Socket{ port })
{
    // setup of select
    FD_ZERO(&readFds_);
    FD_SET(socket_.getSocketFd(), &readFds_);

    std::cout << "Server created" << std::endl;
}

void Server::stop() noexcept
{
    looping_ = false;
}

void Server::reset() noexcept
{
    looping_ = true;
}

bool Server::isQueueEmpty(unsigned int index) const noexcept
{
    if (clients_[index].dataToSend_.size() == 0) { return (true); }
    return (false);
}

void Server::run()
{
    while (looping_) {
        // Wait for data on the socket
        int status = select(socket_.getSocketFd() + 1, &readFds_, &writeFds_, nullptr, nullptr);
        if (status < 0) { throw NetworkExecError("Error while using the socket with select"); }
        for (int i = 0; i != socket_.getSocketFd() + 1; i++) {
            if (FD_ISSET(i, &readFds_)) { receive(); }
            if (FD_ISSET(i, &writeFds_) && !isQueueEmpty(i)) {
                // TODO : remplacer le void * par le format de données sérialisées
                send(getDataFromQueue(i), i);
            }
        }
    }
}

bool Server::isKnownClient(sockaddr_in address) const
{
    for (const auto& client : clients_) {
        if (client.address_->sin_addr.s_addr == address.sin_addr.s_addr) { return true; }
    }
    return false;
}

void Server::addClient(sockaddr_in address) noexcept
{
    ClientInfos client(address, clients_.size());
    clients_.push_back(std::move(client));
}

void Server::receive()
{
    try {
        ReceivedInfos infoReceived = socket_.receive();

        // add the client to the list of recognized hosts if it's not already in it
        if (!isKnownClient(infoReceived.address_)) {
            std::cout << "NEW CLIENT" << std::endl; // TODO: A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL
            addClient(infoReceived.address_);
        }
        handleData(infoReceived);
        std::cout << "END OF RECEPTION" << std::endl;
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Server::send(void* data, unsigned int clientIndex) const
{
    std::cout << "SENDING DATA" << std::endl;
    try {
        socket_.send(data, sizeof(data), *clients_[clientIndex].address_);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void* Server::getDataFromQueue(unsigned int index) noexcept
{
    void* data = clients_[index].dataToSend_.front();
    clients_[index].dataToSend_.pop();
    return (data);
}

void Server::handleData(ReceivedInfos infos) const noexcept
{
    std::cout << "PREPARING DATA" << std::endl;
    // TODO: traiter les données reçues pour notre logique de jeu
}