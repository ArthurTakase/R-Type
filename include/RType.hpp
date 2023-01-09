/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#pragma once

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "EntityManager.hpp"
#include "HitboxComponent.hpp"
#include "HitboxSystem.hpp"
#include "PositionComponent.hpp"

class RType
{
  public:
    RType();
    ~RType() noexcept;
    RType(const RType& other) noexcept = delete;
    RType(RType&& other) noexcept      = delete;

    RType& operator=(const RType& rhs) noexcept = delete;
    RType& operator=(RType&& rhs) noexcept      = delete;

  private:
    std::unique_ptr<EntityManager> _entityManager;
    std::unique_ptr<HitboxSystem>  _hitboxSystem;
};