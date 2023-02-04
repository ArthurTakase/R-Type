#include "SerializerSystem.hpp"

#include <iostream>
#include <memory>

#include "IDeserializer.hpp"

SerializerSystem::SerializerSystem(std::unique_ptr<EntityManager>& manager) noexcept
    : manager_(manager)
    , it_(EntityIterator<TransformComponent, DrawableComponent>(manager->getEntities()))
    , serializer_(std::make_unique<Serializer>())
    , deserializer_(std::make_unique<Deserializer>())
{
}

void SerializerSystem::run() noexcept
{
    for (; !it_.isEnd(); ++it_) {
        std::bitset<ENTITYSIZE> x = Serialize(it_.get());
        std::cout << x << std::endl;
    }
    it_.reset();
}

/**
 * Serialize an Entity
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
    return serializer_->Serialize(keyCode);
}

/**
 * De Serialize
 *
 * @param The Entity you want to serialize
 */
void SerializerSystem::DeSerialize(std::bitset<ENTITYSIZE> data) const
{
    EntityInfo entityInfo = deserializer_->Deserialize(data);

    if (manager_->getEntity(entityInfo.id) == nullptr) {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(manager_->createId());

        auto transform = TransformComponent(entityInfo.x, entityInfo.y);
        auto drawable  = DrawableComponent(
            entityInfo.offsetX, entityInfo.offsetY, entityInfo.width, entityInfo.heigth, entityInfo.idSprite);
        transform.setScale(entityInfo.scaleX, entityInfo.scaleY);

        entity->addComponent(transform);
        entity->addComponent(drawable);

        manager_->addEntity(entity);
    } else {
        auto entity = manager_->getEntity(entityInfo.id);

        auto transform = entity->getComponent<TransformComponent>();
        auto drawable  = entity->getComponent<DrawableComponent>();

        transform->setX(entityInfo.x);
        transform->setY(entityInfo.y);
        transform->setScale(entityInfo.scaleX, entityInfo.scaleY);
        drawable->setOffsetX(entityInfo.offsetX);
        drawable->setOffsetY(entityInfo.offsetY);
        drawable->setWidth(entityInfo.width);
        drawable->setHeight(entityInfo.heigth);
        drawable->setTextureId(entityInfo.idSprite);
    }
}
