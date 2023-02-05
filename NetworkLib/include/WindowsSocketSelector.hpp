/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsSocketSelector
*/

#pragma once

#include <functional>

#include "SocketSelector.hpp"

#ifdef WIN32
#include <winsock2.h>

#include "WindowsSocket.hpp"

class WindowsFdSet
{
  public:
    WindowsFdSet() noexcept;
    WindowsFdSet(const WindowsFdSet& other) noexcept = default;
    WindowsFdSet(WindowsFdSet&& other) noexcept      = default;
    ~WindowsFdSet() noexcept                         = default;

    WindowsFdSet& operator=(const WindowsFdSet& rhs) noexcept = default;
    WindowsFdSet& operator=(WindowsFdSet&& rhs) noexcept      = default;

    fd_set& get() noexcept;
    void    add(int fd) noexcept;
    void    remove(int fd) noexcept;
    bool    isSet(int fd) const noexcept;
    int     select() noexcept;
    void    clear() noexcept;

  protected:
  private:
    fd_set fdSet_;
};

class WindowsSocketSelector : public SocketSelector
{
  public:
    WindowsSocketSelector() noexcept                                   = default;
    WindowsSocketSelector(const WindowsSocketSelector& other) noexcept = delete;
    WindowsSocketSelector(WindowsSocketSelector&& other) noexcept      = default;
    ~WindowsSocketSelector() noexcept                                  = default;

    WindowsSocketSelector& operator=(const WindowsSocketSelector& rhs) noexcept = delete;
    WindowsSocketSelector& operator=(WindowsSocketSelector&& rhs) noexcept      = default;

    void add(ISocket& socket, bool isRead, bool isWrite, bool isExcept) final;
    void remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept) final;
    bool isSet(ISocket& socket, Operation type) const final;
    void select(bool isRead, bool isWrite, bool isExcept) final;
    void clear(bool isRead, bool isWrite, bool isExcept) noexcept final;

  protected:
  private:
    int          nfds_ = 0;
    WindowsFdSet readFds_;
    WindowsFdSet writeFds_;
    WindowsFdSet exceptFds_;
    WindowsFdSet readyReadFds_;
    WindowsFdSet readyWriteFds_;
    WindowsFdSet readyExceptFds_;

    std::vector<std::reference_wrapper<WindowsSocket>> sockets_;
};

#endif