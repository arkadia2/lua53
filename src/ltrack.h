
#ifndef ltrack_h
#define ltrack_h

#include "lua.h"
#include "lobject.h"

const char *track_dump_table(Table *t);
void track_dump_stack(lua_State *L, int add);
void track_test_sizeof();
const char *track_dump_tvalue(TValue *o);

#endif