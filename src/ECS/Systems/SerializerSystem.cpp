#include "SerializerSystem.hpp"

#include <bitset>
#include <iostream>

#include "DrawableComponent.hpp"
#include "EntityIterator.hpp"
#include "TransformComponent.hpp"

using namespace Serializer;

SerializerSystem::SerializerSystem(std::vector<std::unique_ptr<Entity>>& entities)
    : _it(EntityIterator<TransformComponent, DrawableComponent>(entities))
{
}

void SerializerSystem::run() noexcept
{
    for (; !_it.isEnd(); ++_it) {
        std::bitset<ENTITYSIZE> x = Serialize(_it.get());
        std::cout << x << std::endl;
    }
    _it.reset();
}

/**
 * Serialize a key code
 *
 * @param The Entity you want to serialise
 *
 * @return A bitset of the entity's information needed
 */
std::bitset<ENTITYSIZE> SerializerSystem::Serialize(std::unique_ptr<Entity> const& entity) const noexcept
{
    if (!entity->hasComponents<TransformComponent, DrawableComponent>()) { return std ::bitset<ENTITYSIZE>(0); }

    int                     index    = 0;
    auto                    pos      = entity->getComponent<TransformComponent>();
    auto                    drawable = entity->getComponent<DrawableComponent>();
    std::bitset<ENTITYSIZE> x(pos->getX());
    std::bitset<ENTITYSIZE> y(pos->getY());
    std::bitset<ENTITYSIZE> idSprite(drawable->getTextureId());
    std::bitset<ENTITYSIZE> width(drawable->getWidth());
    std::bitset<ENTITYSIZE> height(drawable->getHeight());
    std::bitset<ENTITYSIZE> scaleX(1);
    std::bitset<ENTITYSIZE> scaleY(1);
    std::bitset<ENTITYSIZE> offsetX(drawable->getOffsetX());
    std::bitset<ENTITYSIZE> offsetY(drawable->getOffsetY());

    index += XSIZE;
    x <<= ENTITYSIZE - index;
    index += YSIZE;
    y <<= ENTITYSIZE - index;
    index += IDSPRiTESIZE;
    idSprite <<= ENTITYSIZE - index;
    index += WIDTHSIZE;
    width <<= ENTITYSIZE - index;
    index += HEIGHTSIZE;
    height <<= ENTITYSIZE - index;
    index += SCALEXSIZE;
    scaleX <<= ENTITYSIZE - index;
    index += SCALEYSIZE;
    scaleY <<= ENTITYSIZE - index;
    index += OFFSETXSIZE;
    offsetX <<= ENTITYSIZE - index;
    index += OFFSETYSIZE;
    offsetY <<= ENTITYSIZE - index;

    return x | y | idSprite | width | height | scaleX | scaleY | offsetX | offsetY;
}

/**
 * Serialize a key code
 *
 * @param The keycode you want to serialize
 *
 * @return A bitset of the keycode
 */
std::bitset<INPUTSIZE> SerializerSystem::Serialize(int& keyCode) const noexcept
{
    return std::bitset<INPUTSIZE>(keyCode);
}
