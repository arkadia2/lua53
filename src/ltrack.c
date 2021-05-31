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