/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DrawableComponent.cpp
*/

#pragma once

#include <functional>
#include <memory>

#include "Entity.hpp"
#include "IComponent.hpp"
#include "Sprite.hpp"

/**
 * @brief Component assigned to drawable entities.
 */
class DrawableComponent : public IComponent
{
  public:
    DrawableComponent(int offsetX, int offsetY, int width, int height, int textureId);
    ~DrawableComponent() noexcept                              = default;
    DrawableComponent(const DrawableComponent& other) noexcept = default;
    DrawableComponent(DrawableComponent&& other) noexcept      = delete;

    DrawableComponent& operator=(const DrawableComponent& rhs) noexcept = delete;
    DrawableComponent& operator=(DrawableComponent&& rhs) noexcept      = delete;

    int     getOffsetX() const noexcept;
    int     getOffsetY() const noexcept;
    int     getWidth() const noexcept;
    int     getHeight() const noexcept;
    int     getTextureId() const noexcept;
    void    setOffsetX(int offsetX) noexcept;
    void    setOffsetY(int offsetY) noexcept;
    void    setWidth(int width) noexcept;
    void    setHeight(int height) noexcept;
    void    setTextureId(int textureId) noexcept;
    void    setSprite(Sprite* sprite) noexcept;
    Sprite* getSprite() const noexcept;

  private:
    int     offsetX_;
    int     offsetY_;
    int     width_;
    int     height_;
    int     textureId_;
    Sprite* sprite_;
};