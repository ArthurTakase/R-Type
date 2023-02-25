#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TimerComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Server/RType.hpp>
#include <Tools/Curve.hpp>
#include <iostream>

int RType::createBackground(int x) noexcept
{
    auto background = entityManager_.newEntity();

    background->addComponent(TransformComponent(x, 0));
    background->addComponent(DrawableComponent(0, 0, 255, 255, 0));
    background->addComponent(MouvementComponent(-1, 0, 2.0));
    background->addComponent(DestroyableComponent());

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= -255) { transform->setX(255); }
    }});

    background->addComponent(behaviorComponent);

    return background->getId();
}

int RType::createPowerUp(int x, int y, int type) noexcept
{
    auto             powerUp = entityManager_.newEntity();
    std::vector<int> sprites = {1, 9};
    if (x < 0 || x > 239) { return -1; }
    if (y < 0 || y > 239) { return -1; }

    if (type != 0 && type != 1) { return -1; }

    powerUp->addComponent(TransformComponent(x, y));
    powerUp->addComponent(DrawableComponent(0, 0, 16, 16, sprites[type]));
    powerUp->addComponent(MouvementComponent(-1, 0, 5.0));
    powerUp->addComponent(DestroyableComponent());
    powerUp->addComponent(AnimationComponent(128, 0.1));
    powerUp->addComponent(TimerComponent(10.0));

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[this, y](Entity* entity) {
        auto  trans = entity->getComponent<TransformComponent>();
        auto  mouv  = entity->getComponent<MouvementComponent>();
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();

        int x = trans->getX();
        if (trans->getX() <= 0 || trans->getX() >= 239) { mouv->setDirX(mouv->getDirX() * -1); }

        if (timer.isOver()) { dest->destroy(); }
    }});
    powerUp->addComponent(behaviorComponent);

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[this, type](Entity* entity, Entity* me) {
        if (!entity->hasComponents<StatComponent, InputComponent>()) return;

        auto powerUp = me->getComponent<DrawableComponent>();
        auto player  = entity->getComponent<StatComponent>();
        auto dest    = me->getComponent<DestroyableComponent>();
        auto spr     = entity->getComponent<DrawableComponent>();

        if (type == 0) { // HEAL THE PLAYER
            if (player->getStat(RTypeStats::Life) < 100) {
                player->setStat(RTypeStats::Life, player->getStat(RTypeStats::Life) + 20);
            }
        } else if (type == 1) { // UPGRADE THE PLAYER
            player->setStat(RTypeStats::Level, player->getStat(RTypeStats::Level) + 1);
            if ((int)player->getStat(RTypeStats::Level) % 5 == 0 && player->getStat(RTypeStats::Level) <= 10.0) {
                spr->setTextureId(spr->getTextureId() + 10);
            }
            player->setStat(RTypeStats::Damage, player->getStat(RTypeStats::Damage) + 2);
        }
        dest->destroy();
    }});
    powerUp->addComponent(hitbox);

    return powerUp->getId();
}