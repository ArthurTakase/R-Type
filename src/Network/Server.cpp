/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Server::Server(uint16_t port)
    : socket_(SocketHandler{ port })
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

void Server::run()
{
    while (looping_) {
        // Wait for data on the socket
        int status = select(socket_.getSocketFd() + 1, &readFds_, nullptr, nullptr, nullptr);
        if (status < 0) { throw NetworkExecError("Error while using the socket with select"); }
        for (int i = 0; i != socket_.getSocketFd() + 1; i++) {
            if (FD_ISSET(i, &readFds_)) { receive(); }
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
    ReceivedInfos infoReceived = socket_.receive();

    // add the client to the list of recognized hosts if it's not already in it
    if (!isKnownClient(infoReceived.address_)) {
        std::cout << "NEW CLIENT" << std::endl; // TODO: A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL
        addClient(infoReceived.address_);
    }

    handleData(infoReceived);
    std::cout << "END OF RECEPTION" << std::endl;
}

void Server::handleData(ReceivedInfos infos) const noexcept
{
    // TODO: traiter les données reçues pour notre logique de jeu
}