/*
 * LuaC.cpp
 *
 *  Created on: 2017年3月19日
 *      Author: LeoBrilliant
 */

#include <iostream>
#include <cstring>

using namespace std;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

void LuaTest()
{
	lua_State * L = luaL_newstate();

	lua_pushstring(L, "I am so cool~");
	lua_pushnumber(L, 20);

	if(lua_isstring(L, 1)){
		cout << lua_tostring(L, 1) << endl;
	}

	if(lua_isnumber(L, 2))
	{
		cout << lua_tonumber(L, 2) << endl;
	}

	lua_close(L);
	return;
}


