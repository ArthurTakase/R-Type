#pragma once

#include "ISerializer.hpp"

/**
 * @brief Object used to serialize objects for network
 */
class Serializer : public ISerializer
{
  public:
    Serializer()           = default;
    ~Serializer() noexcept = default;

    Serializer(const Serializer& other)                = delete;
    Serializer(Serializer&& other) noexcept            = delete;
    Serializer& operator=(const Serializer& other)     = delete;
    Serializer& operator=(Serializer&& other) noexcept = delete;

    std::bitset<ENTITYSIZE> Serialize(std::unique_ptr<Entity> const& entity) const noexcept;
    std::bitset<INPUTSIZE>  Serialize(int& keyCode) const noexcept;

  protected:
  private:
};
