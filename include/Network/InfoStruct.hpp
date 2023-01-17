/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Communication
*/
#pragma once

#include <netinet/in.h>
#include <stddef.h>

#include <memory>

struct ReceivedInfos {
    void*       data_;
    ssize_t     dataSize_;
    sockaddr_in address_;
};

struct ClientInfos {
    explicit ClientInfos(sockaddr_in addr, unsigned long value) noexcept;
    std::unique_ptr<sockaddr_in> address_;
    unsigned long                index_;
};