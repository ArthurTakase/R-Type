add_library(
    Error
    Error.cpp
)

target_include_directories(Error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TARGET Error PROPERTY CXX_STANDARD 20)