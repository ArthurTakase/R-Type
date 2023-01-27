/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsFdSet
*/

#pragma once

#include "FdSet.hpp"

#ifdef WIN32
#include <winsock2.h>

class WindowsFdSet : public FdSet
{
  public:
    WindowsFdSet() noexcept;
    WindowsFdSet(const WindowsFdSet& other) noexcept = delete;
    WindowsFdSet(WindowsFdSet&& other) noexcept      = default;
    ~WindowsFdSet() noexcept                         = default;

    WindowsFdSet& operator=(const WindowsFdSet& rhs) noexcept = delete;
    WindowsFdSet& operator=(WindowsFdSet&& rhs) noexcept      = default;

    void add(int fd) noexcept final;
    void remove(int fd) noexcept final;
    bool isSet(int fd) const noexcept final;
    int  select(int nfds) noexcept final;

    operator fd_set*() { return &fdSet_; }
    operator const fd_set*() const { return &fdSet_; }

  protected:
  private:
    fd_set fdSet_;
};
#endif