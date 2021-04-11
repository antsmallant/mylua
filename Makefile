.PHONY: clean all

all: c_util.so c_call_lua

c_util.so:
	$(CC) -fPIC -shared -o cutil.so cutil.c

c_call_lua:
	$(CC) c_call_lua.c -o c_call_lua -llua -lm

test_cutil: c_util.so
	lua test_cutil.lua

clean:
	rm cutil.so c_call_lua
