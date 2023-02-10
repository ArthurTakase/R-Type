/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include <Server/ServerGameInstance.hpp>

RType::RType()
    : hitboxSystem_(&entityManager_)
    , behaviorSystem_(&entityManager_)
    , mouvementSystem_(&entityManager_)
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
    hitboxSystem_.run();
    behaviorSystem_.run();
    mouvementSystem_.run();
}

RType::~RType() noexcept {}

EntityManager& RType::getManager() noexcept
{
    return entityManager_;
}

HitboxSystem& RType::getHitboxSystem() noexcept
{
    return hitboxSystem_;
}

BehaviorSystem& RType::getBehaviorSystem() noexcept
{
    return behaviorSystem_;
}
