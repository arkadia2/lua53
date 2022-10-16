-- test.lua
-- print("hello world")

local a = "a"
local b = "b"
local function func_1()
  print(b, a)
end

local function func_2(p)
  print(a, b)
end

func_2(100)


