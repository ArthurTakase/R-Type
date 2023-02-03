#include "SerializerSystem.hpp"

#include <bitset>
#include <iostream>
#include <memory>

#include "DrawableComponent.hpp"
#include "EntityIterator.hpp"
#include "TransformComponent.hpp"

using namespace Serializer;

SerializerSystem::SerializerSystem(std::unique_ptr<EntityManager>& manager) noexcept
    : _manager(manager)
    , _it(EntityIterator<TransformComponent, DrawableComponent>(manager->getEntities()))
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
std::bitset<INPUTSIZE> SerializerSystem::Serialize(int& keyCode) const noexcept
{
    return std::bitset<INPUTSIZE>(keyCode);
}

/**
 * De Serialize
 *
 * @param The keycode you want to serialize
 */
void SerializerSystem::DeSerialize(std::bitset<ENTITYSIZE> data) const
{
    std::bitset<ENTITYSIZE> bigbit(
        "0000000000000000000000000000000000000000000000000000000000000000000000011111111111111111");
    std::bitset<ENTITYSIZE> smallbit(
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000011111111");

    int index = 0;
    int x     = ((data >> (ENTITYSIZE - (index + XSIZE))) & bigbit).to_ulong();
    index += XSIZE;
    int y = ((data >> (ENTITYSIZE - (index + YSIZE))) & bigbit).to_ulong();
    index += YSIZE;
    int idSprite = ((data >> (ENTITYSIZE - (index + IDSPRITESIZE)) & smallbit)).to_ulong();
    index += IDSPRITESIZE;
    int width = ((data >> (ENTITYSIZE - (index + WIDTHSIZE)) & smallbit)).to_ulong();
    index += WIDTHSIZE;
    int heigth = ((data >> (ENTITYSIZE - (index + HEIGHTSIZE)) & smallbit)).to_ulong();
    index += HEIGHTSIZE;
    int scaleX = ((data >> (ENTITYSIZE - (index + SCALEXSIZE)) & smallbit)).to_ulong();
    index += SCALEXSIZE;
    int scaleY = ((data >> (ENTITYSIZE - (index + SCALEYSIZE)) & smallbit)).to_ulong();
    index += SCALEYSIZE;
    int offsetX = ((data >> (ENTITYSIZE - (index + OFFSETXSIZE)) & smallbit)).to_ulong();
    index += OFFSETXSIZE;
    int offsetY = ((data >> (ENTITYSIZE - (index + OFFSETYSIZE)) & smallbit)).to_ulong();
    index += OFFSETYSIZE;
    int id = ((data >> (ENTITYSIZE - (index + IDSIZE)) & smallbit)).to_ulong();
    index += IDSIZE;

    if (_manager->getEntity(id) == nullptr) {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(_manager->createId());

        auto transform = TransformComponent(x, y);
        auto drawable  = DrawableComponent(offsetX, offsetY, width, heigth, idSprite);
        transform.setScale(scaleX, scaleY);

        entity->addComponent(transform);
        entity->addComponent(drawable);

        _manager->addEntity(entity);
    } else {
        auto entity = _manager->getEntity(id);

        auto transform = entity->getComponent<TransformComponent>();
        auto drawable  = entity->getComponent<DrawableComponent>();

        transform->setX(x);
        transform->setY(y);
        transform->setScale(scaleX, scaleY);
        drawable->setOffsetX(offsetX);
        drawable->setOffsetY(offsetY);
        drawable->setWidth(width);
        drawable->setHeight(heigth);
        drawable->setTextureId(idSprite);
    }
}
