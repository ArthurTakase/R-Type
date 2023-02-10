/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** BehaviorComponent
*/

#include <ECS/Components/BehaviorComponent.hpp>

BehaviorComponent::BehaviorComponent() {}

void BehaviorComponent::setOnUpdate(std::function<void(int key, Entity* self)> onUpdate) noexcept
{
    onUpdate_ = onUpdate;
}

void BehaviorComponent::onUpdate(int key, Entity* self) const noexcept
{
    onUpdate_(key, self);
}
