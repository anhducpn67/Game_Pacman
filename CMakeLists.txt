cmake_minimum_required(VERSION 3.15)
project(Game_Pacman)

set(CMAKE_CXX_STANDARD 14)

file(GLOB pacman_SRC
        "*.h"
        "*.cpp"
        )

add_executable(Game_Pacman ${pacman_SRC})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2, SDL2_image and SDL2_gfx libraries
set(SDL2_PATH "ExtendedLib/SDL2-2.0.12/i686-w64-mingw32" CACHE BOOL "" FORCE)
find_package(SDL2 REQUIRED)
set(SDL2_IMAGE_PATH "ExtendedLib/SDL2_image-2.0.5/i686-w64-mingw32" CACHE BOOL "" FORCE)
find_package(SDL2_image REQUIRED)
set(SDL2_MIXER_PATH "ExtendedLib/SDL2_mixer-2.0.4/i686-w64-mingw32" CACHE BOOL "" FORCE)
find_package(SDL2_mixer REQUIRED)
set(SDL2_TTF_PATH "ExtendedLib/SDL2_ttf-2.0.15/i686-w64-mingw32" CACHE BOOL "" FORCE)
find_package(SDL2_ttf REQUIRED)

# Link SDL2::Main, SDL2::Image and SDL2::GFX to our project
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image SDL2::Mixer SDL2::TTF)

