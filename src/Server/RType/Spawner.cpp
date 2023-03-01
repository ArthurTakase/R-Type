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
        const static json patterns = JsonTools::getPatternsFromFile();
        // std::cout << patterns.dump() << std::endl;

        if (nbEnemyAlive > 1) { return; }
        int  wave_id = rand() % patterns.size();
        auto group   = patterns[wave_id];
        createEntityWave(group["type"], group["positions"]);
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
void RType::createEntityWave(std::string type, json::array_t positions) noexcept
{
    std::map<std::string, int (RType::*)(int, int)> creation = {{"basic", &RType::createBasicEnemy},
        {"curve", &RType::createCurvedEnemy},
        {"powerup", &RType::createRandomPowerUp}};
    for (auto& position : positions) { (this->*(creation[type]))(position[0], position[1]); }
}
