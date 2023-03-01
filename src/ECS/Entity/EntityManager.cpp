/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include <ECS/Entity/EntityManager.hpp>
#include <Lib/Sprite.hpp>
#include <Lib/Timer.hpp>
#include <iostream>

/**
 * It removes an entity from the entity manager
 *
 * @param id The id of the entity to remove.
 *
 * @return A pointer to the entity with the given id.
 */
bool EntityManager::removeEntity(size_t id) noexcept
{
    for (auto it = entities_.begin(); it != entities_.end(); it++) {
        if ((*it)->getId() == id) {
            entities_.erase(it);
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
    for (auto& entity : entities_) {
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
    return entities_;
}

/**
 * If the entity list is empty, return 0, otherwise return the last entity's ID plus one
 *
 * @return The id of the last entity in the vector plus one.
 */
size_t EntityManager::createId() const noexcept
{
    if (entities_.empty()) { return 0; }
    return higherId() + 1;
}

/**
 * It creates a new entity and adds it to the entity manager
 *
 * @return A pointer to the newly created entity.
 */
Entity* EntityManager::newEntity() noexcept
{
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(createId());
    entities_.emplace_back(std::move(entity));
    return entities_[entities_.size() - 1].get();
}

/**
 * It creates a new entity and adds it to the list of entities
 *
 * @param id The id of the entity.
 *
 * @return A pointer to the last element in the vector.
 */
Entity* EntityManager::newEntity(int id) noexcept
{
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(id);
    entities_.emplace_back(std::move(entity));
    return entities_[entities_.size() - 1].get();
}

/**
 * Get the higher id in all entities
 *
 * @return The higher id.
 */
size_t EntityManager::higherId() const noexcept
{
    size_t higher_id = 0;
    for (auto& entity : entities_) {
        size_t entity_id = entity->getId();
        if (entity_id > higher_id) { higher_id = entity_id; }
    }
    return higher_id;
}
