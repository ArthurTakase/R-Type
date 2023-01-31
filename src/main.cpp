/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** main
*/

#include <iostream>
#include <memory>

#include "DrawableComponent.hpp"
#include "HitboxComponent.hpp"
#include "Lib.hpp"
#include "RType.hpp"
#include "TransformComponent.hpp"

int main()
{
    auto lib = std::make_unique<Lib>();
    lib->getWindow().open(800, 600, "R-Type");
    auto& window     = lib->getWindow();
    auto  entity     = std::make_unique<Entity>(0);
    auto  transform  = TransformComponent(234, 69);
    auto  drawable   = DrawableComponent(23, 32, 140, 220, 3);
    auto  serializer = std::make_unique<SerializerSystem>();

    entity->addComponent(transform);
    entity->addComponent(drawable);
    auto data = serializer->Serialize(entity);
    std::cout << data << std::endl;

    while (window.isOpen()) {
        window.clear();

        auto key = window.getKeyPressed();

        if (key == WINDOW_KEY::QUIT) {
            window.close();
            break;
        }

        window.refresh();
    }

    return 0;
}
