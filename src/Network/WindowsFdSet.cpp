/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsFdSet
*/

#ifdef WIN32
#include "WindowsFdSet.hpp"

WindowsFdSet::WindowsFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

void WindowsFdSet::add(int fd) noexcept
{
    FD_SET(fd, &fdSet_);
}

void WindowsFdSet::remove(int fd) noexcept
{
    FD_CLR(fd, &fdSet_);
}

bool WindowsFdSet::isSet(int fd) const noexcept
{
    return (FD_ISSET(fd, &fdSet_));
}

int WindowsFdSet::select(int nfds) noexcept
{
    int status = ::select(nfds, &fdSet_, nullptr, nullptr, nullptr);
    return (status);
}

#endif
