/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#pragma once

#include <SFML/Audio.hpp>

/**
 * @brief This class is used to handle our operations on Sf::Sound and Sf::SoundBuffer.
 *
 */
class SoundData
{
  public:
    SoundData() noexcept = default;
    SoundData(sf::Sound sound, sf::SoundBuffer buffer) noexcept;
    SoundData(const SoundData& other) noexcept;
    SoundData(SoundData&& other) noexcept;
    ~SoundData() noexcept = default;

    SoundData& operator=(const SoundData& rhs) noexcept;
    SoundData& operator=(SoundData&& rhs) noexcept;

    sf::Sound       sound_;
    sf::SoundBuffer buffer_;

  protected:
  private:
};

/**
 * @brief This class is used to create and encapsulate a Sf::Sound.
 *
 */
class Sound
{
  public:
    explicit Sound(const std::string& path);
    Sound(const Sound& other) noexcept = default;
    Sound(Sound&& other) noexcept      = default;
    ~Sound() noexcept                  = default;

    Sound& operator=(const Sound& rhs) noexcept = default;
    Sound& operator=(Sound&& rhs) noexcept      = default;

    void        play() noexcept;
    void        pause() noexcept;
    void        stop() noexcept;
    void        setVolume(float volume) noexcept;
    std::string getPath() const noexcept;

  protected:
  private:
    std::string path_;
    SoundData   soundData_;
};