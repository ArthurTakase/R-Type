/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** main
*/

#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

#include "DrawableComponent.hpp"
#include "Entity.hpp"
#include "Error.hpp"
#include "HitboxComponent.hpp"
#include "Lib.hpp"
#include "RType.hpp"
#include "SerializerSystem.hpp"
#include "TransformComponent.hpp"

int main()
{
    try {
        std::unique_ptr<RType> rtype = std::make_unique<RType>();
    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}
