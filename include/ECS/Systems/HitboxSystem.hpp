/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#pragma once

#include "EntityIterator.hpp"
#include "EntityManager.hpp"
#include "HitboxComponent.hpp"
#include "TransformComponent.hpp"

/**
 * @brief System used to check if an entity is colliding with another
 */
class HitboxSystem
{
  public:
    HitboxSystem(std::unique_ptr<EntityManager>& manager) noexcept;
    ~HitboxSystem() noexcept                         = default;
    HitboxSystem(const HitboxSystem& other) noexcept = default;
    HitboxSystem(HitboxSystem&& other) noexcept      = delete;

    HitboxSystem& operator=(const HitboxSystem& rhs) noexcept = delete;
    HitboxSystem& operator=(HitboxSystem&& rhs) noexcept      = delete;

    void run();
    void checkCollision(std::unique_ptr<Entity>& entity) const;

  private:
    EntityIterator<TransformComponent, HitboxComponent> it_;
    std::unique_ptr<EntityManager>&                     manager_;
};