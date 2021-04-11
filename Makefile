.PHONY: clean all

CC?=gcc

all: cutil.so c_call_lua test_extern testall

cutil.so:
	$(CC) cutil.c -fPIC -shared -o $@

c_call_lua:
	$(CC) c_call_lua.c -o $@ -llua -lm

test_cutil: cutil.so
	lua test_cutil.lua

test_extern:
	$(CC) test_extern.c test_extern_main.c -o $@

testall: test_cutil

clean:
	rm -f cutil.so c_call_lua test_extern
