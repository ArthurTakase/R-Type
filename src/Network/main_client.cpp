/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <iostream>

#include "Client.hpp"
#include "Error.hpp"
int main()
{
    try {
        Client client(4243);

        char send_data[] = "Hello server";

        // client.run();
        // => voir comment ajouter à la boucle run de mon serveur et mon client l'envoi et la réception des données
        // Send data to the server
        // client.send(send_data, sizeof(send_data));

    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}
