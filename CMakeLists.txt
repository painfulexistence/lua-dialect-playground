cmake_minimum_required(VERSION 3.20.0)

option(GLOBAL_VCPKG "Use global Vcpkg " OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (GLOBAL_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

project(
    luau-test
    VERSION 0.0.1
    LANGUAGES CXX
)

find_package(fmt REQUIRED)
add_subdirectory(src/external/luau)

add_executable(main src/main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
set_property(TARGET main PROPERTY OUTPUT_NAME main)
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PUBLIC fmt::fmt)

set(LUAU_BUILD_CLI OFF)
set(LUAU_BUILD_TESTS OFF)
target_link_libraries(main PUBLIC Luau.Compiler Luau.VM)