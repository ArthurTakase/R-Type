/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_network
*/

#include <Error/Error.hpp>
#include <Server/Server.hpp>
#include <iostream>

/**
 * It creates a server on port 4242, and then runs it
 *
 * @return The server is being returned.
 */
int main()
{
    try {
        Server server(Server::SERVER_PORT);

        server.run();
    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}