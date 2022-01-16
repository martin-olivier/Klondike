cmake_minimum_required(VERSION 3.17)

project(Klondike)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5.1 COMPONENTS graphics audio system window REQUIRED)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)
elseif(WIN32)
    add_compile_options(/W4)
endif()

set(SOURCES
    src/main.cpp
    src/Card.cpp
    src/Klondike.cpp
    src/KlondikeEvents.cpp
    src/Sound.cpp
    src/Tas.cpp
    src/Tile.cpp
)

add_executable(Klondike ${SOURCES})

target_link_libraries(Klondike PRIVATE
    sfml-audio
    sfml-graphics
    sfml-system
    sfml-window
)