/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#pragma once

#include "Socket.hpp"
class Client
{
  public:
    explicit Client(uint16_t port) noexcept;

    Client(const Client& other) noexcept = delete;
    Client(Client&& other) noexcept      = default;
    ~Client() noexcept                   = default;

    Client& operator=(const Client& rhs) noexcept = delete;
    Client& operator=(Client&& rhs) noexcept      = default;

    void run();
    void send(void* data);
    void receive();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    bool   looping_ = true;
    int    servPort_;
    Socket socket_;
};