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

int main(int ac, const char* const av[])
{
    try {
        // Address       serverAddress = HostHandler::getHostAddress(ac, av);
        // Address::Port clientPort    = HostHandler::getClientPort(ac, av);
        // UdpClient     client(serverAddress, clientPort);
        // client.run();
        Menu menu;
        menu.run();

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}