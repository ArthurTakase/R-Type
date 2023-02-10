/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>

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

    int   getX() const noexcept;
    int   getY() const noexcept;
    void  setX(int x) noexcept;
    void  setY(int y) noexcept;
    void  setPos(int x, int y) noexcept;
    float getScaleX() const noexcept;
    float getScaleY() const noexcept;
    void  setScaleX(float x) noexcept;
    void  setScaleY(float y) noexcept;
    void  setScale(float x, float y) noexcept;

  private:
    int   x_;
    int   y_;
    float scaleX_ = 1.0;
    float scaleY_ = 1.0;
};
