#pragma once

#include <bitset>
#include <memory>

#include "DrawableComponent.hpp"
#include "EntityIterator.hpp"
#include "TransformComponent.hpp"

/**
 * @brief Macros for Element's BIT size
 */
namespace Serializer
{
#define ENTITYSIZE 88
#define XSIZE 16
#define YSIZE 16
#define IDSPRiTESIZE 8
#define WIDTHSIZE 8
#define HEIGHTSIZE 8
#define SCALEXSIZE 8
#define SCALEYSIZE 8
#define OFFSETXSIZE 8
#define OFFSETYSIZE 8

#define INPUTSIZE 8
};

/**
 * @brief Object used to serialize Entity for network
 */
class SerializerSystem
{
  public:
    SerializerSystem(std::vector<std::unique_ptr<Entity>>& entities);
    virtual ~SerializerSystem() noexcept = default;

    SerializerSystem(const SerializerSystem& other)                = delete;
    SerializerSystem(SerializerSystem&& other) noexcept            = delete;
    SerializerSystem& operator=(const SerializerSystem& other)     = delete;
    SerializerSystem& operator=(SerializerSystem&& other) noexcept = delete;

    std::bitset<ENTITYSIZE> Serialize(std::unique_ptr<Entity> const& entity) const noexcept;
    std::bitset<INPUTSIZE>  Serialize(int& keyCode) const noexcept;

    void run() noexcept;

  protected:
  private:
    EntityIterator<TransformComponent, DrawableComponent> _it;
};
