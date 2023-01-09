/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#pragma once

#include <utility>

#include "IComponent.hpp"

class HitboxComponent : public IComponent
{
  public:
    HitboxComponent(size_t width, size_t height);
    ~HitboxComponent() noexcept                            = default;
    HitboxComponent(const HitboxComponent& other) noexcept = default;
    HitboxComponent(HitboxComponent&& other) noexcept      = delete;

    HitboxComponent& operator=(const HitboxComponent& rhs) noexcept = delete;
    HitboxComponent& operator=(HitboxComponent&& rhs) noexcept      = delete;

    size_t                    getWidth() const noexcept;
    size_t                    getHeight() const noexcept;
    void                      setWidth(size_t width) noexcept;
    void                      setHeight(size_t height) noexcept;
    void                      setSize(size_t width, size_t height) noexcept;
    std::pair<size_t, size_t> getSize() const noexcept;

  private:
    size_t _width;
    size_t _height;
};