/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "Entity.hpp"

#include <gtest/gtest.h>

#include "HitboxComponent.hpp"

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