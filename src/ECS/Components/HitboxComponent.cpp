/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include "Components/HitboxComponent.hpp"

#include <iostream>

/**
 * It's a constructor for the HitboxComponent class
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
HitboxComponent::HitboxComponent(size_t width, size_t height)
    : width_(width)
    , height_(height)
{
}

/**
 * It returns the width of the hitbox
 *
 * @return The width of the hitbox.
 */
size_t HitboxComponent::getWidth() const noexcept
{
    return width_;
}

/**
 * It returns the height of the hitbox
 *
 * @return The height of the hitbox.
 */
size_t HitboxComponent::getHeight() const noexcept
{
    return height_;
}

/**
 * It sets the width of the hitbox
 *
 * @param width The width of the hitbox.
 */
void HitboxComponent::setWidth(size_t width) noexcept
{
    width_ = width;
}

/**
 * It sets the height of the hitbox
 *
 * @param height The height of the hitbox.
 */
void HitboxComponent::setHeight(size_t height) noexcept
{
    height_ = height;
}

/**
 * It sets the width and height of the hitbox
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
void HitboxComponent::setSize(size_t width, size_t height) noexcept
{
    width_  = width;
    height_ = height;
}

void HitboxComponent::setOnCollision(std::function<void(Entity*)> onCollision) noexcept
{
    onCollision_ = onCollision;
}

void HitboxComponent::onCollision(Entity* entity) const noexcept
{
    onCollision_(entity);
}