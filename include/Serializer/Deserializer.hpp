#pragma once

#include "IDeserializer.hpp"

/**
 * @brief Object used to deserialize objects for network
 */
class Deserializer : public IDeserializer
{
  public:
    Deserializer()                   = default;
    virtual ~Deserializer() noexcept = default;

    Deserializer(const Deserializer& other)                = delete;
    Deserializer(Deserializer&& other) noexcept            = delete;
    Deserializer& operator=(const Deserializer& other)     = delete;
    Deserializer& operator=(Deserializer&& other) noexcept = delete;

    EntityInfo Deserialize(std::bitset<ENTITYSIZE> data) const;
    int        Deserialize(std::bitset<INPUTSIZE>) const;

  protected:
  private:
};
