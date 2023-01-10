/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include "HitboxComponent.hpp"

#include <gtest/gtest.h>

#include "Entity.hpp"

TEST(HitboxComponentTest, getWidth)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    EXPECT_EQ(hitbox->getWidth(), 10);
}

TEST(HitboxComponentTest, getHeight)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    EXPECT_EQ(hitbox->getHeight(), 10);
}

TEST(HitboxComponentTest, setWidth)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    hitbox->setWidth(20);
    EXPECT_EQ(hitbox->getWidth(), 20);
}

TEST(HitboxComponentTest, setHeight)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    hitbox->setHeight(20);
    EXPECT_EQ(hitbox->getHeight(), 20);
}

TEST(HitboxComponentTest, setSize)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    hitbox->setSize(20, 20);
    EXPECT_EQ(hitbox->getWidth(), 20);
    EXPECT_EQ(hitbox->getHeight(), 20);
}

TEST(HitboxComponentTest, getSize)
{
    auto hitbox = std::make_unique<HitboxComponent>(10, 10);
    auto size   = hitbox->getSize();
    EXPECT_EQ(size.first, 10);
    EXPECT_EQ(size.second, 10);
}