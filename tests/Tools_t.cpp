/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Tools
*/

#include <gtest/gtest.h>

#include <Components/HitboxComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Tools/InstanceOf.hpp>
#include <memory>

TEST(Tools_, instanceOf)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);

    EXPECT_TRUE(Type::instanceOf<TransformComponent>(pos.get()));
    EXPECT_FALSE(Type::instanceOf<HitboxComponent>(pos.get()));
}