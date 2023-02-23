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

int RType::createPlayer(int x, int y) noexcept
{
    auto player = entityManager_.newEntity();

    player->addComponent(DrawableComponent(0, 0, 16, 16, 1));
    player->addComponent(AnimationComponent(128, 0.1));
    player->addComponent(TransformComponent(x, y));
    player->addComponent(StatComponent({100, 10, 10.0, 1.0}));
    player->addComponent(MouvementComponent(0, 0, 3.0));
    player->addComponent(InputComponent());
    player->addComponent(DestroyableComponent());
    player->addComponent(TimerComponent(0.1));

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto  input = entity->getComponent<InputComponent>();
        auto  mouv  = entity->getComponent<MouvementComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();
        int   lastInput;
        auto  x = trans->getX();
        auto  y = trans->getY();

        while ((lastInput = input->getInput()) != -1) {
            if (lastInput == Input::LeftArrow) { mouv->setDir(-1, 0); }
            if (lastInput == Input::RightArrow) { mouv->setDir(1, 0); }
            if (lastInput == Input::UpArrow) { mouv->setDir(0, -1); }
            if (lastInput == Input::DownArrow) { mouv->setDir(0, 1); }
            if (lastInput == Input::Shift) { mouv->setDir(0, 0); }
            if (lastInput == Input::Space) {
                if (timer.isOver()) {
                    int  dir          = mouv->getDirX() == -1 ? -1 : 1;
                    auto bulletDamage = stat->getStat(RTypeStats::Damage);
                    auto bulletSpeed  = stat->getStat(RTypeStats::Speed);
                    auto bulletSize   = stat->getStat(RTypeStats::Size);
                    createPlayerBullet(x, y, bulletDamage, bulletSpeed * dir, bulletSize);
                }
            }
        }

        auto next_x = x + mouv->getDirX() * mouv->getSpeed();
        auto next_y = y + mouv->getDirY() * mouv->getSpeed();
        if (next_x >= 239 || next_x <= 0) mouv->setDirX(0);
        if (next_y >= 239 || next_y <= 0) mouv->setDirY(0);
    }});

    player->addComponent(hitbox);
    player->addComponent(behavior);

    return player->getId();
}

int RType::createPlayerBullet(int x, int y, float damage, float speed, float size) noexcept
{
    auto bullet = entityManager_.newEntity();

    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(1, 0, speed));
    bullet->addComponent(DrawableComponent(0, 0, 16, 16, 3, size, size));
    bullet->addComponent(AnimationComponent(32, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent({1, damage}));

    auto hitbox         = HitboxComponent(16, 16);
    auto hitboxFunction = std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent>()
            && !entity->hasComponents<InputComponent>()) {
            auto stat   = entity->getComponent<StatComponent>();
            auto statMe = me->getComponent<StatComponent>();
            auto destMe = me->getComponent<DestroyableComponent>();
            auto life   = stat->getStat(RTypeStats::Life);
            auto dmg    = statMe->getStat(RTypeStats::Damage);
            stat->setStat(RTypeStats::Life, life - dmg);
            destMe->destroy();
        }
    }};
    hitbox.setOnCollision(hitboxFunction);

    auto behavior = BehaviorComponent();
    auto function = std::function<void(Entity * entity)>{[](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();

        auto x = trans->getX();
        if (x >= 255 || x <= -16) { dest->destroy(); }
    }};
    behavior.setOnUpdate(function);

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);

    return bullet->getId();
}
