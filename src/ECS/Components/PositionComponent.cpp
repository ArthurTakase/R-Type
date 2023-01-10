/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

#include <iostream>

/**
 * It's a constructor for the PositionComponent class
 *
 * @param x The x coordinate of the position.
 * @param y The y coordinate of the position.
 */
PositionComponent::PositionComponent(int x, int y)
    : _x(x)
    , _y(y)
{
}

/**
 * The destructor for the PositionComponent class.
 */
PositionComponent::~PositionComponent() noexcept {}

/**
 * This function returns the value of the private member variable _x.
 *
 * @return The value of the private member variable _x.
 */
int PositionComponent::getX() const noexcept
{
    return _x;
}

/**
 * It returns the y coordinate of the position component
 *
 * @return The y position of the entity.
 */
int PositionComponent::getY() const noexcept
{
    return _y;
}

/**
 * It returns a pair of integers, the first being the x coordinate and the second being the y
 * coordinate
 *
 * @return A pair of ints
 */
std::pair<int, int> PositionComponent::getPos() const noexcept
{
    return std::make_pair(_x, _y);
}

/**
 * Sets the x position of the entity.
 *
 * @param x The x coordinate of the position.
 */
void PositionComponent::setX(int x) noexcept
{
    _x = x;
}

/**
 * This function sets the y coordinate of the position component.
 *
 * @param y The y coordinate of the position.
 */
void PositionComponent::setY(int y) noexcept
{
    _y = y;
}

/**
 * Sets the position of the entity to the given x and y coordinates.
 *
 * @param x The x position of the entity.
 * @param y The y coordinate of the position.
 */
void PositionComponent::setPos(int x, int y) noexcept
{
    _x = x;
    _y = y;
}