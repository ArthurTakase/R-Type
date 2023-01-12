/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include <gtest/gtest.h>

#include "EntityIterator.hpp"
#include "EntityManager.hpp"
#include "HitboxComponent.hpp"
#include "HitboxSystem.hpp"
#include "PositionComponent.hpp"

TEST(HitboxSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createPlayer();
    manager->createPlayer();
    manager->getEntity(0)->getComponent<PositionComponent>()->setPos(100, 100);

    auto system =
        std::make_unique<HitboxSystem>(EntityIterator<PositionComponent, HitboxComponent>(manager->getEntities()));

    testing::internal::CaptureStdout();
    system->run();
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Collision detected between 1 and 2\nCollision detected between 2 and 1\n");
}