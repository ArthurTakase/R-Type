/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Music
*/

#pragma once

#include <SFML/Audio.hpp>
#include <memory>

class Music
{
  public:
    explicit Music(const std::string& path);
    Music(const Music& other) noexcept = delete;
    Music(Music&& other) noexcept      = default;
    ~Music() noexcept;

    Music& operator=(const Music& rhs) noexcept = delete;
    Music& operator=(Music&& rhs) noexcept      = default;

    void play() noexcept;
    void pause() noexcept;
    void stop() noexcept;
    void setVolume(float volume) noexcept;
    void setLoop(bool value) noexcept;

  protected:
  private:
    std::unique_ptr<sf::Music> music_;
};