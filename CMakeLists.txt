cmake_minimum_required(VERSION 3.17)
project(R-Type)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

set(TEST_BUILD runTests)

if(UNIX)
  find_program(TIDY "clang-tidy")
  if(TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

# ------------------------------
# R-TYPE
# ------------------------------

# Sources
set(
  RTYPE_SRC
  src/RType.cpp
  src/ECS/Entity/Entity.cpp
  src/ECS/Entity/EntityManager.cpp
  src/ECS/Components/TransformComponent.cpp
  src/ECS/Components/HitboxComponent.cpp
  src/ECS/Components/MouvementComponent.cpp
  src/ECS/Components/StatComponent.cpp
  src/ECS/Components/DrawableComponent.cpp
  src/ECS/Systems/HitboxSystem.cpp
  src/ECS/Systems/MouvementSystem.cpp
)

# Merge
add_executable(${PROJECT_NAME} src/main.cpp ${RTYPE_SRC})

# Includes
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Entity)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Components)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Systems)
target_include_directories(${PROJECT_NAME} PRIVATE include/Tools)
target_include_directories(${PROJECT_NAME} PRIVATE include/SFML)

# Options
target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)


if (DEFINED TESTS)
  # ------------------------------
  # Fetch GoogleTest
  # ------------------------------

  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    SOURCE_DIR ${CMAKE_BINARY_DIR}/googletest-src
  )
  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build)
  endif()
  include_directories(${CMAKE_BINARY_DIR}/googletest-src/googletest/include)
  include_directories(${CMAKE_BINARY_DIR}/googletest-src/googlemock/include)

  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  endif()

  # ------------------------------
  # TESTS
  # ------------------------------

  # Sources
  set(
    TESTS_SRC
    tests/HitboxComponent_t.cpp
    tests/TransformComponent_t.cpp
    tests/Entity_t.cpp
    tests/EntityManager_t.cpp
    tests/HitboxSystem_t.cpp
    tests/Tools_t.cpp
    tests/EntityIterator_t.cpp
    tests/MouvementComponent_t.cpp
    tests/StatComponent_t.cpp
    tests/MouvementSystem_t.cpp
    tests/DrawableComponent_t.cpp
  )

  # Merge
  add_executable(${TEST_BUILD} ${TESTS_SRC} ${RTYPE_SRC})

  # Includes
  target_include_directories(${TEST_BUILD} PRIVATE include)
  target_include_directories(${TEST_BUILD} PRIVATE include/ECS)
  target_include_directories(${TEST_BUILD} PRIVATE include/ECS/Entity)
  target_include_directories(${TEST_BUILD} PRIVATE include/ECS/Components)
  target_include_directories(${TEST_BUILD} PRIVATE include/ECS/Systems)
  target_include_directories(${TEST_BUILD} PRIVATE include/Tools)
  target_include_directories(${TEST_BUILD} PRIVATE include/Lib)

  # Options
  target_link_libraries(${TEST_BUILD} gtest gtest_main gmock pthread)

endif()

# ------------------------------
# SFML
# ------------------------------

add_subdirectory(src/Lib)
target_link_libraries(${PROJECT_NAME} CMakeSFMLProject)