#pragma once

#ifndef DLL_LUA
#define DLL_LUA
#endif

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}



#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


#include <cstdlib>


#include "../HookV2.h"
#include <xtl.h>
#include <map>




class ZLuaN{

public: 
	lua_State* L;
	bool error;
	const char* error_msg;
	
	void OpenLuaRaw();
	void OpenLua();
	void OpenLuaMy();
	void LoadLua(const char* file);

	//work with lua

	const char* GetGlobalString(const char* str);
	bool GetGlobalBoolean(const char* str);

	int GetGlobalIntNew(const char* st,bool useglobal);

	static bool EnableDebugOutput;


};

extern ZLuaN CommonLua;
void DLL_LUA_INSTALL();


