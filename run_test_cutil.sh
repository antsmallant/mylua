#!/bin/bash
gcc -fPIC -shared -o cutil.so cutil.c
lua test_cutil.lua
