#pragma once

#include <bitset>
#include <memory>

#include "BitSize.hpp"
#include "DrawableComponent.hpp"
#include "TransformComponent.hpp"

/**
 * @brief Interface for Serializer
 */
class ISerializer
{
  public:
    ISerializer()                   = default;
    virtual ~ISerializer() noexcept = default;

    ISerializer(const ISerializer& other)                = delete;
    ISerializer(ISerializer&& other) noexcept            = delete;
    ISerializer& operator=(const ISerializer& other)     = delete;
    ISerializer& operator=(ISerializer&& other) noexcept = delete;

    virtual std::bitset<ENTITYSIZE> Serialize(std::unique_ptr<Entity> const& entity) const noexcept = 0;
    virtual std::bitset<INPUTSIZE>  Serialize(int& keyCode) const noexcept                          = 0;

  protected:
  private:
};
