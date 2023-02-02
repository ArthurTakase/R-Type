cmake_minimum_required(VERSION 3.17)
project(R-Type)

# ------------------------------
# R-TYPE
# ------------------------------

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

# Libs
add_subdirectory(Error)
add_subdirectory(NetworkLib)
add_subdirectory(src/Lib)
add_subdirectory(src/ECS)

# ------------------------------
# Server
# ------------------------------

set(RTYPE_SERVER r-type_server)

set(RTYPE_SERVER_SRC
  src/Network/Server/Server.cpp
  src/Network/Server/main.cpp
)

add_executable(${RTYPE_SERVER} ${RTYPE_SERVER_SRC})

if(WIN32)
  target_link_libraries(${RTYPE_SERVER} wsock32 ws2_32)
endif()

target_link_libraries(${RTYPE_SERVER} Error)
target_link_libraries(${RTYPE_SERVER} NetworkLib)

set_property(TARGET ${RTYPE_SERVER} PROPERTY CXX_STANDARD 20)
target_compile_options(${RTYPE_SERVER} PUBLIC ${CXX_FLAGS})

target_include_directories(${RTYPE_SERVER} PRIVATE include/Network)
target_include_directories(${RTYPE_SERVER} PRIVATE include/Network/Server)
target_include_directories(${RTYPE_SERVER} PRIVATE include/Tools)


# ------------------------------
# Client
# ------------------------------

set(RTYPE_CLIENT r-type_client)

set(RTYPE_CLIENT_SRC
  src/Network/Client/RClient.cpp
  src/Network/Client/main.cpp
)

add_executable(${RTYPE_CLIENT} src/Network/Client/main.cpp ${RTYPE_CLIENT_SRC})

target_include_directories(${RTYPE_CLIENT} PRIVATE include)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/ECS)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/ECS/Entity)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/ECS/Components)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/ECS/Systems)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/Tools)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/Lib)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/Network/)
target_include_directories(${RTYPE_CLIENT} PRIVATE include/Network/Client)
target_include_directories(${RTYPE_CLIENT} PRIVATE NetworkLib/include)

target_compile_options(${RTYPE_CLIENT} PUBLIC ${CXX_FLAGS})
set_property(TARGET ${RTYPE_CLIENT} PROPERTY CXX_STANDARD 20)

target_link_libraries(${RTYPE_CLIENT} Error)
target_link_libraries(${RTYPE_CLIENT} ECSEncapsulation)
target_link_libraries(${RTYPE_CLIENT} CMakeSFMLProject)


# ------------------------------
# TESTS
# ------------------------------

if(DEFINED TESTS)
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
    tests/Sprite_t.cpp
    tests/Window_t.cpp
    tests/Lib_t.cpp
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
  target_link_libraries(${TEST_BUILD} CMakeSFMLProject)
  target_link_libraries(${TEST_BUILD} ECSEncapsulation)

endif()