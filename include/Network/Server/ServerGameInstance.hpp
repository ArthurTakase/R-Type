/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ServerGameInstance
*/

#pragma once

#include <Components/MouvementComponent.hpp>
#include <Entity/EntityManager.hpp>
#include <Systems/BehaviorSystem.hpp>
#include <Systems/HitboxSystem.hpp>
#include <Systems/MouvementSystem.hpp>
#include <memory>

/**
 * @brief Game Instance for the server
 *
 */
class RType
{
  public:
    RType();
    ~RType() noexcept;
    RType(const RType& other) noexcept = delete;
    RType(RType&& other) noexcept      = default;

    RType& operator=(const RType& rhs) noexcept = delete;
    RType& operator=(RType&& rhs) noexcept      = default;

    void            run() noexcept;
    void            reset() noexcept;
    void            stop() noexcept;
    EntityManager&  getManager() noexcept;
    HitboxSystem&   getHitboxSystem() noexcept;
    BehaviorSystem& getBehaviorSystem() noexcept;

  private:
    bool            looping_ = true;
    EntityManager   entityManager_;
    HitboxSystem    hitboxSystem_;
    BehaviorSystem  behaviorSystem_;
    MouvementSystem mouvementSystem_;
};
