/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** BehaviorComponent
*/

#include "BehaviorComponent.hpp"

BehaviorComponent::BehaviorComponent() {}

void BehaviorComponent::setOnUpdate(std::function<void(int key)> onUpdate) noexcept
{
    onUpdate_ = onUpdate;
}

void BehaviorComponent::onUpdate(int key) const noexcept
{
    onUpdate_(key);
}