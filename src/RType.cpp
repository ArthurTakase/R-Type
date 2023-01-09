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
{
    std::cout << "RType created" << std::endl;

    _entityManager->createPlayer();
    _entityManager->createEnemy();
    _entityManager->createEnemy();
    _entityManager->createEnemy();
    _entityManager->createPlayer();
    _entityManager->createEnemy();
    _entityManager->createPlayer();
    _entityManager->createEnemy();

    std::cout << "Entities..........";
    for (auto& entity : _entityManager->getEntities()) { std::cout << entity->getId() << " "; }
    std::cout << std::endl;

    std::cout << "Ents w Pos........";
    auto entities_pos = _entityManager->getEntsByComps<PositionComponent>();
    for (auto& entity : entities_pos) { std::cout << entity->getId() << " "; }
    std::cout << std::endl;

    std::cout << "Ents w Hit........";
    auto entities_hit = _entityManager->getEntsByComps<HitboxComponent>();
    for (auto& entity : entities_hit) { std::cout << entity->getId() << " "; }
    std::cout << std::endl;

    std::cout << "Ents w Pos & Hit..";
    auto entities_pos_hit = _entityManager->getEntsByComps<PositionComponent, HitboxComponent>();
    for (auto& entity : entities_pos_hit) { std::cout << entity->getId() << " "; }
    std::cout << std::endl;
}

RType::~RType() noexcept {}