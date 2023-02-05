/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#pragma once

#include <functional>
#include <memory>

#include "Entity.hpp"
#include "IComponent.hpp"

/**
 * @brief Component for the hitbox of an entity. Contain the width and the height of the box.
 */
class HitboxComponent : public IComponent
{
  public:
    HitboxComponent(size_t width, size_t height);
    ~HitboxComponent() noexcept                            = default;
    HitboxComponent(const HitboxComponent& other) noexcept = default;
    HitboxComponent(HitboxComponent&& other) noexcept      = delete;

    HitboxComponent& operator=(const HitboxComponent& rhs) noexcept = delete;
    HitboxComponent& operator=(HitboxComponent&& rhs) noexcept      = delete;

    size_t getWidth() const noexcept;
    size_t getHeight() const noexcept;
    void   setWidth(size_t width) noexcept;
    void   setHeight(size_t height) noexcept;
    void   setSize(size_t width, size_t height) noexcept;
    void   setOnCollision(std::function<void(std::unique_ptr<Entity>&)> onCollision) noexcept;
    void   onCollision(std::unique_ptr<Entity>& entity) const noexcept;

  private:
    size_t                                        width_;
    size_t                                        height_;
    std::function<void(std::unique_ptr<Entity>&)> onCollision_;
};