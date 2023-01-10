/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "Entity.hpp"

#include <gtest/gtest.h>

#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

TEST(EntityTest, getId)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getId(), 1);
}

TEST(EntityTest, getComponents)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getComponents().size(), 0);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
}

TEST(EntityTest, addComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
    entity->addComponent(PositionComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 2);
}

TEST(EntityTest, getComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->getComponent<HitboxComponent>());
    EXPECT_FALSE(entity->getComponent<PositionComponent>());
}

TEST(EntityTest, removeComponent)
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

TEST(EntityTest, hasComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->hasComponent<HitboxComponent>());
    EXPECT_FALSE(entity->hasComponent<PositionComponent>());
}

TEST(EntityTest, hasComponents)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_FALSE((entity->hasComponents<HitboxComponent, PositionComponent>()));
    entity->addComponent(PositionComponent(10, 10));
    EXPECT_TRUE((entity->hasComponents<HitboxComponent, PositionComponent>()));
}