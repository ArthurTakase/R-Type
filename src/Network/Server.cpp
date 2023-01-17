/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Server::Server(uint16_t port, unsigned int amount_of_clients)
    : socket_(SocketHandler{ port })
{
    // setup of select
    FD_ZERO(&readFds_);
    FD_SET(socket_.getSocketFd(), &readFds_);

    // pas sûr d'avoir besoin du timeout
    // timeout.tv_sec  = timeout_seconds;
    // timeout.tv_usec = 0;

    // if (listen(socket_.getSocketFd(), amount_of_clients) < 0) { throw NetworkExecError("Failed to listen on
    // socket."); }

    std::cout << "Server created" << std::endl;
}

void Server::setLooping(bool value) noexcept
{
    looping_ = value;
}

void Server::run()
{
    while (looping_) {
        // Wait for data on the socket
        int status = select(socket_.getSocketFd() + 1, &readFds_, nullptr, nullptr, nullptr);
        if (status < 0) { throw NetworkExecError("Error while using the socket with select"); }
        for (int i = 0; i != socket_.getSocketFd() + 1; i++) {
            if (FD_ISSET(i, &readFds_)) {
                // check if new host ? connect if it's the case
                // use accept method of the server class
                // après call la fonction qui va récupérer la data (celle qui fait un recvfrom dans la socket)
            }
        }
    }
}

void Server::receive(void* data, sockaddr_in client_address) const
{
    socket_.receive(data, sizeof(data), client_address);
}

// void Server::accept()
// {
//     // accept a connexion from the queue
//     auto      address     = socket_.getAddress();
//     socklen_t len_address = sizeof(address);

//     int connection = ::accept(socket_.getSocketFd(), reinterpret_cast<sockaddr*>(&address), &len_address);
//     if (connection < 0) { throw NetworkExecError("Accept failed"); }
// }