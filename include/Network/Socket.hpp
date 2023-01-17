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

class SocketHandler
{
  public:
    explicit SocketHandler(uint16_t port);

    SocketHandler(const SocketHandler& other) noexcept = delete;
    SocketHandler(SocketHandler&& other) noexcept      = default;
    ~SocketHandler() noexcept;

    SocketHandler& operator=(const SocketHandler& rhs) noexcept = delete;
    SocketHandler& operator=(SocketHandler&& rhs) noexcept      = default;

    // getters
    [[nodiscard]] int         getSocketFd() const noexcept;
    [[nodiscard]] sockaddr_in getAddress() const noexcept;

    void                  send(const void* data, int data_size, sockaddr_in client_address) const;
    [[nodiscard]] ReceivedInfos receive() const;

  protected:
  private:
    int         socketFd_;
    sockaddr_in address_;
};
