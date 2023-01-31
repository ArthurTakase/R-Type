/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocketSelector
*/

#ifdef __linux__
#include "LinuxSocketSelector.hpp"

#include "Error.hpp"

// fd_set handler for linux :
LinuxFdSet::LinuxFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

fd_set& LinuxFdSet::get() noexcept
{
    return (fdSet_);
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

void LinuxFdSet::clear() noexcept
{
    FD_ZERO(&fdSet_);
}

// wrapper for all fd_set :
LinuxSocketSelector::LinuxSocketSelector(int socketFd) noexcept
    : nfds_(socketFd)
{
}

void LinuxSocketSelector::add(ISocket& socket, bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.add(socket.getSocketFd());
    if (isWrite) writeFds_.add(socket.getSocketFd());
    if (isExcept) exceptFds_.add(socket.getSocketFd());
}

void LinuxSocketSelector::remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.remove(socket.getSocketFd());
    if (isWrite) writeFds_.remove(socket.getSocketFd());
    if (isExcept) exceptFds_.remove(socket.getSocketFd());
}

bool LinuxSocketSelector::isSet(ISocket& socket, Operation type) const noexcept
{
    if (type == Operation::READ) return (readyReadFds_.isSet(socket.getSocketFd()));
    if (type == Operation::WRITE) return (readyWriteFds_.isSet(socket.getSocketFd()));
    if (type == Operation::EXCEPTION) return (readyExceptFds_.isSet(socket.getSocketFd()));
    return (false);
}

void LinuxSocketSelector::clear(bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.clear();
    if (isWrite) writeFds_.clear();
    if (isExcept) exceptFds_.clear();
}

void LinuxSocketSelector::select(bool isRead, bool isWrite, bool isExcept)
{
    readyReadFds_   = readFds_;
    readyWriteFds_  = writeFds_;
    readyExceptFds_ = exceptFds_;

    int status = ::select(nfds_,
        (isRead ? &readyReadFds_.get() : nullptr),
        (isWrite ? &readyWriteFds_.get() : nullptr),
        (isExcept ? &readyExceptFds_.get() : nullptr),
        nullptr);
    if (status < 0) { throw NetworkExecError("Error while using the socket with select."); }
}

#endif
