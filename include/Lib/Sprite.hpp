/*
** EPITECH PROJECT, 2022string
** YEP
** File description:
** Sprite.cpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <bitset>
#include <string>

namespace SpriteIds
{
static constexpr unsigned int BACKGROUND_ID = 45;
}

/**
 * @brief This class is used to create a sprite.
 *
 */
class Sprite
{
  public:
    Sprite();
    Sprite(std::string path, int x, int y);
    ~Sprite() noexcept                   = default;
    Sprite(const Sprite& other) noexcept = delete;
    Sprite(Sprite&& other) noexcept      = delete;

    Sprite& operator=(const Sprite& rhs) noexcept = delete;
    Sprite& operator=(Sprite&& rhs) noexcept      = delete;

    void               setSpritePath(const std::string& path);
    const std::string& getSpritePath() const;
    void               setX(int x);
    void               setY(int y);
    int                getX() const;
    int                getY() const;
    void*              getSprite();
    void*              getTexture();
    void               setTextureRect(int xtexture, int ytexture, int width, int height);
    void               updatePosition();
    void               setScale(float x, float y) noexcept;

  private:
    std::string spritePath;
    int         x;
    int         y;
    sf::Sprite  sprite;
    sf::Texture texture;
};
