
## 库的开发

### 文件结构
```cpp
#define LUA_LIB

#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int track_version(lua_State *L) {
  lua_pushstring(L, "1.0.0");
  return 1;
}

static const luaL_Reg lib[] = {
  {"version",   track_version},
  {NULL, NULL}
};

LUAMOD_API int luaopen_ltrack (lua_State *L) {
  luaL_newlib(L, lib);
  return 1;
}

```

### 内建编译到lua
### 编辑成动态库

### get args
1. luaL_checkXXX拿到某一类型参数值
2. luaL_argcheck检查参数值的合法值
```cpp
static int test_args(lua_State *L) {
  lua_Integer base = luaL_checkinteger(L, 1);
  luaL_argcheck(L, 2 <= base && base <= 36, 1, "base out of range");
  luaL_checktype(L, 2, LUA_TTABLE);
  Table *t = lua_topointer(L, 2);
  return 0;
}
```



