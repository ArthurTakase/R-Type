/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Tools
*/

#include <gtest/gtest.h>

#include <memory>

#include "HitboxComponent.hpp"
#include "InstanceOf.hpp"
#include "PositionComponent.hpp"

TEST(Tools_, instanceOf)
{
    auto pos = std::make_unique<PositionComponent>(10, 10);

    EXPECT_TRUE(Type::instanceOf<PositionComponent>(pos.get()));
    EXPECT_FALSE(Type::instanceOf<HitboxComponent>(pos.get()));
}