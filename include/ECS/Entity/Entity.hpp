/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Entity.cpp
*/

#pragma once
#include <cstddef>
#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

#include "IComponent.hpp"
#include "InstanceOf.hpp"

class Entity
{
  public:
    Entity(size_t id);
    ~Entity() noexcept;
    Entity(const Entity& other) noexcept = delete;
    Entity(Entity&& other) noexcept      = delete;

    Entity& operator=(const Entity& rhs) noexcept = delete;
    Entity& operator=(Entity&& rhs) noexcept      = delete;

    size_t                                    getId() const noexcept;
    std::vector<std::unique_ptr<IComponent>>& getComponents() noexcept;

  private:
    size_t                                   _id;
    std::vector<std::unique_ptr<IComponent>> _components = {};

  public:
    template <typename T>
    void addComponent(const T& component) noexcept
    {
        auto component_ptr = std::make_unique<T>(component);
        _components.push_back(std::move(component_ptr));
    };

    template <typename T>
    std::optional<std::reference_wrapper<T>> getComponent() noexcept
    {
        for (auto& i : _components) {
            if (Type::instanceOf<T>(i.get())) {
                auto value = dynamic_cast<T*>(i.get());
                return (std::reference_wrapper<T>(*value));
            }
        }
        return {};
    };

    template <typename T>
    bool removeComponent() noexcept
    {
        for (size_t i = 0; i < _components.size(); i++) {
            if (Type::instanceOf<T>(_components[i].get())) {
                _components.erase(_components.begin() + i);
                return true;
            }
        }
        return false;
    };

    template <typename T>
    bool hasComponent() noexcept
    {
        for (auto& i : _components)
            if (Type::instanceOf<T>(i.get())) { return true; }
        return false;
    };

    template <typename T, typename... Args>
    bool hasComponents() noexcept
    {
        if constexpr (sizeof...(Args) == 0) {
            return hasComponent<T>();
        } else {
            return hasComponent<T>() && hasComponents<Args...>();
        }
    };
};