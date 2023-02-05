/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HostHandler
*/

#pragma once
#include <string_view>

#include "ISocket.hpp"

/**
 * @brief get infos about the host
 *
 */
class HostHandler
{
  public:
    HostHandler() noexcept                         = delete;
    HostHandler(const HostHandler& other) noexcept = delete;
    HostHandler(HostHandler&& other) noexcept      = delete;
    ~HostHandler() noexcept                        = delete;

    HostHandler& operator=(const HostHandler& rhs) noexcept = delete;
    HostHandler& operator=(HostHandler&& rhs) noexcept      = delete;

    static Address       getHostAddress(int ac, const char* const av[]);
    static Address::Port getClientPort(int ac, const char* const av[]);

  protected:
  private:
    static Address::Ip getIp(std::string_view hostname);
};
