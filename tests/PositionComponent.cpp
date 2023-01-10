/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include "PositionComponent.hpp"

#include <gtest/gtest.h>

#include "Entity.hpp"

TEST(PositionComponentTest, getX)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);
    EXPECT_EQ(pos->getX(), 10);
}

TEST(PositionComponentTest, getY)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);
    EXPECT_EQ(pos->getY(), 10);
}

TEST(PositionComponentTest, getPos)
{
    auto pos  = std::make_unique<PositionComponent>(10, 10);
    auto pair = pos->getPos();
    EXPECT_EQ(pair.first, 10);
    EXPECT_EQ(pair.second, 10);
}

TEST(PositionComponentTest, setX)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);
    pos->setX(20);
    EXPECT_EQ(pos->getX(), 20);
}

TEST(PositionComponentTest, setY)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);
    pos->setY(20);
    EXPECT_EQ(pos->getY(), 20);
}

TEST(PositionComponentTest, setPos)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);
    pos->setPos(20, 20);
    EXPECT_EQ(pos->getX(), 20);
    EXPECT_EQ(pos->getY(), 20);
}