/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#pragma once

#include <SFML/Audio.hpp>

class Sound
{
  public:
    explicit Sound(const std::string& path);
    Sound(const Sound& other) noexcept = default;
    Sound(Sound&& other) noexcept      = delete;
    ~Sound() noexcept;

    Sound& operator=(const Sound& rhs) noexcept = delete;
    Sound& operator=(Sound&& rhs) noexcept      = delete;

    void        play() noexcept;
    void        pause() noexcept;
    void        stop() noexcept;
    void        setVolume(float volume) noexcept;
    std::string getPath() const noexcept;

  protected:
  private:
    sf::Sound       sound_;
    sf::SoundBuffer buffer_;
    std::string     path_;
};