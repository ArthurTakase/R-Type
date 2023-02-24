/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Timer.cpp
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

class Timer
{
  public:
    Timer() noexcept;
    Timer(float limit) noexcept;
    ~Timer() noexcept                  = default;
    Timer(const Timer& other) noexcept = default;
    Timer(Timer&& other) noexcept      = delete;

    Timer& operator=(const Timer& rhs) noexcept = delete;
    Timer& operator=(Timer&& rhs) noexcept      = delete;

    void  start();
    void  stop();
    void  reset();
    bool  isOver();
    float getElapsedTime();
    void  setLimit(float limit);
    float getLimit() const;

  private:
    sf::Clock clock;
    float     limit;
    bool      active;
};