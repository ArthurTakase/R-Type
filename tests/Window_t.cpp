/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Window_t
*/

#include <gtest/gtest.h>

#include <memory>

#include "Window.hpp"

TEST(Window_, constructor)
{
    auto window = std::make_unique<Window>();

    EXPECT_FALSE(window->isOpen());
}

TEST(Window_, openAndClose)
{
    auto window = std::make_unique<Window>();

    window->open(800, 600, "R-Type");
    EXPECT_TRUE(window->isOpen());
    window->close();
    EXPECT_FALSE(window->isOpen());
}
