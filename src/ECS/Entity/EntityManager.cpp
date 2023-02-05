/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

#include <iostream>

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
    // TODO add components before add Entity to list
    entities_.emplace_back(std::make_unique<Entity>(createId()));
    entities_.back()->addComponent(TransformComponent(10, 8));
    entities_.back()->addComponent(HitboxComponent(15, 21));
    entities_.back()->addComponent(StatComponent(100, 5));
    entities_.back()->addComponent(MouvementComponent(1, 0, 1.0));
    entities_.back()->getComponent<HitboxComponent>()->setOnCollision(
        std::function<void(std::unique_ptr<Entity> & entity)>{
            [](std::unique_ptr<Entity>& entity) { std::cout << "Collision" << std::endl; } });
    entities_.back()->addComponent(DrawableComponent(0, 0, 10, 10, 5));
}

/**
 * It creates an entity, adds a position component to it, and then adds it to the entity manager
 */
void EntityManager::createEnemy() noexcept
{
    // TODO add components before add Entity to list
    entities_.emplace_back(std::make_unique<Entity>(createId()));
    entities_.back()->addComponent(TransformComponent(10, 8));
    entities_.back()->addComponent(DrawableComponent(0, 0, 10, 10, 5));
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
    return entities_[entities_.size() - 1]->getId() + 1;
}

/**
 * Add an entity to the entities list
 *
 * @param entity The entity you wish to add
 */
void EntityManager::addEntity(std::unique_ptr<Entity>& entity) noexcept
{
    entities_.emplace_back(std::move(entity));
}
