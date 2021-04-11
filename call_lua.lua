local call_lua = {}

function call_lua.add(a, b)
	return a+b
end

function call_lua.multi(a, b)
	return a*b
end

function call_lua.minus(a, b)
	return a-b
end

print("loaded")

return call_lua