/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MouvementSystem.cpp
*/

#pragma once

#include "EntityIterator.hpp"
#include "MouvementComponent.hpp"
#include "TransformComponent.hpp"

/**
 * @brief A system that will update the position of the entities that have a TransformComponent and a
 * MouvementComponent.
 */
class MouvementSystem
{
  public:
    MouvementSystem(std::vector<std::unique_ptr<Entity>>& entities);
    ~MouvementSystem() noexcept                            = default;
    MouvementSystem(const MouvementSystem& other) noexcept = default;
    MouvementSystem(MouvementSystem&& other) noexcept      = delete;

    MouvementSystem& operator=(const MouvementSystem& rhs) noexcept = delete;
    MouvementSystem& operator=(MouvementSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<TransformComponent, MouvementComponent> _it;
};