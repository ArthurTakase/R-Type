/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TimerComponent
*/

#include <ECS/Components/TimerComponent.hpp>

TimerComponent::TimerComponent(float time)
    : timer_(time)
{
}

Timer& TimerComponent::getTimer() noexcept
{
    return timer_;
}