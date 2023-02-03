/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** BehaviorComponent.cpp
*/

#pragma once

#include <functional>
#include <memory>

#include "Entity.hpp"
#include "IComponent.hpp"

/**
 * @brief Component for the behavior of an entity.
 */
class BehaviorComponent : public IComponent
{
  public:
    BehaviorComponent();
    ~BehaviorComponent() noexcept                              = default;
    BehaviorComponent(const BehaviorComponent& other) noexcept = default;
    BehaviorComponent(BehaviorComponent&& other) noexcept      = delete;

    BehaviorComponent& operator=(const BehaviorComponent& rhs) noexcept = delete;
    BehaviorComponent& operator=(BehaviorComponent&& rhs) noexcept      = delete;

    void setOnUpdate(std::function<void()> onUpdate) noexcept;
    void onUpdate() const noexcept;

  private:
    std::function<void()> _onUpdate;
};