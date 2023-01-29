cmake_minimum_required(VERSION 3.10)
project(Udp_Client_Server)

set(SERVER_SOURCES server.cpp)
set(CLIENT_SOURCES client.cpp)

find_package(SFML 2.5.1 COMPONENTS network REQUIRED)

add_executable(server ${SERVER_SOURCES})
target_link_libraries(server sfml-network)

add_executable(client ${CLIENT_SOURCES})
target_link_libraries(client sfml-network)
