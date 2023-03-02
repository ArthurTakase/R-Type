/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sprite.cpp
*/

#include <Lib/Sprite.hpp>
#include <Error/Error.hpp>

/**
 * This is the default constructor for the Sprite class.
 */
Sprite::Sprite()
    : spritePath("")
    , x(0)
    , y(0)
{
}

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
    if (path == "") { return; }

    if (!texture.loadFromFile(spritePath)) { throw Error("Error: Could not load sprite from file: " + spritePath); }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

/**
 * This function sets the sprite path to the path passed in.
 *
 * @param path The path to the sprite sheet.
 */
void Sprite::setSpritePath(const std::string& path)
{
    spritePath = path;

    if (!texture.loadFromFile(spritePath)) {
        throw Error("Error: Could not load sprite from file: " + spritePath);
    }
    sprite.setTexture(texture);
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
 * This function sets the x coordinate of the sprite.
 *
 * @param x The x coordinate of the sprite.
 */
void Sprite::setX(int x)
{
    this->x = x;
    sprite.setPosition(x, y);
}

/**
 * This function sets the y coordinate of the sprite.
 *
 * @param y The y coordinate of the sprite.
 */
void Sprite::setY(int y)
{
    this->y = y;
    sprite.setPosition(x, y);
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

/**
 * This function returns the sprite.
 *
 * @return The sprite.
 */
void* Sprite::getSprite()
{
    return static_cast<void*>(&sprite);
}

/**
 * This function returns the texture.
 *
 * @return The texture.
 */
void* Sprite::getTexture()
{
    return static_cast<void*>(&texture);
}

/**
 * This function sets the texture rectangle of the sprite.
 *
 * @param xtexture The x coordinate of the texture.
 * @param ytexture The y coordinate of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 */
void Sprite::setTextureRect(int xtexture, int ytexture, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(xtexture, ytexture, width, height));
}

/**
 * This function updates the position of the sprite.
 */
void Sprite::updatePosition()
{
    sprite.setPosition(x, y);
}

/**
 * Sets the scale of the sprite
 *
 * @param x The x-scale of the sprite.
 * @param y The y coordinate of the sprite.
 */
void Sprite::setScale(float x, float y) noexcept
{
    sprite.setScale(x, y);
}