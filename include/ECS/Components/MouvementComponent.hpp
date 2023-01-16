/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MouvementComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component used to set the direction and speed of the movement of an entity
 */

class MouvementComponent : public IComponent
{
    public:
        MouvementComponent(float dirX, float dirY, float speed);
        ~MouvementComponent() noexcept;
        MouvementComponent(const MouvementComponent& other) noexcept = default;
        MouvementComponent(MouvementComponent&& other) noexcept      = delete;

        MouvementComponent& operator=(const MouvementComponent& rhs) noexcept = delete;
        MouvementComponent& operator=(MouvementComponent&& rhs) noexcept      = delete;

        float getDirX() const noexcept;
        float getDirY() const noexcept;
        float getSpeed() const noexcept;
        void setDirX(float x) noexcept;
        void setDirY(float y) noexcept;
        void setSpeed(float speed) noexcept;

    private:
        float _dirX;
        float _dirY;
        float _speed;
};