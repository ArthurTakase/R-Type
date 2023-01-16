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
    Client() noexcept = delete;
    explicit Client(uint16_t port);

    Client(const Client& other) noexcept = delete;
    Client(Client&& other) noexcept      = default;
    ~Client() noexcept                   = default;

    Client& operator=(const Client& rhs) noexcept = delete;
    Client& operator=(Client&& rhs) noexcept      = default;

    // setters
    void setTimeout(unsigned int seconds) noexcept;
    void setLooping(bool value) noexcept;

    void run();
    void send();
    void receive();

  protected:
  private:
    SocketHandler socket_;
    bool          looping_ = true;
    unsigned int  timeout_ = 1;
    fd_set        read_fds;
};