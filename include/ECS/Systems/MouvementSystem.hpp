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

class MouvementSystem
{
  public:
    MouvementSystem(EntityIterator<TransformComponent, MouvementComponent> it);
    ~MouvementSystem() noexcept                            = default;
    MouvementSystem(const MouvementSystem& other) noexcept = default;
    MouvementSystem(MouvementSystem&& other) noexcept      = delete;

    MouvementSystem& operator=(const MouvementSystem& rhs) noexcept = delete;
    MouvementSystem& operator=(MouvementSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<TransformComponent, MouvementComponent> _it;
};