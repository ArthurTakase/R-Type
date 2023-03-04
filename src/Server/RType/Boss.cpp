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

#include <cmath>
#include <vector>

int RType::createBoss(int x, int y) noexcept
{
    auto Boss = entityManager_.newEntity();
    nbEnemyAlive += 1;


    Boss->addComponent(DrawableComponent(0, 0, 16, 16, 35));
    Boss->addComponent(TransformComponent(x, y));
    Boss->addComponent(DestroyableComponent());
    Boss->addComponent(StatComponent({30, 2, 6, 1}));
    Boss->addComponent(MouvementComponent(-1, 0, 0));
    Boss->addComponent(TimerComponent(0.8));


    auto hitbox = HitboxComponent(16, 16);
    
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});


    auto behavior = BehaviorComponent();

    behavior.setOnUpdate(std::function<void(Entity * entity)>{[this](Entity* entity) {
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();
        auto  move  = entity->getComponent<MouvementComponent>();
        auto scaling = entity->getComponent<DrawableComponent>();

        auto x = trans->getX();
        auto y = trans->getY();

        if (timer.isOver()) {
            auto bDamage = stat->getStat(RTypeStats::Damage);
            auto bSpeed  = stat->getStat(RTypeStats::Speed);
            auto bSize   = stat->getStat(RTypeStats::Size);
        }
        if (stat->getStat(RTypeStats::Life) <= 0) {
            if (rand() % 1 == 0) { createPowerUp(trans->getX(), trans->getY(), rand() % 2); }
            nbEnemyAlive -= 1;
            playerLevel += 1;
            dest->destroy();
        }
        if (x <= -16) { trans->setX(255); }
    }});

    Boss->addComponent(hitbox);
    Boss->addComponent(behavior);

    return Boss->getId();
}