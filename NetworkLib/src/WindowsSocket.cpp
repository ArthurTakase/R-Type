/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WinSocket
*/

#ifdef WIN32
#include "WindowsSocket.hpp"

#include "Error.hpp"

WindowsSocket::WindowsSocket(Address::Port port)
{
    WSADATA wsa;
    int     err = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (err < 0) { throw InitError("WSAStartup failed."); }
    socketFd_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFd_ < 1) { throw InitError("Socket initialization failed."); }
    std::cout << "Socket created" << std::endl;

    address_.sin_port        = htons(port);
    address_.sin_addr.s_addr = htonl(INADDR_ANY);
    address_.sin_family      = AF_INET;

    if (bind(socketFd_, reinterpret_cast<SOCKADDR*>(&address_), sizeof(address_)) != 0)
        throw InitError("Socket binding to port failed.");
    receivedBuffer_.reserve(MAX_RECEIVED_BUFFER_SIZE);
}

WindowsSocket::~WindowsSocket() noexcept
{
    WSACleanup();
    closesocket(socketFd_);
}

ISocket::Fd WindowsSocket::getSocketFd() noexcept
{
    return socketFd_;
}

Address WindowsSocket::winAddressToAddress(SOCKADDR_IN address) noexcept
{
    Address converted{ .port = ntohs(address.sin_port), .ip = ntohl(address.sin_addr.s_addr) };
    return converted;
}

SOCKADDR_IN WindowsSocket::addressToWinAddress(Address address) noexcept
{
    SOCKADDR_IN converted;
    converted.sin_family      = AF_INET;
    converted.sin_port        = htons(address.port);
    converted.sin_addr.s_addr = htonl(address.ip);
    return converted;
}

Address WindowsSocket::getAddress() const noexcept
{
    Address address = winAddressToAddress(address_);
    return address;
}

void WindowsSocket::send(const void* data, int data_size, Address destAddr) const
{
    SOCKADDR_IN winDestAddr = addressToWinAddress(destAddr);

    int sent_bytes = sendto(socketFd_,
        reinterpret_cast<const char*>(data),
        data_size,
        0,
        reinterpret_cast<SOCKADDR*>(&winDestAddr),
        sizeof(winDestAddr));

    if (sent_bytes < 0) { throw NetworkExecError("Error in sending data from the server to the client"); }
}

ReceivedInfos WindowsSocket::receive()
{
    SOCKADDR_IN   address = { 0 };
    socklen_t     addrLen = sizeof(address);
    ReceivedInfos infos;

    int bytesReceived = recvfrom(socketFd_,
        receivedBuffer_.data(),
        receivedBuffer_.capacity(),
        0,
        reinterpret_cast<SOCKADDR*>(&address),
        &addrLen);

    if (bytesReceived < 0) { throw NetworkExecError("Error receiving data from the client "); }

    infos.address = winAddressToAddress(address);
    infos.data.insert(infos.data.begin(), receivedBuffer_.data(), receivedBuffer_.data() + bytesReceived);
    return infos;
}

#endif