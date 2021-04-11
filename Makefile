.PHONY: clean all

all: c_util.so c_call_lua

c_util.so:
	$(CC) -fPIC -shared -o $@ cutil.c

c_call_lua:
	$(CC) c_call_lua.c -o $@ -llua -lm

test_cutil: c_util.so
	lua test_cutil.lua

test_extern:
	$(CC) test_extern.c test_extern_main.c -o $@

clean:
	rm cutil.so c_call_lua test_extern
