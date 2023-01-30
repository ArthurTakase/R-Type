/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** main
*/

#include <iostream>
#include <memory>

#include "Entity.hpp"
#include "HitboxComponent.hpp"
#include "Lib.hpp"
#include "RType.hpp"
#include "TransformComponent.hpp"

int main()
{
    auto  lib    = std::make_unique<Lib>();
    auto& window = lib->getWindow();

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
