/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#include "MouvementComponent.hpp"

#include <iostream>

/**
 * It's a constructor that takes three parameters and assigns them to the three member variables
 *
 * @param dirX The direction of the movement on the X axis. (-1, 0 or 1)
 * @param dirY The direction of the movement on the Y axis. (-1, 0 or 1)
 * @param speed the speed of the entity
 */
MouvementComponent::MouvementComponent(int dirX, int dirY, float speed)
    : _dirX(dirX)
    , _dirY(dirY)
    , _speed(speed)
{
}

/**
 * It's the destructor of the class MouvementComponent
 */
MouvementComponent::~MouvementComponent() noexcept {}

/**
 * It returns the value of the private member _dirX
 *
 * @return The direction of the x axis.
 */
float MouvementComponent::getDirX() const noexcept
{
    return _dirX;
}

/**
 * It returns the value of the private attribute _dirY
 *
 * @return The direction of the Y axis.
 */
float MouvementComponent::getDirY() const noexcept
{
    return _dirY;
}

/**
 * It returns the speed of the entity
 *
 * @return The speed of the object.
 */
float MouvementComponent::getSpeed() const noexcept
{
    return _speed;
}

/**
 * It sets the direction of the entity on the X axis
 *
 * @param x The x-coordinate of the direction vector. (-1, 0 or 1)
 */
void MouvementComponent::setDirX(int x) noexcept
{
    _dirX = x;
}

/**
 * It sets the direction of the Y axis
 *
 * @param y The y-axis direction of the movement. (-1, 0 or 1)
 */
void MouvementComponent::setDirY(int y) noexcept
{
    _dirY = y;
}

/**
 * It sets the speed of the entity
 *
 * @param speed The speed of the entity.
 */
void MouvementComponent::setSpeed(float speed) noexcept
{
    _speed = speed;
}
