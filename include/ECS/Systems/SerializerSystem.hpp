#pragma once

#include <memory>

#include "Deserializer.hpp"
#include "EntityIterator.hpp"
#include "EntityManager.hpp"
#include "IDeserializer.hpp"
#include "ISerializer.hpp"
#include "Serializer.hpp"

/**
 * @brief Object used to serialize Entity of System
 */
class SerializerSystem
{
  public:
    SerializerSystem(std::unique_ptr<EntityManager>& manager) noexcept;
    ~SerializerSystem() noexcept = default;

    SerializerSystem(const SerializerSystem& other)                = delete;
    SerializerSystem(SerializerSystem&& other) noexcept            = delete;
    SerializerSystem& operator=(const SerializerSystem& other)     = delete;
    SerializerSystem& operator=(SerializerSystem&& other) noexcept = delete;

    std::bitset<ENTITYSIZE> Serialize(std::unique_ptr<Entity> const& entity) const noexcept;
    std::bitset<INPUTSIZE>  Serialize(int& keyCode) const noexcept;
    void                    DeSerialize(std::bitset<ENTITYSIZE> data) const;
    int                     DeSerialize(std::bitset<INPUTSIZE> input) const;

    void run() noexcept;

  protected:
  private:
    EntityIterator<TransformComponent, DrawableComponent> it_;
    std::unique_ptr<EntityManager>&                       manager_;
    std::unique_ptr<ISerializer>                          serializer_;
    std::unique_ptr<IDeserializer>                        deserializer_;
};
