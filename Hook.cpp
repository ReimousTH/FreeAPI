#include "Hook.h"

void DoHook(int target,int newfunc){

	UINT64 addr = XEX_PC_HEADER + (UINT64)target + HOOK_VALUE; 
	DWORD dw;
	BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,24,4,&dw);	
	DWORD Instructions[ ARRAYSIZE( JumpASMNoPreserve ) ];
	memcpy( Instructions, JumpASMNoPreserve, sizeof( JumpASMNoPreserve ) );
	Instructions[ 0 ] |= ADDRESS_HIGHER( (UINT)newfunc );
	Instructions[ 1 ] |= ADDRESS_LOWER( (UINT)newfunc );
	memcpy((void*)addr,Instructions,sizeof(Instructions));
    ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,24,dw,&dw);	

}
void DoHookR(int target,int newfunc){

	UINT64 addr = XEX_PC_HEADER + (UINT64)target + HOOK_VALUE; 
	DWORD dw;
	BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,24,4,&dw);	
	//TODO : Try Get Original 4 bytes which one we do replace
	DWORD Instructions[ ARRAYSIZE( JumpASMNoPreserveI ) ];
	memcpy( Instructions, JumpASMNoPreserveI, sizeof( JumpASMNoPreserveI ) );
	Instructions[ 0 ] |= ADDRESS_HIGHER( (UINT)newfunc );
	Instructions[ 1 ] |= ADDRESS_LOWER( (UINT)newfunc );
	memcpy((void*)addr,Instructions,sizeof(Instructions));

}

template <typename A1>
inline A1 GetFromMemory(void* addr)
{

	addr = (void*)(((UINT64)addr) + HOOK_VALUE+ XEX_PC_HEADER);
	A1 ret;
	memcpy(&ret,addr,sizeof(A1));
	return ret;


}

void DetourFunction(void* XexAdress,void* MyAddress)
{

	


	GetFromMemory<int>(XexAdress);
	DWORD ORIGINAL_ASSEMBLER_COMMANDS[4];

}



void SetPageProtection(void* XexAddr,DWORD protection,int sz,DWORD* original)
{


	UINT64 addr = (UINT64)XexAddr+XEX_PC_HEADER+HOOK_VALUE;
	BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,sz,protection,original);	
}




void Hook::DataSection_NR_ReHook(void* original,void* target){
	UINT64 addr = 0x31000;
	addr+=(UINT64)original+0xFFCF000;
	DWORD dw;
	BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,24,4,&dw);	
	DWORD Instructions[ ARRAYSIZE( JumpASMNoPreserve ) ];
	memcpy( Instructions, JumpASMNoPreserve, sizeof( JumpASMNoPreserve ) );
	Instructions[ 0 ] |= ADDRESS_HIGHER( (UINT)target );
	Instructions[ 1 ] |= ADDRESS_LOWER( (UINT)target );
	memcpy((void*)addr,Instructions,sizeof(Instructions));
}
void Hook::DataSection_R_ReHook(void* original,void* target){
	UINT64 addr = 0x31000;
	addr+=(UINT64)original+0xFFCF000;
	DWORD dw;
	BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)addr,24,4,&dw);	
	DWORD Instructions[ ARRAYSIZE( JumpASMNoPreserveI ) ];
	memcpy( Instructions, JumpASMNoPreserveI, sizeof( JumpASMNoPreserveI ) );
	Instructions[ 0 ] |= ADDRESS_HIGHER( (UINT)target );
	Instructions[ 1 ] |= ADDRESS_LOWER( (UINT)target );
	memcpy((void*)addr,Instructions,sizeof(Instructions));
}
void Hook::WriteBytesDATASection(void* original,DWORD DATA[]){
	UINT64 addr = 0x31000;
	addr+=(UINT64)original+0xFFCF000;
	DWORD dw;
	for (int i = 0;i<(sizeof(DATA)/sizeof(DWORD));i++){
		DWORD DATAX[] = {DATA[i]};
		BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)(addr+(i*4)),4,4,&dw);	
		memcpy((void*)(addr+(i*4)),DATAX,sizeof(DATAX));
	}
}


void Hook::WriteNOP(void* original,int count){
	UINT64 addr = XEX_PC_HEADER;
	addr+=(UINT64)original+HOOK_VALUE;
	DWORD dw;
	DWORD DATA[] = {0x60000000};
	for (int i = 0;i<count;i++){
		BOOL ok = VirtualProtectEx(GetModuleHandle(0),(void*)(addr+(i*4)),4,4,&dw);	
		memcpy((void*)(addr+(i*4)),DATA,sizeof(DATA));
	}
}

void Hook::WriteNOPNEw(void* original,int count){
	DWORD need[] = {0x60000000};
	for (int i = 0;i<count;i++){
		WriteBytes((void*)((DWORD)original+(i*4)),need);
	}
}

void Hook::WriteBytes(void* original,DWORD DATA[],size_t length){
	UINT64 addr = XEX_PC_HEADER;
	addr+=(UINT64)original+HOOK_VALUE;
	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)addr,length,4,&dw);
	memcpy((void*)addr,DATA,length);	
	VirtualProtectEx(GetModuleHandle(NULL),(void*)addr,length,dw,&dw);
}

void Hook::WriteByte(void* original,BYTE b){
	UINT64 addr = XEX_PC_HEADER;
	addr+=(UINT64)original+HOOK_VALUE;
	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)addr,1,1,&dw);
	BYTE tz[] = {b};
	memcpy((void*)addr,tz,1);	

}

void Hook::WriteDword(void* original,DWORD target){
	DWORD bt[] = {target};
	Hook::WriteBytes(original,bt,sizeof(bt));
}

void Hook::WriteHook(void* original,void* target,Type tp){

	UINT64 addr =((UINT64)original)+HOOK_VALUE+ XEX_PC_HEADER;
	DWORD dw;
	BOOL ok = VirtualProtectEx(GetModuleHandle(NULL),(void*)addr,24,4,&dw);	
	DWORD Instructions[ ARRAYSIZE( JumpASMNoPreserve ) ];
	if (tp == NoReturn){
	memcpy( Instructions, JumpASMNoPreserve, sizeof( JumpASMNoPreserve ) );
	}
	else{
		memcpy( Instructions, JumpASMNoPreserveI, sizeof( JumpASMNoPreserve ) );
	}

	Instructions[ 0 ] |= ADDRESS_HIGHER( (UINT)target );
	Instructions[ 1 ] |= ADDRESS_LOWER( (UINT)target );
	memcpy((void*)addr,Instructions,sizeof(Instructions));
	
	DWORD ou;
	ok = VirtualProtectEx(GetModuleHandle(NULL),(void*)addr,24,dw,&ou);

}

