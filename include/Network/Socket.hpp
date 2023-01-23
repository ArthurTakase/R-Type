/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#pragma once

#ifdef WIN32

#include <winsock2.h>

#elif defined(linux)

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
typedef int                SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr    SOCKADDR;
#define closesocket(s) close(s)

#endif

#include <string_view>

#include "InfoStruct.hpp"

class Socket
{
  public:
    explicit Socket(uint16_t port);

    Socket(const Socket& other) noexcept = delete;
    Socket(Socket&& other) noexcept      = default;
    ~Socket() noexcept;

    Socket& operator=(const Socket& rhs) noexcept = delete;
    Socket& operator=(Socket&& rhs) noexcept      = default;

    // getters
    [[nodiscard]] int         getSocketFd() const noexcept;
    [[nodiscard]] SOCKADDR_IN getAddress() const noexcept;

    void                        send(const void* data, int data_size, SOCKADDR_IN client_address) const;
    [[nodiscard]] ReceivedInfos receive() const;

  protected:
  private:
    SOCKET      socketFd_;
    SOCKADDR_IN address_;
};
