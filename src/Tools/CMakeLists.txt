cmake_minimum_required(VERSION 3.16)
project(Tools LANGUAGES CXX)

if (WIN32)
  add_library(${PROJECT_NAME} STATIC Curve.cpp)
else()
  add_library(${PROJECT_NAME} Curve.cpp)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
