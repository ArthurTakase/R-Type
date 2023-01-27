/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocketSelector
*/

#pragma once

#include "SocketSelector.hpp"

#ifdef __linux__
#include <sys/select.h>

class LinuxFdSet
{
  public:
    LinuxFdSet() noexcept;
    LinuxFdSet(const LinuxFdSet& other) noexcept = default;
    LinuxFdSet(LinuxFdSet&& other) noexcept      = default;
    ~LinuxFdSet() noexcept                       = default;

    LinuxFdSet& operator=(const LinuxFdSet& rhs) noexcept = default;
    LinuxFdSet& operator=(LinuxFdSet&& rhs) noexcept      = default;

    fd_set &get() noexcept;
    void   add(int fd) noexcept;
    void   remove(int fd) noexcept;
    bool   isSet(int fd) const noexcept;
    int    select() noexcept;
    void   clear() noexcept;

  protected:
  private:
    fd_set fdSet_;
};

class LinuxSocketSelector : public SocketSelector
{
  public:
    LinuxSocketSelector(int socketFd) noexcept;
    LinuxSocketSelector(const LinuxSocketSelector& other) noexcept = delete;
    LinuxSocketSelector(LinuxSocketSelector&& other) noexcept      = default;
    ~LinuxSocketSelector() noexcept                                = default;

    LinuxSocketSelector& operator=(const LinuxSocketSelector& rhs) noexcept = delete;
    LinuxSocketSelector& operator=(LinuxSocketSelector&& rhs) noexcept      = default;

    void add(ISocket &socket, bool isRead, bool isWrite, bool isExcept) noexcept final;
    void remove(ISocket &socket, bool isRead, bool isWrite, bool isExcept) noexcept final;
    bool isSet(ISocket &socket, Operation type) const noexcept final;
    void select(bool isRead, bool isWrite, bool isExcept) final;
    void clear(bool isRead, bool isWrite, bool isExcept) noexcept final;

  protected:
  private:
    int        nfds_;
    LinuxFdSet readFds_;
    LinuxFdSet writeFds_;
    LinuxFdSet exceptFds_;
    LinuxFdSet readyReadFds_;
    LinuxFdSet readyWriteFds_;
    LinuxFdSet readyExceptFds_;
};
#endif
