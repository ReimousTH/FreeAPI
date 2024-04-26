#include "DLL_LUA.h"



extern "C" int LUA__GLOBAL__WriteVirtualBytes(lua_State* L){

	int nargs = lua_gettop(L);
	if (nargs < 2) return 0;
	std::stringstream conv;
	DWORD StartOffset,LastOffset;
	const char* StartOffsetS = lua_tostring(L,1);
	const char* ByteArrayString = lua_tostring(L,2);
	conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
	std::string ByteArrayStringR = std::string(ByteArrayString);
	ByteArrayStringR.erase(std::remove( ByteArrayStringR.begin(),
		ByteArrayStringR.end(),
		' '),
		ByteArrayStringR.end());
	int len  = ByteArrayStringR.length();
	if (len % 2 != 0){ //Add Extra Zero
		ByteArrayStringR.append("0");
	}
	const char* cu = ByteArrayStringR.c_str();
	byte* bt = new byte[strlen(cu)/2];
	char buff[2] = {0,0};
	for (int i =0 ;i<strlen(cu)/2;i++){
		memcpy((void*)&buff,(void*)((unsigned int)cu + (i*2)),2);
		bt[i] = (unsigned int)(strtoul(buff,NULL,16));

	}	

	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,1,&dw);
	memcpy((void*)ADDR(StartOffset),bt,strlen(cu)/2);
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,dw,&dw);

	free(bt);
	return 0;
}

extern "C" int LUA__GLOBAL__WriteVirtualBytesRange(lua_State* L){

	int nargs = lua_gettop(L);
	if (nargs < 2) return 0;
	std::stringstream conv;
	DWORD StartOffset,EndOffset,LastOffset;
	const char* StartOffsetS = lua_tostring(L,1);
	const char* EndOffsetS = lua_tostring(L,2);
	const char* ByteArrayString = lua_tostring(L,3);
	conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
	conv << std::hex << EndOffsetS; conv >> EndOffset; conv.clear(); 	conv.str("");
	std::string ByteArrayStringR = std::string(ByteArrayString);

	ByteArrayStringR.erase(std::remove( ByteArrayStringR.begin(),
		ByteArrayStringR.end(),
		' '),
		ByteArrayStringR.end());


	int len  = ByteArrayStringR.length();
	if (len % 2 != 0){ //Add Extra Zero
		ByteArrayStringR.append("0");
	}
	const char* cu = ByteArrayStringR.c_str();
	byte* bt = new byte[strlen(cu)/2];
	char buff[2] = {0,0};
	for (int i =0 ;i<strlen(cu)/2;i++){
		memcpy((void*)&buff,(void*)((unsigned int)cu + (i*2)),2);
		bt[i] = (unsigned int)(strtoul(buff,NULL,16));

	}	
	DWORD dw;

	for (int i = StartOffset; i<EndOffset;i+=strlen(cu)/2 ){
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,1,&dw);
		memcpy((void*)ADDR(i),bt,strlen(cu)/2);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,dw,&dw);
	}
	free(bt);

	return 0;
}

extern "C" int LUA__GLOBAL__WriteVirtualFloat(lua_State* L){
	int nargs = lua_gettop(L);
	if (nargs < 2) return 0;
	std::stringstream conv;
	DWORD StartOffset,LastOffset;

	if (lua_type(L,1) == LUA_TNUMBER){
		StartOffset = lua_tonumber(L,1);
	}
	//STRING
	else{
		const char* StartOffsetS = lua_tostring(L,1);
		conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
	}

	float FloatValue = (float)lua_tonumber(L,2);

	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
	memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,4);
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
	return 0;
}
extern "C" int LUA__GLOBAL__WriteVirtualDWORD(lua_State* L){
	int nargs = lua_gettop(L);
	if (nargs < 2) return 0;
	std::stringstream conv;
	DWORD StartOffset,LastOffset;
	const char* StartOffsetS = lua_tostring(L,1);
	int FloatValue = (int)lua_tonumber(L,2);
	conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
	memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,4);
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
	return 0;
}
extern "C" int LUA__GLOBAL__WriteVirtualShort(lua_State* L){
	int nargs = lua_gettop(L);
	if (nargs < 2) return 0;
	std::stringstream conv;
	DWORD StartOffset,LastOffset;
	const char* StartOffsetS = lua_tostring(L,1);
	short FloatValue = (short)lua_tonumber(L,2);
	conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
	DWORD dw;
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),2,dw,&dw);
	memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,2);
	VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),2,dw,&dw);
	return 0;
}

extern "C" int LUA__GLOBAL__HEX(lua_State* L){
	const char* t = lua_tostring(L,1);

	unsigned int x;
	std::stringstream ss;
	ss << std::hex << t;
	ss >> x;
	lua_pushnumber(L,x);

	return 1;
}


extern "C" int LUA__GLOBAL__ISXBOX360(lua_State* L){
	int nargs = lua_gettop(L);
	lua_pushboolean(L,HookV2::IsNotEmulatedHardWare);
	return 1;
}



extern "C" int LUA__GLOBAL__WriteVirtualASM(lua_State* L){


	return 0;
}


// Trim leading whitespaces
std::string ltrim(const std::string &s) {
	size_t start = s.find_first_not_of(" \t\n\r\f\v");
	return (start == std::string::npos) ? "" : s.substr(start);
}

// Trim trailing whitespaces
std::string rtrim(const std::string &s) {
	size_t end = s.find_last_not_of(" \t\n\r\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// Trim both leading and trailing whitespaces
std::string trim(const std::string &s) {
	return rtrim(ltrim(s));
}

std::string replaceDoubleSpaces(std::string &str) {
	size_t found = str.find("  ");
	while (found != std::string::npos) {
		str.replace(found, 2, " ");
		found = str.find("  ", found + 1);
	}
	return str;
}

std::map<std::string, std::function<byte*(std::vector<std::string>)>> ASM_MAP;

byte* GET_LI_BYTECODE(std::vector<std::string> args){

	unsigned short arg1 = std::stoul(args[1],0,16);

	return 0;
}


extern "C" int LUA__GLOBAL__WriteVirtualHOOK(lua_State* L){


	ASM_MAP[std::string("li")] = GET_LI_BYTECODE;








	const char* str = lua_tostring(L,2);

	
	std::stringstream ss(str);
	std::string token;
	std::string token2;
	std::vector<std::string> tokens;

	while (std::getline(ss, token, '\n')) {
		tokens.push_back(replaceDoubleSpaces(trim(token)));

	}

	std::vector<std::string>::iterator it;
	std::vector<std::string> args;
	
	for (it = tokens.begin();it!=tokens.end();it++){
		args.clear(); //each line
		ss = std::stringstream(*it);

		while (std::getline(ss, token, ' ')) {
			args.push_back(token);
			ss = std::stringstream(token);
			
		

		}
		std::string OP_CODE = args[0]; //
		
	




	}




	return 0;
}



void ZLuaN::OpenLuaRaw()
{
	L = lua_open();
}

void ZLuaN::OpenLua()
{
	L = lua_open();
	luaopen_base(L);
	luaopen_math(L);
	luaopen_table(L);
	luaopen_string(L);
	//luaopen_io(L);
}

void ZLuaN::OpenLuaMy()
{
	lua_register(L,"WriteVirtualBytes",LUA__GLOBAL__WriteVirtualBytes);
	lua_register(L,"WriteVirtualBytesRange",LUA__GLOBAL__WriteVirtualBytesRange);

	lua_register(L,"WriteVirtialBytes",LUA__GLOBAL__WriteVirtualBytesRange);
	lua_register(L,"WriteVirtialBytesRange",LUA__GLOBAL__WriteVirtualBytesRange);

	lua_register(L,"WriteVirtualFloat",LUA__GLOBAL__WriteVirtualFloat);
	lua_register(L,"WriteVirtualShort",LUA__GLOBAL__WriteVirtualShort);
	lua_register(L,"WriteVirtualDword",LUA__GLOBAL__WriteVirtualDWORD);
	lua_register(L,"IsXbox360",LUA__GLOBAL__ISXBOX360);
	lua_register(L,"HEX",LUA__GLOBAL__HEX);
	lua_register(L,"WriteASM",LUA__GLOBAL__WriteVirtualASM);





}

void ZLuaN::LoadLua(const char* file)
{
	

	int error = luaL_loadfile(L,file);

	if (error != 0){
		error_msg = lua_tostring(L,-1);
		lua_pop(L,1);
		ShowXenonMessage(L"MSG",error_msg);
		while (true) {}
		
	}
	else{
		lua_pcall(L,0,LUA_MULTRET,0);
	}

	


	return;
}

const char* ZLuaN::GetGlobalString(const char* str)
{
	lua_getglobal(L,str);
	if (lua_isstring(L,-1)){
		return lua_tostring(L,-1);
	}
	else{
		return "";
	}
}

bool ZLuaN::GetGlobalBoolean(const char* str)
{
	lua_getglobal(L,str);
	if (lua_isboolean(L,-1)){
		return lua_toboolean(L,-1);
	}
	else{
		return false;
	}
}

int ZLuaN::GetGlobalIntNew(const char* st,bool useglobal = true)
{
	int num = 0;
	int result = 0;
	char* str = new char(strlen(st));
	strcpy(str,st);
	std::vector<char*> v;
	char* chars_array = strtok(str, ".");
	while(chars_array)
	{
		v.push_back(chars_array);
		chars_array = strtok(NULL, ".");
	}


	for(size_t n = 0; n < v.size(); ++n)
	{
		lua_pushstring(L,v[n]);
		if (n == 0 && useglobal){

			lua_gettable(L,LUA_GLOBALSINDEX);
		}
		else{
			lua_gettable(L,-2);
		}
		bool fail = false;


	}



	result = (int)lua_tonumber(L,-1);

	lua_settop(L,lua_gettop(L)-v.size()); //Clear Stack From My ACtios
	// ShowXenonMessage(L"MSG",result,0);

	return result;

}

bool ZLuaN::EnableDebugOutput = false;

ZLuaN CommonLua = ZLuaN();
void DLL_LUA_INSTALL()
{
	
	CommonLua.OpenLua();
	CommonLua.OpenLuaMy();
	CommonLua.LoadLua("game:\\common\\test.lua");

	
}
