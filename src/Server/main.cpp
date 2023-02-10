/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_network
*/

#include <Server/Server.hpp>
#include <iostream>

#include "Error.hpp"

int main()
{
    try {
        Server server(4242);

        server.run();
    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}