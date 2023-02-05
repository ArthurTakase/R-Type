/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <cstdlib>
#include <iostream>

#include "Error.hpp"
#include "HostHandler.hpp"
#include "UdpClient.hpp"

int main(int ac, const char* const av[])
{
    try {
        Address       serverAddress = HostHandler::getHostAddress(ac, av);
        Address::Port clientPort    = HostHandler::getClientPort(ac, av);
        UdpClient     client(serverAddress, clientPort);
        client.run();

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}