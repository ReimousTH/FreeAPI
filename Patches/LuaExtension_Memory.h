#pragma once


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


#include <xtl.h>
#include <iostream>
#include <tchar.h>
#include <map>
#include <string>

#include <iostream>
#include <sstream>



#define _DWORD DWORD
#define _BYTE BYTE


namespace DebugLogV2 {



	int MemoryLIB_GlobalInstall(lua_State* LS);



	extern "C" int Memory__NEW(lua_State* L);


	extern "C" int Memory__FMove(lua_State* L);
	extern "C" int Memory__Move(lua_State* L);
	extern "C" int Memory__OR(lua_State* L);
	extern "C" int Memory__AND(lua_State* L);
	extern "C" int Memory__eq(lua_State* L);
	extern "C" int Memory__add(lua_State* L);
	extern "C" int Memory__SBL(lua_State* L);
	extern "C" int Memory__SBR(lua_State* L);


	extern "C" int Memory__SetDWORD(lua_State* L);
	extern "C" int Memory__SetFLOAT(lua_State* L);
	extern "C" int Memory__SetBYTE(lua_State* L);
	extern "C" int Memory__SetPointer(lua_State* L);

	extern "C" int Memory__GetDWORD(lua_State* L);
	extern "C" int Memory__GetFLOAT(lua_State* L);
	extern "C" int Memory__GetBYTE(lua_State* L);
	extern "C" int Memory__GetPointer(lua_State* L);

	extern "C" int Memory__GetPTR(lua_State* L);
	extern "C" int Memory__GetPTRHEX(lua_State* L);

	extern "C" int Memory__GetClassName(lua_State* L);

	extern "C" int Memory__IsValidPTR(lua_State* L);
	extern "C" int Memory__CreateMetatableFields(lua_State* L,int value,int move);
	extern "C" int Memory__CreateMetatable(lua_State* L,int value,int move);


	extern "C" int Memory_GetPointer(lua_State* L);
	extern "C" int Memory_ADD(lua_State* L);
	extern "C" int Memory_SetPointerValue(lua_State* L);
	extern "C" int Memory_GetDWORD(lua_State* L);
	extern "C" int Memory_SetDWORD(lua_State* L);
	extern "C" int Memory_GetFLOAT(lua_State* L);
	extern "C" int Memory_SetFLOAT(lua_State* L);
	extern "C" int Memory_GetBYTE(lua_State* L);
	extern "C" int Memory_SetBYTE(lua_State* L);

	
}