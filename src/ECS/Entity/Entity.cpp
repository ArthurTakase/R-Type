/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

#include <iostream>

Entity::Entity(size_t id)
    : _id(id)
{
}

Entity::~Entity() noexcept {}

size_t Entity::getId() const noexcept
{
    return _id;
}

std::vector<std::unique_ptr<IComponent>>& Entity::getComponents() noexcept
{
    return (_components);
};