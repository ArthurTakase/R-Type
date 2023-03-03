/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#pragma once

#include <Lib/Buffer.hpp>
#include <SFML/Audio.hpp>

class Buffer;

/**
 * @brief This class is used to create and encapsulate a Sf::Sound.
 *
 */
class Sound
{
  public:
    Sound() noexcept;
    explicit Sound(const Buffer& buffer);
    Sound(const Sound& other) noexcept = delete;
    Sound(Sound&& other) noexcept      = default;
    ~Sound() noexcept                  = default;

    Sound& operator=(const Sound& rhs) noexcept = delete;
    Sound& operator=(Sound&& rhs) noexcept      = default;

    void        play() noexcept;
    void        pause() noexcept;
    void        stop() noexcept;
    void        setVolume(float volume) noexcept;
    std::string getPath() const noexcept;

  protected:
  private:
    sf::Sound sound_;
};