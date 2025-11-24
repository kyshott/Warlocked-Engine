cmake_minimum_required(VERSION 4.0)
project(Warlocked)

set(CMAKE_CXX_STANDARD 17)

# NOTE: EVENTUALLY NEED INSTALL COMPONENTS FOR DEPLOYMENT!!!!

# Target copy assets to build directory during make
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
        "${CMAKE_CURRENT_BINARY_DIR}/assets"
)

# Set SDL2 
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2/cmake")
find_package(SDL2 REQUIRED CONFIG)

# Find SDL_image using its CMake configuration
set(SDL2_image_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2/cmake")
find_package(SDL2_image REQUIRED CONFIG)

add_subdirectory(third_party/tinytmx)

# Collect all source files
file(GLOB SRC_FILES src/*.cpp)

# Create the executable
add_executable(game ${SRC_FILES})

add_dependencies(game copy_assets)

# Link against SDL2 and SDL2_image
target_link_libraries(game SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image tinytmx::tinytmx)