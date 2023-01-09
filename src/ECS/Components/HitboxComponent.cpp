/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include "HitboxComponent.hpp"

#include <iostream>

HitboxComponent::HitboxComponent(size_t width, size_t height)
    : _width(width)
    , _height(height)
{
}

size_t HitboxComponent::getWidth() const noexcept
{
    return _width;
}

size_t HitboxComponent::getHeight() const noexcept
{
    return _height;
}

void HitboxComponent::setWidth(size_t width) noexcept
{
    _width = width;
}

void HitboxComponent::setHeight(size_t height) noexcept
{
    _height = height;
}

void HitboxComponent::setSize(size_t width, size_t height) noexcept
{
    _width  = width;
    _height = height;
}

std::pair<size_t, size_t> HitboxComponent::getSize() const noexcept
{
    return std::make_pair(_width, _height);
}