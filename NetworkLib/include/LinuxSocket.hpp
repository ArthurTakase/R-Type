/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocket
*/

#pragma once

#ifdef __linux__

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <memory>
#include <queue>

#include "ISocket.hpp"

class LinuxSocketSelector;

class LinuxSocket : public ISocket
{
    friend class LinuxSocketSelector;

  public:
    explicit LinuxSocket(Address::Port port);

    LinuxSocket(const LinuxSocket& other) noexcept = delete;
    LinuxSocket(LinuxSocket&& other) noexcept      = default;
    ~LinuxSocket() noexcept;

    LinuxSocket& operator=(const LinuxSocket& rhs) noexcept = delete;
    LinuxSocket& operator=(LinuxSocket&& rhs) noexcept      = default;

    [[nodiscard]] Address       getAddress() const noexcept final;
    void                        send(const void* data, int data_size, Address client_address) const final;
    [[nodiscard]] ReceivedInfos receive() final;

  protected:
    Fd getSocketFd() const noexcept;

  private:
    // attributes
    int               socketFd_;
    sockaddr_in       address_;
    std::vector<char> receivedBuffer_;

    static constexpr std::size_t MAX_RECEIVED_BUFFER_SIZE = 1024;

    // methods
    static Address     linuxAddressToAddress(sockaddr_in address) noexcept;
    static sockaddr_in addressToLinuxAddress(Address address) noexcept;
};

#endif
