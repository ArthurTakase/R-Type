#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Server/RType.hpp>
#include <iostream>

int RType::createPlayer(int x, int y) noexcept
{
    auto player = entityManager_.newEntity();

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static Timer timer(0.1);
        static float bulletSpeed  = 10.0;
        static float bulletSize   = 1.0;
        static int   bulletDamage = 10;
        int          lastInput;

        auto input = entity->getComponent<InputComponent>();
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto trans = entity->getComponent<TransformComponent>();
        auto stat  = entity->getComponent<StatComponent>();

        while ((lastInput = input->getInput()) != -1) {
            if (lastInput == Input::LeftArrow) { mouv->setDir(-1, 0); }
            if (lastInput == Input::RightArrow) { mouv->setDir(1, 0); }
            if (lastInput == Input::UpArrow) { mouv->setDir(0, -1); }
            if (lastInput == Input::DownArrow) { mouv->setDir(0, 1); }
            if (lastInput == Input::Shift) { mouv->setDir(0, 0); }
            if (lastInput == Input::Space) {
                if (timer.isOver()) {
                    int dir = mouv->getDirX() == -1 ? -1 : 1;
                    createPlayerBullet(trans->getX(), trans->getY(), bulletDamage, bulletSpeed * dir, bulletSize);
                }
            }
        }
    }});

    player->addComponent(hitbox);
    player->addComponent(behavior);
    player->addComponent(DrawableComponent(0, 0, 16, 16, 1));
    player->addComponent(AnimationComponent(128, 0.1));
    player->addComponent(TransformComponent(x, y));
    player->addComponent(StatComponent(100, 5));
    player->addComponent(MouvementComponent(0, 0, 3.0));
    player->addComponent(InputComponent());
    player->addComponent(DestroyableComponent());

    return player->getId();
}

int RType::createPlayerBullet(int x, int y, int damage, float speed, float size) noexcept
{
    auto bullet = entityManager_.newEntity();

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent>()
            && !entity->hasComponents<InputComponent>()) {
            auto stat   = entity->getComponent<StatComponent>();
            auto statMe = me->getComponent<StatComponent>();
            auto destMe = me->getComponent<DestroyableComponent>();

            stat->setLife(stat->getLife() - statMe->getDamage());
            destMe->destroy();
        }
    }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();

        if (trans->getX() >= 255 || trans->getX() <= -16) { dest->destroy(); }
    }});

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);
    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(1, 0, speed));
    bullet->addComponent(DrawableComponent(0, 0, 16, 16, 3, size, size));
    bullet->addComponent(AnimationComponent(32, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent(1, damage));

    return bullet->getId();
}
