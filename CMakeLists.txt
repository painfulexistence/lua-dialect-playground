cmake_minimum_required(VERSION 3.20.0)

option(GLOBAL_VCPKG "Use global Vcpkg " OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (GLOBAL_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

project(
    lua-tests
    VERSION 0.0.1
    LANGUAGES CXX
)

find_package(fmt CONFIG REQUIRED)
find_package(Lua REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LuaJIT REQUIRED IMPORTED_TARGET luajit)

set(LUAU_BUILD_CLI OFF)
set(LUAU_BUILD_TESTS OFF)
add_subdirectory(src/external/luau)

add_subdirectory(src/external/terra)

add_executable(luau-test src/luau/main.cpp)
target_compile_features(luau-test PRIVATE cxx_std_20)
set_target_properties(luau-test PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME luau-test)
target_link_libraries(luau-test PRIVATE fmt::fmt Luau.Compiler Luau.VM)

add_executable(lua-test src/lua/main.cpp)
target_include_directories(lua-test PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(lua-test PRIVATE fmt::fmt ${LUA_LIBRARIES})

add_executable(luajit-test src/luajit/main.cpp)
target_link_libraries(luajit-test PRIVATE fmt::fmt PkgConfig::LuaJIT)

add_executable(terra-test src/terra/main.cpp)
message(WARNING ${PROJECT_BINARY_DIR})
target_include_directories(terra-test PRIVATE ${PROJECT_BINARY_DIR}/src/external/terra/include/terra)
target_link_libraries(terra-test PRIVATE fmt::fmt TerraLibrary)