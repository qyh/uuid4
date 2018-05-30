#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "uuid4.h"

int _uuid(lua_State* L)
{
	char buf[UUID4_LEN];
	uuid4_generate(buf);
	lua_pushlstring(L, buf, UUID4_LEN);
	return 1;
}
  
static luaL_Reg libs[] = {
	{"gen_uuid", _uuid},
    {NULL, NULL}
};

int luaopen_uuid(lua_State* L)
{
    luaL_newlib(L, libs);
    return 1;
}

