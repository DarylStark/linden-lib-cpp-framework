cmake_minimum_required(VERSION 3.20)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables
set(PROJECT_NAME linden-lib-cpp-framework)
set(PROJECT_VERSION 0.0.1)
set(LIBRARY_NAME ${PROJECT_NAME})

# Project name
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Set the C++ files to compile
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the library
add_library(${LIBRARY_NAME} ${SOURCES})

# Fetch SDL2 and SDL2_image using FetchContent
include(FetchContent)

# Freetype is needed for SDL TTF
find_package(Freetype REQUIRED)

# Ensure SDL2_VERSION and SDL2_INSTALL_DIR are set
set(SDL2_VERSION 2.30.9)
set(SDL2_IMAGE_VERSION 2.8.2)
set(SDL2_TTF_VERSION 2.22.0)
set(SDL2_INSTALL_DIR ${CMAKE_BINARY_DIR}/dependencies/SDL2)
set(SDL2_IMAGE_INSTALL_DIR ${CMAKE_BINARY_DIR}/dependencies/SDL2_image)
set(SDL2_TTF_INSTALL_DIR ${CMAKE_BINARY_DIR}/dependencies/SDL2_ttf)

FetchContent_Declare(
  SDL2
  URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-${SDL2_VERSION}.tar.gz
  SOURCE_DIR ${SDL2_INSTALL_DIR}/src
  BINARY_DIR ${SDL2_INSTALL_DIR}/build
)

FetchContent_Declare(
  SDL2_image
  URL https://github.com/libsdl-org/SDL_image/archive/refs/tags/release-${SDL2_IMAGE_VERSION}.tar.gz
  SOURCE_DIR ${SDL2_IMAGE_INSTALL_DIR}/src
  BINARY_DIR ${SDL2_IMAGE_INSTALL_DIR}/build
)

FetchContent_Declare(
  SDL2_ttf
  URL https://github.com/libsdl-org/SDL_ttf/archive/refs/tags/release-${SDL2_TTF_VERSION}.tar.gz
  SOURCE_DIR ${SDL2_TTF_INSTALL_DIR}/src
  BINARY_DIR ${SDL2_TTF_INSTALL_DIR}/build
)

# Make the SDL libraries available
FetchContent_MakeAvailable(SDL2 SDL2_image SDL2_ttf)

target_include_directories(${LIBRARY_NAME} PRIVATE
  ${SDL2_INSTALL_DIR}/src
  ${SDL2_IMAGE_INSTALL_DIR}/src
  ${SDL2_TTF_INSTALL_DIR}/src
  ${FREETYPE_INCLUDE_DIRS}
)

# Link SDL2 and SDL2_image to your library
target_link_libraries(${LIBRARY_NAME} SDL2 SDL2_image SDL2_ttf)