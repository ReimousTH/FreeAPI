#ifndef Basics_H
#define Basics_H





#include <stdlib.h>
#include <boost/make_shared.hpp>


#include <xtl.h>
#include <cassert>

#include <vector>


#include <iostream>
#include <sstream>


#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"
#include <map>
#include <Xboxmath.h>

// first unsigned macros:

#define BYTEn(x, n)   (*((_BYTE*)&(x)+n))
#define WORDn(x, n)   (*((_WORD*)&(x)+n))
#define DWORDn(x, n)  (*((_DWORD*)&(x)+n))

#define LOBYTE(x)  BYTEn(x,LOW_IND(x,_BYTE))
#define LOWORD(x)  WORDn(x,LOW_IND(x,_WORD))
#define LODWORD(x) DWORDn(x,LOW_IND(x,_DWORD))
#define HIBYTE(x)  BYTEn(x,HIGH_IND(x,_BYTE))
#define HIWORD(x)  WORDn(x,HIGH_IND(x,_WORD))
#define HIDWORD(x) DWORDn(x,HIGH_IND(x,_DWORD))
#define BYTE1(x)   BYTEn(x,  1)         // byte 1 (counting from 0)
#define BYTE2(x)   BYTEn(x,  2)
#define BYTE3(x)   BYTEn(x,  3)
#define BYTE4(x)   BYTEn(x,  4)
#define BYTE5(x)   BYTEn(x,  5)
#define BYTE6(x)   BYTEn(x,  6)
#define BYTE7(x)   BYTEn(x,  7)
#define BYTE8(x)   BYTEn(x,  8)
#define BYTE9(x)   BYTEn(x,  9)
#define BYTE10(x)  BYTEn(x, 10)
#define BYTE11(x)  BYTEn(x, 11)
#define BYTE12(x)  BYTEn(x, 12)
#define BYTE13(x)  BYTEn(x, 13)
#define BYTE14(x)  BYTEn(x, 14)
#define BYTE15(x)  BYTEn(x, 15)
#define WORD1(x)   WORDn(x,  1)
#define WORD2(x)   WORDn(x,  2)         // third word of the object, unsigned
#define WORD3(x)   WORDn(x,  3)
#define WORD4(x)   WORDn(x,  4)
#define WORD5(x)   WORDn(x,  5)
#define WORD6(x)   WORDn(x,  6)
#define WORD7(x)   WORDn(x,  7)


template<class T> T __ROL__(T value, int count)
{
	const uint nbits = sizeof(T) * 8;

	if ( count > 0 )
	{
		count %= nbits;
		T high = value >> (nbits - count);
		if ( T(-1) < 0 ) // signed value
			high &= ~((T(-1) << count));
		value <<= count;
		value |= high;
	}
	else
	{
		count = -count % nbits;
		T low = value << (nbits - count);
		value >>= count;
		value |= low;
	}
	return value;
}

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef          char   int8;
typedef   signed char   sint8;
typedef unsigned char   uint8;
typedef          short  int16;
typedef   signed short  sint16;
typedef unsigned short  uint16;
typedef          int    int32;
typedef   signed int    sint32;
typedef unsigned int    uint32;


inline uint8  __ROL1__(uint8  value, int count) { return __ROL__((uint8)value, count); }
inline uint16 __ROL2__(uint16 value, int count) { return __ROL__((uint16)value, count); }
inline uint32 __ROL4__(uint32 value, int count) { return __ROL__((uint32)value, count); }

inline uint8  __ROR1__(uint8  value, int count) { return __ROL__((uint8)value, -count); }
inline uint16 __ROR2__(uint16 value, int count) { return __ROL__((uint16)value, -count); }
inline uint32 __ROR4__(uint32 value, int count) { return __ROL__((uint32)value, -count); }



extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


//#include <luajit.h>
#include <string>
#include <iostream>
#include <cmath>


#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)
#define LOW_IND(x,part_type)   LAST_IND(x,part_type)
#define HIGH_IND(x,part_type)  0

#define DWORDn(x, n)  (*((_DWORD*)&(x)+n))
#define LODWORD(x) DWORDn(x,LOW_IND(x,_DWORD))
#define HIDWORD(x) DWORDn(x,HIGH_IND(x,_DWORD))
#define _QWORD unsigned long long







#define _DWORD DWORD
#define _BYTE BYTE
typedef short _WORD;



//class ZLua
//{
//public:
//	std::string FilePath;
//	lua_State* L;
//	bool executed;


//	void OpenLua();
//	void UseBaseLibs();
//	void DoFile(bool);
//	void CallFunction();


//	ZLua(void);
//	ZLua(const char*);
//	~ZLua(void);
//};



#define BranchTo(offset,rtype,...) \
	((rtype (__fastcall *)(...))offset)(__VA_ARGS__) \


#define DataPointer(type, name, address) \
	static type &name = *(type *)address

// Function pointer declarations.
#define FunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__cdecl *const NAME)ARGS = (RETURN_TYPE (__cdecl *)ARGS)ADDRESS
#define StdcallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__stdcall *const NAME)ARGS = (RETURN_TYPE (__stdcall *)ARGS)ADDRESS
#define FastcallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__fastcall *const NAME)ARGS = (RETURN_TYPE (__fastcall *)ARGS)ADDRESS
#define ThiscallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__thiscall *const NAME)ARGS = (RETURN_TYPE (__thiscall *)ARGS)ADDRESS
#define VoidFunc(NAME, ADDRESS) FunctionPointer(void,NAME,(void),ADDRESS)



#define FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
	 returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location) \


#define FUNCTION_PTRN(returnType, callingConvention, function, location, ...) \
returnType callingConvention function(__VA_ARGS__)\
{\
return ((returnType (callingConvention *)(__VA_ARGS__))location)(__VA_ARGS__))\
}\



#define MakeState(NM,TP) \
	boost::shared_ptr<TP>& NM(boost::shared_ptr<TP>& a1,int a2){ \
	\
	boost::shared_ptr<TP> x(new TP((Marathon::PlayerState::StateBaseValueP*)a2));\
	a1 = x;\
	return a1;\
}\

#define MakeStateS(TP) \
	boost::shared_ptr<TP>& TP##C(boost::shared_ptr<TP>& a1,int a2){ \
	\
	boost::shared_ptr<TP> x(new TP((Marathon::PlayerState::StateBaseValueP*)a2));\
	a1 = x;\
	return a1;\
}\

#define malloc06(size) \
	BranchTo(0x82186158,int,60) \



#define FD(NM) \
	(int)(NM##C) \



class ZLua
{
public:
	std::string FilePath;
	lua_State* L;
	bool executed;
	bool locked;


	void OpenLua();
	void UseBaseLibs();
	void DoFile(bool);
	void CallFunction();

	const char* ZLua::GetGlobalString(const char* string);
	int ZLua::GetGlobalBool(const char* string);
	int ZLua::GetGlobalInt(const char* string);

	static void UseBaseLibsEx(lua_State* L);


	ZLua(void);
	ZLua(const char*);
	~ZLua(void);
};




LPCWSTR g_pwstrButtonsX[1] = { L"------------OK----------------" };

void ShowXenonMessage(LPCWSTR Title,LPCWSTR wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 
	XShowMessageBoxUI(0,Title,wTitle,1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
}

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString=new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

void ShowXenonMessage(LPCWSTR Title,char* wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 



	XShowMessageBoxUI(0,Title,convertCharArrayToLPCWSTR(wTitle),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
}

MESSAGEBOX_RESULT* ShowXenonMessage(LPCWSTR Title,const char* wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 
	XShowMessageBoxUI(0,Title,convertCharArrayToLPCWSTR(wTitle),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
	return &result;
}


void ShowXenonMessage(LPCWSTR Title,int value,char*){


	int vIn = value;;
	wchar_t vOut [12];
	_itow_s(vIn,vOut,sizeof(vOut)/2,10);

	ShowXenonMessage(Title,vOut);

}



void ShowXenonMessage(LPCWSTR Title,float value,char*){


	float vIn = value;
	char vOutChar [17];
	_gcvt_s(vOutChar,sizeof(vOutChar),vIn,8);
	wchar_t vOut[17];
	mbstowcs_s(NULL,vOut,sizeof(vOut)/2,vOutChar,sizeof(vOutChar));

	ShowXenonMessage(Title,vOut);

}





//Contains Original06 Function


#endif

