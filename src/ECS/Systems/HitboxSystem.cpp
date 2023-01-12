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
 * It takes an iterator of entities with a position and hitbox component, and stores it in a private
 * member variable
 *
 * @param it The iterator to use for the system.
 */
HitboxSystem::HitboxSystem(EntityIterator<PositionComponent, HitboxComponent> it)
    : _it(EntityIterator<PositionComponent, HitboxComponent>(it))
{
}

/**
 * For each entity in the system, check if it collides with any other entity in the system
 */
void HitboxSystem::run()
{
    size_t other;

    for (; !_it.isEnd(); ++_it) {
        assert((_it.get()->hasComponents<HitboxComponent, PositionComponent>()));
        try {
            if ((other = checkCollision(_it.get())) != -1) {
                std::cout << "Collision detected between " << _it.get()->getId() << " and " << other << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

/**
 * If the entity's hitbox is colliding with another entity's hitbox, return the other entity's id
 *
 * @param entity The entity to check for collisions with.
 *
 * @return The id of the entity that is colliding with the entity passed in.
 */
int HitboxSystem::checkCollision(std::unique_ptr<Entity>& entity) const
{
    for (auto other = EntityIterator<PositionComponent, HitboxComponent>(_it.it); !other.isEnd(); ++other) {
        if (other.get() == entity) { continue; }

        assert((other.get()->hasComponents<HitboxComponent, PositionComponent>()));

        auto hitbox      = entity->getComponent<HitboxComponent>();
        auto pos         = entity->getComponent<PositionComponent>();
        auto otherHitbox = other.get()->getComponent<HitboxComponent>();
        auto otherPos    = other.get()->getComponent<PositionComponent>();

        if (pos->getX() + hitbox->getWidth() >= otherPos->getX()
            && pos->getX() <= otherPos->getX() + otherHitbox->getWidth()
            && pos->getY() + hitbox->getHeight() >= otherPos->getY()
            && pos->getY() <= otherPos->getY() + otherHitbox->getHeight()) {
            return other.get()->getId();
        }
    }
    return -1;
}