/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Timer.cpp
*/

#include <Lib/Timer.hpp>

Timer::Timer() noexcept
    : limit(0)
    , active(false)
{
}

Timer::Timer(float limit) noexcept
    : limit(limit)
{
}

void Timer::start()
{
    active = true;
}

void Timer::stop()
{
    active = false;
}

void Timer::reset()
{
    clock.restart();
}

bool Timer::isOver()
{
    if (!active) return false;

    if (getElapsedTime() >= limit) {
        clock.restart();
        return true;
    }
    return false;
}

float Timer::getElapsedTime()
{
    sf::Time time = clock.getElapsedTime();
    return time.asSeconds();
}

void Timer::setLimit(float limit)
{
    this->limit = limit;
}

float Timer::getLimit() const
{
    return limit;
}