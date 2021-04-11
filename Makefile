.PHONY: clean all test_c_call_lua test_cutil test_extern testall

CC?=gcc

all: cutil.so c_call_lua test_extern testall

cutil.so: cutil.c
	$(CC) cutil.c -fPIC -shared -o $@

c_call_lua: c_call_lua.c
	$(CC) c_call_lua.c -o $@ -llua -lm -ldl

test_c_call_lua: c_call_lua
	chmod +x ./c_call_lua && ./c_call_lua

test_cutil: cutil.so
	lua test_cutil.lua

test_extern:
	$(CC) test_extern.c test_extern_main.c -o $@

testall: test_cutil test_c_call_lua test_extern

clean:
	rm -f cutil.so c_call_lua test_extern
