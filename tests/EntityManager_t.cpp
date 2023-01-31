/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EntityManager
*/

#include <gtest/gtest.h>

#include "EntityManager.hpp"

TEST(EntityManager_, createPlayer)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    auto player = manager->getEntity(0);
    EXPECT_TRUE(player->getComponent<TransformComponent>());
    EXPECT_TRUE(player->getComponent<HitboxComponent>());
}

TEST(EntityManager_, createEnemy)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createEnemy();
    auto enemy = manager->getEntity(0);
    EXPECT_TRUE(enemy->getComponent<TransformComponent>());
    EXPECT_FALSE(enemy->getComponent<HitboxComponent>());
}

TEST(EntityManager_, removeEntity)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createEnemy();
    manager->createEnemy();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    EXPECT_EQ(manager->getEntities().size(), 8);
    manager->removeEntity(0);
    manager->removeEntity(2);
    manager->removeEntity(4);
    manager->removeEntity(6);
    EXPECT_EQ(manager->getEntities().size(), 4);
    EXPECT_TRUE(manager->removeEntity(1));
    EXPECT_FALSE(manager->removeEntity(20));
}

TEST(EntityManager_, getEntity)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createEnemy();
    manager->createEnemy();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    EXPECT_EQ(manager->getEntity(0)->getId(), 0);
    EXPECT_EQ(manager->getEntity(1)->getId(), 1);
    EXPECT_FALSE(manager->getEntity(20));
    EXPECT_TRUE(manager->getEntity(5));
}

TEST(EntityManager_, getEntities)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createEnemy();
    manager->createEnemy();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    EXPECT_EQ(manager->getEntities().size(), 8);
}