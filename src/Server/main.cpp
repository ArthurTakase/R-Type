/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_network
*/

#include <Error/Error.hpp>
#include <Server/Server.hpp>
#include <iostream>

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