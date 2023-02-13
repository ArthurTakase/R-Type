/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** DestroyableComponent.cpp
*/

#include <ECS/Components/DestroyableComponent.hpp>

DestroyableComponent::DestroyableComponent() noexcept {}

bool DestroyableComponent::getDestroyed() const noexcept
{
    return destroyed;
}

void DestroyableComponent::destroy() noexcept
{
    destroyed = true;
}