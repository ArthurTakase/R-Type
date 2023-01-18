/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include "MouvementSystem.hpp"

#include <cassert>
#include <iostream>

MouvementSystem::MouvementSystem(EntityIterator<TransformComponent, MouvementComponent> it)
    : _it(EntityIterator<TransformComponent, MouvementComponent>(it))
{
}

void MouvementSystem::run()
{
    size_t other;

    for (; !_it.isEnd(); ++_it) {
        assert((_it.get()->hasComponents<MouvementComponent, TransformComponent>()));

        auto mouvement = _it.get()->getComponent<MouvementComponent>();
        auto transform = _it.get()->getComponent<TransformComponent>();

        transform->setX(transform->getX() + (mouvement->getSpeed() * mouvement->getDirX()));
        transform->setY(transform->getY() + (mouvement->getSpeed() * mouvement->getDirY()));
    }
}