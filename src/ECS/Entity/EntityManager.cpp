/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include <ECS/Entity/EntityManager.hpp>
#include <Lib/Sprite.hpp>
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
    std::unique_ptr<Entity> player = std::make_unique<Entity>(createId());

    player->addComponent(TransformComponent(10, 8));
    player->addComponent(HitboxComponent(15, 21));
    player->addComponent(StatComponent(100, 5));
    player->addComponent(MouvementComponent(0, 0, 1.0));
    player->getComponent<HitboxComponent>()->setOnCollision(
        std::function<void(Entity * entity)>{[](Entity* entity) { std::cout << "Collision" << std::endl; }});
    player->addComponent(DrawableComponent(0, 0, 36, 36, 5));
    entities_.emplace_back(std::move(player));
}

/**
 * It creates an entity, adds a position component to it, and then adds it to the entity manager
 */
void EntityManager::createEnemy() noexcept
{
    std::unique_ptr<Entity> ennemy = std::make_unique<Entity>(createId());

    ennemy->addComponent(TransformComponent(10, 8));
    ennemy->addComponent(DrawableComponent(0, 0, 10, 10, 5));
    entities_.emplace_back(std::move(ennemy));
}

/**
 * It creates an entity, adds a position component to it, and then adds it to the entity manager
 */
void EntityManager::createBackground(int x) noexcept
{
    std::unique_ptr<Entity> background        = std::make_unique<Entity>(createId());
    auto                    behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(int key, Entity* entity)>{[](int key, Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= -255) { transform->setX(255); }
    }});

    background->addComponent(TransformComponent(x, 0));
    background->addComponent(DrawableComponent(0, 0, 255, 255, BACKGROUND_ID));
    background->addComponent(behaviorComponent);
    background->addComponent(MouvementComponent(-1, 0, 1.0));
    entities_.emplace_back(std::move(background));
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
void EntityManager::addEntity(std::unique_ptr<Entity>&& entity) noexcept
{
    entities_.emplace_back(std::move(entity));
}
