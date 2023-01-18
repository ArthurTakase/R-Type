/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include "MouvementSystem.hpp"

#include <cassert>
#include <iostream>

/**
 * It's a constructor that takes an EntityIterator as a parameter and assigns it to the EntityIterator
 * member variable
 *
 * @param it The iterator that will be used to iterate over the entities.
 */
MouvementSystem::MouvementSystem(EntityIterator<TransformComponent, MouvementComponent> it)
    : _it(EntityIterator<TransformComponent, MouvementComponent>(it))
{
}

/**
 * It iterates over all entities that have a MouvementComponent and a TransformComponent, and updates
 * the TransformComponent's position according to the MouvementComponent's speed and direction
 */
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