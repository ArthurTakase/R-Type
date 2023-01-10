cmake_minimum_required(VERSION 3.17)
project(R-Type)

set(OpenGL_GL_PREFERENCE GLVND)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

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
# FILES
# ------------------------------

set(
  RTYPE_SRC
  src/RType.cpp
  src/ECS/Entity/Entity.cpp
  src/ECS/Entity/EntityManager.cpp
  src/ECS/Components/PositionComponent.cpp
  src/ECS/Components/HitboxComponent.cpp
  src/ECS/Systems/HitboxSystem.cpp
)

set(
  RTYPE_INCLUDES
  include
  include/ECS
  include/ECS/Entity
  include/ECS/Components
  include/ECS/Systems
  include/Tools
)

set(
  TESTS_SRC
  tests/sample.cpp
)

# ------------------------------
# R-TYPE
# ------------------------------

add_executable(${PROJECT_NAME} src/main.cpp ${RTYPE_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${RTYPE_INCLUDES})
target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# ------------------------------
# TESTS
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

add_executable(runTests ${TESTS_SRC} ${RTYPE_SRC})
target_include_directories(runTests PRIVATE ${RTYPE_INCLUDES})
target_link_libraries(runTests gtest gtest_main gmock pthread)