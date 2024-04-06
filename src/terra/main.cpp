#include "terra.h"
#include "fmt/core.h"

auto main(int argc, char* args[]) -> int {
    auto const L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dostring(L, "print('Hello from Terra!')");

    lua_close(L);

    fmt::print("Hello from C++!");
    return 0;
}