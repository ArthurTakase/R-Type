/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#pragma once

#include <memory>
#include <thread>
#include <vector>

#include "ISocket.hpp"
#include "SocketSelector.hpp"

class Server
{
  public:
    Server() noexcept = delete;
    explicit Server(Address::Port port);

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
    // attributes
    bool                            looping_  = true;
    int                             tickrate_ = 60;
    std::vector<Client>             clients_  = {};
    std::unique_ptr<ISocket>        socket_;
    std::unique_ptr<SocketSelector> selector_;
    std::thread                     gameThread_;
    std::thread                     networkThread_;

    // methods
    void                  receive();
    void                  send() noexcept;
    void                  sendToClient(Client& client, RawData blob);
    bool                  isKnownClient(Address address) const;
    void                  addClient(Address address) noexcept;
    void                  handleData(ReceivedInfos infos) const noexcept;
    [[nodiscard]] RawData getDataFromQueue(Client& client) noexcept;
    void                  checkData() noexcept;

    // thread methods
    void communicate() noexcept;
    void gameLoop() const noexcept;
};