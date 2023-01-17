/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** InfoStruct
*/

#include "InfoStruct.hpp"

ClientInfos::ClientInfos(sockaddr_in address, unsigned long value) noexcept
    : address_(std::make_unique<sockaddr_in>(address))
    , index_(value)
{
}
