/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** StatComponent Unit Test
*/

#include <gtest/gtest.h>

#include <Components/StatComponent.hpp>

TEST(StatComponent_, getLife)
{
    auto pos = std::make_unique<StatComponent>(10, 10);
    EXPECT_EQ(pos->getLife(), 10);
}

TEST(StatComponent_, getDamage)
{
    auto pos = std::make_unique<StatComponent>(10, 10);
    EXPECT_EQ(pos->getDamage(), 10);
}

TEST(StatComponent_, setLife)
{
    auto pos = std::make_unique<StatComponent>(10, 10);
    pos->setLife(20);
    EXPECT_EQ(pos->getLife(), 20);
}

TEST(StatComponent_, setDamage)
{
    auto pos = std::make_unique<StatComponent>(10, 10);
    pos->setDamage(20);
    EXPECT_EQ(pos->getDamage(), 20);
}