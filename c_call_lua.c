#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdlib.h>

void test_add() {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	int ret = luaL_dofile(L, "call_lua.lua");
	printf("luaL_dofile ret:%d\n", ret);
	if (ret != 0)
		goto exit;
	
	lua_getfield(L, -1, "add");
	lua_pushinteger(L, 5);
	lua_pushinteger(L, 6);
	ret = lua_pcall(L, 2, 1, 0);
	printf("lua_pcall ret:%d\n", ret);
	if (ret != 0)
		goto exit;

	printf("result:%d\n", (int)lua_tointeger(L, -1));

exit:
	lua_close(L);
}

int main() {
	test_add();
	printf("1111\n");
	return 0;
}