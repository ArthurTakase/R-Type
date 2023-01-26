/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#include "Socket.hpp"

#include <iostream> // TODO A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

Socket::Socket(uint16_t port) // init the socket (ipv6, UDP)
{
#ifdef WIN32
    WSADATA wsa;
    int     err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0) { throw InitError("WSAStartup failed."); }
#endif
    socketFd_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFd_ < 1) { throw InitError("Socket initialization failed."); }
    std::cout << "Socket created" << std::endl;

    // make the socket listen to a port passed in parameter
    address_.sin_port        = htons(port);
    address_.sin_addr.s_addr = htonl(INADDR_ANY);
    address_.sin_family      = AF_INET;

    if (bind(socketFd_, reinterpret_cast<SOCKADDR*>(&address_), sizeof(address_)) != 0)
        throw InitError("Socket binding to port failed.");
}

Socket::~Socket() noexcept
{
#ifdef WIN32
    WSACleanup();
#endif
    closesocket(socketFd_);
}

int Socket::getSocketFd() const noexcept
{
    return socketFd_;
}

sockaddr_in Socket::getAddress() const noexcept
{
    return address_;
}

void Socket::send(const void* data, int data_size, sockaddr_in destAddr) const
{
    std::cout << "SENDING DATA" << std::endl;
#ifdef WIN32
    int sent_bytes = sendto(socketFd_, reinterpret_cast<const char *>(data), data_size, 0, reinterpret_cast<SOCKADDR*>(&destAddr), sizeof(destAddr));

#else
    int sent_bytes = sendto(socketFd_, data, data_size, 0, reinterpret_cast<SOCKADDR*>(&destAddr), sizeof(destAddr));
#endif
    if (sent_bytes < 0) { throw NetworkExecError("Error in sending data from the server to the client"); }
    std::cout << "DATA SENT" << std::endl;
}

ReceivedInfos Socket::receive() const
{
    sockaddr_in   address = { 0 };
    socklen_t     addrLen = sizeof(address);
    void*         buffer  = malloc(1024);
    ReceivedInfos infos;

    #ifdef WIN32
    ssize_t bytesReceived =
        recvfrom(socketFd_, reinterpret_cast<char *>(buffer), sizeof(buffer), 0, reinterpret_cast<SOCKADDR*>(&address), &addrLen);

    #else
    ssize_t bytesReceived =
        recvfrom(socketFd_, buffer, sizeof(buffer), 0, reinterpret_cast<SOCKADDR*>(&address), &addrLen);
    #endif
    if (bytesReceived < 0) { throw NetworkExecError("Error receiving data from the client "); }

    infos.address_  = address;
    infos.data_     = buffer;
    infos.dataSize_ = bytesReceived;

    // TODO : quand on va récupérer la data sous forme de bitset, il faut qu'un emplacement (toujours le même) soit
    // réservé pour l'ID du client,
    //  comme ça on pourra le repérer facilement dans mon vecteur de clients stocké dans mon serveur
    return infos;
}