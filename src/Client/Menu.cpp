/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#include <Client/Menu.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <iostream>

Menu::Menu()
    : drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , animationSystem_(&manager_)
{
}

void Menu::run() noexcept
{
    auto& window = lib_.getWindow();
    int   input;

    Text          text("Hello World", "assets/fonts/Hack.ttf", 20, 20, 20);
    TextComponent textComponent("Adios World", "assets/fonts/Hack.ttf", 20, 20, 40);
    auto          test = textComponent;

    window.open(256, 256, "Menu");
    drawableSystem_.setWindow(&lib_.getWindow());

    while (window.isOpen()) {
        input = window.getKeyPressed();
        if (input != 0) { createInput(20, std::to_string(input)); }
        if (input == 255 || input == 36) break;

        destroyableSystem_.run();
        drawableSystem_.run();
    }

    window.close();
}

int Menu::createInput(int y, std::string txt) noexcept
{
    std::cout << "Creating input" << std::endl;

    auto input = manager_.newEntity();
    int  id    = input->getId();
    int  x     = 10 + (id * 10);

    input->addComponent(DrawableComponent());
    input->addComponent(TransformComponent(x, y));
    input->addComponent(DestroyableComponent());
    input->addComponent(TextComponent(txt, "assets/fonts/Hack.ttf", 10, x, y));

    return id;
}