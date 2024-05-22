cmake_minimum_required(VERSION 3.25)
project(nes-emulator LANGUAGES CXX)

find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)

add_executable(nes src/main.cpp)
add_subdirectory(src)

target_compile_features(nes PRIVATE cxx_std_23)
target_link_libraries(nes PRIVATE SDL2::SDL2 spdlog::spdlog)