/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

#include <gtest/gtest.h>

TEST(EntityManagerTest, createPlayer)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    auto player = manager->getEntity(0);
    EXPECT_TRUE(player->getComponent<PositionComponent>());
    EXPECT_TRUE(player->getComponent<HitboxComponent>());
}

TEST(EntityManagerTest, createEnemy)
{
    auto manager = std::make_unique<EntityManager>();
    manager->createEnemy();
    auto enemy = manager->getEntity(0);
    EXPECT_TRUE(enemy->getComponent<PositionComponent>());
    EXPECT_FALSE(enemy->getComponent<HitboxComponent>());
}

TEST(EntityManagerTest, removeEntity)
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

TEST(EntityManagerTest, getEntity)
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

TEST(EntityManagerTest, getEntities)
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