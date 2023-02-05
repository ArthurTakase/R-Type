# CmakeLists to create the network library

add_library(
  NetworkLib
  src/LinuxSocketSelector.cpp
  src/LinuxSocket.cpp
  src/SocketFactory.cpp
  src/SocketSelectorFactory.cpp
  src/WindowsSocket.cpp
  src/WindowsSocketSelector.cpp
  src/HostHandler.cpp
)

if(WIN32)
  target_link_libraries(NetworkLib wsock32 ws2_32)
endif()

target_include_directories(NetworkLib PUBLIC include)
target_link_libraries(NetworkLib Error)
set_property(TARGET NetworkLib PROPERTY CXX_STANDARD 20)