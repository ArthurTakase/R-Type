/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** FdSetFactory
*/

#include "FdSetFactory.hpp"

#include "LinuxFdSet.hpp"
#include "WindowsFdSet.hpp"

std::unique_ptr<FdSet> FdSetFactory::createFdSet()
{
#ifdef WIN32
    return std::make_unique<WindowsFdSet>();
#elif __linux__
    return std::make_unique<LinuxFdSet>();
#else
    static_assert(false, "OS not supported");
#endif
}
