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
#include "TransformComponent.hpp"

TEST(Tools_, instanceOf)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);

    EXPECT_TRUE(Type::instanceOf<TransformComponent>(pos.get()));
    EXPECT_FALSE(Type::instanceOf<HitboxComponent>(pos.get()));
}