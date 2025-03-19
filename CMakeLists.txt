cmake_minimum_required(VERSION 4.0)
project(Warlocked)

set(CMAKE_CXX_STANDARD 17)

# Use the SDL2 
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2/cmake")
find_package(SDL2 REQUIRED CONFIG)

# Find SDL_image using its CMake configuration
set(SDL2_image_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2/cmake")
find_package(SDL2_image REQUIRED CONFIG)

# Collect all source files
file(GLOB SRC_FILES src/*.cpp)

# Create the executable
add_executable(game ${SRC_FILES})

# Link against SDL2 and SDL2_image
target_link_libraries(game SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)