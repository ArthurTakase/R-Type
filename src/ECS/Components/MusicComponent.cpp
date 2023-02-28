/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#include <ECS/Components/MusicComponent.hpp>

/**
 * It takes a string_view, and uses it to construct a music object.
 *
 * @param path The path to the music file.
 */
MusicComponent::MusicComponent(const std::string_view& path)
    : music_(path.data())
{
}

/**
 * It takes a string_view, and uses it to construct a music object.
 *
 * @param path The path to the music file.
 */
MusicComponent::MusicComponent(const int musicId)
    : musicId_(musicId)
    , music_(("assets/audio/r-type" + std::to_string(musicId_) + ".wav"))
{
}

/**
 * Copy constructor for DrawableComponent.
 *
 * @param other The other DrawableComponent to copy from.
 */
MusicComponent::MusicComponent(const MusicComponent& other) noexcept
    : music_(other.music_.getPath())
    , musicId_(other.musicId_)
{
}

/**
 * It returns the value of the private member variable _textureId
 *
 * @return The texture id of the drawable component.
 */
int MusicComponent::getMusicId() const noexcept
{
    return musicId_;
}

/**
 * `getIsPlayed` returns the value of the private member variable `isPlayed_`
 *
 * @return isPlayed_
 */
bool MusicComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

/**
 * It sets the value of the isPlayed_ member variable to the value of the value
 * parameter
 *
 * @param value The value to set the playing state to.
 */
void MusicComponent::setPlaying(bool value) noexcept
{
    isPlayed_ = value;
}

/**
 * It plays the music if it's not already playing
 */
void MusicComponent::play() noexcept
{
    if (isPlayed_) {
        music_.play();
        isPlayed_ = false;
    }
}

/**
 * `getMusic` returns the value of the private member variable `music_`
 *
 * @return music_
 */
Music& MusicComponent::getMusic() noexcept
{
    return music_;
}

/**
 * It sets the value of the musicId member variable to the value of the value
 * parameter
 *
 * @param value The value to set the musicId.
 */
void MusicComponent::setMusicId(const int musicId) noexcept
{
    musicId_ = musicId;
}
