/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_network
*/

#include <iostream>

#include "Error.hpp"
#include "Server.hpp"

int main()
{
    try {
        Server server(4242);

        char send_data[] = "Hello server";
        char receive_data[1024];

        // server.run();
        // client.run();
        // => voir comment ajouter à la boucle run de mon serveur et mon client l'envoi et la réception des données
        // Send data to the server
        // client.send(send_data, sizeof(send_data));
        // server.send(send_data, sizeof(send_data));

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}
