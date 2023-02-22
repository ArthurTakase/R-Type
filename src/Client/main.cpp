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
    if (ac != 4) return {"", "", ""};
    return {av[1], av[2], av[3]};
}

int main(int ac, const char* const av[])
{
    Menu                     menu;
    std::vector<std::string> infos = checkArgs(ac, av);

    if (infos[0] == "") infos = menu.run();
    if (infos[0] == "" || infos[1] == "" || infos[2] == "") return 0;

    try {
        Address       serverAddress = HostHandler::getHostAddress(infos);
        Address::Port clientPort    = HostHandler::getClientPort(infos);
        UdpClient     client(serverAddress, clientPort);
        client.run();

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}