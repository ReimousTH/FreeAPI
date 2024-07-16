#pragma once

#ifndef DLL_LUA
#define DLL_LUA
#endif

#include "InputData.h"

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

#include "LuaExtension_Memory.h"




class ZLuaN{

public: 
	lua_State* L;
	bool error;
	const char* error_msg;
	
	void OpenLuaRaw();
	void OpenLua();
	void OpenLuaMy();
	void LoadLua(const char* file);
	void Close();

	//work with lua

	const char* GetGlobalString(const char* str);
	const std::string GetGlobalSString(const char* str);


	bool GetGlobalBoolean(const char* str);

	int GetGlobalIntNew(const char* st,bool useglobal);


	void RegisterFunction(const char* name,lua_CFunction fn);
	void CallFunction(const char* name,...);


	static bool EnableDebugOutput;
	static bool TogeableHud;

	static std::vector<std::string> _file_redirect_;





};

extern ZLuaN CommonLua;
void DLL_LUA_INSTALL();


