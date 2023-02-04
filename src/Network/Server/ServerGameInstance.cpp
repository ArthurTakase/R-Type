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
{
    hitboxSystem_     = std::make_unique<HitboxSystem>(entityManager_);
    serializerSystem_ = std::make_unique<SerializerSystem>(entityManager_);
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
    while (looping_) {
        hitboxSystem_->run();
        serializerSystem_->run();
    }
}

RType::~RType() noexcept {}

std::unique_ptr<EntityManager>& RType::getManager() noexcept
{
    return entityManager_;
}
