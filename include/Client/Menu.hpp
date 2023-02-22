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
#include <ECS/Systems/MouvementSystem.hpp>
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

    std::vector<std::string> run() noexcept;
    int                      createText(int x, int y, int size, std::string txt) noexcept;
    int                      createIPMenu() noexcept;
    int                      createTitleMenu() noexcept;
    int                      createBackground(int x) noexcept;

  private:
    Lib               lib_;
    EntityManager     manager_;
    DrawableSystem    drawableSystem_;
    DestroyableSystem destroyableSystem_;
    BehaviorSystem    behaviorSystem_;
    MouvementSystem   mouvementSystem_;

    std::string ip_;
    std::string port_;
    std::string client_port_;

    bool open = true;
};