/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISocket
*/

#pragma once
#include <cstdint>
#include <memory>
#include <queue>

struct Address {
    using Port = std::uint16_t;
    using Ip   = std::uint32_t;

    Port port;
    Ip   ip;
};

inline bool operator==(const Address& lhs, const Address& rhs) noexcept
{
    return (lhs.port == rhs.port && lhs.ip == rhs.ip);
}

using RawData = std::vector<std::uint8_t>;

struct ReceivedInfos {
    RawData data;
    Address address;
};

struct Client {
    Address             address;
    std::queue<RawData> dataToSend = {};
};

class ISocket
{
  public:
    using Fd = std::int32_t;

  public:
    ISocket() noexcept                     = default;
    ISocket(const ISocket& other) noexcept = delete;
    ISocket(ISocket&& other) noexcept      = default;
    virtual ~ISocket() noexcept            = default;

    ISocket& operator=(const ISocket& rhs) noexcept = delete;
    ISocket& operator=(ISocket&& rhs) noexcept      = default;

    virtual Fd      getSocketFd() const noexcept = 0;
    virtual Address getAddress() const noexcept  = 0;

    virtual void          send(const void* data, int data_size, Address client_address) const = 0;
    virtual ReceivedInfos receive() const                                                     = 0;

  protected:
  private:
};