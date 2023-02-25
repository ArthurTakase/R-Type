/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Clock
*/

#include <Time/Clock.hpp>

Clock::Clock() noexcept
    : end_(std::chrono::system_clock::now())
    , start_(std::chrono::high_resolution_clock::now())
    , actualTime_(std::chrono::high_resolution_clock::now())
    , lastPing_(std::chrono::high_resolution_clock::now())
{
}

std::chrono::system_clock::time_point Clock::getEnd() const noexcept
{
    return (end_);
}

std::chrono::high_resolution_clock::time_point Clock::getStart() const noexcept
{
    return (start_);
}
std::chrono::high_resolution_clock::time_point Clock::getActualTime() const noexcept
{
    return (actualTime_);
}

std::chrono::high_resolution_clock::time_point Clock::getLastPing() const noexcept
{
    return (lastPing_);
}

void Clock::setEnd(std::chrono::system_clock::time_point end) noexcept
{
    end_ = end;
}

void Clock::setStart(std::chrono::high_resolution_clock::time_point start) noexcept
{
    start_ = start;
}

void Clock::setActualTime(std::chrono::high_resolution_clock::time_point actualTime) noexcept
{
    actualTime_ = actualTime;
}

void Clock::setLastPing(std::chrono::high_resolution_clock::time_point lastPing) noexcept
{
    lastPing_ = lastPing;
}

std::chrono::duration_cast<std::chrono::seconds> Clock::calculateTimelapseInSeconds(
    std::chrono::system_clock::time_point givenTime) noexcept
{
    auto timelapse = std::chrono::duration_cast<std::chrono::seconds>(actualTime_ - givenTime);

    return (timelapse);
}
