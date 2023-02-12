/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ServerGameInstance
*/

#pragma once

#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/AnimationSystem.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
#include <ECS/Systems/HitboxSystem.hpp>
#include <ECS/Systems/MouvementSystem.hpp>
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
    void            createPlayer(int x, int y) noexcept;
    void            createEnemy(int x, int y) noexcept;
    void            createBackground(int x) noexcept;
    void            init() noexcept;

  private:
    bool            looping_ = true;
    EntityManager   entityManager_;
    HitboxSystem    hitboxSystem_;
    BehaviorSystem  behaviorSystem_;
    MouvementSystem mouvementSystem_;
    AnimationSystem animationSystem_;
};
