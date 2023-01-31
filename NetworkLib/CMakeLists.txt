# CmakeLists to create the network library

add_library(
    NetworkLib
    src/LinuxSocketSelector.cpp
    src/LinuxSocket.cpp
    src/SocketFactory.cpp
    src/SocketSelectorFactory.cpp
    src/WindowsSocket.cpp
    src/WindowsSocketSelector.cpp
)

target_include_directories(NetworkLib PUBLIC include)
target_link_libraries(NetworkLib Error)
set_property(TARGET NetworkLib PROPERTY CXX_STANDARD 20)