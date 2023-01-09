/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#pragma once

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "HitboxComponent.hpp"
#include "InstanceOf.hpp"
#include "PositionComponent.hpp"

class EntityManager
{
  public:
    EntityManager();
    ~EntityManager() noexcept                          = default;
    EntityManager(const EntityManager& other) noexcept = delete;
    EntityManager(EntityManager&& other) noexcept      = delete;

    EntityManager& operator=(const EntityManager& rhs) noexcept = delete;
    EntityManager& operator=(EntityManager&& rhs) noexcept      = delete;

  private:
    std::vector<std::shared_ptr<Entity>> _entities;

  public:
    void createPlayer() noexcept;
    void createEnemy() noexcept;

    bool                                  removeEntity(size_t id) noexcept;
    std::shared_ptr<Entity>               getEntity(size_t id) const noexcept;
    std::vector<std::shared_ptr<Entity>>& getEntities() noexcept;

    template <typename T, typename... Args>
    std::vector<std::shared_ptr<Entity>> getEntsByComps()
    {
        std::vector<std::shared_ptr<Entity>> entities;

        for (auto& entity : _entities)
            if (entity.get()->hasComponents<T, Args...>()) { entities.push_back(entity); }

        return entities;
    }

  private:
    size_t get_id();
};