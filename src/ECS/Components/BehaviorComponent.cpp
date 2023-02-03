/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** BehaviorComponent
*/

#include "BehaviorComponent.hpp"

BehaviorComponent::BehaviorComponent() {}

void BehaviorComponent::setOnUpdate(std::function<void()> onUpdate) noexcept
{
    _onUpdate = onUpdate;
}

void BehaviorComponent::onUpdate() const noexcept
{
    _onUpdate();
}