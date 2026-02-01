cmake_minimum_required(VERSION 3.16)
project(UDPSocketClient C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

add_executable(UDPSocketClient src/main.c
        src/protocol/protocol.h
        src/net/net.c
        src/net/net.h
        src/render/render.c
        src/render/render.h
        src/input/input.c
        src/input/input.h
        src/game/game.c
        src/game/game.h)

target_include_directories(UDPSocketClient PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(UDPSocketClient PRIVATE ${SDL2_LIBRARIES} m)
