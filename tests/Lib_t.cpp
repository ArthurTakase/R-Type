/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Lib_t
*/

#include <gtest/gtest.h>

#include <memory>

#include "Lib.hpp"

TEST(Lib_t, constructor)
{
    auto lib = std::make_unique<Lib>();

    EXPECT_FALSE(lib == nullptr);
}