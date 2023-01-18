/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#pragma once

#include <sys/socket.h>
#include <unistd.h>

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
    [[nodiscard]] sockaddr_in getAddress() const noexcept;

    void                        send(const void* data, int data_size, sockaddr_in client_address) const;
    [[nodiscard]] ReceivedInfos receive() const;

  protected:
  private:
    int         socketFd_;
    sockaddr_in address_;
};
