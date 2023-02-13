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

typedef enum Input { LeftArrow = 71, RightArrow = 72, UpArrow = 73, DownArrow = 74, Space = 57, Shift = 38 } Input;

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
    void            init() noexcept;

    int createPlayer(int x, int y) noexcept;
    int createEnemy(int x, int y) noexcept;
    int createBackground(int x) noexcept;
    int createPlayerBullet(int x, int y) noexcept;

  private:
    bool            looping_ = true;
    EntityManager   entityManager_;
    HitboxSystem    hitboxSystem_;
    BehaviorSystem  behaviorSystem_;
    MouvementSystem mouvementSystem_;
    AnimationSystem animationSystem_;
};
