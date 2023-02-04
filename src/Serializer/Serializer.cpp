#include "Serializer.hpp"

/**
 * Serialize an Entity
 *
 * @param The Entity you want to serialise
 *
 * @return A bitset of the entity's information needed
 */
std::bitset<ENTITYSIZE> Serializer::Serialize(std::unique_ptr<Entity> const& entity) const noexcept
{
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
    std::bitset<ENTITYSIZE> id(entity->getId());

    index += XSIZE;
    x <<= ENTITYSIZE - index;
    index += YSIZE;
    y <<= ENTITYSIZE - index;
    index += IDSPRITESIZE;
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
    index += IDSIZE;
    id <<= ENTITYSIZE - index;

    return x | y | idSprite | width | height | scaleX | scaleY | offsetX | offsetY | id;
}

/**
 * Serialize a key code
 *
 * @param The keycode you want to serialize
 *
 * @return A bitset of the keycode
 */
std::bitset<INPUTSIZE> Serializer::Serialize(int& keyCode) const noexcept
{
    return std::bitset<INPUTSIZE>(keyCode);
}
