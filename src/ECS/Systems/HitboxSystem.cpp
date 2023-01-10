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

/**
 * It's a constructor for the HitboxSystem class
 *
 * @param shared_ptr A smart pointer that manages the lifetime of an object.
 */
HitboxSystem::HitboxSystem(std::vector<std::shared_ptr<Entity>>& entities)
    : ASystem(entities)
{
}

/**
 * For each entity in the system, check if it has a hitbox and a position component, and if it does,
 * check if it's colliding with anything
 */
void HitboxSystem::run()
{
    for (auto& entity : _entities) {
        assert((entity->hasComponents<HitboxComponent, PositionComponent>()));
        if (checkCollision(entity)) { std::cout << "Collision detected" << std::endl; }
    }
}

/**
 * It checks if the entity is colliding with anything else in the system
 *
 * @param entity The entity to check collision for.
 *
 * @return A boolean value.
 */
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