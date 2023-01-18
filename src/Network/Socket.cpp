/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#include "Socket.hpp"

#include <iostream> // TODO A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

SocketHandler::SocketHandler(uint16_t port) // init the socket (ipv6, UDP)
{
    socketFd_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFd_ == -1) { throw InitError("Socket initialization failed."); }
    std::cout << "Socket created" << std::endl;

    // make the socket listen to a port passed in parameter
    address_.sin_port        = htons(port);
    address_.sin_addr.s_addr = htonl(INADDR_ANY);
    address_.sin_family      = AF_INET;

    if (::bind(socketFd_, reinterpret_cast<sockaddr*>(&address_), sizeof(address_)) == -1)
        throw InitError("Socket binding to port failed.");
}

SocketHandler::~SocketHandler() noexcept
{
    close(socketFd_);
}

int SocketHandler::getSocketFd() const noexcept
{
    return socketFd_;
}

sockaddr_in SocketHandler::getAddress() const noexcept
{
    return address_;
}

void SocketHandler::send(const void* data, int data_size, sockaddr_in destAddr) const
{
    std::cout << "SENDING DATA" << std::endl;
    int sent_bytes = sendto(socketFd_, data, data_size, 0, reinterpret_cast<sockaddr*>(&destAddr), sizeof(destAddr));
    if (sent_bytes < 0) { throw NetworkExecError("Error in sending data from the server to the client"); }
    std::cout << "DATA SENT" << std::endl;
}

ReceivedInfos SocketHandler::receive() const
{
    sockaddr_in   address = { 0 };
    socklen_t     addrLen = sizeof(address);
    void*         buffer  = malloc(1024);
    ReceivedInfos infos;

    ssize_t bytesReceived =
        recvfrom(socketFd_, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&address), &addrLen);

    if (bytesReceived < 0) { throw NetworkExecError("Error receiving data from the client "); }

    infos.address_  = address;
    infos.data_     = buffer;
    infos.dataSize_ = bytesReceived;

    // TODO : quand on va récupérer la data sous forme de bitset, il faut qu'un emplacement (toujours le même) soit
    // réservé pour l'ID du client,
    //  comme ça on pourra le repérer facilement dans mon vecteur de clients stocké dans mon serveur

    // exemple pour tester avec une string la réception de données:
    // ((char *)buffer)[bytesReceived] = '\0';
    // std::cout << "SERVER RECEIVED : " << (char *)buffer << std::endl;
    return infos;
}