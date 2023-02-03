/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include "BehaviorSystem.hpp"

#include <cassert>
#include <iostream>

/**
 * It takes a reference to a unique pointer to an EntityManager, and then it initializes the _manager
 * member variable with that reference, and it initializes the _it member variable with an
 * EntityIterator that iterates over the entities in the EntityManager
 *
 * @param EntityManager The EntityManager that the system will use to iterate over entities.
 */
BehaviorSystem::BehaviorSystem(std::unique_ptr<EntityManager>& manager) noexcept
    : _manager(manager)
    , _it(EntityIterator<BehaviorComponent>(manager->getEntities()))
{
}

/**
 * It iterates through all entities with a BehaviorComponent and calls their onUpdate() function
 */
void BehaviorSystem::run()
{
    size_t other;

    for (; !_it.isEnd(); ++_it) {
        assert((_it.get()->hasComponents<BehaviorComponent>()));
        _it.get()->getComponent<BehaviorComponent>()->onUpdate();
    }
    _it.reset();
}