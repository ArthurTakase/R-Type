/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#include <Components/TransformComponent.hpp>
#include <iostream>

/**
 * It's a constructor for the TransformComponent class
 *
 * @param x The x coordinate of the position.
 * @param y The y coordinate of the position.
 */
TransformComponent::TransformComponent(int x, int y)
    : x_(x)
    , y_(y)
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
    : x_(x)
    , y_(y)
    , scaleX_(scaleX)
    , scaleY_(scaleY)
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
    return x_;
}

/**
 * It returns the y coordinate of the position component
 *
 * @return The y position of the entity.
 */
int TransformComponent::getY() const noexcept
{
    return y_;
}

/**
 * Sets the x position of the entity.
 *
 * @param x The x coordinate of the position.
 */
void TransformComponent::setX(int x) noexcept
{
    x_ = x;
}

/**
 * This function sets the y coordinate of the position component.
 *
 * @param y The y coordinate of the position.
 */
void TransformComponent::setY(int y) noexcept
{
    y_ = y;
}

/**
 * Sets the position of the entity to the given x and y coordinates.
 *
 * @param x The x position of the entity.
 * @param y The y coordinate of the position.
 */
void TransformComponent::setPos(int x, int y) noexcept
{
    x_ = x;
    y_ = y;
}

/**
 * This function returns the value of the private member variable _scaleX.
 *
 * @return The scaleX value of the TransformComponent.
 */
float TransformComponent::getScaleX() const noexcept
{
    return scaleX_;
}

/**
 * `getScaleY()` returns the value of the `_scaleY` member variable
 *
 * @return The scaleY variable.
 */
float TransformComponent::getScaleY() const noexcept
{
    return scaleY_;
}

/**
 * This function sets the scale of the x-axis of the entity.
 *
 * @param x The x position of the entity.
 */
void TransformComponent::setScaleX(float x) noexcept
{
    scaleX_ = x;
}

/**
 * It sets the scale of the Y axis
 *
 * @param y The new scale of the Y axis.
 */
void TransformComponent::setScaleY(float y) noexcept
{
    scaleY_ = y;
}

/**
 * It sets the scale of the entity
 *
 * @param x The x position of the entity.
 * @param y The y position of the entity.
 */
void TransformComponent::setScale(float x, float y) noexcept
{
    scaleX_ = x;
    scaleY_ = y;
}
