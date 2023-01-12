/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#pragma once

#include "ASystem.hpp"
#include "EntityIterator.hpp"

/**
 * @brief System used to check if an entity is colliding with another
 */
class HitboxSystem
{
  public:
    HitboxSystem(EntityIterator<PositionComponent, HitboxComponent> it);
    ~HitboxSystem() noexcept                         = default;
    HitboxSystem(const HitboxSystem& other) noexcept = default;
    HitboxSystem(HitboxSystem&& other) noexcept      = delete;

    HitboxSystem& operator=(const HitboxSystem& rhs) noexcept = delete;
    HitboxSystem& operator=(HitboxSystem&& rhs) noexcept      = delete;

    void run();
    int  checkCollision(std::unique_ptr<Entity>& entity) const;

  private:
    EntityIterator<PositionComponent, HitboxComponent> _it;
};