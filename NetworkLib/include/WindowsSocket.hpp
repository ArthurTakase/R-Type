/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#pragma once

#ifdef WIN32
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <string_view>

#include "ISocket.hpp"

class WindowsSocket : public ISocket
{
  public:
    explicit WindowsSocket(Address::Port port);

    WindowsSocket(const WindowsSocket& other) noexcept = delete;
    WindowsSocket(WindowsSocket&& other) noexcept      = default;
    ~WindowsSocket() noexcept;

    WindowsSocket& operator=(const WindowsSocket& rhs) noexcept = delete;
    WindowsSocket& operator=(WindowsSocket&& rhs) noexcept      = default;

    [[nodiscard]] Address       getAddress() const noexcept final;
    void                        send(const void* data, int data_size, Address client_address) const final;
    [[nodiscard]] ReceivedInfos receive() final;

  protected:
  private:
    // attributes
    SOCKET            socketFd_;
    SOCKADDR_IN       address_;
    std::vector<char> receivedBuffer_;

    static constexpr std::size_t MAX_RECEIVED_BUFFER_SIZE = 1024;

    // methods
    static Address     winAddressToAddress(SOCKADDR_IN address) noexcept;
    static SOCKADDR_IN addressToWinAddress(Address address) noexcept;
    friend Fd          getSocketFd() noexcept;
};
#endif
