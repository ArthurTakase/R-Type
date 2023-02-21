/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** AnimationComponent
*/

#include <ECS/Components/AnimationComponent.hpp>

AnimationComponent::AnimationComponent(int limit, float timer_limit)
    : limit(limit)
    , timer_(timer_limit)
{
}

int AnimationComponent::getLimit() const noexcept
{
    return limit;
}

void AnimationComponent::setLimit(int limit) noexcept
{
    this->limit = limit;
}

Timer& AnimationComponent::getTimer() noexcept
{
    return timer_;
}