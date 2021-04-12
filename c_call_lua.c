#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdlib.h>

void test_add() {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	int ret = luaL_dofile(L, "call_lua.lua");
	printf("luaL_dofile ret:%d\n", ret);

	lua_getfield(L, -1, "add");
	lua_pushinteger(L, 5);
	lua_pushinteger(L, 6);
	int ret2 = lua_pcall(L, 2, 1, 0);
	printf("ret2:%d\n", ret2);
	if (ret2 == 0)
		printf("result:%d\n", (int)lua_tointeger(L, -1));

	lua_close(L);
}

int main() {
	test_add();
	printf("1111\n");
	return 0;
}