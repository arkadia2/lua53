
### 相关文件
1. lua.h 类型定义, 外部api声明
```cpp
#define LUA_TTABLE		5
#define lua_newtable(L)		lua_createtable(L, 0, 0)
// stack index func
#define lua_istable(L,n)	(lua_type(L, (n)) == LUA_TTABLE) 
```

2. lobject.h 结构定义和内部api
```cpp
// StkId(TValue*) func
#define ttistable(o)		checktag((o), ctb(LUA_TTABLE)) // is func
#define hvalue(o)	check_exp(ttistable(o), gco2t(val_(o).gc)) // get func
#define sethvalue(L,obj,x) \ // set func
  { TValue *io = (obj); Table *x_ = (x); \
    val_(io).gc = obj2gco(x_); settt_(io, ctb(LUA_TTABLE)); \
    checkliveness(G(L),io); }
// data struct
struct TKey {};
struct Node {};
struct Table {};
```

3. ltable.h, ltable.c 核心实现
```cpp
LUAI_FUNC const TValue *luaH_getint (Table *t, lua_Integer key);
LUAI_FUNC void luaH_setint (lua_State *L, Table *t, lua_Integer key,
                                                    TValue *value);
LUAI_FUNC const TValue *luaH_getstr (Table *t, TString *key);
LUAI_FUNC const TValue *luaH_get (Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_newkey (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_set (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC Table *luaH_new (lua_State *L);
LUAI_FUNC void luaH_resize (lua_State *L, Table *t, unsigned int nasize,
                                                    unsigned int nhsize);
LUAI_FUNC void luaH_resizearray (lua_State *L, Table *t, unsigned int nasize);
LUAI_FUNC void luaH_free (lua_State *L, Table *t);
LUAI_FUNC int luaH_next (lua_State *L, Table *t, StkId key);
LUAI_FUNC int luaH_getn (Table *t);
```

4. ltablib.c 库
```cpp
static const luaL_Reg tab_funcs[] = {
  {"concat", tconcat},
#if defined(LUA_COMPAT_MAXN)
  {"maxn", maxn},
#endif
  {"insert", tinsert},
  {"pack", pack},
  {"unpack", unpack},
  {"remove", tremove},
  {"move", tmove},
  {"sort", sort},
  {NULL, NULL}
};
LUAMOD_API int luaopen_table (lua_State *L) {
  ...
}
```

5. lapi.c api函数实现
```cpp
LUA_API void lua_createtable (lua_State *L, int narray, int nrec) {
  ...
}
```

### 使用
1. new
2. get
3. set
4. is

### 设计

### 问题


### 参考
