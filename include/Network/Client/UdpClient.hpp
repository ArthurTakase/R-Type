/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#pragma once

#include <memory>
#include <thread>

#include "ISocket.hpp"
#include "SocketSelector.hpp"
class UdpClient
{
  public:
    UdpClient() noexcept = delete;
    explicit UdpClient(Address serverAddress, Address::Port clientPort);

    UdpClient(const UdpClient& other) noexcept = delete;
    UdpClient(UdpClient&& other) noexcept      = default;
    ~UdpClient() noexcept                      = default;

    UdpClient& operator=(const UdpClient& rhs) noexcept = delete;
    UdpClient& operator=(UdpClient&& rhs) noexcept      = default;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    // attributes
    bool                            looping_ = true;
    Address                         serverAddress_;
    std::unique_ptr<ISocket>        socket_;
    std::unique_ptr<SocketSelector> selector_;
    std::thread                     gameThread_;
    std::thread                     networkThread_;
    std::queue<RawData>             dataToSend_ = {};

    // TODO : add a game instance in the client

    // methods
    void    receive();
    void    send();
    void    handleData(ReceivedInfos infos) const noexcept;
    RawData getDataFromQueue() noexcept;

    // thread methods
    void communicate() noexcept;
    void gameLoop() noexcept;
};