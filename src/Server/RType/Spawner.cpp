#include <Server/RType.hpp>
#include <iostream>
#include <map>

/**
 * It creates a new entity, adds a behavior component to it, and returns the
 * entity's id
 *
 * @return The id of the entity that was created.
 */
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

/**
 * It creates a map of function pointers to member functions of the class, and then
 * calls the function pointed to by the map's value, using the map's key as the
 * argument
 *
 * @param type the type of enemy to create
 * @param positions a json array of json arrays of 2 ints.
 */
void RType::createEnemyWave(std::string type, json::array_t positions) noexcept
{
    std::map<std::string, int (RType::*)(int, int)> creation = {
        {"basic", &RType::createBasicEnemy}, {"curve", &RType::createCurvedEnemy}};
    for (auto& position : positions) { (this->*(creation[type]))(position[0], position[1]); }
}
