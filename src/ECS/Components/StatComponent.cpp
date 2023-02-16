/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.cpp
*/

#include <ECS/Components/StatComponent.hpp>
#include <iostream>

/**
 * It's a constructor that takes two parameters and assigns them to the two member variables
 *
 * @param life The life of the entity.
 * @param damage The damage of the entity.
 */
StatComponent::StatComponent(std::vector<float> stats)
    : stats(stats)
{
}

/**
 * It's the destructor of the class StatComponent
 */
StatComponent::~StatComponent() noexcept {}

float StatComponent::getStat(int index) const noexcept
{
    if (index >= stats.size()) { return NO_INDEX; }
    return stats[index];
}

void StatComponent::setStat(int index, float value) noexcept
{
    while (index >= stats.size()) { stats.push_back(0); }
    stats[index] = value;
}