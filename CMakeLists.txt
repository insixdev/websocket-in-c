cmake_minimum_required(VERSION 3.10)
project(WebsocketClient)

find_package(libwebsockets CONFIG REQUIRED)


file(GLOB_RECURSE SRC_FILES "src/*.c")
add_executable(websocket_client ${SRC_FILES})

target_link_libraries(websocket_client PRIVATE websockets_shared)
