/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <cstdlib>
#include <iostream>

#include "Client.hpp"
#include "Error.hpp"

int getPort(int ac, const char* const av[])
{
    int value = 0;
    if (ac != 2) throw Error("Usage: ./client [server port]");

    value = std::atoi(av[1]);
    if (value < 0) throw Error("Port must be a positive number");
    return (value);
}
int main(int ac, const char* const av[])
{
    try {
        int port = getPort(ac, av);
        Client client(port);
        client.run();

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}