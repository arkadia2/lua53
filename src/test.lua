
local ltrack = require("ltrack")
print(">> ltrack.version: ", ltrack.version())
ltrack.run_test()


local s = 0x1fffffffffffffff
-- local s = 100
local t = {}
for i=1, 1024 do
  for j = 1, 16 do
    table.insert(t, s)
  end
end
local fobj = io.open("minimap.map", "wb")
for _, s in ipairs(t) do
  fobj:write(string.pack(">J", s))
end
fobj:close()

-- local p = 0xffffffffffffffff
-- print(">> p", p, type(p))
-- local s = string.pack(">J", p)
-- local len = string.packsize(">J")
-- print(">> s", s, len)
-- local i = string.unpack(">J", s)
-- print(">> i", i, type(i))


