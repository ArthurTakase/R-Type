/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** BehaviorComponent
*/

#include <ECS/Components/BehaviorComponent.hpp>

BehaviorComponent::BehaviorComponent() {}

void BehaviorComponent::setOnUpdate(std::function<void(Entity* self)> onUpdate) noexcept
{
    onUpdate_ = onUpdate;
}

void BehaviorComponent::onUpdate(Entity* self) const noexcept
{
    if (!onUpdate_) return;
    onUpdate_(self);
}
