#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
// make:  gcc -fPIC -shared -o cutil.so cutil.c

static int add(lua_State *L) {
	int a = lua_tonumber(L, -1);
	int b = lua_tonumber(L, -2);
	int c = a+b;
	lua_pushnumber(L, c);
	return 1;
}

static int minus(lua_State *L) {
	int a = lua_tonumber(L, -1);
	int b = lua_tonumber(L, -2);
	int c = b-a;
	lua_pushnumber(L, c);
	return 1;
}

static int multi(lua_State *L) {
	int a = lua_tonumber(L, -1);
	int b = lua_tonumber(L, -2);
	int c = a*b;
	lua_pushnumber(L, c);
	return 1;	
}

int luaopen_cutil_a (lua_State *L) {
  	lua_newtable(L);
	struct luaL_Reg libs[] = {
		{"add", add},
		{NULL, NULL}
	};
    luaL_setfuncs(L, libs, 0);
  	return 1;
}

int luaopen_cutil_b (lua_State *L) {
  	lua_newtable(L);
	struct luaL_Reg libs[] = {
	  	{"multi", multi},
	  	{NULL, NULL}
	};
    luaL_setfuncs(L, libs, 0);
  	return 1;
}

int luaopen_cutil(lua_State* L) {
	struct luaL_Reg libs[] = {
		{"add", add},
	  	{"multi", multi},
	  	{NULL, NULL}
	};
	luaL_newlib(L, libs);
	lua_register(L, "minus", minus);
  	return 1;
}