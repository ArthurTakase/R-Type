/*
** EPITECH PROJECT, 2022string
** YEP
** File description:
** Sprite.cpp
*/

#pragma once

#include <bitset>
#include <string>

namespace SpriteIds
{
#define BACKGROUND_ID 45
}

/**
 * @brief This class is used to create a sprite.
 *
 */
class Sprite
{
  public:
    Sprite(std::string path, int x, int y);
    ~Sprite() noexcept                   = default;
    Sprite(const Sprite& other) noexcept = delete;
    Sprite(Sprite&& other) noexcept      = delete;

    Sprite& operator=(const Sprite& rhs) noexcept = delete;
    Sprite& operator=(Sprite&& rhs) noexcept      = delete;

    void               setSpritePath(const std::string& path);
    const std::string& getSpritePath() const;
    std::bitset<8>     serialize() const;
    void               setX(int x);
    void               setY(int y);
    int                getX() const;
    int                getY() const;

  private:
    std::string spritePath;
    int         x;
    int         y;
};
