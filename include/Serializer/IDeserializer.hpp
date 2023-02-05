#pragma once

#include <bitset>
#include <memory>

#include "BitSize.hpp"

/**
 * @brief Structure for EntityInfo
 *
 */
struct EntityInfo {
    int x;
    int y;
    int idSprite;
    int width;
    int heigth;
    int scaleX;
    int scaleY;
    int offsetX;
    int offsetY;
    int id;
};

/**
 * @brief Interface for Deserializer
 */
class IDeserializer
{
  public:
    IDeserializer()                   = default;
    virtual ~IDeserializer() noexcept = default;

    IDeserializer(const IDeserializer& other)                = delete;
    IDeserializer(IDeserializer&& other) noexcept            = delete;
    IDeserializer& operator=(const IDeserializer& other)     = delete;
    IDeserializer& operator=(IDeserializer&& other) noexcept = delete;

    virtual EntityInfo Deserialize(std::bitset<ENTITYSIZE> data) const = 0;
    virtual int        Deserialize(std::bitset<INPUTSIZE>) const       = 0;

  protected:
  private:
};
