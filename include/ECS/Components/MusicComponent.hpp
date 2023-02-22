/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#pragma once
#include <ECS/Components/IComponent.hpp>
#include <Lib/Music.hpp>
#include <memory>

class MusicComponent : public IComponent
{
  public:
    MusicComponent(const std::string& path);
    MusicComponent(const MusicComponent& other) noexcept;
    MusicComponent(MusicComponent&& other) noexcept = delete;
    ~MusicComponent() noexcept                      = default;

    MusicComponent& operator=(const MusicComponent& rhs) noexcept = delete;
    MusicComponent& operator=(MusicComponent&& rhs) noexcept      = delete;

    bool        getIsPlayed() const noexcept;
    std::string getPath() const noexcept;
    void        setPlaying(bool value) noexcept;
    void        play() noexcept;

  protected:
  private:
    Music       music_;
    bool        isPlayed_ = true;
    std::string path_;
};