/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#include "Socket.hpp"

#include <iostream> // TODO A SUPPRIMER QUAND LE CODE SERA FONCTIONNEL

#include "Error.hpp"

[[nodiscard]] SocketHandler::SocketHandler(uint16_t port) // init the socket (ipv6, UDP)
{
    socketFd_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socketFd_ == -1) { throw InitError("Socket initialization failed."); }
    std::cout << "Socket created" << std::endl;

    // make the socket listen to a port passed in parameter
    address_.sin_addr.s_addr = INADDR_ANY;  // allows to listen on all local interfaces
    address_.sin_port        = htonl(port); // to translate the port to an endianess network
    address_.sin_family      = AF_INET;     // our address is IPv6

    SocketHandler::bind();
}

SocketHandler::~SocketHandler() noexcept
{
    ::close(socketFd_);
}

int SocketHandler::getSocketFd() const noexcept
{
    return socketFd_;
}

sockaddr_in SocketHandler::getAddress() const noexcept
{
    return address_;
}

void SocketHandler::bind()
{
    if (::bind(socketFd_, reinterpret_cast<sockaddr*>(&address_), sizeof(address_)) != 0)
        throw NetworkExecError("Socket binding to port failed.");
}

void SocketHandler::send(const void* data, int data_size, sockaddr_in client_address) const
{
    int sent_bytes =
        sendto(socketFd_, data, data_size, 0, reinterpret_cast<sockaddr*>(&client_address), sizeof(client_address));
    if (sent_bytes < 0) { throw NetworkExecError("Error in sending data from the server to the client"); }
}

unsigned int SocketHandler::receive(void* data, int data_size, sockaddr_in& client_address) const
{
    socklen_t address_len = sizeof(client_address);
    int       received_bytes =
        recvfrom(socketFd_, data, data_size, 0, reinterpret_cast<sockaddr*>(&client_address), &address_len);
    if (received_bytes < 0) { throw NetworkExecError("Error receiving data from the client "); }

    std::cout << data << std::endl;
    return received_bytes;
}
