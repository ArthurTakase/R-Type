/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** BehaviorSystem.cpp
*/

#pragma once

#include "BehaviorComponent.hpp"
#include "EntityIterator.hpp"
#include "EntityManager.hpp"

/**
 * @brief System used to check if an entity is colliding with another
 */
class BehaviorSystem
{
  public:
    BehaviorSystem(std::unique_ptr<EntityManager>& manager) noexcept;
    ~BehaviorSystem() noexcept                           = default;
    BehaviorSystem(const BehaviorSystem& other) noexcept = default;
    BehaviorSystem(BehaviorSystem&& other) noexcept      = delete;

    BehaviorSystem& operator=(const BehaviorSystem& rhs) noexcept = delete;
    BehaviorSystem& operator=(BehaviorSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<BehaviorComponent> it_;
    std::unique_ptr<EntityManager>&   manager_;
};