#include <Json/JsonTools.hpp>
#include <Server/RType.hpp>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

int RType::createSpawner() noexcept
{
    auto spawner = entityManager_.newEntity();
    json data    = JsonTools::getPatternFromFile(PATTERN_ENEMY_GROUP_FILE_PATH);

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static std::map<int, std::vector<std::vector<int>>> patterns = {{1, {{{255, 10}, {255, 50}}}}};
        if (nbEnemyAlive != 0) { return; }
        try {
            auto level = patterns.at(playerLevel);
            if (level.empty()) {
                playerLevel += 1;
                return;
            }
            auto pattern = level.back();
            std::cout << "level size1 = " << level.size() << std::endl;
            level.pop_back();
            std::cout << "level size2 = " << level.size() << std::endl;
            std::cout << pattern[0] << " " << pattern[1] << std::endl;
            createEnemyWave(pattern[0], pattern[1]);
        } catch (const std::out_of_range& e) {
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
