/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include "ServerGameInstance.hpp"

RType::RType()
    : entityManager_(std::make_unique<EntityManager>())
    , hitboxSystem_(nullptr)
    , serializerSystem_(nullptr)
    , behaviorSystem_(nullptr)
    , mouvementSystem_(nullptr)
{
    hitboxSystem_     = std::make_unique<HitboxSystem>(entityManager_);
    serializerSystem_ = std::make_unique<SerializerSystem>(entityManager_);
    behaviorSystem_   = std::make_unique<BehaviorSystem>(entityManager_);
    mouvementSystem_  = std::make_unique<MouvementSystem>(entityManager_);
}

void RType::stop() noexcept
{
    looping_ = false;
}

void RType::reset() noexcept
{
    looping_ = true;
}

void RType::run() const noexcept
{
    hitboxSystem_->run();
    // serializerSystem_->run();
    behaviorSystem_->run();
    mouvementSystem_->run();
}

RType::~RType() noexcept {}

EntityManager& RType::getManager() noexcept
{
    return *entityManager_;
}

HitboxSystem& RType::getHitboxSystem() noexcept
{
    return *hitboxSystem_;
}

SerializerSystem& RType::getSerializerSystem() noexcept
{
    return *serializerSystem_;
}

BehaviorSystem& RType::getBehaviorSystem() noexcept
{
    return *behaviorSystem_;
}
