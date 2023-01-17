/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#pragma once

#include <memory>
#include <vector>

#include "Socket.hpp"
class Server
{
  public:
    Server() noexcept = delete;
    explicit Server(uint16_t port);

    Server(const Server& other) noexcept = delete;
    Server(Server&& other) noexcept      = default;
    ~Server() noexcept                   = default;

    Server& operator=(const Server& rhs) noexcept = delete;
    Server& operator=(Server&& rhs) noexcept      = default;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    SocketHandler         socket_;
    bool                  looping_ = true;
    fd_set                readFds_;
    std::vector<ClientInfos> clients_ = {};

    // methods
    void receive();
    bool isKnownClient(sockaddr_in address) const;
    void addClient(sockaddr_in address) noexcept;
    void handleData(ReceivedInfos infos) const noexcept;
};