/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sprite_t
*/

#include <gtest/gtest.h>

#include <memory>

#include "Sprite.hpp"

TEST(Sprite_, setSpritePath)
{
    auto sprite = std::make_unique<Sprite>("", 0, 0);

    sprite->setSpritePath("test");
    EXPECT_EQ(sprite->getSpritePath(), "test");
}

TEST(Sprite_, serialize)
{
    auto sprite = std::make_unique<Sprite>("", 0, 0);

    EXPECT_EQ(sprite->serialize(), std::bitset<8>());
}

TEST(Sprite_, setX)
{
    auto sprite = std::make_unique<Sprite>("", 0, 0);

    sprite->setX(10);
    EXPECT_EQ(sprite->getX(), 10);
}

TEST(Sprite_, setY)
{
    auto sprite = std::make_unique<Sprite>("", 0, 0);

    sprite->setY(10);
    EXPECT_EQ(sprite->getY(), 10);
}

TEST(Sprite_, getX)
{
    auto sprite = std::make_unique<Sprite>("", 10, 0);

    EXPECT_EQ(sprite->getX(), 10);
}

TEST(Sprite_, getY)
{
    auto sprite = std::make_unique<Sprite>("", 0, 10);

    EXPECT_EQ(sprite->getY(), 10);
}