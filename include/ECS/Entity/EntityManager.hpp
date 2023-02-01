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
#include "MouvementComponent.hpp"
#include "StatComponent.hpp"
#include "TransformComponent.hpp"

/**
 * @brief Object used to create the different entities of the software
 */
class EntityManager
{
  public:
    EntityManager();
    ~EntityManager() noexcept                          = default;
    EntityManager(const EntityManager& other) noexcept = default;
    EntityManager(EntityManager&& other) noexcept      = delete;

    EntityManager& operator=(const EntityManager& rhs) noexcept = delete;
    EntityManager& operator=(EntityManager&& rhs) noexcept      = delete;

    void createPlayer() noexcept;
    void createEnemy() noexcept;

    bool                                  removeEntity(size_t id) noexcept;
    Entity*                               getEntity(size_t id) const noexcept;
    std::vector<std::unique_ptr<Entity>>& getEntities() noexcept;
    void                                  addEntity(std::unique_ptr<Entity>& entity) noexcept;

  private:
    std::vector<std::unique_ptr<Entity>> _entities;

  private:
    size_t createId();
};
