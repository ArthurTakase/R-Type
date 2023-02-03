/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** RClient
*/

#pragma once

#include "ISocket.hpp"

class RClient
{
  public:
    explicit RClient(uint16_t port) noexcept;

    RClient(const RClient& other) noexcept = default;
    RClient(RClient&& other) noexcept      = default;
    ~RClient() noexcept                    = default;

    RClient& operator=(const RClient& rhs) noexcept = delete;
    RClient& operator=(RClient&& rhs) noexcept      = default;

    void run();
    void send(void* data);
    void receive();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    bool looping_ = true;
    int  servPort_;
    // Socket socket_;
};