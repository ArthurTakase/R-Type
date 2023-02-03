/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <cstdlib>
#include <iostream>

#include "Error.hpp"
#include "UdpClient.hpp"

Address getServerId(int ac, const char* const av[])
{
    Address serverInfos;

    if (ac != 4) throw Error("Usage: ./r-type_client [server port] [server ip] [client port]");

    serverInfos.port = std::atoi(av[1]);
    if (serverInfos.port < 0) throw Error("Port must be a positive number");
    serverInfos.ip = std::atoi(av[2]);
    if (serverInfos.ip < 0) throw Error("The server ip must be a positive number");

    return (serverInfos);
}

Address::Port getClientPort(int ac, const char* const av[])
{
    Address::Port clientPort = std::atoi(av[3]);
    if (clientPort < 0) throw Error("Port must be a positive number");

    return (clientPort);
}

int main(int ac, const char* const av[])
{
    try {
        Address       serverAddress = getServerId(ac, av);
        Address::Port clientPort    = getClientPort(ac, av);
        UdpClient     client(serverAddress, clientPort);
        client.run();

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}