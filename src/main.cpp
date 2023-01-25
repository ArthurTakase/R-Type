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
#include "RType.hpp"
#include "TransformComponent.hpp"

int main()
{
    std::unique_ptr<RType> rtype = std::make_unique<RType>();
    return 0;
}