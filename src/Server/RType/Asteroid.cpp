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

int RType::createAsteroid(int x) noexcept
{
    auto asteroid = entityManager_.newEntity();

    int   y     = (rand() % 239);
    float speed = (float)(rand() % 25) / 10 + 5;
    float scale = (float)(rand() % 20) / 10 + 1;

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto stat  = entity->getComponent<StatComponent>();
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto draw  = entity->getComponent<DrawableComponent>();

        if (trans->getX() <= -16 || stat->getStat(RTypeStats::Life) <= 0) {
            scale = (float)(rand() % 20) / 10 + 1;
            speed = (float)(rand() % 25) / 10 + 5;

            mouv->setSpeed(speed);
            trans->setX(255);
            trans->setY((rand() % 239));
            stat->setStat(RTypeStats::Life, 25 * scale);
            draw->setScale(scale, scale);
        }
    }});

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setSCale(scale, scale);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent, InputComponent>()) {
            auto otherStat = entity->getComponent<StatComponent>();
            auto meStat    = me->getComponent<StatComponent>();
            auto meTrans   = me->getComponent<TransformComponent>();
            auto meMouv    = me->getComponent<MouvementComponent>();
            auto meDraw    = me->getComponent<DrawableComponent>();

            auto life   = otherStat->getStat(RTypeStats::Life);
            auto damage = meStat->getStat(RTypeStats::Damage);
            otherStat->setStat(RTypeStats::Life, life - damage);

            scale = (float)(rand() % 20) / 10 + 1;
            speed = (float)(rand() % 25) / 10 + 5;

            meMouv->setSpeed(speed);
            meTrans->setX(255);
            meTrans->setY((rand() % 239));
            meStat->setStat(RTypeStats::Life, 25 * scale);
            meDraw->setScale(scale, scale);
        }
    }});

    auto draw = DrawableComponent(0, 0, 16, 16, 4);
    draw.setScale(scale, scale);

    asteroid->addComponent(behavior);
    asteroid->addComponent(draw);
    asteroid->addComponent(hitbox);
    asteroid->addComponent(TransformComponent(x, y));
    asteroid->addComponent(AnimationComponent(128, 0.1));
    asteroid->addComponent(MouvementComponent(-1, 0, speed));
    asteroid->addComponent(DestroyableComponent());
    asteroid->addComponent(StatComponent({25 * scale, 2}));

    return asteroid->getId();
}
