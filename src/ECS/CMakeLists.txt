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
  Components/AnimationComponent.cpp
  Components/InputComponent.cpp
  Systems/HitboxSystem.cpp
  Systems/MouvementSystem.cpp
  Systems/BehaviorSystem.cpp
  Systems/AnimationSystem.cpp
  Systems/DrawableSystem.cpp
)

# Merge
add_library(${PROJECT_NAME} ${ECS_SRC})

# Ajouter ici les dossiers contenants les .hpp de l'exec de l'ECS
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)