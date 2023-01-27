/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxFdSet
*/

#ifdef __linux__
#include "LinuxFdSet.hpp"

LinuxFdSet::LinuxFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

void LinuxFdSet::add(int fd) noexcept
{
    FD_SET(fd, &fdSet_);
}

void LinuxFdSet::remove(int fd) noexcept
{
    FD_CLR(fd, &fdSet_);
}

bool LinuxFdSet::isSet(int fd) const noexcept
{
    return (FD_ISSET(fd, &fdSet_));
}

int LinuxFdSet::select(int nfds) noexcept
{
    int status = ::select(nfds, &fdSet_, nullptr, nullptr, nullptr);
    return (status);
}

#endif