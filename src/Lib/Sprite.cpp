/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sprite.cpp
*/

#include <Lib/Sprite.hpp>

/**
 * Sprite is a class that takes a string, an int, and an int and sets the spritePath, x, and y
 * variables to the values of the string, int, and int.
 *
 * @param path The path to the image file.
 * @param x The x coordinate of the sprite.
 * @param y The y coordinate of the sprite.
 */
Sprite::Sprite(std::string path, int x, int y)
    : spritePath(path)
    , x(x)
    , y(y)
{
}

/**
 * This function sets the sprite path to the path passed in.
 *
 * @param path The path to the sprite sheet.
 */
void Sprite::setSpritePath(const std::string& path)
{
    spritePath = path;
}

/**
 * Returns the path to the sprite's image file.
 *
 * @return The spritePath variable is being returned.
 */
const std::string& Sprite::getSpritePath() const
{
    return spritePath;
}

/**
 * Return a bitset of 8 bits that represents the sprite.
 *
 * @return A bitset of 8 bits.
 */
std::bitset<8> Sprite::serialize() const
{
    std::bitset<8> serialized;
    return serialized;
}

/**
 * This function sets the x coordinate of the sprite.
 *
 * @param x The x coordinate of the sprite.
 */
void Sprite::setX(int x)
{
    this->x = x;
}

/**
 * This function sets the y coordinate of the sprite.
 *
 * @param y The y coordinate of the sprite.
 */
void Sprite::setY(int y)
{
    this->y = y;
}

/**
 * This function returns the x coordinate of the sprite.
 *
 * @return The x coordinate of the sprite.
 */
int Sprite::getX() const
{
    return x;
}

/**
 * This function returns the y coordinate of the sprite.
 *
 * @return The y coordinate of the sprite.
 */
int Sprite::getY() const
{
    return y;
}