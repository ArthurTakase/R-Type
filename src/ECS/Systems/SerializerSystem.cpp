#include "SerializerSystem.hpp"

#include <iostream>

SerializerSystem::SerializerSystem(std::unique_ptr<EntityManager>& manager) noexcept
    : manager_(manager)
    , it_(EntityIterator<TransformComponent, DrawableComponent>(manager->getEntities()))
{
}

void SerializerSystem::run() noexcept
{
    for (; !it_.isEnd(); ++_it) {
        std::bitset<ENTITYSIZE> x = Serialize(it_.get());
        std::cout << x << std::endl;
    }
    it_.reset();
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

    return serializer_->Serialize(entity);
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

    // TODO Transfer the responsability of create entity
    if (manager_->getEntity(id) == nullptr) {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(manager_->createId());

        auto transform = TransformComponent(x, y);
        auto drawable  = DrawableComponent(offsetX, offsetY, width, heigth, idSprite);
        transform.setScale(scaleX, scaleY);

        entity->addComponent(transform);
        entity->addComponent(drawable);

        manager_->addEntity(entity);
    } else {
        auto entity = manager_->getEntity(id);

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
