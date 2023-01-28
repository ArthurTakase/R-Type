/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window.cpp
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <bitset>

class Window
{
  public:
    Window();
    ~Window() noexcept                   = default;
    Window(const Window& other) noexcept = delete;
    Window(Window&& other) noexcept      = delete;

    Window& operator=(const Window& rhs) noexcept = delete;
    Window& operator=(Window&& rhs) noexcept      = delete;

    void           close();
    void           clear();
    void           refresh();
    bool           isOpen();
    std::bitset<8> getKeyPressed();

  private:
    sf::RenderWindow window;
};