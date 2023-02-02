/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** RClient
*/

#include "RClient.hpp"

#include <iostream>

#include "Error.hpp"

[[nodiscard]] RClient::RClient(uint16_t port) noexcept
    : servPort_(port)
// , socket_(Socket{ port })
{
    std::cout << "RClient created" << std::endl;
}

void RClient::stop() noexcept
{
    looping_ = false;
}

void RClient::reset() noexcept
{
    looping_ = true;
}

void RClient::run()
{
    // TODO : finir la loop dans server.cpp et faire la même chose ici
}

void RClient::send(void* data)
{
    std::cout << "Message sent to server" << std::endl;
}

void RClient::receive() {}
