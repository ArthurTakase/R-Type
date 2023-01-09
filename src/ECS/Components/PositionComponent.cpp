/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

#include <iostream>

PositionComponent::PositionComponent(int x, int y)
    : _x(x)
    , _y(y)
{
}

PositionComponent::~PositionComponent() noexcept {}

int PositionComponent::getX() const noexcept
{
    return _x;
}

int PositionComponent::getY() const noexcept
{
    return _y;
}

std::pair<int, int> PositionComponent::getPos() const noexcept
{
    return std::make_pair(_x, _y);
}

void PositionComponent::setX(int x) noexcept
{
    _x = x;
}

void PositionComponent::setY(int y) noexcept
{
    _y = y;
}

void PositionComponent::setPos(int x, int y) noexcept
{
    _x = x;
    _y = y;
}