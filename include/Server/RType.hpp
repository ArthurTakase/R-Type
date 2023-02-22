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
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/HitboxSystem.hpp>
#include <ECS/Systems/MouvementSystem.hpp>
#include <Json/JsonTools.hpp>
#include <Serializer/BitSize.hpp>
#include <memory>

typedef enum RTypeStats { Life = 0, Damage = 1, Speed = 2, Size = 3 } RTypeStats;

#define PATTERN_ENEMY_GROUP_FILE_PATH "assets/jsons/pattern_enemy_group.json"
#define BASIC_ENEMY_ID_SPRITE 2
#define CURVE_ENEMY_ID_SPRITE 7

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
    RType(RType&& other) noexcept      = delete;

    RType& operator=(const RType& rhs) noexcept = delete;
    RType& operator=(RType&& rhs) noexcept      = delete;

    void            run() noexcept;
    void            reset() noexcept;
    void            stop() noexcept;
    EntityManager&  getManager() noexcept;
    HitboxSystem&   getHitboxSystem() noexcept;
    BehaviorSystem& getBehaviorSystem() noexcept;
    void            init() noexcept;

    int  createPlayer(int x, int y) noexcept;
    int  createBasicEnemy(int x, int y) noexcept;
    int  createCurveEnemy(int x, int y) noexcept;
    int  createSpawner() noexcept;
    int  createBackground(int x) noexcept;
    int  createPlayerBullet(int x, int y, float damage, float speed, float size) noexcept;
    int  createAsteroid(int x) noexcept;
    int  createEnemyBullet(int x, int y, float damage, float speed, float size, bool type) noexcept;
    void createEnemyWave(std::string type, json::array_t positions) noexcept;

    int curve(int center, int amplitude, int period, int x) noexcept;

  private:
    bool              looping_     = true;
    int               nbEnemyAlive = 0;
    int               playerLevel  = 1;
    EntityManager     entityManager_;
    HitboxSystem      hitboxSystem_;
    BehaviorSystem    behaviorSystem_;
    MouvementSystem   mouvementSystem_;
    AnimationSystem   animationSystem_;
    DestroyableSystem destroyableSystem_;
};
