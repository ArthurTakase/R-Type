/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundComponent
*/

#include <ECS/Components/SoundComponent.hpp>

/**
 * It creates a sound component with the given path
 *
 * @param path The path to the sound file.
 */
SoundComponent::SoundComponent(const std::string& path)
    : sound_(path)
{
}

/**
 * It takes a sound ID, and creates a sound object with the corresponding file name
 *
 * @param soundId The ID of the sound to play.
 */
SoundComponent::SoundComponent(const int soundId)
    : soundId_(soundId)
    , sound_(AUDIO_PATH.data() + std::to_string(soundId_) + ".wav")
{
}

/**
 * It returns the sound_ member variable
 *
 * @return A reference to the sound_ member variable.
 */
Sound SoundComponent::getSound() const noexcept
{
    return sound_;
}

/**
 * This function returns the soundId_ member variable.
 *
 * @return The soundId_ variable.
 */
int SoundComponent::getSoundId() const noexcept
{
    return soundId_;
}

/**
 * A function used to determine whether or not the sound is played
 *
 * @return a boolean value
 */
bool SoundComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

/**
 * This function sets the value of the isPlayed_ member variable
 *
 * @param value The value to set the played state to.
 */
void SoundComponent::setPlayed(bool value) noexcept
{
    isPlayed_ = value;
}

/**
 * If the sound has to be played, plays it
 */
void SoundComponent::play() noexcept
{
    if (isPlayed_) {
        sound_.play();
        isPlayed_ = false;
    }
}

/**
 * It sets the soundId_ member variable to the value of the soundId parameter
 *
 * @param soundId The id of the sound to play.
 */
void SoundComponent::setSoundId(const int soundId) noexcept
{
    soundId_ = soundId;
}
