/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include "HitboxComponent.hpp"

#include <iostream>

/**
 * It's a constructor for the HitboxComponent class
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
HitboxComponent::HitboxComponent(size_t width, size_t height)
    : _width(width)
    , _height(height)
{
}

/**
 * It returns the width of the hitbox
 *
 * @return The width of the hitbox.
 */
size_t HitboxComponent::getWidth() const noexcept
{
    return _width;
}

/**
 * It returns the height of the hitbox
 *
 * @return The height of the hitbox.
 */
size_t HitboxComponent::getHeight() const noexcept
{
    return _height;
}

/**
 * It sets the width of the hitbox
 *
 * @param width The width of the hitbox.
 */
void HitboxComponent::setWidth(size_t width) noexcept
{
    _width = width;
}

/**
 * It sets the height of the hitbox
 *
 * @param height The height of the hitbox.
 */
void HitboxComponent::setHeight(size_t height) noexcept
{
    _height = height;
}

/**
 * It sets the width and height of the hitbox
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
void HitboxComponent::setSize(size_t width, size_t height) noexcept
{
    _width  = width;
    _height = height;
}