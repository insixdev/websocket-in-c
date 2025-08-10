cmake_minimum_required(VERSION 3.10)
project(WebsocketClient C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# ---
# Configuración de los directorios de salida
# ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# ---
# Configuración del proyecto
# ---
# 1. Recopila todos los archivos .c del directorio src
file(GLOB_RECURSE SRC_FILES "src/*.c")

# 2. Crea el ejecutable con el nombre 'websocket_client' usando esos archivos.
#    Este comando define el destino (target) 'websocket_client'.
add_executable(websocket_client ${SRC_FILES})

# 3. Encuentra la biblioteca libwebsockets DESPUÉS de definir el destino.
find_package(libwebsockets CONFIG REQUIRED)

message(STATUS "libwebsockets_INCLUDE_DIRS: ${libwebsockets_INCLUDE_DIRS}")
#    Añade los directorios de inclusión de libwebsockets
target_include_directories(websocket_client PRIVATE ${CMAKE_SOURCE_DIR}/include)

#    Vincula las bibliotecas necesarias al ejecutable
target_link_libraries(websocket_client PRIVATE websockets_shared)