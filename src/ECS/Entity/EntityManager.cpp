/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

/**
 * `EntityManager::EntityManager()` is the constructor for the `EntityManager` class
 */
EntityManager::EntityManager() {}

/**
 * It creates a new entity, adds a position component and a hitbox component to it, and then adds it to
 * the entity manager
 */
void EntityManager::createPlayer() noexcept
{
    _entities.emplace_back(std::make_unique<Entity>(get_id()));
    _entities.back()->addComponent(TransformComponent(10, 8));
    _entities.back()->addComponent(HitboxComponent(15, 21));
}

/**
 * It creates an entity, adds a position component to it, and then adds it to the entity manager
 */
void EntityManager::createEnemy() noexcept
{
    _entities.emplace_back(std::make_unique<Entity>(get_id()));
    _entities.back()->addComponent(TransformComponent(10, 8));
}

/**
 * It removes an entity from the entity manager
 *
 * @param id The id of the entity to remove.
 *
 * @return A pointer to the entity with the given id.
 */
bool EntityManager::removeEntity(size_t id) noexcept
{
    for (auto it = _entities.begin(); it != _entities.end(); it++) {
        if ((*it)->getId() == id) {
            _entities.erase(it);
            return true;
        }
    }
    return false;
}

/**
 * It loops through all the entities in the entity manager and returns the entity with the specified ID
 *
 * @param id The id of the entity to get.
 *
 * @return A pointer to an entity.
 */
Entity* EntityManager::getEntity(size_t id) const noexcept
{
    for (auto& entity : _entities) {
        if (entity->getId() == id) { return entity.get(); }
    }
    return nullptr;
}

/**
 * It returns a reference to the vector of entities
 *
 * @return A reference to the vector of entities.
 */
std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities() noexcept
{
    return _entities;
}

/**
 * If the entity list is empty, return 0, otherwise return the last entity's ID plus one
 *
 * @return The id of the last entity in the vector plus one.
 */
size_t EntityManager::get_id()
{
    if (_entities.empty()) { return 0; }
    return _entities[_entities.size() - 1]->getId() + 1;
}