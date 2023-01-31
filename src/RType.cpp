/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include "RType.hpp"

#include <iostream>

RType::RType()
    : _entityManager(std::make_unique<EntityManager>())
    , _hitboxSystem(nullptr)
    , _serializerSystem(std::make_unique<SerializerSystem>())
{
    std::cout << "coucou je suis un R-Type" << std::endl;
}

RType::~RType() noexcept {}
