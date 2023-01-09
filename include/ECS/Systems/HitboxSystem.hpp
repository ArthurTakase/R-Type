/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#pragma once

#include "ASystem.hpp"

class HitboxSystem : public ASystem
{
  public:
    HitboxSystem(std::vector<std::shared_ptr<Entity>>& entities);
    ~HitboxSystem() noexcept                         = default;
    HitboxSystem(const HitboxSystem& other) noexcept = default;
    HitboxSystem(HitboxSystem&& other) noexcept      = delete;

    HitboxSystem& operator=(const HitboxSystem& rhs) noexcept = delete;
    HitboxSystem& operator=(HitboxSystem&& rhs) noexcept      = delete;

    void run() final;
    bool checkCollision(std::shared_ptr<Entity>& entity) const noexcept;
};