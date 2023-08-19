
local is_running = false
local co_pools = {}

local function loop()
  while is_running do

  end
end


local function main()
  is_running = true
  loop()
  -- print(string.format("main thread isyieldable:%s", coroutine.isyieldable()))
  -- local co = coroutine.create(
  --   function (...)
  --     print("enter co", ...)
  --     print("yield")
  --     print("resume", coroutine.yield())
  --     return
  --   end)
  --   print("call co")
  --   coroutine.resume(co, 1, 2, 3) -- start
  --   coroutine.resume(co, 4, 5, 6) -- continue




end

main()