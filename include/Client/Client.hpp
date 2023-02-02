/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Client.cpp
*/

#pragma once

class Client
{
public:
    Client();
    ~Client() noexcept = default;
    Client(const Client& other) noexcept = delete;
    Client(Client&& other) noexcept      = delete;

    Client& operator=(const Client& rhs) noexcept = delete;
    Client& operator=(Client&& rhs) noexcept = delete;
};