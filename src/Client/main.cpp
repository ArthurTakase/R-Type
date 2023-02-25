/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <Client/Menu.hpp>
#include <Client/UdpClient.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/HostHandler.hpp>
#include <cstdlib>
#include <iostream>

std::vector<std::string> checkArgs(int ac, const char* const av[])
{
    if (ac == 1) return {};
    if (ac == 4) return {av[1], av[2], av[3]};
    else
        throw InitError("Error: Invalid number of arguments");
}

int main(int ac, const char* const av[])
{
    try {
        std::vector<std::string> infos = checkArgs(ac, av);
        if (infos.size() == 0) {
            UdpClient client((Address::Port(0)));
            client.run();
        } else {
            Address::Port clientPort    = HostHandler::getClientPort(infos);
            Address       serverAddress = HostHandler::getHostAddress(infos);
            UdpClient     client(serverAddress, clientPort);
            client.run();
        }
    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}