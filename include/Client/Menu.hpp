/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
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
    int  createText(int x, int y, std::string txt) noexcept;
    int  createIPMenu() noexcept;

  private:
    Lib               lib_;
    EntityManager     manager_;
    DrawableSystem    drawableSystem_;
    DestroyableSystem destroyableSystem_;
    BehaviorSystem    behaviorSystem_;

    std::string ip_;
    std::string port_;
    std::string client_port_;

    bool open = true;
};