#include <Json/JsonTools.hpp>
#include <Server/RType.hpp>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

int RType::createSpawner() noexcept
{
    auto spawner = entityManager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static int        pattern_index = 0;
        const static json data          = JsonTools::getPatternFromFile(PATTERN_ENEMY_GROUP_FILE_PATH);

        if (nbEnemyAlive != 0) { return; }
        try {
            auto level = data.at(std::to_string(playerLevel));
            if (pattern_index >= level.size() || level.empty()) {
                pattern_index = 0;
                playerLevel += 1;
                return;
            }
            auto pattern = level[pattern_index];
            std::cout << pattern[0] << " " << pattern[1] << std::endl;
            createEnemyWave(pattern[0], pattern[1]);
            pattern_index += 1;
        } catch (const json::out_of_range& e) {
            return;
        }
    }});

    spawner->addComponent(behavior);
    return spawner->getId();
}

void RType::createEnemyWave(int x, int y) noexcept
{
    for (int i = 0; i < 4; i++) { createEnemy(x += 10, y); }
}
