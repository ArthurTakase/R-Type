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

    void setOnUpdate(std::function<void(int key, std::unique_ptr<Entity>& self)> onUpdate) noexcept;
    void onUpdate(int key, std::unique_ptr<Entity>& self) const noexcept;

  private:
    std::function<void(int key, std::unique_ptr<Entity>& self)> onUpdate_;
};
