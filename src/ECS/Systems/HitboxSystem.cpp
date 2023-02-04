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
#include "TransformComponent.hpp"

/**
 * It takes an iterator of entities with a position and hitbox component, and stores it in a private
 * member variable
 *
 * @param it The iterator to use for the system.
 */
HitboxSystem::HitboxSystem(std::unique_ptr<EntityManager>& manager) noexcept
    : manager_(manager)
    , it_(EntityIterator<TransformComponent, HitboxComponent>(manager->getEntities()))
{
}

/**
 * For each entity in the system, check if it collides with any other entity in the system
 */
void HitboxSystem::run()
{
    size_t other;

    for (; !it_.isEnd(); ++it_) {
        assert((it_.get()->hasComponents<HitboxComponent, TransformComponent>()));
        try {
            checkCollision(it_.get());
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    it_.reset();
}

/**
 * If the entity's hitbox is colliding with another entity's hitbox, return the other entity's id
 *
 * @param entity The entity to check for collisions with.
 *
 * @return The id of the entity that is colliding with the entity passed in.
 */
void HitboxSystem::checkCollision(std::unique_ptr<Entity>& entity) const
{
    for (auto other = EntityIterator<TransformComponent, HitboxComponent>(it_.it); !other.isEnd(); ++other) {
        if (other.get() == entity) { continue; }

        assert((other.get()->hasComponents<HitboxComponent, TransformComponent>()));

        auto hitbox      = entity->getComponent<HitboxComponent>();
        auto pos         = entity->getComponent<TransformComponent>();
        auto otherHitbox = other.get()->getComponent<HitboxComponent>();
        auto otherPos    = other.get()->getComponent<TransformComponent>();

        if (pos->getX() + hitbox->getWidth() >= otherPos->getX()
            && pos->getX() <= otherPos->getX() + otherHitbox->getWidth()
            && pos->getY() + hitbox->getHeight() >= otherPos->getY()
            && pos->getY() <= otherPos->getY() + otherHitbox->getHeight()) {
            entity->getComponent<HitboxComponent>()->onCollision(other.get());
        }
    }
}
