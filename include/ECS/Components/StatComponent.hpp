/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.hpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <vector>

/**
 * @brief Component used to store the stats of an entity
 */
class StatComponent : public IComponent
{
  public:
    StatComponent(std::vector<float> stats);
    ~StatComponent() noexcept                          = default;
    StatComponent(const StatComponent& other) noexcept = default;
    StatComponent(StatComponent&& other) noexcept      = default;

    StatComponent& operator=(const StatComponent& rhs) noexcept = default;
    StatComponent& operator=(StatComponent&& rhs) noexcept      = default;

    float getStat(int index) const noexcept;
    void  setStat(int index, float value) noexcept;

  private:
    std::vector<float>   statistics_;
    static constexpr int NO_INDEX = -10000;
};