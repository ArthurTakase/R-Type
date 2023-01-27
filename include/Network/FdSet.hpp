/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** FdSet class to encapsulate fd_set
*/

#pragma once

class FdSet
{
  public:
    FdSet() noexcept                   = default;
    FdSet(const FdSet& other) noexcept = delete;
    FdSet(FdSet&& other) noexcept      = default;
    virtual ~FdSet() noexcept          = default;

    FdSet& operator=(const FdSet& rhs) noexcept = delete;
    FdSet& operator=(FdSet&& rhs) noexcept      = default;

    virtual void add(int fd) noexcept         = 0;
    virtual void remove(int fd) noexcept      = 0;
    virtual bool isSet(int fd) const noexcept = 0;
    virtual int  select(int nfds) noexcept    = 0;

  protected:
  private:
};