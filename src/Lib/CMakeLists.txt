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
    Lib.cpp
    Window.cpp
    Sprite.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include/Lib)