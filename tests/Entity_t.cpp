/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include <gtest/gtest.h>

#include "Entity.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

TEST(Entity_, getId)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getId(), 1);
}

TEST(Entity_, getComponents)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getComponents().size(), 0);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
}

TEST(Entity_, addComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
    entity->addComponent(PositionComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 2);
}

TEST(Entity_, getComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->getComponent<HitboxComponent>());
    EXPECT_FALSE(entity->getComponent<PositionComponent>());
}

TEST(Entity_, removeComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    entity->addComponent(PositionComponent(10, 10));
    EXPECT_TRUE(entity->getComponent<HitboxComponent>());
    EXPECT_TRUE(entity->getComponent<PositionComponent>());
    EXPECT_EQ(entity->getComponents().size(), 2);
    entity->removeComponent<HitboxComponent>();
    EXPECT_FALSE(entity->getComponent<HitboxComponent>());
    EXPECT_EQ(entity->getComponents().size(), 1);
    entity->removeComponent<PositionComponent>();
    EXPECT_FALSE(entity->getComponent<PositionComponent>());
    EXPECT_FALSE(entity->removeComponent<PositionComponent>());
    EXPECT_EQ(entity->getComponents().size(), 0);
}

TEST(Entity_, hasComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->hasComponent<HitboxComponent>());
    EXPECT_FALSE(entity->hasComponent<PositionComponent>());
}

TEST(Entity_, hasComponents)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_FALSE((entity->hasComponents<HitboxComponent, PositionComponent>()));
    entity->addComponent(PositionComponent(10, 10));
    EXPECT_TRUE((entity->hasComponents<HitboxComponent, PositionComponent>()));
}