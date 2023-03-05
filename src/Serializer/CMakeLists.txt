cmake_minimum_required(VERSION 3.16)
project(Serializer LANGUAGES CXX)

if (WIN32)
  add_library(${PROJECT_NAME} STATIC Serializer.cpp)
else()
  add_library(${PROJECT_NAME} Serializer.cpp)
endif()

target_link_libraries(${PROJECT_NAME} ECSEncapsulation)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
