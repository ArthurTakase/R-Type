/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.hpp
*/

#pragma once

#include "Components/IComponent.hpp"

/**
 * @brief Component used to store the stats of an entity
 */
class StatComponent : public IComponent
{
  public:
    StatComponent(int life, int damage);
    ~StatComponent() noexcept;
    StatComponent(const StatComponent& other) noexcept = default;
    StatComponent(StatComponent&& other) noexcept      = delete;

    StatComponent& operator=(const StatComponent& rhs) noexcept = delete;
    StatComponent& operator=(StatComponent&& rhs) noexcept      = delete;

    int  getLife() const noexcept;
    int  getDamage() const noexcept;
    void setLife(int life) noexcept;
    void setDamage(int damage) noexcept;

  private:
    int life_;
    int damage_;
};