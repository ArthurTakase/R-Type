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

set(
  RTYPE_SRC
  src/main.cpp
  src/RType.cpp
  src/ECS/Entity/Entity.cpp
  src/ECS/Entity/EntityManager.cpp
  src/ECS/Components/PositionComponent.cpp
  src/ECS/Components/HitboxComponent.cpp
  src/ECS/Systems/HitboxSystem.cpp
)

set(RTYPE_SERVER
  src/Network/Server/Server.cpp
  src/Network/Server/main.cpp
)

add_subdirectory(Error)
add_subdirectory(NetworkLib)

add_executable(${PROJECT_NAME} ${RTYPE_SRC})
add_executable(server ${RTYPE_SERVER})

#link all external lib necessary

if(WIN32)
  target_link_libraries(server wsock32 ws2_32)
endif()

target_link_libraries(${PROJECT_NAME} Error)
target_link_libraries(server Error)
target_link_libraries(server NetworkLib)

# Ajouter ici les dossiers contenants les .hpp de l'exec du R-Type
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Entity)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Components)
target_include_directories(${PROJECT_NAME} PRIVATE include/ECS/Systems)
target_include_directories(${PROJECT_NAME} PRIVATE include/Tools)
target_include_directories(${PROJECT_NAME} PRIVATE include/Network)

# Ajouter ici les dossiers contenants les .hpp de l'exec du Server
target_include_directories(server PRIVATE include/Network)
target_include_directories(server PRIVATE include/Tools)

target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})
target_compile_options(server PUBLIC ${CXX_FLAGS})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET server PROPERTY CXX_STANDARD 20)