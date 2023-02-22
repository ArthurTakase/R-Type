#include <Json/JsonTools.hpp>
#include <fstream>
#include <iostream>

json JsonTools::getGroupFromFile(std::string filePath)
{
    std::map<int, std::vector<std::vector<int>>> patterns;

    std::ifstream f(filePath);
    json          data = json::parse(f);
    return data;
}
