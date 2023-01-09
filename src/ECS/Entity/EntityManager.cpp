/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

EntityManager::EntityManager() {}

void EntityManager::createPlayer() noexcept
{
    _entities.emplace_back(std::make_shared<Entity>(get_id()));
    _entities.back()->addComponent(PositionComponent(10, 8));
    _entities.back()->addComponent(HitboxComponent(15, 21));
}

void EntityManager::createEnemy() noexcept
{
    _entities.emplace_back(std::make_shared<Entity>(get_id()));
    _entities.back()->addComponent(PositionComponent(10, 8));
}

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

std::shared_ptr<Entity> EntityManager::getEntity(size_t id) const noexcept
{
    for (auto& entity : _entities) {
        if (entity->getId() == id) { return entity; }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Entity>>& EntityManager::getEntities() noexcept
{
    return _entities;
}

size_t EntityManager::get_id()
{
    if (_entities.empty()) { return 0; }
    return _entities[_entities.size() - 1]->getId() + 1;
}