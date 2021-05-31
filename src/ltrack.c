#define LUA_LIB

#include "lprefix.h"

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"
#include "lapi.h"

static int track_version(lua_State *L) {
  lua_pushstring(L, "1.0.0");
  return 1;
}

static int track_run_test(lua_State *L) {
  api_check(1, "run_test check fail");
  return 0;
}

static const luaL_Reg lib[] = {
  {"version",   track_version},
  {"run_test",  track_run_test},
  {NULL, NULL}
};

LUAMOD_API int luaopen_ltrack (lua_State *L) {
  luaL_newlib(L, lib);
  return 1;
}