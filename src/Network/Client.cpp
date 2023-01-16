/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Client::Client(uint16_t port)
    : socket_(SocketHandler{ port })
{
    // setup of select
    FD_ZERO(&read_fds);
    FD_SET(socket_.getSocketFd(), &read_fds);

    // timeout.tv_sec  = timeout_seconds;
    // timeout.tv_usec = 0;

    std::cout << "Client created" << std::endl;
}

void Client::setTimeout(unsigned int seconds) noexcept
{
    if (seconds > 0) { timeout_ = seconds; }
}

void Client::setLooping(bool value) noexcept
{
    looping_ = value;
}

void Client::run()
{
    // TODO : finir la loop dans server.cpp et faire la même chose ici
}

void Client::send()
{
    // appeller la fonction send de mon socket avec tous les bons paramètres
    //  socket_.send();
}

void Client::receive()
{
    // appeller la fonction receive avec tous les bons paramètres

    // int received_bytes = socket_.receive();
    // if (received_bytes > 0) { std::cout << "Received data from server: " << receive_data << std::endl; }
}
