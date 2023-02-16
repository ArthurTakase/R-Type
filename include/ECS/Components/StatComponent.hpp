/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.hpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <vector>

#define NO_INDEX -10000

/**
 * @brief Component used to store the stats of an entity
 */
class StatComponent : public IComponent
{
  public:
    StatComponent(std::vector<float> stats);
    ~StatComponent() noexcept;
    StatComponent(const StatComponent& other) noexcept = default;
    StatComponent(StatComponent&& other) noexcept      = delete;

    StatComponent& operator=(const StatComponent& rhs) noexcept = delete;
    StatComponent& operator=(StatComponent&& rhs) noexcept      = delete;

    float getStat(int index) const noexcept;
    void  setStat(int index, float value) noexcept;

  private:
    std::vector<float> stats;
};