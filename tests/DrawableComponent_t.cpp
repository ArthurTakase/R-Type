/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** DrawableComponent Unit Test
*/

#include <gtest/gtest.h>

#include <Components/DrawableComponent.hpp>

TEST(DrawableComponent_, getOffsetX)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    EXPECT_EQ(drawableComponent.getOffsetX(), 0);
}

TEST(DrawableComponent_, getOffsetY)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    EXPECT_EQ(drawableComponent.getOffsetY(), 0);
}

TEST(DrawableComponent_, getWidth)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    EXPECT_EQ(drawableComponent.getWidth(), 0);
}

TEST(DrawableComponent_, getHeight)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    EXPECT_EQ(drawableComponent.getHeight(), 0);
}

TEST(DrawableComponent_, getTextureId)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    EXPECT_EQ(drawableComponent.getTextureId(), 0);
}

TEST(DrawableComponent_, setOffsetX)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    drawableComponent.setOffsetX(1);
    EXPECT_EQ(drawableComponent.getOffsetX(), 1);
}

TEST(DrawableComponent_, setOffsetY)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    drawableComponent.setOffsetY(1);
    EXPECT_EQ(drawableComponent.getOffsetY(), 1);
}

TEST(DrawableComponent_, setWidth)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    drawableComponent.setWidth(1);
    EXPECT_EQ(drawableComponent.getWidth(), 1);
}

TEST(DrawableComponent_, setHeight)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    drawableComponent.setHeight(1);
    EXPECT_EQ(drawableComponent.getHeight(), 1);
}

TEST(DrawableComponent_, setTextureId)
{
    DrawableComponent drawableComponent(0, 0, 0, 0, 0);
    drawableComponent.setTextureId(1);
    EXPECT_EQ(drawableComponent.getTextureId(), 1);
}