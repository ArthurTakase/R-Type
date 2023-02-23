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

int RType::createEnemy(int x, int y) noexcept
{
    auto enemy = entityManager_.newEntity();

    enemy->addComponent(DrawableComponent(0, 0, 16, 16, 2));
    enemy->addComponent(AnimationComponent(128, 0.1));
    enemy->addComponent(TransformComponent(x, y));
    enemy->addComponent(DestroyableComponent());
    enemy->addComponent(StatComponent({30, 2, 6, 1}));
    enemy->addComponent(MouvementComponent(-1, 0, 2.0));
    enemy->addComponent(TimerComponent(0.8));

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[this, y](Entity* entity) {
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();

        auto x = trans->getX();
        trans->setY(y - (Tools::curve(20, 0.05, x)));

        if (timer.isOver()) {
            auto bDamage = stat->getStat(RTypeStats::Damage);
            auto bSpeed  = stat->getStat(RTypeStats::Speed);
            auto bSize   = stat->getStat(RTypeStats::Size);
            createEnemyBullet(x, trans->getY(), bDamage, bSpeed, bSize, rand() % 2 == 0);
        }
        if (stat->getStat(RTypeStats::Life) <= 0) { dest->destroy(); }
        if (x <= -16) { trans->setX(255); }
    }});

    enemy->addComponent(hitbox);
    enemy->addComponent(behavior);

    return enemy->getId();
}

int RType::createEnemyBullet(int x, int y, float damage, float speed, float size, bool type) noexcept
{
    auto  bullet = entityManager_.newEntity();
    float life   = type ? 1.0 : 200.0;

    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(-1, 0, speed));
    bullet->addComponent(DrawableComponent(0, 0, 16, 16, type ? 6 : 5, size, size));
    bullet->addComponent(AnimationComponent(32, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent({life, damage}));

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent, InputComponent>()) {
            auto stat   = entity->getComponent<StatComponent>();
            auto statMe = me->getComponent<StatComponent>();
            auto destMe = me->getComponent<DestroyableComponent>();

            auto life = stat->getStat(RTypeStats::Life);
            auto dmg  = statMe->getStat(RTypeStats::Damage);
            stat->setStat(RTypeStats::Life, life - dmg);
            destMe->destroy();
        }
    }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();
        auto stat  = entity->getComponent<StatComponent>();

        if (trans->getX() <= 0 || stat->getStat(RTypeStats::Life) <= 0) { dest->destroy(); }
    }});

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);

    return bullet->getId();
}