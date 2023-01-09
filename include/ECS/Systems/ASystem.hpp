/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** ASystem.cpp
*/

#pragma once

#include <memory>
#include <vector>

#include "Entity.hpp"

class ASystem
{
  public:
    ASystem(std::vector<std::shared_ptr<Entity>>& entities) noexcept
        : _entities(entities){};
    virtual ~ASystem() noexcept = default;
    // ASystem(const ASystem& other) noexcept = delete;
    // ASystem(ASystem&& other) noexcept      = delete;

    // ASystem& operator=(const ASystem& rhs) noexcept = delete;
    // ASystem& operator=(ASystem&& rhs) noexcept = delete;

    virtual void run() = 0;
    inline void  setEntities(std::vector<std::shared_ptr<Entity>>& entities) noexcept { _entities = entities; }

  protected:
    std::vector<std::shared_ptr<Entity>>& _entities;
};