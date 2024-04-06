extern "C"{

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "fmt/core.h"

auto main(int argc, char* args[]) -> int {
    auto const L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dostring(L, "print('Hello')");

    lua_close(L);
    return 0;
}