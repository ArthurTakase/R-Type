/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Lib.cpp
*/

#pragma once

#include "Window.hpp"

class Lib
{
  public:
    Lib();
    ~Lib() noexcept                = default;
    Lib(const Lib& other) noexcept = delete;
    Lib(Lib&& other) noexcept      = delete;

    Lib& operator=(const Lib& rhs) noexcept = delete;
    Lib& operator=(Lib&& rhs) noexcept      = delete;

    Window& getWindow();

  private:
    Window window;
};