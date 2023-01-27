/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsSocketSelector
*/

#ifdef WIN32
#include "WindowsSocketSelector.hpp"

#include "Error.hpp"

// fd_set handler for windows :
WindowsFdSet::WindowsFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

fd_set& WindowsFdSet::get() noexcept
{
    return (fdSet_);
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

void WindowsFdSet::clear() noexcept
{
    FD_ZERO(&fdSet_);
}

// wrapper for all fd_set :
WindowsSocketSelector::WindowsSocketSelector(int socketFd) noexcept
    : nfds_(socketFd)
{
}
void WindowsSocketSelector::add(ISocket& socket, bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.add(socket.getSocketFd());
    if (isWrite) writeFds_.add(socket.getSocketFd());
    if (isExcept) exceptFds_.add(socket.getSocketFd());
}

void WindowsSocketSelector::remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.remove(socket.getSocketFd());
    if (isWrite) writeFds_.remove(socket.getSocketFd());
    if (isExcept) exceptFds_.remove(socket.getSocketFd());
}

bool WindowsSocketSelector::isSet(ISocket& socket, Operation type) const noexcept
{
    if (type == Operation::READ) return (readyReadFds_.isSet(socket.getSocketFd()));
    if (type == Operation::WRITE) return (readyWriteFds_.isSet(socket.getSocketFd()));
    if (type == Operation::EXCEPTION) return (readyExceptFds_.isSet(socket.getSocketFd()));
    return (false);
}

void WindowsSocketSelector::clear(bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.clear();
    if (isWrite) writeFds_.clear();
    if (isExcept) exceptFds_.clear();
}

void WindowsSocketSelector::select(bool isRead, bool isWrite, bool isExcept)
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
