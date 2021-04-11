local cutil_a = require "cutil.a"
local cutil_b = require "cutil.b"
local cutil = require "cutil"

print("test_cutil begin")

print(cutil_a.add(10,20))

print(cutil_b.multi(10, 20))

print(cutil.add(1, 2))
print(cutil.multi(1, 2))

print(minus(20,30))

print("test_cutil finish")