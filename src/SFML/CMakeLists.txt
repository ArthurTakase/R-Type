cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

# Force the script to use FetchContent and not CPM internally to fetch asio
option(SFML_USE_CPM "Download SFML with CPM instead of FetchContent" OFF)
option(
  SFML_CPM_FETCHCONTENT_COMPAT
  "Should SFML be declared with FetchContent functions to be compatible. This doesn't not allow CPM cache to work."
  ON
)
# Download this repository
include(FetchContent)
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(sfml)

add_library(
    ${PROJECT_NAME}
    SFML.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC  sfml-audio sfml-graphics sfml-network)

# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
# set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

# target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
