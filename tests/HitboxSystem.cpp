/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include "HitboxSystem.hpp"

#include <gtest/gtest.h>

#include "EntityManager.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

TEST(HitboxSystemTest, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createPlayer();
    manager->createPlayer();
    manager->getEntity(0)->getComponent<PositionComponent>()->get().setPos(100, 100);

    auto entities = manager->getEntsByComps<HitboxComponent, PositionComponent>();
    auto system   = std::make_unique<HitboxSystem>(entities);

    testing::internal::CaptureStdout();
    system->run();
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Collision detected\nCollision detected\n");
}