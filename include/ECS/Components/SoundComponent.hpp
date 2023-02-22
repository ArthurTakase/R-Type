/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundComponent
*/

#pragma once
#include <ECS/Components/IComponent.hpp>
#include <Lib/Sound.hpp>

class SoundComponent : public IComponent
{
  public:
    SoundComponent(const std::string& path);
    SoundComponent(const SoundComponent& other) noexcept;
    SoundComponent(SoundComponent&& other) noexcept = delete;
    ~SoundComponent() noexcept = default;

    SoundComponent& operator=(const SoundComponent& rhs) noexcept = delete;
    SoundComponent& operator=(SoundComponent&& rhs) noexcept      = delete;

    Sound getSound() const noexcept;
    bool  getIsPlayed() const noexcept;
    void  setPlayed(bool value) noexcept;
    void  play() noexcept;

  protected:
  private:
    Sound sound_;
    bool  isPlayed_ = true;
};