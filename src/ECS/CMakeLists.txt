cmake_minimum_required(VERSION 3.17)
project(ECSEncapsulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

# Sources
set(
  ECS_SRC
  Entity/Entity.cpp
  Entity/EntityManager.cpp
  Components/TransformComponent.cpp
  Components/HitboxComponent.cpp
  Components/MouvementComponent.cpp
  Components/StatComponent.cpp
  Components/DrawableComponent.cpp
  Components/BehaviorComponent.cpp
  Systems/HitboxSystem.cpp
  Systems/MouvementSystem.cpp
  Systems/SerializerSystem.cpp
  Systems/BehaviorSystem.cpp
)

set(
  SERIALIZER_SRC
  ../Serializer/Serializer.cpp
  ../Serializer/Deserializer.cpp
)

# Merge
add_library(${PROJECT_NAME} ${ECS_SRC} ${SERIALIZER_SRC})

# Ajouter ici les dossiers contenants les .hpp de l'exec de l'ECS
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ECS)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ECS/Entity)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ECS/Components)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ECS/Systems)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/Tools)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/Serializer)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/Lib)

include_directories(${CMAKE_BINARY_DIR}/../../include)
include_directories(${CMAKE_BINARY_DIR}/../../include/ECS)
include_directories(${CMAKE_BINARY_DIR}/../../include/ECS/Entity)
include_directories(${CMAKE_BINARY_DIR}/../../include/ECS/Components)
include_directories(${CMAKE_BINARY_DIR}/../../include/ECS/Systems)
include_directories(${CMAKE_BINARY_DIR}/../../include/Tools)
include_directories(${CMAKE_BINARY_DIR}/../../include/Serializer)
include_directories(${CMAKE_BINARY_DIR}/../../include/Lib)
