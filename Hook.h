#pragma once

#ifndef __HOOK__
#define __HOOK__
#include <xtl.h>
#include <cassert>

#define ADDRESS_HIGHER(X) ( ( X >> 16 ) & 0xFFFF )
#define ADDRESS_LOWER(X)  ( X & 0xFFFF )
#define POWERPC_BRANCH_OPTION_SET(X)      ( X << 21 ) 
#define POWERPC_CONDITION_REGISTER_SET(X) ( X << 16 )
#define PPC_BASE_ADDRES 0x82000000

#define XeniaPadding 0x10000000
#define TRUE_START_XENIA 0x10000000

#define SECTION_TEXT 0xFFCF000
#define SECTION_RDATA 0xFFCF000
#define SECTION_DATA 0xFFCF000

//#define KinectTEST
//#define TEST
#ifndef TEST
#define HOOK_VALUE 0xFFCF000
#define XEX_PC_HEADER 0x31000
#else
#define HOOK_VALUE 0
#define XEX_PC_HEADER 0

#endif

#define ADDR(val) ((UINT64)val + (UINT64)(HOOK_VALUE+XEX_PC_HEADER))




const DWORD JumpASMNoPreserve[] = { /*Dont always have enough space to preserve registers*/
	0x3d600000, // lis %r11, Destination@h
	0x616b0000, // ori %r11, %r11, Destination@l
	0x7d6903a6, // mtctr %r11
	0x4E800420  // bcctr (Used For PatchInJumpEx bcctr 20, 0 == bctr)
};
const DWORD JumpASMNoPreserveI[] = { /*Dont always have enough space to preserve registers*/
	0x3d600000, // lis %r11, Destination@h
	0x616b0000, // ori %r11, %r11, Destination@l
	0x7d6903a6, // mtctr %r11
	0x4E800421  // bcctr (Used For PatchInJumpEx bcctr 20, 0 == bctr)
};





void DoHook(int target,int newfunc);
void DoHookR(int target,int newfunc);




#define HOOK(returnType, callingConvention, functionName, location, ...) \
	int original_addr_##functionName = (int)location ;\
	typedef returnType callingConvention functionName(__VA_ARGS__); \
	functionName* original##functionName = (functionName*)(location+0x10); \
	returnType callingConvention implOf##functionName(__VA_ARGS__)


#define HOOKN(returnType, callingConvention, functionName, location, ...) \
	int original_addr_##functionName = (int)location ;\
	typedef returnType callingConvention functionName(__VA_ARGS__); \
	functionName* original##functionName = (functionName*)(location+0x10); \
	returnType __declspec( naked )  callingConvention implOf##functionName(__VA_ARGS__)

#define INSTALL_HOOK(functionName) \
	DoHook((int)original_addr_##functionName, (int)implOf##functionName); \

#define INSTALL_HOOKR(functionName) \
	DoHookR((int)original_addr_##functionName, (int)implOf##functionName); \


#define WRITE_DWORD(target,RWORD) \
	Hook::WriteDword((void*)target,(DWORD)RWORD) \

#define WRITE_NOP(target,c) \
	Hook::WriteNOP((void*)target,c) \
	



class Hook
{
	


public:
	enum Type{
		NoReturn,
		Return
	};
	static void DataSection_NR_ReHook(void* original,void* target);
	static void DataSection_R_ReHook(void* original,void* target);
	static void WriteBytesDATASection(void* original,DWORD DATA[]);
	static void WriteNOP(void* original,int count);
	static void WriteHook(void* original,void* target,Type tp = NoReturn);
	static void WriteDword(void* original,DWORD target);
    static void WriteBytes(void* original,DWORD DATA[],size_t length = 4);
	static void WriteNOPNEw(void* original,int count);
    static void WriteByte(void* original,BYTE b);
	

};
#endif