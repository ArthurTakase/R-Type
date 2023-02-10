/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_network
*/

#include <chaiscript/chaiscript.hpp>
#include <iostream>

#include "Error.hpp"
#include "Server.hpp"

double function(int i, double j)
{
    return i * j;
}

int main()
{
    chaiscript::ChaiScript chai;
    chai.add(chaiscript::fun(&function), "function");

    double d = chai.eval<double>("function(3, 4.75);");

    std::cout << d << std::endl;
}

// int main()
// {
// try {
//     Server server(4242);

//     server.run();
// } catch (Error const& error) {
//     std::cerr << error.what() << std::endl;
//     return (84);
// }
// return (0);
// }