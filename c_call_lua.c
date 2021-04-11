#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdlib.h>

void test_add() {
	lua_State *L = luaL_newstate();
	int ret = luaL_dofile(L, "./call_lua.lua");
	lua_close(L);
	printf("ret:%d\n", ret);
}

void main() {
	test_add();
	printf("1111\n");
	return;
}