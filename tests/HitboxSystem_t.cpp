/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include <gtest/gtest.h>

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/HitboxSystem.hpp>
#include <Tools/EntityIterator.hpp>

TEST(HitboxSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createPlayer();
    manager->createPlayer();
    manager->getEntity(0)->getComponent<TransformComponent>()->setPos(100, 100);

    auto system = std::make_unique<HitboxSystem>(manager.get());

    testing::internal::CaptureStdout();
    system->run();
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Collision\nCollision\n");
}