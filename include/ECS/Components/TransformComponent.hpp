/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component used to store the position of an entity
 */
class TransformComponent : public IComponent
{
  public:
    TransformComponent(int x, int y);
    TransformComponent(int x, int y, float scaleX, float scaleY);
    ~TransformComponent() noexcept;
    TransformComponent(const TransformComponent& other) noexcept = default;
    TransformComponent(TransformComponent&& other) noexcept      = delete;

    TransformComponent& operator=(const TransformComponent& rhs) noexcept = delete;
    TransformComponent& operator=(TransformComponent&& rhs) noexcept      = delete;

    int  getX() const noexcept;
    int  getY() const noexcept;
    void setX(int x) noexcept;
    void setY(int y) noexcept;
    void setPos(int x, int y) noexcept;
    int  getScaleX() const noexcept;
    int  getScaleY() const noexcept;
    void setScaleX(float x) noexcept;
    void setScaleY(float y) noexcept;
    void setScale(float x, float y) noexcept;

  private:
    int   _x;
    int   _y;
    float _scaleX = 1.0;
    float _scaleY = 1.0;
};