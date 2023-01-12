/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** ASystem.cpp
*/

#pragma once

#include <memory>
#include <vector>

#include "EntityManager.hpp"

/**
 * @brief System part of the ECS. It gets a vector with the entities and applies various methods according to the
 * components they have
 */
class ASystem
{
  public:
    ASystem(std::unique_ptr<EntityManager>& manager) noexcept
        : _manager(manager){};
    virtual ~ASystem() noexcept = default;
    // ASystem(const ASystem& other) noexcept = delete;
    // ASystem(ASystem&& other) noexcept      = delete;

    // ASystem& operator=(const ASystem& rhs) noexcept = delete;
    // ASystem& operator=(ASystem&& rhs) noexcept = delete;

    virtual void run() = 0;

  protected:
    // std::vector<std::unique_ptr<Entity>>& _entities;
    std::unique_ptr<EntityManager>& _manager;
};