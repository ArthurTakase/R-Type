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
    explicit Client() noexcept;

    Client(const Client& other) noexcept = delete;
    Client(Client&& other) noexcept      = default;
    ~Client() noexcept                   = default;

    Client& operator=(const Client& rhs) noexcept = delete;
    Client& operator=(Client&& rhs) noexcept      = default;

    // setters
    void setLooping(bool value) noexcept;

    void run();
    void send(sockaddr_in address);
    void receive();

  protected:
  private:
    bool          looping_ = true;
    fd_set        read_fds;
};