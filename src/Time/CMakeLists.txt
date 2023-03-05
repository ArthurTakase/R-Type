cmake_minimum_required(VERSION 3.16)
project(Time LANGUAGES CXX)

if (WIN32)
  add_library(${PROJECT_NAME} STATIC Clock.cpp)
else()
  add_library(${PROJECT_NAME} Clock.cpp)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)