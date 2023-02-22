#include <Json/JsonTools.hpp>
#include <fstream>
#include <iostream>

json JsonTools::getPatternFromFile(std::string filePath)
{
    std::map<int, std::vector<std::vector<int>>> patterns;

    std::ifstream f(filePath);
    json          data = json::parse(f);
    std::cout << data.dump() << std::endl;
    return data;
}
