#include <Server/RType.hpp>
#include <iostream>
#include <map>

int RType::createSpawner() noexcept
{
    auto spawner = entityManager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static int        group_index = 0;
        const static json data        = JsonTools::getGroupFromFile(PATTERN_ENEMY_GROUP_FILE_PATH);

        if (nbEnemyAlive != 0) { return; }
        try {
            auto level = data.at(std::to_string(playerLevel));
            if (group_index >= level.size() || level.empty()) {
                group_index = 0;
                playerLevel += 1;
                return;
            }
            auto group = level[group_index];
            createEnemyWave(group["type"], group["positions"]);
            group_index += 1;
        } catch (const json::out_of_range& e) {
            return;
        }
    }});

    spawner->addComponent(behavior);
    return spawner->getId();
}

void RType::createEnemyWave(std::string type, json::array_t positions) noexcept
{
    std::map<std::string, int (RType::*)(int, int)> creation = {
        {"basic", &RType::createBasicEnemy}, {"curve", &RType::createCurveEnemy}};
    for (auto& position : positions) { (this->*(creation[type]))(position[0], position[1]); }
}
