.PHONY: clean all test_c_call_lua test_cutil test_extern testall

CC?=gcc

all: cutil.so c_call_lua extern_test

cutil.so: cutil.c
	$(CC) cutil.c -fPIC -shared -o $@

c_call_lua: c_call_lua.c
	$(CC) c_call_lua.c -o $@ -llua -lm -ldl

extern_test:
	$(CC) test_extern.c test_extern_main.c -o $@

test_extern_test: extern_test
	chmod +x ./extern_test && ./extern_test

test_c_call_lua: c_call_lua
	chmod +x ./c_call_lua && ./c_call_lua

test_cutil: cutil.so
	lua test_cutil.lua



testall: test_extern_test test_cutil test_c_call_lua

clean:
	rm -f cutil.so c_call_lua extern_test
