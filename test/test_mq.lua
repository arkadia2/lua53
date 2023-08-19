


local IsRunning = false
local MessageQueue = {}

local function push_msg(msg)
  table.insert(MessageQueue, msg)
end

local function pop_msg()
  if #MessageQueue == 0 then
    return
  end
  return table.remove(MessageQueue, 1)
end

local function process_msg(msg)
end

local function send()
end

local function call()
end

local function response()
end

local function fork()
end

local function sleep()
end

local function wait()
end

local function wakeup()
end


local function main()
  IsRunning = true
  while IsRunning then
    local msg = pop_msg()
    if msg then
      process_msg(msg)
    end
  end
end


main()


main:
  fork(function ()
    while true do
      -- do sth
      sleep(100)
    end
  end)



