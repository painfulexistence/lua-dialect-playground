#include "lua.h"
#include "lualib.h"
#include "luacode.h"
#include "fmt/core.h"

auto main(int argc, char* args[]) -> int {
    auto const source = "print(\"Hello from Luau!\")";

    auto const L = luaL_newstate();
    luaL_openlibs(L);
    size_t bytecodeSize = 0;
    char* bytecode = luau_compile(source, strlen(source), nullptr, &bytecodeSize);
    int result = luau_load(L, "a", bytecode, bytecodeSize, 0);
    lua_pcall(L, 0, 0, 0);
    delete bytecode;
    if (result == 1)
        return 1;


    fmt::print("Hello from C++!");

    lua_close(L);
    return 0;
}
