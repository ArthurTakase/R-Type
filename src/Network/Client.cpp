/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Client::Client(uint16_t port) noexcept : servPort_(port), socket_(Socket{ port })
{
    std::cout << "Client created" << std::endl;
}

void Client::stop() noexcept
{
    looping_ = false;
}

void Client::reset() noexcept
{
    looping_ = true;
}

void Client::run()
{
    // TODO : finir la loop dans server.cpp et faire la même chose ici
}

void Client::send(void *data)
{
    std::cout << "Message sent to server" << std::endl;
}

void Client::receive()
{
}
