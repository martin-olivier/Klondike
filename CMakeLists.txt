cmake_minimum_required(VERSION 3.1)

project(Klondike)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

set(SOURCE
    src/main.cpp
    src/Card.cpp
    src/Klondike.cpp
    src/KlondikeEvents.cpp
    src/Sound.cpp
    src/Tas.cpp
    src/Tile.cpp
)

add_executable(Klondike
    ${SOURCE}
)

target_link_libraries(Klondike
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)
else ()
    add_compile_options(/W4)
endif()