/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/AnimationSystem.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <Lib/Lib.hpp>

class Menu
{
  public:
    Menu();
    ~Menu() noexcept                 = default;
    Menu(const Menu& other) noexcept = delete;
    Menu(Menu&& other) noexcept      = delete;

    Menu& operator=(const Menu& rhs) noexcept = delete;
    Menu& operator=(Menu&& rhs) noexcept      = delete;

    void run() noexcept;
    int  createInput(int x, std::string txt) noexcept;

  private:
    Lib               lib_;
    EntityManager     manager_;
    DrawableSystem    drawableSystem_;
    DestroyableSystem destroyableSystem_;
    AnimationSystem   animationSystem_;
};