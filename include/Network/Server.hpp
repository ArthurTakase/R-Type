/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#pragma once

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

    // setters
    void setLooping(bool value) noexcept;

    void run();

  protected:
  private:
    SocketHandler socket_;
    bool          looping_        = true;
    unsigned int  timeout_seconds = 1;
    fd_set        readFds_;

    // methods
    void accept();
};