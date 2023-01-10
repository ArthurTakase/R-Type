/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PositionComponent.cpp
*/

#pragma once

#include <utility>

#include "IComponent.hpp"

/**
 * @brief Component used to store the position of an entity
 */
class PositionComponent : public IComponent
{
  public:
    PositionComponent(int x, int y);
    ~PositionComponent() noexcept;
    PositionComponent(const PositionComponent& other) noexcept = default;
    PositionComponent(PositionComponent&& other) noexcept      = delete;

    PositionComponent& operator=(const PositionComponent& rhs) noexcept = delete;
    PositionComponent& operator=(PositionComponent&& rhs) noexcept      = delete;

    int                 getX() const noexcept;
    int                 getY() const noexcept;
    void                setX(int x) noexcept;
    void                setY(int y) noexcept;
    void                setPos(int x, int y) noexcept;
    std::pair<int, int> getPos() const noexcept;

  private:
    int _x;
    int _y;
};