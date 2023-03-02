/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Buffer
*/

#pragma once
#include <Lib/Sound.hpp>
#include <SFML/Audio.hpp>
#include <string_view>

class Sound;

class Buffer
{
    friend class Sound;

  public:
    Buffer(const std::string_view& path);
    Buffer(const Buffer& other) noexcept = delete;
    Buffer(Buffer&& other) noexcept      = default;
    ~Buffer() noexcept                   = default;

    Buffer& operator=(const Buffer& rhs) noexcept = delete;
    Buffer& operator=(Buffer&& rhs) noexcept      = default;

  protected:
  private:
    sf::SoundBuffer buffer_;
};