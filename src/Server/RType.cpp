/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include <Server/RType.hpp>
#include <iostream>

RType::RType()
    : hitboxSystem_(&entityManager_)
    , behaviorSystem_(&entityManager_)
    , mouvementSystem_(&entityManager_)
    , animationSystem_(&entityManager_)
    , destroyableSystem_(&entityManager_)
{
}

void RType::stop() noexcept
{
    looping_ = false;
}

void RType::reset() noexcept
{
    looping_ = true;
}

void RType::run() noexcept
{
    destroyableSystem_.run();
    hitboxSystem_.run();
    mouvementSystem_.run();
    behaviorSystem_.run();
    animationSystem_.run();
}

RType::~RType() noexcept {}

HitboxSystem& RType::getHitboxSystem() noexcept
{
    return hitboxSystem_;
}

BehaviorSystem& RType::getBehaviorSystem() noexcept
{
    return behaviorSystem_;
}

EntityManager& RType::getManager() noexcept
{
    return entityManager_;
}

void RType::init() noexcept
{
    createBackground(0);
    createBackground(255);
    createAsteroid(255);
    createAsteroid(300);
    createAsteroid(200);
    createEnemy(255, 120);
    createEnemy(300, 200);
    createEnemy(200, 300);
}
