/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] Client::Client() noexcept
{
    std::cout << "Client created" << std::endl;
}

void Client::setLooping(bool value) noexcept
{
    looping_ = value;
}

void Client::run()
{
    // TODO : finir la loop dans server.cpp et faire la même chose ici
}

void Client::send(sockaddr_in address)
{
    const char* data = "Hello world";
    //trouver un moyen de send la data ????
    std::cout << "Message sent to server" << std::endl;
}

void Client::receive()
{
    // appeller la fonction receive avec tous les bons paramètres

    // int received_bytes = socket_.receive();
    // if (received_bytes > 0) { std::cout << "Received data from server: " << receive_data << std::endl; }
}
