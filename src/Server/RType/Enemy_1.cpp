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
#include <Tools/Curve.hpp>
#include <iostream>

int RType::createEnemy(int x, int y) noexcept
{
    auto enemy = entityManager_.newEntity();

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static Timer timer(0.5);
        static float bulletSpeed  = 6.0;
        static float bulletSize   = 1.0;
        static int   bulletDamage = 2;

        auto dest  = entity->getComponent<DestroyableComponent>();
        auto stat  = entity->getComponent<StatComponent>();
        auto trans = entity->getComponent<TransformComponent>();

        trans->setY(128 - (Tools::curve(20, 0.05, trans->getX())));

        if (timer.isOver()) {
            createEnemyBullet(trans->getX(), trans->getY(), bulletDamage, bulletSpeed, bulletSize, rand() % 2 == 0);
        }
        if (stat->getLife() <= 0) { dest->destroy(); }
        if (trans->getX() <= -16) { trans->setX(255); }
    }});

    enemy->addComponent(DrawableComponent(0, 0, 16, 16, 2));
    enemy->addComponent(AnimationComponent(128, 0.1));
    enemy->addComponent(TransformComponent(x, y));
    enemy->addComponent(DestroyableComponent());
    enemy->addComponent(StatComponent(30, 8));
    enemy->addComponent(MouvementComponent(-1, 0, 2.0));
    enemy->addComponent(hitbox);
    enemy->addComponent(behavior);

    return enemy->getId();
}

int RType::createEnemyBullet(int x, int y, int damage, float speed, float size, bool type) noexcept
{
    auto bullet = entityManager_.newEntity();

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent, InputComponent>()) {
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
        auto stat  = entity->getComponent<StatComponent>();

        if (trans->getX() <= 0 || stat->getLife() <= 0) { dest->destroy(); }
    }});

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);
    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(-1, 0, speed));
    bullet->addComponent(DrawableComponent(0, 0, 16, 16, type ? 6 : 5, size, size));
    bullet->addComponent(AnimationComponent(32, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent(type ? 1 : 200, damage));

    return bullet->getId();
}