/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include "HitboxSystem.hpp"

#include <cassert>
#include <iostream>

#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

HitboxSystem::HitboxSystem(std::vector<std::shared_ptr<Entity>>& entities)
    : ASystem(entities)
{
}

void HitboxSystem::run()
{
    for (auto& entity : _entities) {
        assert((entity->hasComponents<HitboxComponent, PositionComponent>()));
        if (checkCollision(entity)) { std::cout << "Collision detected" << std::endl; }
    }
}

bool HitboxSystem::checkCollision(std::shared_ptr<Entity>& entity) const noexcept
{
    for (auto& otherEntity : _entities) {
        if (!otherEntity->hasComponents<HitboxComponent, PositionComponent>()) continue;
        if (otherEntity == entity) { continue; }

        auto& hitbox      = entity->getComponent<HitboxComponent>()->get();
        auto& pos         = entity->getComponent<PositionComponent>()->get();
        auto& otherHitbox = otherEntity->getComponent<HitboxComponent>()->get();
        auto& otherPos    = otherEntity->getComponent<PositionComponent>()->get();

        if (pos.getX() + hitbox.getWidth() >= otherPos.getX() && pos.getX() <= otherPos.getX() + otherHitbox.getWidth()
            && pos.getY() + hitbox.getHeight() >= otherPos.getY()
            && pos.getY() <= otherPos.getY() + otherHitbox.getHeight()) {
            return true;
        }
    }
    return false;
}