/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxFdSet
*/

#pragma once

#include "FdSet.hpp"

#ifdef __linux__
#include <sys/select.h>

class LinuxFdSet : public FdSet
{
  public:
    LinuxFdSet() noexcept;
    LinuxFdSet(const LinuxFdSet& other) noexcept = delete;
    LinuxFdSet(LinuxFdSet&& other) noexcept      = default;
    ~LinuxFdSet() noexcept                       = default;

    LinuxFdSet& operator=(const LinuxFdSet& rhs) noexcept = delete;
    LinuxFdSet& operator=(LinuxFdSet&& rhs) noexcept      = default;

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
