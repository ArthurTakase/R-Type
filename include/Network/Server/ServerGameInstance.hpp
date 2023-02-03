/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ServerGameInstance
*/

#pragma once

#include <memory>

#include "EntityManager.hpp"
#include "HitboxSystem.hpp"
#include "SerializerSystem.hpp"

class RType
{
  public:
    RType();
    ~RType() noexcept;
    RType(const RType& other) noexcept = delete;
    RType(RType&& other) noexcept      = default;

    RType& operator=(const RType& rhs) noexcept = delete;
    RType& operator=(RType&& rhs) noexcept      = default;

    void run() const noexcept;
    void reset() noexcept;
    void stop() noexcept;

  private:
    bool                              looping_ = true;
    std::unique_ptr<EntityManager>    entityManager_;
    std::unique_ptr<HitboxSystem>     hitboxSystem_;
    std::unique_ptr<SerializerSystem> serializerSystem_;
};
