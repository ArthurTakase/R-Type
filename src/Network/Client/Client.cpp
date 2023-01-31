/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

#include <iostream> //A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

// SOCKET sock;
// char buffer[1024];
// [...]
// struct hostent *hostinfo = NULL;
// SOCKADDR_IN to = { 0 };
// const char *hostname = "www.developpez.com";
// int tosize = sizeof to;

// hostinfo = gethostbyname(hostname);
// if (hostinfo == NULL)
// {
//     fprintf (stderr, "Unknown host %s.\n", hostname);
//     exit(EXIT_FAILURE);
// }

// to.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
// to.sin_port = htons(PORT);
// to.sin_family = AF_INET;

// if(sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)&to, tosize) < 0)
// {
//     perror("sendto()");
//     exit(errno);
// }

// if((n = recvfrom(sock, buffer, sizeof buffer - 1, 0, (SOCKADDR *)&to, &tosize)) < 0)
// {
//     perror("recvfrom()");
//     exit(errno);
// }

// buffer[n] = '\0';

[[nodiscard]] Client::Client(uint16_t port) noexcept
    : servPort_(port)
    , socket_(Socket{ port })
{
    std::cout << "Client created" << std::endl;
}

void Client::stop() noexcept
{
    looping_ = false;
}

void Client::reset() noexcept
{
    looping_ = true;
}

void Client::run()
{
    // TODO : finir la loop dans server.cpp et faire la même chose ici
}

void Client::send(void* data)
{
    std::cout << "Message sent to server" << std::endl;
}

void Client::receive() {}
