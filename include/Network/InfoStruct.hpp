/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Communication
*/
#pragma once

#ifdef WIN32
#include <winsock2.h>
typedef SSIZE_T ssize_t;

#elif defined(linux)
#include <unistd.h>
#include <netinet/in.h>

#endif
#include <stddef.h>

#include <memory>
#include <queue>

struct ReceivedInfos {
    void*       data_;
    SSIZE_T     dataSize_;
    sockaddr_in address_;
};

struct ClientInfos {
    explicit ClientInfos(sockaddr_in addr, unsigned long value) noexcept;
    std::unique_ptr<sockaddr_in> address_;
    unsigned long                index_;
    std::queue<void*> dataToSend_ = {}; // TODO: à changer en queue de données sérialisées quand ça sera implémenté
};