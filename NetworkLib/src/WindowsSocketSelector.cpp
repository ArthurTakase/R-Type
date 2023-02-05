/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsSocketSelector
*/

#ifdef WIN32
#include "WindowsSocketSelector.hpp"

#include "Error.hpp"

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

void WindowsSocketSelector::add(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkExecError("Error while using the socket with select.");

    if (isRead) readFds_.add(windowsSocket->getSocketFd());
    if (isWrite) writeFds_.add(windowsSocket->getSocketFd());
    if (isExcept) exceptFds_.add(windowsSocket->getSocketFd());

    sockets_.push_back(*windowsSocket);
    if (nfds_ < windowsSocket->getSocketFd() + 1) nfds_ = windowsSocket->getSocketFd() + 1;
}

void WindowsSocketSelector::remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkExecError("Error while using the socket with select.");

    if (isRead) readFds_.remove(windowsSocket->getSocketFd());
    if (isWrite) writeFds_.remove(windowsSocket->getSocketFd());
    if (isExcept) exceptFds_.remove(windowsSocket->getSocketFd());

    auto it = std::find_if(sockets_.begin(), sockets_.end(), [&windowsSocket](auto& socket) {
        return (socket.get().getSocketFd() == windowsSocket->getSocketFd());
    });
    if (it != sockets_.end()) {
        sockets_.erase(it);
        it = std::max_element(sockets_.begin(), sockets_.end(), [](auto& socket1, auto& socket2) {
            return (socket1.get().getSocketFd() < socket2.get().getSocketFd());
        });
        if (it != sockets_.end()) nfds_ = it->get().getSocketFd() + 1;
    }
}

bool WindowsSocketSelector::isSet(ISocket& socket, Operation type) const
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkExecError("Error while using the socket with select.");

    if (type == Operation::READ) return (readyReadFds_.isSet(windowsSocket->getSocketFd()));
    if (type == Operation::WRITE) return (readyWriteFds_.isSet(windowsSocket->getSocketFd()));
    if (type == Operation::EXCEPTION) return (readyExceptFds_.isSet(windowsSocket->getSocketFd()));
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
