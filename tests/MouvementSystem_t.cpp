/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MouvementSystem Unit Test
*/

#include <gtest/gtest.h>

#include "EntityManager.hpp"
#include "MouvementSystem.hpp"

TEST(MouvementSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createPlayer();
    manager->createPlayer();

    manager->getEntity(0)->getComponent<MouvementComponent>()->setSpeed(10);
    manager->getEntity(1)->getComponent<MouvementComponent>()->setDirY(1);
    manager->getEntity(1)->getComponent<MouvementComponent>()->setDirX(0);

    auto system = std::make_unique<MouvementSystem>(manager);

    system->run();

    EXPECT_EQ(manager->getEntity(0)->getComponent<TransformComponent>()->getX(), 20);
    EXPECT_EQ(manager->getEntity(0)->getComponent<TransformComponent>()->getY(), 8);

    EXPECT_EQ(manager->getEntity(1)->getComponent<TransformComponent>()->getX(), 10);
    EXPECT_EQ(manager->getEntity(1)->getComponent<TransformComponent>()->getY(), 9);

    EXPECT_EQ(manager->getEntity(2)->getComponent<TransformComponent>()->getX(), 11);
    EXPECT_EQ(manager->getEntity(2)->getComponent<TransformComponent>()->getY(), 8);
}