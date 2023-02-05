/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.cpp
*/

#include "StatComponent.hpp"

#include <iostream>

/**
 * It's a constructor that takes two parameters and assigns them to the two member variables
 *
 * @param life The life of the entity.
 * @param damage The damage of the entity.
 */
StatComponent::StatComponent(int life, int damage)
    : life_(life)
    , damage_(damage)
{
}

/**
 * It's the destructor of the class StatComponent
 */
StatComponent::~StatComponent() noexcept {}

/**
 * It returns the value of the private member _life
 *
 * @return The life of the entity.
 */
int StatComponent::getLife() const noexcept
{
    return life_;
}

/**
 * It returns the value of the private attribute _damage
 *
 * @return The damage of the entity.
 */
int StatComponent::getDamage() const noexcept
{
    return damage_;
}

/**
 * It sets the value of the private member _life
 *
 * @param life The life of the entity.
 */
void StatComponent::setLife(int life) noexcept
{
    life_ = life;
}

/**
 * It sets the value of the private attribute _damage
 *
 * @param damage The damage of the entity.
 */
void StatComponent::setDamage(int damage) noexcept
{
    damage_ = damage;
}