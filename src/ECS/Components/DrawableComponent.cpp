/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include <ECS/Components/DrawableComponent.hpp>
#include <iostream>

/**
 * It's a constructor for the DrawableComponent class
 *
 * @param offsetX The x offset of the texture.
 * @param offsetY The y offset of the texture
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param textureId The id of the texture to use.
 */
DrawableComponent::DrawableComponent(int offsetX, int offsetY, int width, int height, int textureId)
    : offsetX_(offsetX)
    , offsetY_(offsetY)
    , width_(width)
    , height_(height)
    , textureId_(textureId)
{
}

/**
 * It returns the value of the private member variable _offsetX
 *
 * @return The offset of the x-coordinate of the drawable component.
 */
int DrawableComponent::getOffsetX() const noexcept
{
    return offsetX_;
}

/**
 * This function returns the y-offset of the drawable component.
 *
 * @return The offset of the y-axis.
 */
int DrawableComponent::getOffsetY() const noexcept
{
    return offsetY_;
}

/**
 * It returns the width of the drawable component
 *
 * @return The width of the DrawableComponent.
 */
int DrawableComponent::getWidth() const noexcept
{
    return width_;
}

/**
 * It returns the height of the drawable component
 *
 * @return The height of the DrawableComponent.
 */
int DrawableComponent::getHeight() const noexcept
{
    return height_;
}

/**
 * It returns the value of the private member variable _textureId
 *
 * @return The texture id of the drawable component.
 */
int DrawableComponent::getTextureId() const noexcept
{
    return textureId_;
}

/**
 * It sets the offset of the X coordinate of the DrawableComponent
 *
 * @param offsetX The x offset of the sprite.
 */
void DrawableComponent::setOffsetX(int offsetX) noexcept
{
    offsetX_ = offsetX;
}

/**
 * It sets the offsetY variable to the value passed in
 *
 * @param offsetY The y-offset of the sprite.
 */
void DrawableComponent::setOffsetY(int offsetY) noexcept
{
    offsetY_ = offsetY;
}

/**
 * This function sets the width of the drawable component
 *
 * @param width The width of the drawable component.
 */
void DrawableComponent::setWidth(int width) noexcept
{
    width_ = width;
}

/**
 * It sets the height of the drawable component
 *
 * @param height The height of the drawable component.
 */
void DrawableComponent::setHeight(int height) noexcept
{
    height_ = height;
}

/**
 * It sets the texture ID of the drawable component
 *
 * @param textureId The id of the texture to use.
 */
void DrawableComponent::setTextureId(int textureId) noexcept
{
    textureId_ = textureId;
}

/**
 * It sets the sprite of the drawable component
 *
 * @param sprite The sprite to use.
 */
void DrawableComponent::setSprite(Sprite* sprite) noexcept
{
    sprite_ = sprite;
}

/**
 * It returns the sprite of the drawable component
 *
 * @return The sprite of the drawable component.
 */
Sprite* DrawableComponent::getSprite() const noexcept
{
    return sprite_;
}