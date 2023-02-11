#define LUA_LIB

#include <stdio.h>
#include "lprefix.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "ltrack.h"
#include "ltable.h"

#define TVALUE_BUFF_SIZE 1024
static char TValueBuff[TVALUE_BUFF_SIZE];

const char *track_dump_table(Table *t) {
  return "{}";
}

void track_dump_stack(lua_State *L, int add) {
  printf("-------- dump_stack --------\n");
  printf("top:%p stack:%p size:%d add:%d\n", L->top, L->stack, L->stacksize, add);
  int count = L->top-1+add - L->stack;
  for (StkId o=L->top-1+add; o>L->stack; o--) {
    count--;
    const char *s = track_dump_tvalue(o);
    printf("%d: %s\n", count, s);
  }
}


const char *track_dump_tvalue(TValue *o) {
  TValueBuff[0] = '\0';
  int t = ttnov(o);
  const char *tname = ttypename(t);
  switch (t)
  {
  case LUA_TNUMBER:
    snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s <%f>", o, tname, fvalue(o));
    break;
  case LUA_TFUNCTION:
    if (ttisCclosure(o)) {
      snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s c closure", o, tname);
    }
    else if (ttisLclosure(o)) {
      LClosure *cl = clLvalue(o);
      Proto *p = cl->p;
      const char *source = cast(const char*, getaddrstr(p->source));
      int line = p->linedefined;
      snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s lua closure <%s:%d>", o, tname, source, line);
    }
    else {
      snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s c light func", o, tname);
    }
    break;
  case LUA_TTABLE:
    snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s <%s>", o, tname, track_dump_table(o));
    break;
  case LUA_TSTRING:
    snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s <'%s'>", o, tname, svalue(o));
    break;
  default:
    snprintf(TValueBuff, TVALUE_BUFF_SIZE, "%p %s", o, tname);
    break;
  }
  return TValueBuff;
}

#define print_size(t) printf("sizeof(" #t "): %lu\n", sizeof(t))
void track_test_sizeof() {
  print_size(Value);
  print_size(int);
  print_size(TValue);
  print_size(TString);
  print_size(UTString);
}

static int track_version(lua_State *L) {
  lua_pushstring(L, "1.0.0");
  return 1;
}

static int track_run_test(lua_State *L) {
  api_check(1, "run_test check fail");
  return 0;
}

static int track_sizeof(lua_State *L) {
  return 1;
}

static int track_test_table(lua_State *L) {
  // lua_newtable(L);
  lua_createtable(L, 100, 100);
  int tidx = lua_gettop(L);
  Table *t = (Table*)lua_topointer(L, tidx);
  for (size_t i = 7; i <= 8; i++)
  {
    lua_pushinteger(L, i*100); // push value
    lua_seti(L, tidx, i); // push key, set t[key]=value
  }
  lua_pushinteger(L, 100);
  lua_seti(L, tidx, 127);
  printf(">> size 111 list:%d map:%d\n", t->sizearray, 1<<t->lsizenode);
  luaH_resize(L, t, 10, 10);
  printf(">> size 222 list:%d map:%d\n", t->sizearray, 1<<t->lsizenode);
  return 0;
}

static const luaL_Reg lib[] = {
  {"version",   track_version},
  {"run_test",  track_run_test},
  {"sizeof",  track_sizeof},
  {"test_table",  track_test_table},
  {NULL, NULL}
};

LUAMOD_API int luaopen_ltrack (lua_State *L) {
  luaL_newlib(L, lib);
  return 1;
}