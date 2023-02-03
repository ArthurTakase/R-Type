/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#include "TransformComponent.hpp"

#include <iostream>

/**
 * It's a constructor for the TransformComponent class
 *
 * @param x The x coordinate of the position.
 * @param y The y coordinate of the position.
 */
TransformComponent::TransformComponent(int x, int y)
    : _x(x)
    , _y(y)
{
}

/**
 * It's a constructor that takes in four parameters and assigns them to the class variables
 *
 * @param x The x position of the entity.
 * @param y The y position of the entity.
 * @param scaleX The scale of the object on the X axis.
 * @param scaleY The scale of the object on the Y axis.
 */
TransformComponent::TransformComponent(int x, int y, float scaleX, float scaleY)
    : _x(x)
    , _y(y)
    , _scaleX(scaleX)
    , _scaleY(scaleY)
{
}

/**
 * The destructor for the TransformComponent class.
 */
TransformComponent::~TransformComponent() noexcept {}

/**
 * This function returns the value of the private member variable _x.
 *
 * @return The value of the private member variable _x.
 */
int TransformComponent::getX() const noexcept
{
    return _x;
}

/**
 * It returns the y coordinate of the position component
 *
 * @return The y position of the entity.
 */
int TransformComponent::getY() const noexcept
{
    return _y;
}

/**
 * Sets the x position of the entity.
 *
 * @param x The x coordinate of the position.
 */
void TransformComponent::setX(int x) noexcept
{
    _x = x;
}

/**
 * This function sets the y coordinate of the position component.
 *
 * @param y The y coordinate of the position.
 */
void TransformComponent::setY(int y) noexcept
{
    _y = y;
}

/**
 * Sets the position of the entity to the given x and y coordinates.
 *
 * @param x The x position of the entity.
 * @param y The y coordinate of the position.
 */
void TransformComponent::setPos(int x, int y) noexcept
{
    _x = x;
    _y = y;
}

/**
 * This function returns the value of the private member variable _scaleX.
 *
 * @return The scaleX value of the TransformComponent.
 */
float TransformComponent::getScaleX() const noexcept
{
    return _scaleX;
}

/**
 * `getScaleY()` returns the value of the `_scaleY` member variable
 *
 * @return The scaleY variable.
 */
float TransformComponent::getScaleY() const noexcept
{
    return _scaleY;
}

/**
 * This function sets the scale of the x-axis of the entity.
 *
 * @param x The x position of the entity.
 */
void TransformComponent::setScaleX(float x) noexcept
{
    _scaleX = x;
}

/**
 * It sets the scale of the Y axis
 *
 * @param y The new scale of the Y axis.
 */
void TransformComponent::setScaleY(float y) noexcept
{
    _scaleY = y;
}

/**
 * It sets the scale of the entity
 *
 * @param x The x position of the entity.
 * @param y The y position of the entity.
 */
void TransformComponent::setScale(float x, float y) noexcept
{
    _scaleX = x;
    _scaleY = y;
}
