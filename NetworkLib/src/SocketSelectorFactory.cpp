/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SocketSelectorFactory
*/

#include "SocketSelectorFactory.hpp"

#include "LinuxSocketSelector.hpp"
#include "WindowsSocketSelector.hpp"

std::unique_ptr<SocketSelector> SocketSelectorFactory::createSocketSelector(int socketFd)
{
#ifdef WIN32
    return std::make_unique<WindowsSocketSelector>(socketFd);
#elif __linux__
    return std::make_unique<LinuxSocketSelector>(socketFd);
#else
    static_assert(false, "OS not supported");
#endif
}
