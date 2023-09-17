#ifndef PatchDataCPP
#define PatchDataCPP
#include "Hook.h"
#include "Basics.h"
#include "All06Functions.h"
#include "IdaExports.h"
#include "RidersFree.h"



#include "AtgInput.h"
#include "AtgUtil.h"
//#include <boost/make_shared.hpp>
#include <Xboxmath.h>






DWORD DPAD_LEFT_RING = false;
DWORD DPAD_RIGHT_RING = false;
DWORD MENU_BUTTON_A = false;
DWORD MENU_BUTTON_Y = false;
DWORD ShowUI = false;
DWORD ForcePauseGame = false;

DWORD P1Slot = 0;
DWORD P2Slot = 1;

const byte ConnectSessionID[8] = {0,0,0,0,0,0,0,0};



ZLua CommonLua = ZLua("game:\\common\\test.lua");


static ATG::GAMEPAD* gc = &ATG::Input::m_Gamepads[P1Slot];
static ATG::GAMEPAD* gc2P = &ATG::Input::m_Gamepads[P2Slot];



std::vector<byte> GetIPHelper(const char* st){

	int num = 0;
	int result = 0;
	char* str = new char(strlen(st));
	strcpy(str,st);
	std::vector<byte> v;
	char* chars_array = strtok(str, ".");
	while(chars_array)
	{
		v.push_back((byte)(strtoul(chars_array,NULL,10)));
		chars_array = strtok(NULL, ".");

	}
	return v;

}




void SetSessionIP(){

	const char* str =CommonLua.GetGlobalString("ConnectSessionID");
	std::vector<byte> IP_VEC = GetIPHelper(CommonLua.GetGlobalString("ConnectIP"));
	

	std::stringstream conv;
	const char* ByteArrayString = str;
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
		memcpy((void*)&buff,(void*)((uint)cu + (i*2)),2);
		bt[i] = (uint)(strtoul(buff,NULL,16));

	}




	XINVITE_INFO* t = (XINVITE_INFO*)(XNLiveSomeStatic + 0x67);
	memcpy((void*)t->hostInfo.sessionID.ab,bt,8);
	t->dwTitleID = 0x5345084D;
	t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b1 = IP_VEC[0];
	t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b2 = IP_VEC[1];
	t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b3 = IP_VEC[2];
	t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b4 = IP_VEC[3];
	t->hostInfo.hostAddress.wPortOnline = 36000;
	t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b1 = IP_VEC[0];
	t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b2 = IP_VEC[1];
	t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b3 = IP_VEC[2];
	t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b4 = IP_VEC[3];





}







namespace DebugLogRestore{

	struct tust{
		char* s1;
		DWORD a2;


	};










	std::vector<std::string*> log;

	struct TX06Zero{
		char* Animation;
		int Type;
		int value;
		int time;
	};

	extern "C" void PrintTable(lua_State *L,std::string* stri,int zx = 0)
	{
		lua_pushnil(L);

		while(lua_next(L, -2) != 0)
		{
			if(lua_isstring(L, -1)){
				stri->append(lua_tostring(L, -2));
				stri->append("=");
				stri->append(lua_tostring(L, -1));
				stri->append(" ");

			}
			else if(lua_isnumber(L, -1)){
				stri->append(lua_tostring(L, -2));
				stri->append("=");

				int a = lua_tonumber(L,-1);
				std::stringstream ss;
				ss << a;

				stri->append(ss.str());
				stri->append(" ");
			}
			else if(lua_istable(L, -1))
			{
				//	stri->append(lua_tostring(L, -2));
				//	lua_tonumber(L,-1);

				//	lua_getfield())

				stri->append("={\n");
				PrintTable(L,stri,zx+1);
				stri->append("\n}\n");



			}
			else//MB
			{
				return;
			}

			lua_pop(L, 1);
		}

	}



	extern "C" static int XenonMessage(lua_State* L,std::string** so){


		int ltype = lua_type(L,-1);

		std::stringstream ss;
		TX06Zero zx;




		*so = new std::string("Type : ?? ");
		//so->append(std::to_string(ltype));

		switch (ltype){
			case LUA_TNIL:
				*so = new std::string("NIL");
				break;
			case LUA_TBOOLEAN:
				*so = new std::string(lua_toboolean(L,1) == true ? "true" : "false");
				break;
			case LUA_TLIGHTUSERDATA:

				//				so = new std::string("LightTable : \n{\n");
				//				PrintTable(L,so);

luabridge:
				//	so = new std::string("N");

				//				so->append("\n}");

				break;
			case LUA_TNUMBER:
			case LUA_TSTRING:
				*so = new std::string(lua_tostring(L,-1));
				break;
			case LUA_TTABLE:

				*so = new std::string("Table Not Supported");
				//		PrintTable(L,so);

				//lua_pushstring(L,"__tostring");

				//	so = new std::string("N");

				//	so->append("\n}");
				//so->insert(0," : ");

				break;
			case LUA_TFUNCTION:
				*so = new std::string("Not Supported LUA_TFUNCTION");
				break;
			case LUA_TUSERDATA:
				//	static_cast<int*>(lua_to(L, -3));
				*so = new std::string("Not Supported LUA_TUSERDATA");
				break;
			case LUA_TTHREAD:
				*so = new std::string("Not Supported LUA_TTHREAD");
				break;


		}



		return 0;
	}


	static int luaB_print (lua_State *L) {

		int n = lua_gettop(L);  /* number of arguments */
		int i;
		lua_getglobal(L, "tostring");
		for (i=1; i<=n; i++) {
			const char *s;
			lua_pushvalue(L, -1);  /* function to be called */
			lua_pushvalue(L, i);   /* value to print */
			lua_call(L, 1, 1);
			s = lua_tostring(L, -1);  /* get result */
			if (s == NULL)
				return luaL_error(L, "`tostring' must return a string to `print'");

			log.push_back(new std::string(s));

			//if (i>1) fputs("\t", stdout);
			//fputs(s, stdout);
			lua_pop(L, 1);  /* pop result */
		}
		fputs("\n", stdout);
		return 0;
	}



	extern "C" static int  Log(lua_State* L){



		std::string* so = new std::string();
		XenonMessage(L,&so);


		log.push_back(so);


		return 0;

	}



	static const luaL_reg tx2[] = {
		{"print", Log},



		{NULL, NULL}
	};

	static tust tx3[] = {

		{"math",0x825DB498},
		{"script",0x82639830},
		{"level",0x825D9660},
		{
			NULL,NULL
		}
	};



	static tust tx[] = {

		{"SetPlayer",0x82462948},
		{"StartEntityByName",0x824632A0},
		{"Signal",0x82463370},
		{"PlayBGM",0x824623D8},
		{"StopBGM",0x82462430},
		{"SetGenArea",0x82462A50},
		{"LoadTerrain",0x82462460},
		///	{"LoadTerrain",0x82462460},
		{"LoadSky",0x82463CB0},
		{"LoadStageSet",0x824624E8},
		{"LoadPath",0x82462548},
		{"LoadParticle",0x824626A8},
		{"LoadSceneParams",0x82463FE0},
		{"LoadLight",0x82464070},
		{"LoadSceneEnvMap",0x82464100},
		{"LoadReflectionAreas",0x82464190},
		{"LoadSoundBank",0x82462710},
		{"LoadVoiceBank",0x82462770},
		{"LoadCameraParam",0x82463D48},
		{"LoadRenderScript",0x82463DE0},
		{"LoadKynapse",0x82463E70},
		{"LoadTownsmanInfo",0x82463F28},
		{"LoadRaderMap",0x82464210},
		{"LoadObjectPhysics",0x824642A0},
		{"LoadExplosion",0x82464330},
		{"LoadEnemy",0x824643C0},
		{"LoadShot",0x82464450},
		{"DebugCommand",0x824649E0},
		{"LoadTimeLight",0x82464948},
		{"ProcessMessage",0x824627D0},
		{"InternalMessage",0x82462810},
		{"SeparateRenderAndExecute",0x82462850},
		{"SetAreaName",0x824644E0},
		{"PlayerIndexToActorID",0x82AD0700},
		{"LoadPEBank",0x82AD0700},
		{"PreloadPlayer",0x82AD0700},
		{"LoadCameraLib",0x82AD0700},
		{"LoadCameraSet",0x82AD0700},
		{"LoadEntityLib",0x82AD0700},
		{"CreateCameraTornado",0x82AD0700},
		{"CreateObjInfo",0x82AD0700},
		{"NewActor",0x82AD0700},
		{"LoadEvent",0x82AD0700},
		{"ChangeArea",0x82AD0700},
		{"SetupWorld",0x82AD0700},
		{"DestroyWorld",0x82AD0700},
		{"StartPlaying",0x82AD0700},
		{"Retry",0x82AD0700},
		{"End",0x82AD0700},
		{"Log",(DWORD)Log},
		{
			NULL,NULL
		}

	};

	extern "C" static int  LogNext(lua_State* L){


		std::string* so = new std::string();
		XenonMessage(L,&so);

		ShowXenonMessage(L"LogNext",so->c_str());


		return 0;

	}
	bool Showed = false;
	extern "C" static int  FixedMessage(lua_State* L){


		//	std::string* so = new std::string();
		//	XenonMessage(L,&so);

		//	MESSAGEBOX_RESULT result;
		//	XOVERLAPPED m_Overlapped; 

		//	XShowMessageBoxUI(0,L"FixedMessage",convertCharArrayToLPCWSTR(so->c_str()),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);


		return 0;
	}

	//For Pointer* Work
	extern "C" static int GetIntField(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		//	if (lua_isnumber())
		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int endz = *(int*)(Struct + Value);

		lua_pushnumber(L,endz);



		return 1;
	}

	extern "C" static int GetFloatField(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		//	if (lua_isnumber())
		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int endz = *(float*)(Struct + Value);

		lua_pushnumber(L,endz);



		return 1;
	}

	extern "C" static int SetIntField(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int Setter = (int)lua_tonumber(L,3);
		*(int*)(Struct + Value) = Setter;




		return 0;
	}

	extern "C" static int BuildNewState(lua_State* L){




		return 0;

	}
	extern "C" static int WriteVirtialDword(lua_State* L){

		return 0;
	}


	extern "C" static int StateChangeState(lua_State* L){


		return 1;


	}

	//Replace Custom State

	//Suported Only Pointers,Floats,INTS


	extern "C" int ArgumentsAnalys(lua_State* L,int i,int* a){

		switch (lua_type(L,i)){

			case LUA_TNUMBER:
				a[i-2]=(lua_tonumber(L,i)); //ADD ARGUMENT
				//	ShowXenonMessage(L"S",a[i-1],"");
				break;
			case LUA_TUSERDATA:
				break;
			case  LUA_TNIL:
				break;
			case LUA_TSTRING:
				a[i-2]=((int)lua_tostring(L,i));
				break;

		}


		return 0;
	}
	extern "C"  void __declspec( naked ) _cdecl CallCPLUSFuncHELPER(){
		__asm{
			lwz r9,24(r12)
				lwz r8,20(r12)
				lwz r7,16(r12)
				lwz r6,12(r12)
				lwz r5,8(r12)
				lwz r4,4(r12)
				lwz r3,0(r12)
				blr
		}
	}


	extern "C" static int HEX(lua_State* L){


		const char* t = lua_tostring(L,1);
		unsigned int x;
		std::stringstream ss;
		ss << std::hex << t;
		ss >> x;
		ss.str("");
		lua_pushnumber(L,x);

		return 1;

	}
	std::vector<int> malloc_buffer;
	extern "C" static int MallocX(lua_State* L){


		int size = lua_tonumber(L,1);
		DWORD x = (DWORD)malloc(size);



		lua_pushnumber(L,x);

		return 1;

	}
	extern "C" static int NewString(lua_State* L){


		std::string* x = new std::string(lua_tostring(L,1));

		lua_pushnumber(L,(int)x);

		return 1;

	}
	extern "C" static int FreeString(lua_State* L){


		std::string* x = (std::string*)(int*)(int)lua_tonumber(L,1);

		delete x;

		return 0;

	}
	extern "C" static int FreeX(lua_State* L){


		int x = lua_tonumber(L,1);
		free((void*)x);
		return 0;

	}


	//Arguments is r3,r4,r5,r6,r7,r8,r9 //LIMIT Bigger Count using stack  and pointers
	extern "C" static int CallCPLUSFunc(lua_State* L){

		int nargs = lua_gettop(L); //Arguments Count
		DWORD offset = lua_tonumber(L,1); //NUM
		DWORD ARGStack[10];
		DWORD result = 0;
		//PUSH ARGS
		for (int i= 0;i<10;i++){
			ARGStack[i]= 0;
		}
		for (int i = 2;i<=nargs;i++){

			ArgumentsAnalys(L,i,(int*)&ARGStack);
		}

		const DWORD word = (DWORD)&ARGStack; // VALUE
		__asm{
			mr r12,word 

		};
		CallCPLUSFuncHELPER();
		BranchTo(offset,int);
		_asm{
			mr result,r3
		}
		lua_pushnumber(L,result);	
		return 1;
	}

	extern "C" static int SonicTeam_EffectModule_HideEffect(lua_State* L){

		int argc = lua_gettop(L);
		//1 self

		int SSGroup = (int)lua_tonumber(L,2);
		DWORD v7[2];
		v7[0]=0;
		v7[1]=0;
		BranchTo(0x8221F3C8,void,SSGroup,v7);
		return 0;


	}



	extern "C" static int SonicTeam_EffectModule_RunEffect(lua_State* L){


		int argc = lua_gettop(L);
		//1 self
		int SSModule = (int)lua_tonumber(L,2);
		int SSGroup = (int)lua_tonumber(L,3);
		int SSParticle = (int)lua_tonumber(L,4);

		if (*(int*)(SSGroup+4) || *(int*)(SSGroup)) return 0;
		int sxz = SSModule +0x4A0; 
		sxz = SSParticle;
		DWORD _RS[3];
		int res = BranchTo(0x82225BD8,int,
			_RS,
			(__int64)(SSModule+0xC), //r3
			*((__int64*)(sxz)), // 0x2F4 (r4)
			*((__int64*)(sxz+0x8)), //  (r5)
			*((__int64*)(sxz+0x10)), //  (r6)
			(__int64)*((int*)(sxz+0x18)), //  (r7)	
			((__int64)(SSModule+0x488)) //  (r8)
			);
		BranchTo(0x8221F3C8,int,SSGroup,res);
		if ( _RS[1] )
			sub_821601B8(_RS[1]);


		return 0;

	}

	extern "C" static int BitBase(lua_State*L,int cs){

		int v1 = lua_tonumber(L,2);
		int v2 = lua_tonumber(L,3);
		int result = 0;
		switch (cs){

			case 0:
				result = v1 << v2;
				break;
			case 1:
				result = v1 >> v2;
				break;
			case 3:
				result = v1 & v2;
				break;
			case 4:
				result = v1 | v2;
				break; 

			default:
				lua_pushnil(L);
				return 1;
		}
		lua_pushnumber(L,result);
		return 1;
	}

	extern "C" static int BIT_ShiftLeft(lua_State* L){
		return BitBase(L,0);

	}
	extern "C" static int BIT_ShiftRight(lua_State* L){
		return BitBase(L,1);

	}
	extern "C" static int BIT_AND(lua_State* L){
		return BitBase(L,3);

	}
	extern "C" static int BIT_OR(lua_State* L){
		return BitBase(L,4);

	}



	std::map<int,std::vector<int>> EffectMapJoiner;
	extern "C" static int ConnectEffectModuleFunc(lua_State* L){


		int argc = lua_gettop(L);
		//	if (argc < 1 ) return 0;
		//int arg1 = lua_tonumber(L,1); // self 
		int arg1 = lua_tonumber(L,2); // arg1
		int arg2 = (int)lua_topointer(L,3); //arg 2

		// setup callback
		lua_pushvalue(L, 3);
		int ref = luaL_ref(L, LUA_REGISTRYINDEX);
		//ShowXenonMessage(L"MSG",luaL_ref(L,LUA_REGISTRYINDEX),"");


		EffectMapJoiner[arg1].push_back(ref);
		return 0;
	}
	std::map<int,std::vector<int>> ContextMapJoiner;
	extern "C" static int ConnectContextModuleFunc(lua_State* L){

		int argc = lua_gettop(L);
		//	if (argc < 1 ) return 0;
		//int arg1 = lua_tonumber(L,1); // self 
		int arg1 = (int)lua_tonumber(L,2); // arg1


		// setup callback
		lua_pushvalue(L, 3);
		int ref = luaL_ref(L, LUA_REGISTRYINDEX);
		//ShowXenonMessage(L"MSG",luaL_ref(L,LUA_REGISTRYINDEX),"");


		ContextMapJoiner[arg1].push_back(ref);
		return 0;
	}

	const char po[] = "game:\\common\\";
	const polen = sizeof(po);
	extern "C" static int LuaDoFile(lua_State* L){

		int argc = lua_gettop(L);
		if (argc < 1 ) return 0;
		const char* arg1 = lua_tostring(L,1);
		int len = strlen(arg1);


		std::string* bruh = new std::string();
		bruh->append(po);
		bruh->append(arg1);
		const char* n = bruh->c_str();


		//	memcpy(n+strlen(po),arg1,strlen(arg1));

		const char* pdata;

		//HRESULT resu  = ATG::LoadFile(n,(void**)&pdata);

		//ShowXenonMessage(L"",n);
		//lua_dostring(L,pdata);
		luaL_dofile(L,n);


		//free(n);


		return 0;
	}

	//Arguments is r3,r4,r5,r6,r7,r8,r9 //LIMIT Bigger Count using stack  and pointers
	extern "C" static int CallCPLUSFuncF(lua_State* L){

		int nargs = lua_gettop(L); //Arguments Count
		DWORD offset = lua_tonumber(L,1); //NUM
		DWORD ARGStack[10];
		DWORD result = 0;
		//PUSH ARGS
		for (int i= 0;i<10;i++){
			ARGStack[i]= 0;
		}
		for (int i = 2;i<=nargs;i++){

			ArgumentsAnalys(L,i,(int*)&ARGStack);
		}

		const DWORD word = (DWORD)&ARGStack; // VALUE
		__asm{
			mr r12,word 

		};
		CallCPLUSFuncHELPER();
		BranchTo(offset,float);
		_asm{
			mr result,r3
		}
		lua_pushnumber(L,result);	
		return 1;
	}


	//Replace State (Will be Renamed soon)
	extern "C" static int AddCustomState(lua_State* L){




		return 0;
	}


	extern "C" static int WriteVirtialBytesRange(lua_State* L){
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
			memcpy((void*)&buff,(void*)((uint)cu + (i*2)),2);
			bt[i] = (uint)(strtoul(buff,NULL,16));

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

	extern "C" static int WriteVirtialFloat(lua_State* L){
		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,LastOffset;

		if (lua_type(L,-1) == LUA_TNUMBER){
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


	}

	extern "C" static int WriteVirtialInt(lua_State* L){
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


	}
	extern "C" static int WriteVirtialShort(lua_State* L){
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


	}

	extern "C" static int WriteVirtialBytes(lua_State* L){

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
			memcpy((void*)&buff,(void*)((uint)cu + (i*2)),2);
			bt[i] = (uint)(strtoul(buff,NULL,16));
	
		}	
		DWORD dw;
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,1,&dw);
		memcpy((void*)ADDR(StartOffset),bt,strlen(cu)/2);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,dw,&dw);


		//Free Buffer
		free(bt);




		return 0;

	/*	const char* offsetS = lua_tostring(L,1);
		std::stringstream ss;
		ss << std::hex << offsetS;
		DWORD offset = 0;
		ss >> offset;
		const char* si = lua_tostring(L,2);
		int sv = strlen(si);
		for (int i = 0;i<sv;i+=2){
			unsigned int x;
			unsigned int x1;
			ss.clear();
			ss << std::hex << si[i];
			ss >> x;
			ss.clear();
			ss << std::hex << si[i+1];
			ss >> x1;
			BYTE byte3 = x<< 4 | x1;
			Hook::WriteByte((void*)(offset+(i/2)),byte3);
		}



		return 0;
		*/
	}
	extern "C" static int WriteVirtualString(lua_State* L){

		return 0;
	}


	extern "C" static int SetFloatValue(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);


		float Setter = lua_tonumber(L,3);

		*(float*)(Struct + Value) = Setter;




		return 0;
	}


	extern "C" static int Memory_GetHelper(lua_State* L,int cases){


		int args = lua_gettop(L);
		if (args < 2){
			lua_pushnil(L);
			return 1;
		}
		int arg1 = lua_tonumber(L,2); //Memory Address


		switch (cases){

			case 0:
				lua_pushnumber(L,(int)*(_BYTE*)arg1);
				break;
			case 1:
				lua_pushnumber(L,*(int*)arg1);
				break;



			default:
				lua_pushnil(L);

		}

		return 1;
	}
	extern "C" static int Memory_SetHelper(lua_State* L,int cases){


		int args = lua_gettop(L);
		if (args < 3){
			lua_pushboolean(L,false);
			return 1;
		}
		int arg1 = lua_tonumber(L,2); //Memory Address
		int arg2 = lua_tonumber(L,3); //value
		bool result = true;

		switch (cases){

			case 0:
				*(byte*)arg1 = (byte)arg2;
				break;
			case 1:
				*(int*)arg1 = (int)arg2;
				break;
			default:
				lua_pushnil(L);
				result = false;

		}

		lua_pushboolean(L,result);
		return 1;
	}
	extern "C" static int Memory_WriteByte(lua_State* L){

		return Memory_SetHelper(L,0);
	}
	extern "C" static int Memory_WriteInt(lua_State* L){

		return Memory_SetHelper(L,1);
	}


	extern "C" static int Memory_GetByte(lua_State* L){

		return Memory_GetHelper(L,0);
	}
	extern "C" static int Memory_GetInt(lua_State* L){

		return Memory_GetHelper(L,1);
	}



	const char* GM = "Game";




	DWORD WINAPI ThreadProcX( LPVOID lpParameter )
	{

		DWORD dwThreadNumber = (DWORD) lpParameter;



		while (true){

			//ATG::GAMEPAD* gc = ATG::Input::GetMergedInput(0);

			if (!gc) continue;

			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP){
				std::string* si = new std::string();
				for (int i = 0;i<log.size();i++){
					si->append(*log[i]);
					si->append("\n");
				}

				MESSAGEBOX_RESULT result;
				XOVERLAPPED m_Overlapped; 
				XShowMessageBoxUI(0,L"Debug.Log(Result)",convertCharArrayToLPCWSTR(si->c_str()),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);

				while (result.dwButtonPressed != 0){


				}
				Sleep(1000);




			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
				CommonLua.DoFile(true);
			}


			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN){

				for (int i = 0;i<log.size();i++){
					delete log[i];
				}


				log.resize(0);
			}


		}


		return 0;
	}









	void GlobalInstall(){
		CommonLua.DoFile(true);
		const int stackSize = 65536;
		HANDLE Thr = CreateThread( NULL, stackSize, ThreadProcX, (VOID *)0, CREATE_SUSPENDED, NULL );
		ResumeThread(Thr);
	}
}










int __fastcall sub_824BB580(int a1)
{
	return BranchTo(0x824BB580,int,a1);
}

int _set = 0;



void __fastcall TitleFunc02(int result){



	BranchTo(0x8244E2C0,void,result);

}

int __fastcall sub_824B2C48(int a1)
{

	


	*(_DWORD *)(a1 + 4) = 0;
	*(_DWORD *)(a1 + 8) = 0;
	*(_DWORD *)(a1 + 12) = 0;
	*(_DWORD *)(a1 + 16) = 2;
	*(_DWORD *)(a1 + 20) = 0;
	*(float *)(a1 + 48) = 0.0;
	*(_DWORD *)(a1 + 24) = 0;
	*(float *)(a1 + 52) = 0.0;
	*(_DWORD *)(a1 + 28) = 1;
	*(_DWORD *)(a1 + 32) = 0;
	*(_DWORD *)(a1 + 36) = 0;
	*(_DWORD *)(a1 + 40) = 0;
	*(_DWORD *)(a1 + 44) = 254;
	*(_DWORD *)(a1 + 56) = 0;
	*(_DWORD *)(a1 + 92) = 0;
	*(_DWORD *)(a1 + 96) = 0;
	*(_DWORD *)(a1 + 100) = 0;
	*(_DWORD *)(a1 + 104) = 0;




	return 0;
}

int __fastcall sub_824B0018(int a1)
{
	int v1; // r11
	int v3; // r29
	int v4; // r29
	int v5; // r30
	int v6; // r28
	int v7; // r3
	int result; // r3
	char v9; // [sp+50h] [-70h] BYREF


	v1 = *(_DWORD *)(a1 + 496);
	if ( v1 )
		(*(void (**)(void))(*(_DWORD *)v1 + 12))();
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 32))(a1);
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 36))(a1);
	v3 = BranchTo(0x82211440,int);
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 40))(a1);
	(*(void (__fastcall **)(int, int, double, double, double))(*(_DWORD *)v3 + 88))(
		v3,
		a1 + 512,
		1.0,
		1.0,
		1.0);
	(*(void (__fastcall **)(int, int, double, double, double))(*(_DWORD *)v3 + 88))(
		v3,
		a1 + 528,
		1.0,
		1.0,
		1.0);
	(*(void (__fastcall **)(int, int, double, double, double))(*(_DWORD *)v3 + 88))(
		v3,
		a1 + 544,
		1.0,
		1.0,
		1.0);
	v4 = BranchTo(0x82211440,int);
	v5 = *(_DWORD *)(a1 + 416);
	v6 = *(_DWORD *)v4;
	v7 = (*(int (__fastcall **)(int, char *, int))(*(_DWORD *)v4 + 224))(v4, &v9, a1 + 32);
	(*(void (__fastcall **)(int, int, int, int))(v6 + 252))(v4, a1 + 352, v7, v5);
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 24))(a1);
	result = (*(int (__fastcall **)(int))(*(_DWORD *)a1 + 28))(a1);
	
	return result;
}


int __declspec( naked ) XamInputGetStateLLLLTrampline(int a1){
	__asm{
		mflr r12
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0x90(r1)
			lwz       r30, 4(r3)
			lis r11,0x8222
			ori r11,r11,0xCDA8 
			mtctr r11
			bctr r11
	}
}

HOOK(int ,__fastcall ,XamInputGetStateLLLL,0x8222CD98,int a1){


	std::stringstream ss;

	ss << std::hex << a1;

//	ShowXenonMessage(L"MSG",ss.str().c_str());





	return XamInputGetStateLLLLTrampline(a1);
}

DWORD TABLE[100];

int __fastcall XamInputModuleBase(int a1)
{

	

	int v3; // r3
	unsigned __int8 v4; // r30
	int v5; // r3
	int v6; // r11
	double v7; // fp12

//	if ( (*(int (__fastcall **)(int))(*(_DWORD *)a1 + 20))(a1) != 1
//		&& !(*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)a1 + 32))(a1) )
//	{
	//	return 0;
	//}
	
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 112))(a1);
	v3 = (*(int (__fastcall **)(int))(*(_DWORD *)a1 + 116))(a1);
	v4 = v3;
	
	(*(void (__fastcall **)(int, int))(*(_DWORD *)a1 + 128))(a1, v3);
	v5 = (*(int (__fastcall **)(int))(*(_DWORD *)a1 + 28))(a1);

//	if ( XamInputGetStateL(v5, 16 * (v4 + 66) + a1) )
//		return 0;
	(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 152))(a1);// 821AB57C
		
	if ( *(_BYTE *)(a1 + 1020) && *(float *)(a1 + 1016) >= 0.0 )
	{
		
		v6 = BranchTo(0x82211440,float*)[6];
		//v7 = (float)(*(float *)(a1 + 1016) - *(float *)(v6 + 36));
		*(float *)(a1 + 1016) = *(float *)(a1 + 1016) - 0;
		//if ( v7 <= 0.0 )
			(*(void (__fastcall **)(int))(*(_DWORD *)a1 + 44))(a1);
	}
	return 1;
}
_DWORD* __fastcall sub_824C6440(_DWORD *a1){

	//ShowXenonMessage(L"MSG","MSG");


	a1[263] = 1;



	return (_DWORD*)1;
}
DWORD TABLEX[100];

HOOK(int,__fastcall,sub_82A70D30,0x82A70D30,int a1){

	return (int)&TABLEX;
}


int __declspec( naked ) sub_8223A578Tramp(int a1){
	__asm{
		mflr r12

			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			addi      r31, r1, -0x150
			stwu      r1, -0x150(r1)
			lis r11,0x8223
			ori r11,r11,0xA588 
			mtctr r11
			bctr r11
	}
}



int __fastcall sub_8270EDD0(int a1, _DWORD *a2, int a3, int a4, double a5, int a6, int a7)
{
//*(int*)a3 = 65539;
//ShowXenonMessage(L"MSG",*(int*)a3,"");

return BranchTo(0x8270EDD0,int,a1,a2,a3,a4,a5,a6,a7);
}

HOOK(int,__fastcall,sub_8223A578,0x8223A578,int a1){


	//*(int*)(a1+0x10)=3;
return sub_8223A578Tramp(a1);
}

int *__fastcall sub_82451300(int a1){


	
	return BranchTo(0x82451300,int*,a1);
}


int __fastcall sub_8244F880(int a1){



    return BranchTo(0x8244F880,int,a1);


}

DWORD WINAPI ThreadProc( LPVOID lpParameter )
{

	while (1){
		
	
	
	}
	return 0;
}
 


int __fastcall sub_82457258(int a1){
return BranchTo(0x82457258,int,a1);
}

_DWORD *__fastcall sub_824617A8(int a1){
return BranchTo(0x824617A8,_DWORD*,a1);
}


int __declspec(naked) sub_823EF348H(int result,int a2s){
	__asm{
		mflr r12
			std       r20, -0x68(r1)
			std       r21, -0x60(r1)
			std       r22, -0x58(r1)
			std       r23, -0x50(r1)
			std       r24, -0x48(r1)
			std       r25, -0x40(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stfd      fp31, -0x70(r1)
			stwu      r1, -0xC0(r1)
			lis r11,0x823E
			ori r11,r11,0xF358
			mtctr r11
			bctr
	}
}



HOOK(int,__fastcall,sub_823EF348,0x823EF348,int a1,int a2){


	DWORD result = 3;

		if (gc->wPressedButtons & XINPUT_GAMEPAD_B){
			result= 1;
		}
		else if (gc->wPressedButtons & XINPUT_GAMEPAD_X){
			result= 0;
		}
		if (result == 3){
			return sub_823EF348H(a1,a2);
		}
		
	
		return result;
}







int __fastcall sub_824578F0(struct_a11* a1, int a2, int a3){



	ItemNRElement* v33;
	//	if ( !a1->byte7D6 )
	{
		auto v31 = (int)a1 -0x24;
		int i = 0;
		sub_82454320((int)&a1[0xFFFFFFFF].gap721[0x93]);


		int c = 0;
		//1 = Main Main Menu Ring
		//2  Races and next ring,chr select and etc
		//3 Second Player Ring

		std::map<int, std::vector<DWORD>> m;
		m[0x38] = std::vector<DWORD>();
		m[0x39] = std::vector<DWORD>();
		m[0x3A] = std::vector<DWORD>();
		//Seach Mode
		for ( i = *(_DWORD *)(v31 + 0x50); i != *(_DWORD *)(v31 + 0x54); i += 8 ){
			auto RingElement = *(struct_UIRingController**)i;
			if (m.find(RingElement->Tag1) != m.end()){
				m[RingElement->Tag1].push_back((DWORD)RingElement);
			}
		}

		for ( i = *(_DWORD *)(v31 + 0x50); i != *(_DWORD *)(v31 + 0x54); i += 8 ){

			auto RingElement = *(struct_UIRingController**)i;
			if ((m.find(RingElement->Tag1) != m.end()))
			{
				auto r =  m[RingElement->Tag1];
				auto it = find(r.begin(),r.end(),(DWORD)RingElement);
				int index = it - r.begin();
				if (m[RingElement->Tag1].size() >= 2 && (index == 1 || index == 3) ){
				
					for ( int j = RingElement->dword12C; j != RingElement->dword130; j += 8 ){
						auto NR = *(ItemNRElement**)j;
						DWORD result = NR->dword11C;
						if (gc2P->wPressedButtons & XINPUT_GAMEPAD_A){
							if ((NR->ItemState & 0xF) == 0){

								*(_DWORD *)(4 * (((*(_DWORD *)(NR->dword11C + 0x140) >> 4) & 1) + 0x20) + NR->ParentOrMainMenuNRInstance) = (DWORD)NR;
								MAINMENUBIGSUB(
									NR->ParentOrMainMenuNRInstance,
									(struct_a2 *)NR ,
									(*(_DWORD *)(NR->dword11C + 0x140) >> 4) & 1);

							}
						}
					}
				}
				if (m[RingElement->Tag1].size() >= 2 && (index == 0 || index == 2) ){
					for ( int j = RingElement->dword12C; j != RingElement->dword130; j += 8 ){
						auto NR = *(ItemNRElement**)j;
						DWORD result = NR->dword11C;

						if (gc->wPressedButtons & XINPUT_GAMEPAD_A){

							if ((NR->ItemState & 0xF) == 0){

								*(_DWORD *)(4 * (((*(_DWORD *)(NR->dword11C + 0x140) >> 4) & 1) + 0x20) + NR->ParentOrMainMenuNRInstance) = (DWORD)NR;
								MAINMENUBIGSUB(
									NR->ParentOrMainMenuNRInstance,
									(struct_a2 *)NR ,
									(*(_DWORD *)(NR->dword11C + 0x140) >> 4) & 1);


							}
						}
					}
				}
			}
		}
	}





	return BranchTo(0x824578F0,int,a1,a2,a3);
}

int __fastcall sub_822340D0(int a1){

	

	return BranchTo(0x822340D0,int,a1);

}

//Can Break Render //wut
HOOK(int,__fastcall,sub_824E69A8,0x824E69A8,int a1,char a2){


  //*(_QWORD *)(a1 + 16) = 1;
	return BranchTo(0x824E69A8,int,a1,a2);
	return 0;
}

//Check If Controller Exist Or Work Maybe
HOOK(INT,__fastcall,sub_82439760,0x82439760){
return 1;
}




int first_call = 0;






float positions[] = {

	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0,
	0.0
};


//voice COMMAND 
HOOK(int,__fastcall,sub_82A54AE0,0x82A54AE0,char* a1,char* a2){

	
	int v2; // r10
	int v3; // r11
	int v4; // r9

	v2 = *(unsigned __int16 *)a2;
	v3 = *(unsigned __int16 *)a1 - v2;
	if ( *(unsigned __int16 *)a1 == v2 )
	{
		v4 = a1 - a2;
		do
		{
			if ( !v2 )
				break;
			a2 += 2;
			v2 = *(unsigned __int16 *)a2;
			ShowXenonMessage(L"MSG",v4,0);
			v3 = *(unsigned __int16 *)&a2[v4] - v2;
		}
		while ( *(unsigned __int16 *)&a2[v4] == v2 );
	}
	if ( v3 < 0 )
	{
	return -1;
	}
	
	if ( v3 > 0 ){

//		ShowXenonMessage(L"MSG","");

		v3 = 1;
	}
	return v3;


}


int __declspec(naked) sub_824A0458H(int a1){
	__asm{
		mflr      r12
		stw       r12, -8(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		lis r11,0x824A
		ori r11, r11,0x0468
		mtctr r11
		bctr
	}
}
std::stringstream sxz;
DWORD install = false;
class TestSpecial{


public: TestSpecial(){


		}

		virtual void void01(){

		}
		virtual void void02(){

		}
		virtual void void03(){

		}
		virtual void void04(){

		}
		virtual void void05(){

		}
		virtual void void07(){

		}
		virtual void void08(){

		}

};

float delta = 0;
float StickForceX = 0.0;
float StickForceY = 0.0;
float AStickForceX = 0.0;
float AStickForceY = 0.0;

#define clampf(n,lower,upper) max(lower,min(n,upper))
float clamp(float n, float lower, float upper) {
	return max(lower,min(n,upper));
//	return std::max(lower, std::min(n, upper));
}



bool AButtonHold = false;


struct NukFakeDeviceHelpers{
	bool Button_A_Hold;
	bool Button_B_Hold;
	bool Button_X_Hold;
	bool Button_LT_Hold;
	bool Button_Y_Toggle;
	bool DPAD_LEFT_RING;
	bool DPAD_LEFT_RING_RELEASED;
	short DPAD_LEFT_RING_COUNT;
	short DPAD_LEFT_RING_COUNT_PRE;
	float DPAD_LEFT_RING_TIME;


	bool DPAD_RIGHT_RING;
	bool DPAD_RIGHT_RING_RELEASED;
	short DPAD_RIGHT_RING_COUNT;
	short DPAD_RIGHT_RING_COUNT_PRE;
	float DPAD_RIGHT_RING_TIME;

	bool MENU_BUTTON_A;
	bool MENU_BUTTON_Y;
	bool Menu_START_BUTTON_PRESS;
	float StickForceX;
	float StickForceY;
	float BackHoldTime;
	float SelectHoldTime;
};


static  NukFakeDeviceHelpers NuiFakeDeviceHP1 = NukFakeDeviceHelpers();
static  NukFakeDeviceHelpers NuiFakeDeviceHP2 = NukFakeDeviceHelpers();

static  NukFakeDeviceHelpers* NuiFakeDevicePO[] = {&NuiFakeDeviceHP1,&NuiFakeDeviceHP2};


static struct_v35 NuiFakeDevice = struct_v35();
static DWORD NuiFakeDeviceEZ[4096];
static struct_dword300 NuiFakeDeviceExtra = struct_dword300();


static struct_v35 NuiFakeDeviceP2 = struct_v35();
static DWORD NuiFakeDeviceEZP2[4096];
static struct_dword300 NuiFakeDeviceExtraP2 = struct_dword300();
//static byte NuiFakeDeviceExUnk[2048];


int __declspec(naked) sub_8246A6D0H(int result,int a2s){
	__asm{
		    mflr r12
			std       r23, -0x50(r1)
			std       r24, -0x48(r1)
			std       r25, -0x40(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			addi      r12, r1, -0x50
			stfd      fp28, -0x20(r12)
			stfd      fp29, -0x18(r12)
			stfd      fp30, -0x10(r12)
			stfd      fp31, -8(r12)
			lis r11,0x8246
			ori r11,r11,0xA6E0
			mtctr r11
			bctr
	}
}

DWORD ProcessDpadMoveRing(int* a1){
	DWORD result = 0;
	int index = (*a1)-1;
	if (index == -1 ){
		index = 0;

	}

	if (NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT > 0 &&  NuiFakeDevicePO[index]->DPAD_LEFT_RING == true ){
		
		result = (int)-NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT;
		NuiFakeDevicePO[index]->DPAD_LEFT_RING = false;
		NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT = 0;
	}

	if (NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT > 0 &&  NuiFakeDevicePO[index]->DPAD_RIGHT_RING == true ){
		result = (int)NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT;
		NuiFakeDevicePO[index]->DPAD_RIGHT_RING = false;
		NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT = 0;
	}
	return result;

}

HOOK(int,__fastcall,sub_8246A6D0,0x8246A6D0,int* a1,int a2){


	DWORD v5;
	DWORD v6;
	int result = 0;

	//ShowXenonMessage(L"MSG")

	result = ProcessDpadMoveRing(a1);


	//noooooooooo

	return sub_8246A6D0H((int)a1,a2) | result;
}



int __declspec(naked) SelfViewUpdateH(int result){
	__asm{
		mflr r12
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0x80(r1)
			lis r11,0x8243
			ori r11,r11,0x8940 
			mtctr r11
			lbz       r11, 0x200C(r3)
			bctr
	}

}



bool Button_A_Hold = false;
bool Button_X_Hold = false;
bool Button_Y_Toggle = false;
bool Menu_START_BUTTON_PRESS = false;

byte BrakePreLoadD0[] = {0x3E,0xA3,0xD7,0x0A,0xBE,0x99,0x1F,0xEB,0xC0,0x02,0xDC,0xBD,0x3F,0x80,0x00,0x00};
byte BrakePreLoadE0[] = {0x3E,0xA6,0x32,0xF8,0xBF,0x27,0xE8,0xE1,0xC0,0x05,0x6F,0x92,0x3F,0x80,0x00,0x00};
byte BrakePreLoad110[] = {0x3D,0xB7,0x32,0x3E,0xBE,0x97,0x3C,0xB6,0xC0,0x01,0x83,0xCA,0x3F,0x80,0x00,0x00};
byte BrakePreLoad210[] = {0x3E,0xA5,0x10,0xCD,0xBE,0x99,0x1F,0xEB,0xC0,0x02,0xDC,0xBD,0x3F,0x80,0x00,0x00};
byte BrakePreLoad250[] = {0x3D,0xB9,0x91,0x62,0xBE,0x97,0x20,0x2A,0xC0,0x01,0x3F,0xDD,0x3F,0x80,0x00,0x00};

DWORD ResetInputParams(struct_v35* NuiFakeDevice,int id){
NuiFakeDevice->field_280=0.5;
NuiFakeDevice->dword310 = 1;
NuiFakeDevice->dword300->gap0 = 0;
NuiFakeDevice->dword300->dwTrackingID = 0;
NuiFakeDevice->field_24 =0;
NuiFakeDevice->field_20 = 0;

//field_24 -- Slip of from (possible its int)
//field_20 -- Move Direction (Left Right)
NuiFakeDevice->field_4 = -1.0;
NuiFakeDevice->field_14 = 0.5;
NuiFakeDevice->field_18 = 0.5;

NuiFakeDevice->field_84 = 1.0; //Sursor Second
NuiFakeDevice->field_88 = 1.0; //Sursor Second


NuiFakeDevice->field_B0 = 0.0;
NuiFakeDevice->field_B4 = 0.0;


NuiFakeDevice->field_284 = 0.0;
NuiFakeDevice->field_2E4 = 0;
NuiFakeDevice->field_2F4 = 0;


*(int*)&NuiFakeDevice->dword300->gapex[0]=id;


return 0;

}


DWORD ProcessSingleDpadExtra(ATG::GAMEPAD* gc,bool* DPAD_LEFT_RING,short* DPAD_LEFT_RING_COUNT,short* DPAD_LEFT_RING_COUNT_PRE,float* DPAD_LEFT_RING_TIME,bool* DPAD_LEFT_RING_RELEASED,WORD ControlDPAD){


	if (gc->wPressedButtons & ControlDPAD){
		*DPAD_LEFT_RING_COUNT +=1;


	}
	if (gc->wLastButtons & ControlDPAD){
		*DPAD_LEFT_RING_TIME += 0.1;
		*DPAD_LEFT_RING_RELEASED = false;
		if (        (*DPAD_LEFT_RING_TIME >= 10.0    && *DPAD_LEFT_RING_COUNT_PRE == 0) || (*DPAD_LEFT_RING_TIME >= 1.0    && *DPAD_LEFT_RING_COUNT_PRE > 0)         ) {
			*DPAD_LEFT_RING_TIME = 0.0;
			*DPAD_LEFT_RING_COUNT_PRE += 1;
		}
	}
	else
	{

		*DPAD_LEFT_RING_TIME = 0.0;
		*DPAD_LEFT_RING_RELEASED = true;
	}

	if (*DPAD_LEFT_RING_COUNT_PRE > 0 && *DPAD_LEFT_RING_RELEASED  == true ){
		*DPAD_LEFT_RING_COUNT = *DPAD_LEFT_RING_COUNT_PRE;
		*DPAD_LEFT_RING_COUNT_PRE = 0;


	}
	else if (*DPAD_LEFT_RING_TIME <= 0){
		*DPAD_LEFT_RING = true;
	}
	

	return 0;
}
DWORD ProcessSingleDpadsExtra(ATG::GAMEPAD* gc,NukFakeDeviceHelpers* HP){


	ProcessSingleDpadExtra(gc,&HP->DPAD_LEFT_RING,
		&HP->DPAD_LEFT_RING_COUNT,
		&HP->DPAD_LEFT_RING_COUNT_PRE,
		&HP->DPAD_LEFT_RING_TIME,
		&HP->DPAD_LEFT_RING_RELEASED,XINPUT_GAMEPAD_DPAD_LEFT);
	ProcessSingleDpadExtra(gc,&HP->DPAD_RIGHT_RING,
		&HP->DPAD_RIGHT_RING_COUNT,
		&HP->DPAD_RIGHT_RING_COUNT_PRE,
		&HP->DPAD_RIGHT_RING_TIME,
		&HP->DPAD_RIGHT_RING_RELEASED,XINPUT_GAMEPAD_DPAD_RIGHT);
	return 0;

}




DWORD  ProcessSingleInput(struct_v35* NuiFakeDevice,struct_dword300 * NuiFakeDeviceExtra,NukFakeDeviceHelpers* HP,ATG::GAMEPAD* gc,int index){


	auto t = (int)(int*)&KinnectNuiBox::Instance->dword78;
	auto t1 = (int)(int*)&KinnectNuiBox::Instance->floatA0;
	auto z = (struct_v35**)(t+(index*4));

	auto z1 = (float*)(t1+(index*4));


	if (gc->wLastButtons & XINPUT_GAMEPAD_BACK){
		HP->SelectHoldTime += 1.0 * MBKinnectInput->dword18->GameSpeed;
		if (HP->SelectHoldTime > 2.0){
			*z = 0;
			HP->SelectHoldTime = 0.0;
		}
		return 0 ;
	}
	else{
		HP->SelectHoldTime = 0.0;
	}


	if (gc->bConnected == false){
		if (*z != 0){
			*z = 0;
		}
		return 0;
	}




	else if  (*z != NuiFakeDevice){


	
		*z=NuiFakeDevice;
		//KinnectNuiBox::Instance->dwordB8 = 3;
		NuiFakeDevice->dword300 = NuiFakeDeviceExtra;
		ResetInputParams(NuiFakeDevice,index);

	}


//	if (GameRootStateController && (GameRootStateController->GameRootState == 2 |GameRootStateController->GameRootState == 1  ))
//	{
//
//	}
	
//	else


	{
		//ShowXenonMessage(L"MSG","B");
		HP->StickForceX =(-gc->fX1+1)/2;
		HP->StickForceX = clamp(HP->StickForceX,0.0,1.0);
		HP->StickForceY = (gc->fY1);
		//StickForceY = clamp(StickForceY,0.0,1.0);
		if (NuiFakeDevice->field_4 != 0){
			NuiFakeDevice->field_4 = 0;
		}
		if (NuiFakeDevice->field_30 != 0)NuiFakeDevice->field_30 = 0;
		if (NuiFakeDevice->field_34 != 0)NuiFakeDevice->field_34 = 0;
		if (NuiFakeDevice->field_24 != 0) NuiFakeDevice->field_24 = 0;
		if (NuiFakeDevice->field_48 != 0) NuiFakeDevice->field_48 = 0;
		if (NuiFakeDevice->field_104 != 0) NuiFakeDevice->field_104 = 0;
		if (NuiFakeDevice->field_108 != 0) NuiFakeDevice->field_108 = 0;




		
		if (NuiFakeDevice->field_58 != gc->fX1){
			NuiFakeDevice->field_58 = gc->fX1;
		}
		if (NuiFakeDevice->field_284 != HP->StickForceX)
		{
			//-0x168 = Kick Dash Value First
			//-0x28 = Kick Dash Second First
			//0x258
			//0x118
			NuiFakeDevice->field_284 = HP->StickForceX;
			NuiFakeDevice->field_20 = -gc->fX1; // left right
			NuiFakeDevice->dword310 = (NuiFakeDevice->dword310) == 0 ? 1 : 0;
		}
		if (NuiFakeDevice->field_28 != HP->StickForceY)
		{
			if (HP->StickForceY <= -0.75){
				//NuiFakeDevice->field_2C0 = 2;
				//NuiFakeDevice->field_2D0 = 2;
				NuiFakeDevice->field_2E4 = 2;
				NuiFakeDevice->field_2F4 = 2;

			//	memcpy((byte*)&NuiFakeDevice->field_D0 ,(byte*)&BrakePreLoadD0,0x10);
			//	memcpy((byte*)&NuiFakeDevice->field_E0 ,(byte*)&BrakePreLoadE0,0x10);
			//	memcpy((byte*)&NuiFakeDevice->field_110 ,(byte*)&BrakePreLoad110,0x10);
			//	memcpy((byte*)&NuiFakeDevice->field_210 ,(byte*)&BrakePreLoad210,0x10);
			//	memcpy((byte*)&NuiFakeDevice->field_250 ,(byte*)&BrakePreLoad250,0x10);
				


			}
			NuiFakeDevice->field_28 = HP->StickForceY;
			NuiFakeDevice->dword310 = (NuiFakeDevice->dword310) == 0 ? 1 : 0;

		}


		if (NuiFakeDevice->field_10 != gc->fX2){
			NuiFakeDevice->field_10 = gc->fX2;
		}





		if (gc->bLastRightTrigger){
			NuiFakeDevice->field_5C = 1.0;
		}
		else{
			NuiFakeDevice->field_5C = 0.0;
		}




		if (NuiFakeDevice->field_60 != gc->fY2){
			NuiFakeDevice->field_60 = gc->fY2;
	
		}

		if (gc->wLastButtons & XINPUT_GAMEPAD_X){
			NuiFakeDevice->field_0 += MBKinnectInput->dword18->GameSpeed;
		}
		else{
			if (NuiFakeDevice->field_0 != 0.0)
				NuiFakeDevice->field_0 = 0.0;
		}


		if ((gc->wPressedButtons & XINPUT_GAMEPAD_X) && HP->Button_X_Hold == false){

			NuiFakeDevice->field_30 = 1.0; //Ready
			HP->Button_X_Hold = true;

		}

		if (!(gc->wLastButtons & XINPUT_GAMEPAD_X) && HP->Button_X_Hold == true){
			NuiFakeDevice->field_34 = 1.0; //Do Kick
			HP->Button_X_Hold = false;
		}


		if ((gc->wLastButtons & XINPUT_GAMEPAD_A) && HP->Button_A_Hold == false){
			HP->Button_A_Hold = true;
			//OnEnterAction
			NuiFakeDevice->field_2F4 = 2;
			NuiFakeDevice->field_8 = 1.0;	
		}
		if (!(gc->wLastButtons & XINPUT_GAMEPAD_A) && HP->Button_A_Hold == true){
			HP->Button_A_Hold = false;
			NuiFakeDevice->field_8 = 0.0;
			NuiFakeDevice->field_2F4 = 0;
			NuiFakeDevice->field_2E4 = 0;
			NuiFakeDevice->field_4 = 1.0;
			NuiFakeDevice->field_24 = 1.0;
		}

		if ((gc->wLastButtons & XINPUT_GAMEPAD_B) && HP->Button_B_Hold == false){
			HP->Button_B_Hold = true;
			//OnEnterAction	
			//NuiFakeDevice->field_10C = 1.0;	
			NuiFakeDevice->field_110 = 1.0;	
		}
		if (!(gc->wLastButtons & XINPUT_GAMEPAD_B) && HP->Button_B_Hold == true){
			HP->Button_B_Hold = false;
		//	NuiFakeDevice->field_10C = 0.0;
			NuiFakeDevice->field_110 = 0.0;

		}


		if (gc->wPressedButtons & XINPUT_GAMEPAD_A){
			NuiFakeDevice->field_58 = 1.0;
		}

		if ((gc->wPressedButtons & XINPUT_GAMEPAD_Y)){
			NuiFakeDevice->field_48 = 1.0;

		}


		



		if ((gc->bLastLeftTrigger) && HP->Button_LT_Hold == false){
			HP->Button_LT_Hold = true;
			//OnEnterAction
			NuiFakeDevice->field_100 = 1.0;	
		}
		if (!(gc->bLastLeftTrigger) && HP->Button_LT_Hold == true){
			HP->Button_LT_Hold = false;
			NuiFakeDevice->field_100 = 0.0;
		}


		if (gc->wPressedButtons & XINPUT_GAMEPAD_LEFT_SHOULDER){

			NuiFakeDevice->field_104 = 1.0;
		}
		if (gc->wPressedButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER){

			NuiFakeDevice->field_108 = 1.0;
		}




		
	}



	//HP->DPAD_LEFT_RING_COUNT = 0;


	//HP->DPAD_RIGHT_RING = false;
	HP->MENU_BUTTON_A = false;
	HP->MENU_BUTTON_Y = false;
	HP->Menu_START_BUTTON_PRESS = false;





	ProcessSingleDpadsExtra(gc,HP);




	if (gc->wPressedButtons & XINPUT_GAMEPAD_A){
		HP->MENU_BUTTON_A = true;
	}
	if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
		HP->MENU_BUTTON_Y = true;
		*(DWORD*)((INT)&NuiFakeDevice->dword300->gap0+0x17C)  = *(DWORD*)((int)&NuiFakeDevice->dword300->gap0+0x17C) == 0 ? 2 : 0;
	}
	if (gc->wPressedButtons & XINPUT_GAMEPAD_BACK){
	
		ResetInputParams(NuiFakeDevice,index);

	}
	float accelle = 1.0;
	if (gc->wLastButtons & XINPUT_GAMEPAD_X){
		accelle = 2.0;
	}


	NuiFakeDevice->field_B0 += -gc->fX2 * MBKinnectInput->dword18->GameSpeed /100.0 * accelle;
	NuiFakeDevice->field_B4 += -gc->fY2 * MBKinnectInput->dword18->GameSpeed /100.0 * accelle;
	//*(float*)((INT)&NuiFakeDevice->dword300->gap0+0x17C+0x4+0x20) += gc->fY2 *MBKinnectInput->dword18->GameSpeed /100.0;


return 0;
}

bool once = false;
DWORD seg_83E52F84Fake[1000];
DWORD InputSomeUnkStaticA0Fake[100];
DWORD dword_83E53144Fake[100];


HOOK(int,__fastcall,SelfViewUpdate,0x82438930,int a1){
	



	ATG::Input::GetMergedInput();


	if (KinnectNuiBox::Instance){
		if (KinnectNuiBox::Instance->dword78 == 0){
			//KinnectNuiBox::Instance->dword78 = &NuiFakeDevice;
			//KinnectNuiBox::Instance->dwordB8 = 3;

		}


	
		ProcessSingleInput(&NuiFakeDevice,&NuiFakeDeviceExtra,&NuiFakeDeviceHP1,gc,0);

		


		ProcessSingleInput(&NuiFakeDeviceP2,&NuiFakeDeviceExtraP2,&NuiFakeDeviceHP2,gc2P,1);

		if ( (gc->wPressedButtons & XINPUT_GAMEPAD_LEFT_THUMB ) &&   (gc->wLastButtons & XINPUT_GAMEPAD_DPAD_UP )){
			ShowUI = !ShowUI;
		}
		if ( (gc->wPressedButtons & XINPUT_GAMEPAD_RIGHT_THUMB )) {

			ForcePauseGame = !ForcePauseGame;

			if (ForcePauseGame){
				sub_8249F9C8((int)MBKinnectInput->field_34, 3u, 2);
			}
			else{
				sub_8249F9C8((int)MBKinnectInput->field_34, 3u, 0);
			}


		}

		if ((gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP) && GameRootStateController->GameRootState == 1){
			 //XINVITE_INFO* t = (XINVITE_INFO*)(XNLiveSomeStatic + 0x67);

			 SetSessionIP();

			 *(_BYTE *)(XNLiveSomeStatic + 0x65) = 1;
	//		 *(_BYTE *)(XNLiveSomeStatic + 0x66) = 0;

			 *(_BYTE *)(XNLiveSomeStatic + 0xBB) = 0;
		}


		if (ForcePauseGame){
		DWORD t1 = (_DWORD )MBKinnectInput[1].field_28;

		DWORD tl_cam = **(int**)(t1 + 0x8);

		float* CameraPosition = (float*)(tl_cam + 0x50);


	




		float* CameraRotation = (float*)(tl_cam + 0x40);
			CameraPosition[0] += gc->fX1;

			if (gc->wLastButtons & XINPUT_GAMEPAD_A){
				CameraPosition[1] += 0.1;
			}
			if (gc->wLastButtons & XINPUT_GAMEPAD_B){
				CameraPosition[1] -= 0.1;
			}

			CameraPosition[2] += gc->fY1;



				float* CameraMetric = (float*)(tl_cam + 0x20);

		

		auto t = ( irr::core::CMatrix4<float>*)(tl_cam + 0x20);
		auto rot = t->getRotationDegrees();

		if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
			irr::core::vector3d<float> pos_camera;
			irr::core::vector3d<float> TTT;


			pos_camera.X = CameraPosition[0];
			pos_camera.Y = CameraPosition[1];
			pos_camera.Z = CameraPosition[2];
		//	t->setTranslation(pos_camera);
	
		//	t->setRotationCenter(TTT,pos_camera.invert());
			//t->setTextureTranslate()
		
		
			//t->setRotationCenter(pos_camera,t->getTranslation());
		}
	

		rot.X+=gc->fX2;
		rot.Z += gc->fY2;

	
		rot.Y +=gc->bLastLeftTrigger;
		rot.Y -=gc->bLastRightTrigger;

		




		t->setRotationDegrees(rot);





			//CameraRotation[0] = clamp(CameraRotation[0] + gc->fX2 * 0.01,-1.0,1.0);

			//CameraRotation[1] = clamp(CameraRotation[1] + gc->fY2 * 0.01,-1.0,1.0);

			//CameraRotation[2] = clamp(CameraRotation[2] + gc->fY2 * 0.01,-1.0,1.0);
		}






		//WriteVirtualBytes("0x8229A6D4","60000000")
	    //WriteVirtualBytes("0x8229A6EC","60000000")
		if (seg_83E52F84){
//			*(_DWORD *)(4 * 0 + *(_DWORD *)(seg_83E52F84 + 4)) = (DWORD)&seg_83E52F84Fake;
//			*(_DWORD *)(4 * 1 + *(_DWORD *)(seg_83E52F84 + 4)) = (DWORD)&seg_83E52F84Fake;


//			DWORD v5 = *(_DWORD *)(4 * 0 + *(_DWORD *)(seg_83E52F84 + 4));
//			DWORD v6 = *(_DWORD *)(4 * 1 + *(_DWORD *)(seg_83E52F84 + 4));

//			*(_DWORD **)(v5 + 0x4C) = (DWORD*)&seg_83E52F84Fake;
//			*(_DWORD **)(v6 + 0x4C) = (DWORD*)&seg_83E52F84Fake;


		}
	
	
		//*(byte*)((int)MainTitlev144Actions + 0x1558)=1; //GlobalInputLock




		if (!once){
			once = true;
			*(int*)((int)NUI::Input::Instance + 0x60)=2;
			*(int*)((int)NUI::Input::Instance + 0x220)=2;

		}

	}
	

	if (InputSomeUnkStatic){

		if (*(int*)(InputSomeUnkStatic + 0xA0) == 0){

		//	*(int*)(InputSomeUnkStatic + 0xA0)  = (int)&InputSomeUnkStaticA0Fake;

		}
	}

	if (dword_83E53144 == 0){
		//dword_83E53144 = (int)&dword_83E53144Fake;
	}



	
	return SelfViewUpdateH(a1);
}

HOOK(int,__fastcall,sub_824A0458,0x824A0458,int a1){





	*(int*)((int)NUI::Input::Instance + 0x60)=2;
	*(int*)((int)NUI::Input::Instance + 0x220)=2;



	return sub_824A0458H(a1);

	


}

			
		
int *__fastcall Riders__MenuNRItem__V0Unk03(int *result){




	return result;
}

HOOK(int, __fastcall ,sub_82452FF0,0x82452FF0){



	if (gc)
	{
		if ( gc->wLastButtons & XINPUT_GAMEPAD_Y){
			return 1;
		}
	}



	return 0;
}



int __declspec(naked) sub_82251018H(int result,int a2){
	__asm{
		    mflr r12
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0x80(r1)
			lis r11,0x8225
			ori r11,r11,0x1028 
			mtctr r11
			lis       r27, -0x7C1B
			bctr
	}
}

int p1 = 0 ;
HOOK(INT,__fastcall,sub_82251018,0x82251018,int result,int a2){

	if (a2){

	
		if (!CommonLua.locked){

			if (gc){
				if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
				//	CommonLua.DoFile(true);
				//	p1 = CommonLua.GetGlobalInt("param0");
				//	ShowXenonMessage(L"Lua","Reloaded");
				}
			}
	
			
		}
		if (gc){
			if (gc->wLastButtons & XINPUT_GAMEPAD_DPAD_UP){
				*(_DWORD *)(a2 + 2472)=p1;
			}
		}
	
		


	}

	return sub_82251018H(result,a2);
}

HOOK(int,__fastcall,sub_82287200 ,0x82287200 ,int a1){


	

	return 0;
}




// i sure that not runned like configrm was


HOOK(float,__fastcall,sub_8226D7B0 ,0x8226D7B0 ,int result){

	if (gc){



		if (gc->fX1 > 0 ){
			return 1.0;
		}
	
		


	}
	return 0.0;
}


int __declspec(naked) sub_822AB3B0H(int result){
	__asm{
		        mflr r12
				std       r14, -0x98(r1)
				std       r15, -0x90(r1)
				std       r16, -0x88(r1)
				std       r17, -0x80(r1)
				std       r18, -0x78(r1)
				std       r19, -0x70(r1)
				std       r20, -0x68(r1)
				std       r21, -0x60(r1)
				std       r22, -0x58(r1)
				std       r23, -0x50(r1)
				std       r24, -0x48(r1)
				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				addi      r12, r1, -0x98
				stfd      fp27, -0x28(r12)
				stfd      fp28, -0x20(r12)
				stfd      fp29, -0x18(r12)
				stfd      fp30, -0x10(r12)
				stfd      fp31, -8(r12)


				lis r11,0x822A
				ori r11,r11,0xB3C0 
				mtctr r11
				lis       r27, -0x7C1B
				bctr
	}
}



bool locked = false;
bool hold = false;
bool released = false;
HOOK(float,__fastcall,sub_822AB3B0,0x822AB3B0,int result){

	

return sub_822AB3B0H(result);

}




int __declspec(naked) sub_82494658H(int result){
	__asm{
		mflr r12

			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stfd      fp31, -0x40(r1)
			addi      r31, r1, -0x1F0
			lis r11,0x8249
			ori r11,r11,0x4668 
			mtctr r11
			bctr
	}
}






bool hold_start = false;
float hold_start_time = 0.0;

int __declspec( naked ) sub_82494658HH(int a1){
	__asm{
		    mflr      r12		    
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
	

			stfd      fp31, -0x40(r1)
			addi      r31, r1, -0x1F0

		
			lis r11,0x8249
			ori r11,r11,0x4668 
			mtctr r11
			bctr r11
	}
}

HOOK(int,__fastcall,sub_82494658,0x82494658,int result){




	 
	 sub_82494658HH(result);
	 if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
		 //	int some = *(int*)( off_83E52FA0 + 0xD4);
		//	*(int*)( some + 0x7C) = 0;


	 }




	//*(_DWORD *)(result + 5440) =0;

	//



	 if (NearKinnectNuiBox::Instance && *(int*)((int)KinnectNuiBox::Instance + 0x50)){

		 int tuto = *(int*)((int)KinnectNuiBox::Instance + 0x50);
		 // if ((int)*(byte*)(tuto + 0x85D) == 1)
		 DWORD pass = true;
		 if (MessageBoxInputMB )
		 {
			 if ( *(_DWORD *)(MessageBoxInputMB + 0xC) ){
				 pass = false;
			 }
		 }
		 if (pass)
		 {
			 if (gc->wPressedButtons & XINPUT_GAMEPAD_START){

				 *(_DWORD *)(MainTitlev144Actions + 0x1540)=(DWORD)L"pauseopen";
			 }

			 if (gc->wPressedButtons & XINPUT_GAMEPAD_A)
			 {
				 *(_DWORD *)(result + 5440) = (DWORD)L"ok";
	
			 }
			 if (gc->wPressedButtons & XINPUT_GAMEPAD_B)
			 {
				 *(_DWORD *)(result + 5440) = (DWORD)L"back";
			 }

		 }


	 }






	if (gc && result && !NearKinnectNuiBox::Instance ){

		DWORD pass = true;

		if (MessageBoxInputMB )
		{
		
			if ( *(_DWORD *)(MessageBoxInputMB + 0xC) ){
				pass = false;
			}

		}
		if (pass)
		{
			if (gc->wPressedButtons & XINPUT_GAMEPAD_A)
			{
				*(_DWORD *)(result + 5440) = (DWORD)L"ok";
			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_B)
			{
				*(_DWORD *)(result + 5440) = (DWORD)L"back";
			}

			if (gc->wPressedButtons & XINPUT_GAMEPAD_START){
				*(_DWORD *)(result + 5440)=(DWORD)L"start";


			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN){
				*(_DWORD *)(result + 5440)=(DWORD)L"rulesetting";


			}

		}

		

		
	


		if (gc->wLastButtons & XINPUT_GAMEPAD_START){
			hold_start_time+=MBKinnectInput->dword18->GameSpeed;;
		}
		else{
			hold_start_time = 0.0;
		}



		//if (gc->wPressedButtons & XINPUT_GAMEPAD_Y ){
		//	*(_DWORD *)(result + 5440)=(DWORD)L"pause";
			//  ShowXenonMessage(L"Paause","	");
		//	hold_start_time = 0.0;
	//	}



	}







	return result;


}

//Convert NUI to Normal One
HOOK(DWORD,__stdcall,sub_824D0CE8,0x824D0CE8,__in DWORD dwTrackingID,__in DWORD dwUserIndex,__in_z LPCWSTR wszTitle,__in_z LPCWSTR wszText,__in DWORD cButtons,__in_opt LPCWSTR* pwszButtons,__in DWORD dwFocusButton,__in DWORD dwFlags,__out PMESSAGEBOX_RESULT pResult,__inout_opt PXOVERLAPPED pOverlapped){

return XShowMessageBoxUI(dwUserIndex,wszTitle,wszText,cButtons,pwszButtons,dwFocusButton,dwFlags,pResult,pOverlapped);

}

HOOK(DWORD,__stdcall,XamShowNuiDeviceSelectorUI,0x82ACB3EC,__in    DWORD dwTrackingID,__in    DWORD dwUserIndex,__in    DWORD dwContentType,__in    DWORD dwContentFlags,__in    ULARGE_INTEGER uliBytesRequested,__out   PXCONTENTDEVICEID pDeviceID,__inout PXOVERLAPPED pOverlapped){

return XShowDeviceSelectorUI(dwUserIndex,dwContentType,dwContentFlags,uliBytesRequested,pDeviceID,pOverlapped);
}


int __fastcall sub_822CA518ZZ(int a1, _DWORD *a2, _DWORD *a3){

	int v6; // r11
	int result; // r3
	int v8; // r10
	int v9; // r9
	int v10; // r8
	int v11; // r8
	int v12; // r10
	int v13; // r11
	double v14; // fp0
	int v15; // r11
	int v16; // r9

	DWORD* v17;
	result = 2;
	if (gc->wLastButtons & XINPUT_GAMEPAD_X){
		result = 1;
		v17 = (_DWORD *)(84 * a3[2] + *a3 + 4);
		*v17 |= 0x800u;
	//	*(_DWORD *)(a1 + 88) = v11;
	//	*(_DWORD *)(a1 + 92) = v12;
	}
	

	return result;

}
int __fastcall sub_822CA518X(int a1, _DWORD *a2, _DWORD *a3){



	return 1;

}


int __fastcall sub_822CA518(int a1, _DWORD *a2, _DWORD *a3){


	if (gc->wPressedButtons & XINPUT_GAMEPAD_X){
		*(float *)(a1 + 0x40) = 40.0;
	*(float *)(a1 + 0x44) = 40.0;
	*(DWORD *)(a1 + 0x3C) = 1;
	return 1;
	}

	return 2;

}



int Dummy(){
	return 1;
}


int __fastcall ChargeStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	 struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	 DWORD* v22;
	 DWORD result = 0;
 
	 if ( _R3->field_8 >= 1.0)
	 {
		
		 DebugLogRestore::log.push_back(new std::string("test"));
		 v22 = (_DWORD *)(84 * a3[2] + *a3 + 4);
		 *v22 |= 0x7000u;
		 return 1;
	 }

	return 0;
}
int __fastcall JumpStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD* v17;
	DWORD result = 0;



	if (_R3->field_4 != 1.0)
	{
		result = 2;
		*(_DWORD *)(a1 + 88) = 1;
		*(_DWORD *)(a1 + 92) = 1;
	}
	else
	{
		result = 1;
		v17 = (_DWORD *)(84 * a3[2] + *a3 + 4);
		*v17 |= 0x200u;
		*(_DWORD *)(a1 + 88) = -1;
		*(_DWORD *)(a1 + 92) = -1;
	}

	return result;
}

int __fastcall CrouschStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 2;

	if (_R3->field_8 > 0){
        auto v16 = MBKinnectInput->dword18;
		DWORD v15 = *(float *)(a1 + 72) < 6.0;
		float v17 = (float)((float)(v16->SpeedSome * (float)v15) + *(float *)(a1 + 72));
	    *(float *)(a1 + 72) = (float)(v16->SpeedSome * (float)v15) + *(float *)(a1 + 72);
		if ( v17 < 6.0 )
		{
			result = 0;
		}
		else
		{
			result = 1;
			DWORD* v19 = (_DWORD *)(84 * a3[2] + *a3 + 4);
			*v19 |= 0x7000u;
		}
	}
	else{
		result = 2;
		*(float *)(a1 + 72) = 0.0;
	}
	
	return result;
}
int __fastcall KickDashStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	//field_30 HOLD_A FIELD_34 RELEASE A
    struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;

	int v19 = 0x54 * a3[2] + *a3;


	DWORD v12 = a2->field_64->dword14;
	DWORD v13 = a2->field_60->dword14;

	DWORD v15;



	v15 = 0x54 * a3[2] + *a3;


	int v8 = a2->field_64->dword14;
	int v9 = a2->field_60->dword14;

	*(&_R3->field_2B0 + v8) = 2;
	*(&_R3->field_2B0 + v9) = 2;

	if (_R3->field_30 == 1.0){

		*(_BYTE *)(a1 + 0x48)=1;
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x800000u; //Preapare	
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x400000u; // Do Fake Side
		result = 0;
	}
	else if (_R3->field_34 == 1.0){

		*(_BYTE *)(a1 + 0x48) = 0;
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x1000000; //Do Dash	
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x400000u; // Do Fake Side
		result = 1;
	}
	else{
		*(_BYTE *)(a1 + 0x48)  = 0;
		result = 2;
	}











END:



	return result;
}

int __fastcall ArmsUPStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	double v5; // fp0
	int v6; // r11
	double v7; // fp0
	int v8; // r11
	int result; // r3
	int v10; // r11
	_DWORD *v11; // r10

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	if ( v4->field_60 > 0.0 )
	{
		v6 = 84 * a3[2] + *a3;
		*(_DWORD *)(v6 + 4) |= 0x80u;
	}
;
	if ( v4->field_60 > 0.0 )
	{
		v8 = 84 * a3[2] + *a3;
		*(_DWORD *)(v8 + 4) |= 0x40u;
	}
	if ( (*(_DWORD *)(84 * a3[2] + *a3 + 4) & 0xC0) != 192 )
		return 2;
	result = 1;
	v10 = 84 * a3[2] + *a3;
	*(_DWORD *)(v10 + 4) |= 0x10000000u;
	v11 = (_DWORD *)(84 * a3[2] + *a3 + 20);
	*v11 |= 0x120u;
	return result;
}

int __fastcall TrickROTStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	double v5; // fp0
	int v6; // r11
	double v7; // fp0
	int v8; // r11
	int result; // r3
	DWORD* v10; // r11
	_DWORD *v11; // r10

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);



	if (v4->field_8 == 0){

		*(float *)(a1 + 0x4C) = 0.0;
		*(float *)(a1 + 0x48) = 0.0;
		return 2;
	}

	float neg = -1.0;
	if (a2->field_68 == 0){
		neg = 1.0;
	}



	float direction = 0;
	float StickX = -((v4->field_284  *2.0) -1.0) ;
	float StickY = v4->field_28;
	float Dzone = 0.65;


	float Spoint = 1.0;


	if (*(float *)(a1 + 0x4C) > 0.0 || *(float *)(a1 + 0x48) > 0.0 ){
		if (*(float *)(a1 + 0x4C) >= 1.0){
			//1
			switch ((int)*(float *)(a1 + 0x4C)){
			case 1:
				if (StickY  <= -Dzone){
					*(float *)(a1 + 0x4C) += 1.0; //2
				}
				break;
			case 2:
				if (StickX  >= Dzone){
					*(float *)(a1 + 0x4C) += 1.0; //3
				}
				break;

	
			}
		}
		else if (*(float *)(a1 + 0x48) >= 1.0){
			//1
			switch ((int)*(float *)(a1 + 0x48)){
			case 1:
				if (StickY  <= -Dzone){
					*(float *)(a1 + 0x48) += 1.0; //2
				}
				break;
			case 2:
				if (StickX  <= -Dzone){
					*(float *)(a1 + 0x48) += 1.0; //3
				}
				break;


			}
		}
	}
	else{
		//Right
		if (StickX >= Dzone)
		{
			*(float *)(a1 + 0x48) = 1.0;
		}
		//Left
		else if (StickX <= -Dzone){
			*(float *)(a1 + 0x4C) = 1.0;
		}
	}

	if (*(float *)(a1 + 0x4C) >= 3.0 || *(float *)(a1 + 0x48) >= 3.0 ){
	
		result = 1;
		*(_BYTE *)(a1 + 0x50) = 1;
		//*(float *)(0x54 * a3[2] + *a3 + 0x38) = *(float *)(0x54 * a3[2] + *a3 + 0x38)  + ((StickX) * 3.14);

	//	ShowXenonMessage(L"MSG","T");
		if (*(float *)(a1 + 0x4C) >= 3.0){
		*(float *)(0x54 * a3[2] + *a3 + 0x38) = *(float *)(0x54 * a3[2] + *a3 + 0x38)  + (3.14*0.0055555557 * 0.0001) + (1.0);
		}
		else if (*(float *)(a1 + 0x48) >= 3.0){
		*(float *)(0x54 * a3[2] + *a3 + 0x38) = *(float *)(0x54 * a3[2] + *a3 + 0x38)  - (3.14*0.0055555557 * 0.0001) - (1.0);
		}
		*(float *)(a1 + 0x48) = 1.0;
		*(float *)(a1 + 0x4C) = 1.0;
		//*(float *)(0x54 * a3[2] + *a3 + 0x38) = 360.0;
		v10 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		*v10 |= 0x800u;

	}
	else{
		return 1;
	}




	


	
	

	return 1;


}


int __fastcall SideStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD result;
	


	result = 2;
	v16 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	v17 = (_DWORD *)(0x54 * a3[2] + *a3 + 20);
	//*v16 |= 0x400000u;
	*v17 |= 0x2000u;

	return result;

}

int ST1[] = {0x8218B518,0x8218B4F8};


int __fastcall SkillPowerNormalGear(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;
	DWORD v9= 0;
	DWORD v56 = 0x54 * a3[2] + *a3;

	DWORD cond = 0;

	if (v4->field_104 == 1.0){

		cond |= 0x80000u;
		result = 1;
	}
	if (v4->field_108 == 1.0){

		cond |= 0x100000u;
		result = 1;
	}

	if ( v4->field_104 == 1.0 || v4->field_108 == 1.0 ){

		 *(_DWORD *)(v56 + 4) |= cond;
	}




	return result;
}

int __fastcall StanceStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v177;
	DWORD* v27;
	DWORD result = 0;
	DWORD v9= 0;

	if (v4->field_48 == 0){


	
		return 0;
	}
	DWORD v11 = a2->field_68;


	DWORD po = *(_DWORD *)(0x54 * a3[2] + *a3 + 0x48);


	DWORD va = po == 0 ? 1 : 0;
	
	*(_DWORD *)(0x54 * a3[2] + *a3 + 0x48)= va;

	DWORD Side = 0;

		 a2->field_68  = va;
	if (va == 0){

		Side = 1;
		a2->field_64 = (struct_field_64*)ST1[1];
		a2->field_60 = (struct_field_60*)ST1[0];
		result = 0;
	}
	else if ( va == 1){
		Side = 2;
		a2->field_64 = (struct_field_64*)ST1[0];
		a2->field_60 = (struct_field_60*)ST1[1];
		result = 0;
	}
	

	result = 2;

	*(_DWORD *)(0x54 * a3[2] + *a3 + 0x48) = va;
	v27 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	v177 = (_DWORD *)(0x54 * a3[2] + *a3 + 20);
	*v27 |= 0x200000u;




	return result;

}

int __fastcall SkillFlyStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v22;
	DWORD result = 2;


	if (v4->field_8 == 0){
		return result;
	}

	result = 1;
	v22 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	*v22 |= 0x40000u;

	

	return result;

}

int __fastcall SwimingStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v18;


	if ( v4->field_0 <= 0 )
		*(float *)(a1 + 0x48) = 0.0;
	else
		*(float *)(a1 + 0x48) = *(float *)(a1 + 0x48) + (float)v4->field_0 / 100;
	if ( *(float *)(a1 + 0x48) > 0.5 )
	{
		result = 1;
		v18 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v18 |= 0x80u;
		*(float *)(a1 + 0x48) = 0.0;
	}


	return result;

}
int __fastcall HoldHandsStateAddaptiveBROKE(int a1, StateA2P *a2, _DWORD *a3){

	int v5; // r29
	int v6; // r9
	int v7; // r8
	int v8; // r10
	int v9; // r11
	bool v10; // cr58
	char v11; // r11
	int v12; // r11
	bool v13; // cr58
	char v14; // r11
	_DWORD ***v15; // r31
	_DWORD ***v16; // r30
	char v20; // r11
	unsigned __int8 v21; // r9
	int result; // r3
	int v25; // r6
	int v29; // r11
	int v30; // r11
	int v31; // r9
	int *v35; // r11
	float v36[3]; // [sp+50h] [-40h] BYREF
	float v37; // [sp+5Ch] [-34h]

	
	v5 = 2;
	v6 = *(_DWORD *)(InputSomeUnkStatic + 0x14);
	if ( v6 <= 0 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		v7 = 0;
	else
		v7 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
	if ( v6 <= 1 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		v8 = 0;
	else
		v8 = *(_DWORD *)(*(_DWORD *)(InputSomeUnkStatic + 0x24) + 4);
	v9 = *(_DWORD *)(v7 + 0x6C);
	if ( !v9 || (v10 = v9 == 3, v11 = 0, v10) )
		v11 = 1;
	if ( !v11 )
		goto LABEL_38;
	v12 = *(_DWORD *)(v8 + 0x6C);
	if ( !v12 || (v13 = v12 == 3, v14 = 0, v13) )
		v14 = 1;
	if ( !v14 )
		goto LABEL_38;
	v15 = *(_DWORD ****)(v7 + 0xC94);
	v16 = *(_DWORD ****)(v8 + 0xC94);
	if ( !((unsigned __int8 (__fastcall *)(_DWORD ***, StateA2P *))(*v15)[0x1A])(v15, a2)
		|| !((unsigned __int8 (__fastcall *)(_DWORD ***))(*v16)[0x1A])(v16) )
	{
		goto LABEL_38;
	}


	struct_v35* _R31 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v15[0x51] + 4))(*v15[0x51]);
	struct_v35* _R3 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v16[0x51] + 4))(*v16[0x51]);
	v20 = 0;
	if (_R31->field_100 >= 1.0 )
		v20 = 1;
	v21 = 0;
	if ( _R3->field_100 >= 1.0)
		v21 = 1;



	if ( v20 || v21 )
	{

		v25 = 2;
		if ( v20 )
		{



			v25 = 1;
			v29 = 0x54 * a3[2] + *a3;
			*(_DWORD *)(v29 + 0x14) |= 0x200u;

		}
		v30 = v21;
		v31 = 2;
		if ( v30 )
		{
				v31 = 1;
				v35 = (int *)(0x54 * a3[2] + *a3);
				v35[5] |= 0x200u;
		
		}
		if ( v25 == 1 || (v5 = 2, v31 == 1) )
			v5 = 1;
LABEL_38:
		*(_DWORD *)(a1 + 0x4C) = v5;
		result = v5;
		goto LABEL_28;
	}
	result = *(_DWORD *)(a1 + 0x4C);
	*(_DWORD *)(a1 + 0x4C) = result;
LABEL_28:
	
	return result;
}


int __fastcall BdAcceleStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	  _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	  if (_R3->field_28 >= 0.65) {

		 DWORD* v14 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		    *v14 |= 0x8000u;
			 result = 1;

	  }



	  return result;

}


int __fastcall HoldHandsStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	int v5; // r29
	int v6; // r9
	int v7; // r8
	int v8; // r10
	int v9; // r11
	bool v10; // cr58
	char v11; // r11
	int v12; // r11
	bool v13; // cr58
	char v14; // r11
	_DWORD ***v15; // r31
	_DWORD ***v16; // r30
	char v20; // r11
	unsigned __int8 v21; // r9

	int v25; // r6
	int v29; // r11
	int v30; // r11
	int v31; // r9
	int *v35; // r11
	float v36[3]; // [sp+50h] [-40h] BYREF
	float v37; // [sp+5Ch] [-34h]

	
auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
DWORD result = 2;
v35 = (int *)(0x54 * a3[2] + *a3);


v5 = 2;
v6 = *(_DWORD *)(InputSomeUnkStatic + 0x14);
if ( v6 <= 0 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
v7 = 0;
else
v7 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
if ( v6 <= 1 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
v8 = 0;
else
v8 = *(_DWORD *)(*(_DWORD *)(InputSomeUnkStatic + 0x24) + 4);
v9 = *(_DWORD *)(v7 + 0x6C);
if ( !v9 || (v10 = v9 == 3, v11 = 0, v10) )
v11 = 1;
if ( !v11 )
goto LABEL_38;
v12 = *(_DWORD *)(v8 + 0x6C);
if ( !v12 || (v13 = v12 == 3, v14 = 0, v13) )
v14 = 1;
if ( !v14 )
goto LABEL_38;


v15 = *(_DWORD ****)(v7 + 0xC94);
v16 = *(_DWORD ****)(v8 + 0xC94);


struct_v35* P1 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v15[0x51] + 4))(*v15[0x51]);
struct_v35* P2 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v16[0x51] + 4))(*v16[0x51]);



	if (P1->field_100 >= 1.0 && P2->field_100 >= 1.0){
		v35 = (int *)(0x54 * a3[2] + *a3);
		v35[5] |= 0x200u;
		result = 1;
	}
	else{

	
		result = 2;
	}
	

LABEL_38:

	if (result != 1){
		v35 = (int *)(0x54 * a3[2] + *a3);
		*(short*)((int)&v35[5] + 0x2)  = 0;
	}

	*(_DWORD *)(a1 + 0x4C) = result;



return result;
}
int __fastcall ShakeStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 2;
	DWORD* v59;

		if ( v4->field_5C > 0.0)
		{


			result = 0;
			if (*(float *)(a1 + 0x74) > 5.0){ //ONLY THIS PART

				result = 1;
				v59 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
				*(v59)  |= 0x44u;
				*(float *)(a1 + 0x74) = 0.0;

			}
			*(_DWORD *)(a1 + 0x64) = 1;
			*(_DWORD *)(a1 + 0x68) = 1;
			*(float *)(a1 + 0x6C) +=0.5*MBKinnectInput->dword18->GameSpeed; 
			*(float *)(a1 + 0x74) +=0.25*MBKinnectInput->dword18->GameSpeed; 

		}

	
	return result;

}
int __fastcall SteamWipeAddaptive(int a1, StateA2P *a2, int a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v59;

	if ( v4->field_5C > 0.0)
	{


	 //  *(_DWORD *)(0x54 * *(_DWORD *)(a3 + 8) + *(_DWORD *)a3 + 0x14) |= 0x8000u;
	   *(_DWORD *)(0x54 * *(_DWORD *)(a3 + 8) + *(_DWORD *)a3 + 0x14) |= 0x10000u;
		if (v4->field_60 != 0.0){
			_WORD v = *(_WORD *)(a3 + 0x4E);
			*(_WORD *)(a3 + 0x4E) = clamp( v + (int)(-v4->field_60 * 14.0 *MBKinnectInput->dword18->GameSpeed),-640,640);

		}
		if (v4->field_10 != 0.0){
			_WORD v = *(_WORD *)(a3 + 0x4C);
			*(_WORD *)(a3 + 0x4C) = clamp( v + (int)(v4->field_10 * 14.0 *MBKinnectInput->dword18->GameSpeed),-480,480);

		}

		result = 0;

	
	//	*(_WORD *)(a3 + 0x4A) = 100;
		//*(_WORD *)(a3 + 0x48) = 100;


	}


	return result;

}

int __fastcall CatchLRStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;
	byte* v8;
	DWORD *v49 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x4);
	DWORD *v50 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
	v8 = (_BYTE *)(0x54 * a3[2] + *a3 + 0x53);

	if ( v4->field_100 != 0.0)
	{

		*(_BYTE *)(a1 + 0x50)  = 0;
		*(_BYTE *)(a1 + 0x51)  = 1;
		DWORD v46 = *(_BYTE *)(a1 + 0x50); //ARMS SOME
		DWORD v44 = *(_BYTE *)(a1 + 0x51);

		*(_DWORD *)(a1 + 0x4C) = 1;
		*(float *)(a1 + 0x48) = 1.0;

		if ( v46 != v44 )
			*(_DWORD *)(a1 + 0x4C) = (2 * v46 + v44) << 0x1D;
		//v49 = 0x54 * *(_DWORD *)(*(&v27 + 1) + 8) + *(_DWORD *)*(&v27 + 1);
		*v49  |=  (2 * v46 + v44) << 0x1D;


		//	v50 = 0x54 * *(_DWORD *)(*(&v27 + 1) + 8) + *(_DWORD *)*(&v27 + 1);
		*v50  = (__ROL4__(*(unsigned __int8 *)(a1 + 0x51), 1) + *(unsigned __int8 *)(a1 + 0x50)) << 0x11;


	}


	return result;

	return result;
}


int __fastcall UUUUUUUUUUUUUUUUUUUUAD(int result)
{


return BranchTo(0x822CEB10,int,result);
}

float correct_stick = 0.45;
int RidersCharacterStateHelperHandler(int *a1){

BranchTo(0x822A8AB0,int,a1);
	
int* v3 = a1 + 4;
DWORD* po = (DWORD*)(0x54 * a1[6] + *v3);
DWORD* pX = (DWORD*)(0x54 * a1[7] + *v3);

DWORD* v8 = (_DWORD *)(0x54 * a1[6] + a1[4]);


auto r = *(StateA2P**)((int)a1+0x140+0x30+0x24);
auto v4 = r->pdword0->dword0->pfunc4(r->pdword0);
if (v4){

	if (v4->field_10 < -correct_stick){	
		pX[1] |= 0xA0000000;
	
	}
	else if (v4->field_10 > correct_stick){
		pX[1] |= 0xC0000000;
	}

	if (v4->field_100 >= 1.0){
	//	ShowXenonMessage(L"MSG","T");
	//	pX[1] |= 0x21000000;
	//	pX[1] |= 0x21000000;
		//pX[1] |= 0x200;
	}


}



return (int)a1;



}


HOOK(int,__fastcall,sub_82ACC28C,0x82ACC28C){

	
	return 0;
}

int DriftStateHandle(int a1){


	int v1 = a1-0x60;

	int c94 = *(_DWORD *)(v1 + 0xC94);

		auto a1x = (struct_v1*)a1;

	 *(float *)&a1x->field_7A4  =1.0;

	 *(float *)&a1x->gap7E0[0x38] = 1.0;

	

	 a1x->floatD4  = 1.0;

	if (c94)
	{
		auto r = *(StateA2P**)(c94+0x140+0x30+0x24);
		if (r){
			auto v4 = r->pdword0->dword0->pfunc4(r->pdword0);


		
			auto v11 = a1x->pfloat690;

			if (v4->field_110 > 0.0 ){

				 *(float *)&a1x->field_7A4 = *(float *)&a1x->field_7A4 + (float)0.0099999998;

				 auto _FP0 = v4->field_284 * 0.0099999998;

				 float v15 = v4->field_284 > 0.5 ? 1.0 : v4->field_284 < 0.5 ? 0.0 : -1.0 ;


				 auto v20 = (float)(*(float *)&a1x->gap7E0[0x38] * (float)v15);
				 auto v21 = (float)-(float)((float)(flt_83E519F0 * (float)_FP0) - a1x->floatD4);
				 a1x->floatD4 = -(float)((float)(flt_83E519F0 * (float)_FP0) - a1x->floatD4);
				 auto v22 = (float)((float)(flt_82B3BCE0 * (float)_FP0) + (float)((float)v20 * (float)0.69999999));


				 auto v1 =    a1x->pfloat690;
				 auto v16 = (_DWORD *)(*((_DWORD *)v1 + 0x325) + 0x10);

				 auto v18 = *(unsigned __int8 *)(0x54 * v16[3] + *v16 + 0x4C);
				 sub_82299420(
					 (int)&a1x->float200,
					 abs(v18),
					 (char)v18 ^ ((unsigned __int64)(char)v18 >> 0x20),
					 (unsigned __int64)(char)v18 >> 0x20,
					 (char)v18,
					 v18,
					 (int)&dword_82B3FFF8[2],
					 (int)&dword_8218FFB4[0x13],
					 v21,
					 0.0);


			}
			else{
				
				*(_DWORD *)&a1x->gap95C[0xC] = 0;
				ChrChangeState((struct_v1*)a1, 9);
				
			}
		}
	}


	return a1;

}

int OtherCharacterUpdateSome(int a1){
	

	int v1 = a1-0x60;

	int c94 = *(_DWORD *)(v1 + 0xC94);
	int* c944 = *(int **)(v1 + 0xC94);

	int s = *(DWORD*)(v1 + 0xC88);
	int Z = *(DWORD*)(v1 + 0xC8C);
	int Z1 = *(DWORD*)(Z + 0x160);
	int s1 = *(DWORD*)(s+0xC);
	int s2 = *(DWORD*)(s+0x14);
	if (gc->wPressedButtons & XINPUT_GAMEPAD_B){
		//*(_BYTE *)(v1 + 0xAA8) = *(_BYTE *)(v1 + 0xAA8) == 0 ? 1 :0;
		//*(_BYTE *)(v1 + 0xAA4) = 1;
	
		 
	}

	if (c94)
	{
		auto r = *(StateA2P**)(c94+0x140+0x30+0x24);
		if (r){
			auto v4 = r->pdword0->dword0->pfunc4(r->pdword0);


			auto a1x = (struct_v1*)a1;
			auto v11 = a1x->pfloat690;

			if (v4->field_110 > 0.0){
				
			
				ChrChangeState((struct_v1*)a1, 0x1F); //1F (DRIFT)

		

			
				
				///*(_DWORD *)(0x54 * *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x1C) + *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x10) + 4) |= 0xAu;
			//	ShowXenonMessage(L"MSG",(int)(_DWORD *)(0x54 * *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x1C) + *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x10) + 4),0);



			}
		}
	}


	return BranchTo(0x822B8498,int,a1);

}

HOOK(int,__fastcall,sub_82452198 ,0x82452198 ,int a1){

	if ((gc->wLastButtons & XINPUT_GAMEPAD_START) | (gc->wLastButtons  & XINPUT_GAMEPAD_X) ){
		return 1;
	}
	return 0;

}

int __fastcall AcceleLRStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	if (_R3->field_28 >= 0.65) {

		DWORD* v14 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		*v14 |= 0x8000u;
		result = 1;

	}



	return result;



}

float test = 0.0;
int __fastcall InflatorAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

			result =1 ;
			*(_BYTE *)(a1 + 0x48) = 0xFF;
			v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
			*v7 |= 0x400u;
			test = 0.0;
	//	}
		

	}



	return result;


}

int __fastcall HammerHandAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{


		result =1 ;

		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x1u;
		test = 0.0;
		//	}


	}



	return result;

}

int __fastcall OverThrowAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

*(_DWORD *)(a1 + 0x4C) =1;
		result =1 ;
		*(_BYTE *)(a1 + 0x48) = 0xFF;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x8u;

	

	}



	return result;


}

int __fastcall UnderThrowAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		*(_DWORD *)(a1 + 0x4C) =1;
		result =1 ;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x10u;

	}



	return result;


}

int __fastcall UnderSwingAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		*(_DWORD *)(a1 + 0x48) =0;
		result =1 ;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x2u;

	}



	return result;
}

int __fastcall FrontLeverAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;

	DWORD v39 = (DWORD)(0x54 * a3[2] + *a3);
	DWORD v40 = a3[2];

	double v41;


	if (v4->field_58 == 0){
		return result;
	}
	
     
	*(_BYTE *)(v39 + 0x52) =  (((byte)(v4->field_58 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * v40 + *a3 + 0x52) )
	{
		result = 1;
		*(_DWORD *)(0x54 * v40 + *a3 + 0x14) |= 0x1000u;
	}


	return result;
}

int __fastcall HandleStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;

	DWORD v39 = (DWORD)(0x54 * a3[2] + *a3);
	DWORD v40 = a3[2];

	double v41;


	if (v4->field_58 == 0){

		if (*(_BYTE *)(v39 + 0x53) != 0)
		*(_BYTE *)(v39 + 0x53) = 0;
		return result;
	}


	*(_BYTE *)(v39 + 0x53) =  (((byte)(v4->field_58 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * v40 + *a3 + 0x53) )
	{
		result = 1;
		*(_DWORD *)(0x54 * v40 + *a3 + 0x14) |= 0x4000u;
	}
	

	return result;
}


int __fastcall FrontCurveStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);



	*(_BYTE *)(0x54 * a3[2] + *a3 + 0x51) =  (((byte)(-v4->field_20 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * a3[2] + *a3 + 0x51) )
		    *(_DWORD *)(0x54 * a3[3] + *a3 + 0x14) |= 0x800u;


	return 0;
}


int __fastcall CatchStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;
	byte* v8;
	DWORD v49 = (_DWORD )(0x54 * a3[2] + *a3 );
	DWORD v50 = (_DWORD )(0x54 * a3[2] + *a3 );
	v8 = (_BYTE *)(0x54 * a3[2] + *a3 + 0x53);

	if ( v4->field_10 != 0.0)
	{
		*(unsigned __int8 *)(v4 + 0x49) = 1;
		*(unsigned __int8 *)(v4 + 0x48) = 0;
		int v46 = *(unsigned __int8 *)(v4 + 0x49);
		int v44 = *(unsigned __int8 *)(v4 + 0x48);

		if ( (unsigned __int8)v46 != v44 )
			*(_DWORD *)(v4 + 0x4C) = (2 * v46 + v44) << 0x1D;
		
		*(_DWORD *)(v49 + 4) |= 0x40u;
		*(_DWORD *)(v50 + 20) |= 0x80u;


	}


	return result;
}

int __fastcall BrakeVStateAdaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	if (_R3->field_10C == 1.0){

		*(float *)(a1 + 0x48) +=MBKinnectInput->dword18->GameSpeed;

	///	if (*(float *)(a1 + 0x48) > 60.0){

		//	std::stringstream ss;
		//	ss << std::hex << (0x54 * a3[2] + *a3 + 4);
		//	DebugLogRestore::log.push_back(new std::string(ss.str().c_str()));

			_R3->field_2E4 = 2;
			_R3->field_2F4 = 2;
			result = 1;
			DWORD *v9;
			*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0x64;
			v9 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
			*v9 |= 0x100u;

	//	}

	}
	else{
		_R3->field_2E4 = 0;
		_R3->field_2F4 = 0;

		result = 2;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0;
		*(float *)(a1 + 0x48) = 0.0;
	}









return result;


}

int __fastcall BrakeStateAdaptive(int a1, StateA2P *a2, _DWORD *a3){
	
	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	
	if (_R3->field_10C == 1.0){

		*(float *)(a1 + 0x48) +=MBKinnectInput->dword18->GameSpeed;
		
		//if (*(float *)(a1 + 0x48) > 1.0){

		//	std::stringstream ss;
		//	ss << std::hex << (0x54 * a3[2] + *a3 + 4);
		//	DebugLogRestore::log.push_back(new std::string(ss.str().c_str()));
			_R3->field_2E4 = 2;
			 _R3->field_2F4 = 2;
			result = 1;
			DWORD *v9;
			*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = (((byte)(abs(_R3->field_28) *1.0*100.0)));

		


			v9 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
			*v9 |= 0x100u;
			*v9 |= 0x400000u; // Force allow to do it ( need find where originally this requires condition is & 0x400000u or else brake wont work)

		//}

	}
	else{
		_R3->field_2E4 = 0;
		_R3->field_2F4 = 0;

		result = 2;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0;
		*(float *)(a1 + 0x48) = 0.0;
	}



	return result;
}

HOOK(int,__fastcall,sub_823DC2D0,0x823DC2D0,int a1){


	DWORD result = 0;
	if (gc){
		if (gc->wLastButtons & XINPUT_GAMEPAD_START  | (gc->wLastButtons  & XINPUT_GAMEPAD_X) ){

			if (  *(_DWORD *)(a1 + 0x3AC)  == 0)   *(_DWORD *)(a1 + 0x3AC) = 1;
			
			 *(float *)(a1 + 0x3B0) += MBKinnectInput->dword18->SpeedSome * (float)1.0;

			 if (*(float *)(a1 + 0x3B0) < 45.0){
				 result  = 1;
			
			 }
			 else{
				 result = 2;
				 *(float *)(a1 + 0x3B0) = 45.0;
				 *(_DWORD *)(a1 + 0x3AC) = 2;
			 }

		}
		else{
			  *(_DWORD *)(a1 + 0x3AC) = 0;
			  if ( *(float *)(a1 + 0x3B0) > 0.0){
				  *(float *)(a1 + 0x3B0)-= MBKinnectInput->dword18->SpeedSome * (float)2.0;
			  }
			
		}
	}

	return result;
}

HOOK(float,__fastcall,sub_82A54518,0x82A54518,int a1){

	return 0.0;
}

HOOK(int*,__fastcall,sub_82ACB43C,0x82ACB43C,int a1){

	*(int*)(a1+0xC)=3;
	return (int*)a1;
}

int __declspec( naked ) sub_8224A500H(int a1){
	__asm{
			mflr r12
			std       r24, -0x48(r1)
			std       r25, -0x40(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			addi      r31, r1, -0xA0
			stwu      r1, -0xA0(r1)
			lis r11,0x8224
			ori r11,r11,0xA510
			mtctr r11
			bctr r11
	}
}


HOOK(int*,__fastcall,sub_8224A500,0x8224A500,int a1){

	sub_8224A500H(a1);
	int* result;


	if ( *(_BYTE *)(a1 + 0x85D)
		|| (result = (int *)(*(int (__fastcall **)(int))(*(_DWORD *)a1 + 0x1C))(a1), (_BYTE)result) )
	{

	if (gc){
		if (gc->wPressedButtons & XINPUT_GAMEPAD_START){
			
			(int *)BranchTo(0x82223E88,int,a1);
		}
	}
	}


	return (int*)a1;

}

HOOK(int,__fastcall,sub_82494E18,0x82494E18,int a1,int a2,int a3){


	return 0;
}
HOOK(int,__fastcall,sub_82494A68,0x82494A68,int a1, int a2, __int64 a3){





	

	int v5; // r11
	int v6; // r9
	double v7; // fp11
	unsigned int v8; // r5
	unsigned int v9; // r30
	int v10; // r11
	int v11; // r11
	int v12; // r9
	double v13; // fp12


	if ( !*(_BYTE *)(a2 + 820) && (*(_DWORD *)(a2 + 8) & 0x80000) == 0 )
	{
		v5 = *(_DWORD *)(a2 + 12);
		if ( v5 )
		{
			v6 = *((_DWORD *)MBKinnectInput + 6);
			v7 = (float)(*(float *)(v6 + 40) + *(float *)(a2 + 1000));
			*(float *)(a2 + 1000) = *(float *)(v6 + 40) + *(float *)(a2 + 1000);
			if ( v7 >= 60.0 )
				*(float *)(a2 + 1000) = 60.0;
			if ( abs(*(float *)(v5 + 772)) <= (float)((float)(3.14 * (float)0.0055555557) * (float)45.0)
				&& *(float *)(a2 + 1000) >= 60.0 )
			{
				*(float *)(a2 + 1000) = 0.0;
				*(_BYTE *)(a2 + 820) = 19;
			}
		}
	}
	//if ( *(_DWORD *)(a2 + 12) )
		//BranchTo(0x82494C00,int,a2, a2, a3);
	v8 = 0;
	v9 = 0;
	do
	{
		v10 = 400 * v9 + a2;
		if ( (*(_DWORD *)(v10 + 20) & 4) != 0 )
			goto LABEL_19;
		v11 = v10 + 16;
		if ( *(_DWORD *)(a2 + 12) && *(float *)(v11 + 164) >= 90.0)
		{
			v12 = *((_DWORD *)MBKinnectInput + 6);
			v13 = (float)(*(float *)(v12 + 40) + *(float *)(v11 + 384));

			*(float *)(v11 + 384) = *(float *)(v12 + 40) + *(float *)(v11 + 384) +  gc->fX1 * MBKinnectInput->dword18->GameSpeed / (10.0*v9);
			if ( v13 < 20.0 )
				goto LABEL_19;
			*(_DWORD *)v11 |= 8u;
		}
		*(float *)(v11 + 384) = 0.0;
LABEL_19:
		BranchTo(0x82494E18,int,a1, a2, v8);
		v8 = (v9 + 1);
		v9 = v8;
	}
	while ( v8 < 2 );


	return 0;
}

HOOK(_DWORD*,__fastcall ,sub_822A3B30,0x822A3B30,_DWORD *result, _DWORD *a2){


	 *(_BYTE *)(0x54 * result[2] + *result + 0x4D) = 0x64;
		 return result;

}

int __declspec( naked ) sub_824A3398H(int a1,int a2,int a3,int a4){
	__asm{
		mflr r12

			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0x80(r1)
			lwz       r28, 4(r3)
			lis r11,0x824A
			ori r11,r11,0x33A8 
			mtctr r11
			bctr r11
	}
}

HOOK(int,__fastcall,sub_824A3398,0x824A3398,unsigned int MainHeapX, int a2, unsigned int a3, unsigned int a4){




	return sub_824A3398H(MainHeapX,a2,a3,a4);
}
DWORD Expo[1000];
DWORD Expo1[1000];





int __declspec( naked ) sub_8229FD40H(int a1,int a2,int* a3){
	__asm{
		mflr r12
			std       r25, -0x30(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0xA0(r1)
			lwz       r30, 4(r3)
			lis r11,0x8229
			ori r11,r11,0xFD50 
			mtctr r11
			lbz       r11, 0x7FB(r3)
			bctr
	}
}

HOOK(int,__fastcall,sub_8229FD40,0x8229FD40,int a1, int a2, int *a3){



	if (*(_DWORD *)(a1 + 0x690) == 0){

		*(DWORD*)(((int)&Expo)+0x4) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0xC) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x8) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x4C) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0xC8) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x74) = (DWORD)&Expo;

	
		*(_DWORD *)(a1 + 0x690) = (DWORD)&Expo;
	}

	if (*(_DWORD *)(a1 + 0x144) == 0){
		*(_DWORD *)(a1 + 0x144) = (DWORD)&Expo1;
		*(DWORD*)(((int)&Expo1)+0x5C) = (DWORD)&Expo1;

	}


	return sub_8229FD40H(a1,a2,a3);

}


HOOK(int,__fastcall,sub_8229A650,0x8229A650,unsigned int a1){

	int v1; // r10
	int v3; // r10
	int v4; // r9
	int v5; // r11
	_DWORD *v6; // r9

	if ( *((_DWORD *)NearKinnectNuiBox::Instance + 0x27) == 3 )
	{
		v1 = *(_DWORD *)(*((_DWORD *)off_83E53128 + 0x17) + 0x10 * a1 + 4);
		if ( v1 < *(_DWORD *)(InputSomeUnkStatic + 0x14)
			&& *(_DWORD *)(InputSomeUnkStatic + 0x24) != *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		{
			return *(_DWORD *)(4 * v1 + *(_DWORD *)(InputSomeUnkStatic + 0x24));
		}
	}
	else
	{
		v3 = *(_DWORD *)(seg_83E52F84 + 8);
		v4 = *(_DWORD *)(seg_83E52F84 + 4);
		if ( ((v3 - v4) & 0xFFFFFFFC) != 0 && (v3 - v4) >> 2 > a1 )
			v5 = *(_DWORD *)(4 * a1 + *(_DWORD *)(seg_83E52F84 + 4));
		else
			v5 = (int)&Expo;
		v6 = *(_DWORD **)(v5 + 0x4C);
		if ( *v6 < *(_DWORD *)(InputSomeUnkStatic + 0x14)
			&& *(_DWORD *)(InputSomeUnkStatic + 0x24) != *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		{
			return *(_DWORD *)(4 * *v6 + *(_DWORD *)(InputSomeUnkStatic + 0x24));
		}
	}
	return 0;
}


HOOK(int,__fastcall,sub_82306F00,0x82306F00,int a1){

	return 5 + ( std::rand() % ( 0x15 - 5 + 1 ) );
}



int __declspec( naked ) sub_824E96C8H(int* a1,int* a2){
	__asm{

		    mflr      r12
		    stw       r12, -8(r1)
		    stwu      r1, -0x70(r1)
		    lwz       r9, 0xC(r4)
			lis r11,0x824E
			ori r11,r11,0x96D8 
			mtctr r11
			bctr r11
	}
}

DWORD FakedData[8] = {1280,720,0,0,3840,2160,1065353216,0};

HOOK(int,__fastcall,sub_824E96C8,0x824E96C8,int* a1,int* a2){



	return sub_824E96C8H(a1,(int*)&FakedData[2]);
}

int __declspec( naked ) sub_8244EA78H(int* a1,int* a2){
	__asm{

		    lwz       r11, 0(r4)
			lfs       fp0, 0xA8(r3)
			clrlwi    r10, r11, 0
			std       r10, -0x10(r1)
			lis r12,0x8244
			ori r12,r12,0xEA88 
			mtctr r12
			bctr r12
	}
}

HOOK(int,__fastcall,sub_8244EA78,0x8244EA78,int* a1,int* a2){


	return sub_8244EA78H(a1,(int*)&FakedData[0]);
}




int __declspec( naked ) sub_8248B560H(_DWORD* a1){
	__asm{
		    mflr      r12
		
			std       r18, -0x78(r1)
			std       r19, -0x70(r1)
			std       r20, -0x68(r1)
			std       r21, -0x60(r1)
			std       r22, -0x58(r1)
			std       r23, -0x50(r1)
			std       r24, -0x48(r1)
			std       r25, -0x40(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)


			addi      r31, r1, -0x180
			stwu      r1, -0x180(r1)
			lis r11,0x8248
			ori r11,r11,0xB570 
			mtctr r11
			bctr r11
	}
}

HOOK(int,__fastcall,sub_8248B560,0x8248B560,_DWORD* a1){



	std::string v44  = std::string("");
	
    sub_8248B948(a1[0x16], (int)&v44);



	return sub_8248B560H(a1);
}


HOOK(int,__fastcall,sub_8222B520,0x8222B520,int a1, unsigned int a2){
	int v2; // r10
	struct_MBKinnectInput *v3; // r11
	struct_a1_4 *v4; // r9
	int result; // r3

	v2 = *(_DWORD *)(a1 + 0x98);
	*(_DWORD *)(a1 + 0x9C) = a2;
	v3 = MBKinnectInput;
	*(_BYTE *)(a1 + 0xB6) = (((a2 & 0x80000000) == 0) + (a2 <= 1)) & 1;
	if ( v2 != a2 )
	{
		*(_DWORD *)(a1 + 0xA0) = a2;
		*(_DWORD *)&v3->field_1C[1].gap0[0x38] = a2;
	}
	v4 = v3->dword18;
	result = 1;


	float GameSpeed = 1.5;
	float FrameRateValue = 45.0;
	float CalculatedFrameRate = (1.0/FrameRateValue);
	float CalculatedFrameRateEX = CalculatedFrameRate * 1000000;

	/*
	v4->GameSpeed = 1.0;
	v4->gap38[0x20] = 60;
	v4->dword1C = 16666;
	v4->gap38[0x21] = 1;
	*(float *)&v4->gap8[4] = 60.0;
	*(float *)&v4->gap8[8] = 0.016666668;
	v4->CameraSpeed = 1.0;
	*(float *)v4->gap18 = 1.0;
	*/

	v4->GameSpeed = GameSpeed;
	v4->gap38[0x20] = (int)FrameRateValue;
	v4->dword1C = (int)CalculatedFrameRateEX;
	v4->gap38[0x21] = 1;
	*(float *)&v4->gap8[4] = FrameRateValue;
	*(float *)&v4->gap8[8] = CalculatedFrameRate;
	v4->CameraSpeed = GameSpeed;
	*(float *)v4->gap18 = GameSpeed;




	return result;

}

HOOK(int,__fastcall,XamShowNuiSigninUIE,0x82ACB39C,_DWORD a1,_DWORD a2){

	return XShowSigninUI(a1,a2);
}




static float GameSpeed = 1.0;




int __declspec( naked ) sub_8248B438H(_DWORD* a1){
	__asm{
		    mflr      r12
			stw       r12, -8(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			lis r11,0x8248
			ori r11,r11,0xB448 
			mtctr r11
			bctr r11
	}
}


static DWORD FakeNetplayData[512];
static DWORD FakeNetplayDataEX[512];

HOOK(int,__fastcall,sub_8248B438,0x8248B438,_DWORD* a1){


	  a1[0x11] = (INT)(new int(1024));
	  FakeNetplayData[0] = 10;
	  FakeNetplayData[1] = (int)&FakeNetplayDataEX;


	return sub_8248B438H(a1);
}


HOOK(int,__fastcall,EtxProducerRegistersFake,0x82ACC28C,int a1, int a2, int a3, int a4, int a5, int* a6){

	//*a6 = 0x1;
return 0;
}







HOOK(int*,__fastcall,sub_823FAEC0,0x823FAEC0,int a1)
{
	char v1; // r27
	int v3; // r25
	int *result; // r3
	int v5; // r11
	_DWORD *v6; // r30
	int v7; // r26
	int v8; // r11
	int v9; // r11
	int v10; // r3
	char v11; // r11
	char v12; // r30
	_DWORD *v13; // r11
	int v14; // r9
	int v15; // r4
	int v16; // r11
	int v17; // [sp+58h] [-48h] BYREF
	int v18; // [sp+5Ch] [-44h] BYREF


	v1 = 0;
	v3 = *(_DWORD *)(a1 + 4);
	result = sub_82211440();
	v5 = *(_DWORD *)(a1 + 0x44);
	if ( v5 == 2 )
	{
		v16 = *(_DWORD *)(a1 + 0xC);
		*(_DWORD *)(a1 + 0x7C) = 8;
		*(_DWORD *)(v16 + 0x38) &= 0xFFFFFFFC;
		++*(_DWORD *)(a1 + 0x44);
		goto LABEL_27;
	}
	if ( v5 == 3 )
	{
		v6 = *(_DWORD **)(NearKinnectNuiBox::Instance + 0x50);
		result = (int *)(*(int (__fastcall **)(_DWORD *))(*v6 + 0x1C))(v6);// 8224C720
		if ( (_BYTE)result )
			v7 = *(_DWORD *)(v6[0x20A] + 0x68);
		else
			v7 = 8;

		if (ShowUI){
			v7 = 0;
		}
		v8 = *(_DWORD *)(a1 + 0x7C);
		if ( v7 != v8 )
		{
			if ( v7 == 8 )
			{
				if ( *(_BYTE *)(a1 + 0x80) )
				{
					if ( *(int *)(InputSomeUnkStatic + 0x14) <= 0
						|| *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
					{
						v9 = 0;
					}
					else
					{
						v9 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
					}
					if ( *(_DWORD *)(v9 + 0x9A8) == 2
						|| (v1 = 1,
						v10 = (int)*sub_82230F38((DWORD*)&v17, NearKinnectNuiBox::Instance),
						result = (int *)(*(int (__fastcall **)(int))(*(_DWORD *)v10 + 0x28))(v10),
						v11 = 1,
						(_BYTE)result) )
					{
						v11 = 0;
					}
					v12 = v11;
					if ( (v1 & 1) != 0 )
						result = boostsomex(&v18);
					if ( v12 )
						result = (int *)sub_82408998(v3, 0, 0);
					if ( *(_DWORD *)(NearKinnectNuiBox::Instance + 0x9C) == 1 )
					{
						*((_DWORD *)off_83E52FA0 + 0x39) = 0;
						*(_DWORD *)(a1 + 0x7C) = 8;
						goto LABEL_27;
					}
				}
			}
			else if ( v8 == 8 )
			{
				result = (int *)sub_82408998(v3, 1, 0);
				if ( *(_DWORD *)(NearKinnectNuiBox::Instance + 0x9C) == 1 )
				{
					v13 = (DWORD*)off_83E52FA0;
					v14 = *((_DWORD *)off_83E52FB4 + 0x1A);
					v15 = *((_DWORD *)off_83E52FB4 + 0x14);
					*((_DWORD *)off_83E52FA0 + 0x3A) = (int)flt_82B34BD8;
					result = (int *)(v14 + 0x28);
					v13[0x3B] = 0x276;
					v13[0x37] = v14 + 0x28;
					v13[0x39] = 0xFFFFFFFF;
					v13[0x38] = v15;
				}
			}
		}
		*(_DWORD *)(a1 + 0x7C) = v7;
	}
LABEL_27:
	
	return result;
}

HOOK(int,__fastcall,sub_8224C6F8,0x8224C6F8,int a1){
	int v1; // r11
	bool v2; // cr58
	unsigned __int8 v3; // r11

	v1 = *(_DWORD *)(a1 + 0x828);
	if ( !v1 || (v2 = *(_BYTE *)(v1 + 0x7B) == 0, v3 = 1, v2) )
		v3 = 0;

	if (ForcePauseGame) v3 = 1;

	return v3;
}



void GlobalInstall(){


	//Do Lua First
	CommonLua.DoFile(true);


	gc = &ATG::Input::m_Gamepads[CommonLua.GetGlobalIntNew((char*)"Gamepad_Slots.P1",true)];
	gc2P = &ATG::Input::m_Gamepads[CommonLua.GetGlobalIntNew((char*)"Gamepad_Slots.P2",true)];



	//CommonLua.GetGlobalInt("ConnectPort")
	
	
	//SetSessionID();



	INSTALL_HOOK(sub_8224C6F8);

	//Todo Lua Param For Togable UI
	INSTALL_HOOK(sub_823FAEC0);

	INSTALL_HOOK(EtxProducerRegistersFake);
	//INSTALL_HOOK(sub_8248B438);

	//ShowXenonMessage(L"MSG",(int)&GameSpeed,0);
//	WRITE_DWORD((0x8222B568),0x3D000000 | (ADDRESS_HIGHER((DWORD)&GameSpeed) & 0xFFFF));
//	WRITE_DWORD((0x8222B580),0xC0080000 | (ADDRESS_LOWER((DWORD)&GameSpeed) & 0xFFFF));
	

//	INSTALL_HOOK(sub_822A4770);// Fix Cailibration Global

	
	//INSTALL_HOOK(sub_8222B520);


	INSTALL_HOOK(XamShowNuiSigninUIE);

	INSTALL_HOOK(XamShowNuiDeviceSelectorUI);
	INSTALL_HOOK(sub_824D0CE8);

	//INSTALL_HOOK(sub_8248B560);


	WRITE_DWORD(0x8222CA38,0x4E800020);
	WRITE_DWORD(0x8226086C,0x60000000); //fix free hand timer
	WRITE_DWORD(0x82260754,0x60000000); //fix free hand timer


	WRITE_DWORD(0x8222CA38,0x4E800020); //other

	WRITE_DWORD(0x82456B14,0x4800004C); //SURSOR



	//Others Fixes (fro input)
	WRITE_DWORD(0x82222B80,0x4E800020); 
	WRITE_DWORD(0x8222302C,0x60000000);
	WRITE_DWORD(0x82223084,0x60000000);

	
	
	WRITE_DWORD(0x821A2484,0x822C8958);// Bike Move Fix



#ifndef TEST
	WRITE_DWORD(0x82438CC8,0x4E800020); //--Disable Crash Func (DLL)
#else


#endif








	//INSTALL_HOOK(sub_8244EA78);
	//INSTALL_HOOK(sub_824E96C8);



	//INSTALL_HOOK(sub_82306F00);
	
	// Make a littble stable (useles because softlock still there ( )
//	INSTALL_HOOK(sub_8229A650);

	//INSTALL_HOOK(sub_8229FD40);









	//WRITE_DWORD(0X8229A650,0x4E800020);
	//INSTALL_HOOK(sub_823B75D8); //make stable



	//INSTALL_HOOK(sub_824A3398);

//	INSTALL_HOOK(sub_82ACC28C);
	//INSTALL_HOOK(sub_822A3B30);
	//INSTALL_HOOK(sub_82494E18);
	//INSTALL_HOOK(sub_82494A68);
//	INSTALL_HOOK(sub_8224A500); // Disable Pause Later MB i just pausing ????

	INSTALL_HOOK(sub_82ACB43C); //Fake XamNuiGetDeviceStatus
	//INSTALL_HOOK(sub_82A54518); //fixall
	INSTALL_HOOK(sub_823DC2D0);
	INSTALL_HOOK(sub_82452198);
	

#ifndef TTT

	WRITE_DWORD(0x82B09EA4,OtherCharacterUpdateSome);
	WRITE_DWORD(0x82B09EB4,OtherCharacterUpdateSome);

//	WRITE_DWORD(0x82B09F14,DriftStateHandle);


	WRITE_DWORD(0x821A21F8,RidersCharacterStateHelperHandler);
	WRITE_DWORD(0x821A237C,SkillFlyStateAddaptive);

//	WRITE_DWORD(0x821A2590,UUUUUUUUUUUUUUUUUUUUAD);
//	WRITE_DWORD(0x822C422C,0x60000000);
	WRITE_DWORD(0x821A2368,JumpStateAddaptive);


	WRITE_DWORD(0x821A23D0,TrickROTStateAddaptive);

	WRITE_DWORD(0x821A232C,ArmsUPStateAddaptive);
	//WRITE_DWORD(0x821A238C,Dummy);
	//WRITE_DWORD(0x821A2378,Dummy);
    WRITE_DWORD(0x821A2358,HoldHandsStateAddaptive);
	//WRITE_DWORD(0x821A23A8,Dummy);
	//WRITE_DWORD(0x821A23BC,Dummy);
	WRITE_DWORD(0x821A2454,AcceleLRStateAddaptive); //Accell
	//WRITE_DWORD(0x821A2454,Dummy);
	WRITE_DWORD(0x821A245C,BrakeVStateAdaptive);
	//WRITE_DWORD(0x821A246C,CatchStateAddaptive);
	WRITE_DWORD(0x821A247C,ChargeStateAddaptive); //Not this Real (it not charge jump and this some)
	//WRITE_DWORD(0x821A2484,Dummy);
	//WRITE_DWORD(0x821A2484,Dummy);
	WRITE_DWORD(0x821A2494,KickDashStateAddaptive); // Bike
	WRITE_DWORD(0x821A249C,SkillPowerNormalGear);
	//WRITE_DWORD(0x821A2428,SideStateAddaptive); //Requires To DO 
	WRITE_DWORD(0x821A244C,StanceStateAddaptive);
	WRITE_DWORD(0x821A2418,KickDashStateAddaptive);
	WRITE_DWORD(0x821A23F4,BrakeStateAdaptive);
   //  WRITE_DWORD(0x821A2404,CatchLRStateAddaptive); //CATCHLR
	WRITE_DWORD(0x821A23E4,BdAcceleStateAddaptive);
	WRITE_DWORD(0x821A243C,SkillPowerNormalGear);
	WRITE_DWORD(0x821A233C,CrouschStateAddaptive);
	//WRITE_DWORD(0x821A2344,Dummy);
	WRITE_DWORD(0x821A24C4,OverThrowAddaptive);
	WRITE_DWORD(0x821A24FC,UnderThrowAddaptive);
	WRITE_DWORD(0x821A24E8,UnderSwingAddaptive);
	WRITE_DWORD(0x821A24B0,HammerHandAddaptive);
	WRITE_DWORD(0x821A24D4,ShakeStateAddaptive);
	WRITE_DWORD(0x821A2548,InflatorAddaptive);

	WRITE_DWORD(0x821A2510,FrontCurveStateAddaptive);


	WRITE_DWORD(0x821A2524,FrontLeverAddaptive);
	WRITE_DWORD(0x821A2570,SwimingStateAddaptive);
	WRITE_DWORD(0x821A2534,HandleStateAddaptive);
	WRITE_DWORD(0x821A255C,SteamWipeAddaptive);

#endif

  //Other stuff



//	WRITE_DWORD(0x821A22F0,Dummy);
//	WRITE_DWORD(0x821A22DC,Dummy);
//	WRITE_DWORD(0x821A2304,Dummy);
//	WRITE_DWORD(0x821A22F0,Dummy);
	//WRITE_DWORD(0x821A22C8,Dummy);
	//WRITE_DWORD(0x821A2314,Dummy);

	//Now i cant confirm (Get Sead And etc)
//	WRITE_DWORD(0x821A22A8,Dummy);
	//WRITE_DWORD(0x821A1C08,Dummy);




	//WRITE_DWORD(0x82B09EA4,OtherCharacterUpdateSome);
	//WRITE_DWORD(0x821A2418,sub_822CA518);
//	WRITE_DWORD(0x821A2368,sub_822CA518);
//	WRITE_DWORD(0x821A2494,sub_822CA518X);
	INSTALL_HOOK(SelfViewUpdate);

	

	INSTALL_HOOK(sub_82494658);



//	INSTALL_HOOK(sub_822AB3B0);


	//INSTALL_HOOK(sub_8226D7B0);
	//INSTALL_HOOK(sub_82287200);
	//INSTALL_HOOK(sub_82251018);
	//INSTALL_HOOK(sub_82452FF0)
	//INSTALL_HOOK(sub_824A0458); //Just Attack to update input with game speed
	INSTALL_HOOK(sub_8246A6D0); //MoveFuckingCursorInputDetection

	//WRITE_DWORD(0x824543CC,0x7FE3FB78);
//	WRITE_DWORD(0x823F3144,0x7FC3F378);
//	WRITE_DWORD(0x8245435C,0x7FE3FB78);







	//INSTALL_HOOK(sub_82A54AE0); //ThisIsMaybeConfirmInput Required Special Param That means is Will be Runned(in lua for now)(just Remote commands)
	INSTALL_HOOK(sub_823EF348); //MessageBoxInputResult
	WRITE_DWORD(0x821A8D34,sub_824578F0);
	//const int stackSize = 65536;
	//HANDLE Thr = CreateThread( NULL, stackSize, ThreadProc, (VOID *)0, CREATE_SUSPENDED, NULL );
	//ResumeThread(Thr);
	//WRITE_DWORD(0x821A8C38,TitleFunc02);
	//WRITE_DWORD(0x821A8EA8,Riders__MenuNRItem__V0Unk03);
	

//	INSTALL_HOOK(sub_82439760); //Microphone
	//INSTALL_HOOK(sub_824E69A8);
//	WRITE_DWORD(0x821A8CCC,sub_8244F880);
//	WRITE_DWORD(0x821A8CD0,sub_82451300);

//  WRITE_DWORD(0x82198974,sub_822340D0);
//WRITE_DWORD(0x824B2C48,0x4E800020);
//WRITE_DWORD(0x821AA8DC,sub_824B2C48);
//WRITE_DWORD(0x821AA68C,sub_824B0018);
	//WRITE_DWORD(0x82050E40,sub_8270EDD0);
//	WRITE_DWORD(0x821AB504,sub_824C6440);
//	WRITE_DWORD(0x821AB4E8,XamInputModuleBase);
	//INSTALL_HOOK(sub_8223A578);
	//WRITE_NOP(0x824C6248,1);
	//WRITE_DWORD(0x824C6268,0x4800000C);
	//INSTALL_HOOK(sub_82A70D30);
	//WRITE_NOP(0x824C6308,1);
	//WRITE_NOP(0x824C631C,1);

}





namespace ModLoaderTest{



	int __declspec( naked ) sub_8249D028H(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){
		__asm{
			mflr r12
				std       r25, -0x30(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0x200(r1)
				mr        r30, r8
				lis r11,0x8249
				ori r11,r11,0xD038
				mtctr r11
				bctr r11
		}
	}

	int __declspec( naked ) sub_8249D028HX(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){
		__asm{
			    mflr r12
				std       r25, -0x30(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0x200(r1)
				mr        r30, r8
				lis r11,0x8249
				ori r11,r11,0xD038
				mtctr r11
				bctr
		}
	}








	int __declspec( naked ) sub_8249D028_Remade(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){

		__asm{
		    mflr      r12
		

				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw r12,-8(r1)

			stwu      r1, -0x200(r1)
			mr        r30, r8
			mr        r25, r3
			mr        r29, r4
			mr        r28, r5
			mr        r31, r6
			mr        r27, r7
			mr        r8, r9
			mr        r26, r10
			cmplwi    cr6, r9, 0
			bne       cr6, loc_8249D064
		//	bl        sub_82211440()

			lis r11,0x8221
			ori r11,r11,0x1440
			mtctr r11
			bctrl

			lwz       r8, 4(r3)
loc_8249D064:                           
										cmplwi    cr6, r30, 0
										beq       cr6, loc_8249D074
										li        r11, 1
										stw       r11, 0(r30)
loc_8249D074:                           
										li        r10, 1
										stw       r30, 0x54(r1)
										mr        r9, r26
										mr        r7, r31
										mr        r6, r28
										mr        r5, r29
										mr        r4, r27
										addi      r3, r1, 0x70
										//bl        sub_8249EC20
										//qASMBranch(r11,0x8249,0xEC20)
										lis r11,0x8249
										ori r11,r11,0xEC20
										mtctr r11
										bctrl


										rlwinm    r11, r31, 0,26,26
										li        r10, 0
										cmplwi    cr6, r11, 0
										std       r10, 0x60(r1)
										beq       cr6, loc_8249D0F0
										lwz       r31, 0x8C(r25)
										mr        r3, r31
										lwz       r11, 0(r31)
										lwz       r10, 8(r11)
										mtctr     r10
										bctrl
										addi      r4, r1, 0x70
										addi      r3, r25, 0x20
									//	bl        loc_8249DD08
										//qASMBranch(r11,0x8249,0xDD08)

										lis r11,0x8249
										ori r11,r11,0xDD08
										mtctr r11
										bctrl

										lwz       r9, 0(r31)
										mr        r3, r31
										lwz       r8, 0xC(r9)
										mtctr     r8
										bctrl
										ld        r3, 0x60(r1)
										addi      r1, r1, 0x200
										ld       r25, -0x40(r1)
										ld       r26, -0x38(r1)
										ld       r27, -0x30(r1)
										ld       r28, -0x28(r1)
										ld       r29, -0x20(r1)
										ld       r30, -0x18(r1)
										ld       r31, -0x10(r1)
										lwz       r12, -8(r1)
										mtlr r12
										blr
loc_8249D0F0:                          
										lwz       r11, 0x1A0(r1)
										addi      r4, r1, 0x70
										mr        r3, r25
										cmplwi    cr6, r11, 0
										bne       cr6, loc_8249D11C
										addi      r11, r1, 0x60
										stw       r11, 0x1A0(r1)
										//bl        loc_8249CEB0
										//qASMBranch(r11,0x8249,0xCEB0)


										lis r11,0x8249
										ori r11,r11,0xCEB0
										mtctr r11
										bctrl

										ld        r3, 0x60(r1)
										addi      r1, r1, 0x200
									


										ld       r25, -0x40(r1)
										ld       r26, -0x38(r1)
										ld       r27, -0x30(r1)
										ld       r28, -0x28(r1)
										ld       r29, -0x20(r1)
										ld       r30, -0x18(r1)
										ld       r31, -0x10(r1)
										lwz       r12, -8(r1)
										mtlr r12
										blr

loc_8249D11C:                           
										//bl        loc_8249CEB0
									//	qASMBranch(r11,0x8249,0xCEB0)

										lis r11,0x8249
										ori r11,r11,0xCEB0
										mtctr r11
										bctrl


										lwz       r11, 0x1A0(r1)
										ld        r3, 0(r11)
										addi      r1, r1, 0x200
										ld       r25, -0x40(r1)
										ld       r26, -0x38(r1)
										ld       r27, -0x30(r1)
										ld       r28, -0x28(r1)
										ld       r29, -0x20(r1)
										ld       r30, -0x18(r1)
										ld       r31, -0x10(r1)
										lwz       r12, -8(r1)
										mtlr r12
										blr

		}

	}

	int SaveParams[] = {0,0,0,0,0,0,0,0};
	HOOK(int,__fastcall,sub_8249D028,0x8249D028,int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){

	

		DWORD result;
		

		std::string stru = std::string((char*)a2);
		stru.insert(6,"mods\\");

// Open the file for reading
	HANDLE hFile = CreateFile( stru.c_str(), GENERIC_READ, 0, NULL,		OPEN_EXISTING, 0, NULL );

	 if( INVALID_HANDLE_VALUE != hFile ){
		 DebugLogRestore::log.push_back(new std::string((char*)stru.c_str()));
		// DebugLogRestore::log.push_back(new std::string((char*)a3));

		result =  sub_8249D028_Remade(a1,(int)stru.c_str(),a3,a4,a5,a6,a7,a8);
		result = sub_8249D028_Remade(a1,a2,a3,a4,a5,1,a7,1);
		
	}
	 else{
		 result = sub_8249D028_Remade(a1,a2,a3,a4,a5,a6,a7,a8);
	 }
	
	



		//DebugLogRestore::log.push_back(new std::string((char*)a2));


	

		return result;

	}


	void GlobalInstall(){

		INSTALL_HOOK(sub_8249D028)
	}
}

namespace KinectTESTEX{

	int __fastcall TrickROTStateAddaptiveT(int a1, StateA2P *a2, _DWORD *a3){


		DWORD result = BranchTo(0x822C9938,int,a1,a2,a3);

		if (result == 1){

			ShowXenonMessage(L"DEBUG",*(float *)(a1 + 0x4C),0);
			ShowXenonMessage(L"DEBUG",(int)*(_BYTE *)(a1 + 0x50) ,0);
			ShowXenonMessage(L"DEBUG",*(float *)(0x54 * a3[2] + *a3 + 0x38),0);


		}




		return result;


	}



	void GlobalInstall(){


			WRITE_DWORD(0x821A23D0,TrickROTStateAddaptiveT);
	}
}





ZLua::ZLua(void)
{
	OpenLua();
	UseBaseLibs();



	executed = false;
}

ZLua::~ZLua(void)
{
	lua_close(L);
}
ZLua::ZLua(const char* a1){
	FilePath = std::string(a1);
	OpenLua();
	UseBaseLibs();
	executed = false;
	
	
}
void ZLua::UseBaseLibsEx(lua_State* L){
	
	lua_register(L,"LOG",DebugLogRestore::LogNext);
	lua_register(L,"DLOG",DebugLogRestore::Log);
	lua_register(L,"FixedMessage",DebugLogRestore::LogNext);
	lua_register(L,"GetIntField",DebugLogRestore::GetIntField);
	lua_register(L,"SetIntField",DebugLogRestore::SetIntField);
	lua_register(L,"SetFloatField",DebugLogRestore::SetFloatValue);
	lua_register(L,"GetFloatField",DebugLogRestore::GetFloatField);
	lua_register(L,"WriteVirtualBytes",DebugLogRestore::WriteVirtialBytes);
	lua_register(L,"WriteVirtualFloat",DebugLogRestore::WriteVirtialFloat);
	lua_register(L,"WriteVirtualInt",DebugLogRestore::WriteVirtialInt);
	lua_register(L,"WriteVirtualShort",DebugLogRestore::WriteVirtialShort);
	lua_register(L,"WriteVirtialBytesRange",DebugLogRestore::WriteVirtialBytesRange);
	lua_register(L,"StateChangeState",DebugLogRestore::StateChangeState);
	lua_register(L,"AddCustomState",DebugLogRestore::AddCustomState);
	lua_register(L,"CallCPLUSFunc",DebugLogRestore::CallCPLUSFunc);
	lua_register(L,"HEX",DebugLogRestore::HEX);
	lua_register(L,"Malloc",DebugLogRestore::MallocX);
	lua_register(L,"Free",DebugLogRestore::FreeX);
	lua_register(L,"NewString",DebugLogRestore::NewString);
	lua_register(L,"FreeString",DebugLogRestore::FreeString);
	lua_register(L,"CallCPLUSFuncF",DebugLogRestore::CallCPLUSFuncF);
	lua_register(L,"reload",DebugLogRestore::LuaDoFile);


	lua_newtable(L);
	lua_setglobal(L,"Bit");


	lua_getglobal(L,"Bit");
	lua_registerex1(L,"SL",DebugLogRestore::BIT_ShiftLeft,-1);
	lua_registerex1(L,"SR",DebugLogRestore::BIT_ShiftRight,-1);
	lua_registerex1(L,"AND",DebugLogRestore::BIT_AND,-1);
	lua_registerex1(L,"OR",DebugLogRestore::BIT_OR,-1);

	lua_pop(L,1);
	lua_newtable(L);
	lua_setglobal(L,"script");

	lua_getglobal(L,"script");
	lua_registerex1(L,"reload",DebugLogRestore::LuaDoFile,-1);

	lua_pop(L,1);

	lua_newtable(L);
	lua_setglobal(L,"Memory");

	lua_getglobal(L,"Memory");
	lua_registerex1(L,"WriteByte",DebugLogRestore::Memory_WriteByte,-1);
	lua_registerex1(L,"WriteInt",DebugLogRestore::Memory_WriteInt,-1);

	lua_registerex1(L,"GetByte",DebugLogRestore::Memory_GetByte,-1);
	lua_registerex1(L,"GetInt",DebugLogRestore::Memory_GetInt,-1);


	lua_pop(L,1);








	


}

void ZLua::UseBaseLibs(){

	luaopen_base(this->L);
	luaopen_string(this->L);
	luaopen_table(this->L);
	luaopen_math(this->L);
	UseBaseLibsEx(L);

}
void ZLua::OpenLua(){
	L = lua_open();


}

const char* ZLua::GetGlobalString(const char* string){

	lua_getglobal(this->L,string);
	return lua_tostring(this->L,-1);
	
}


int ZLua::GetGlobalBool(const char* string){

	lua_getglobal(this->L,string);
	return lua_toboolean(this->L,-1);

}
int ZLua::GetGlobalInt(const char* string){

	lua_getglobal(this->L,string);
	return lua_tonumber(this->L,-1);
}


int ZLua::GetGlobalIntNew(char* st,bool useglobal){

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

void Errors(){

}


static int report (lua_State *L, int status) {
	const char *msg;
	if (status) {
		msg = lua_tostring(L, -1);
		if (msg == NULL) msg = "(error with no message)";
		fprintf(stderr, "status=%d, %s\n", status, msg);
		lua_pop(L, 1);
	}
	return status;
}


void ZLua::DoFile(bool ignore){


	locked = true;

	if (ignore){

		executed =false;

	}
	

	if (!executed) {
		
		
		if (luaL_loadfile(L, FilePath.c_str()) == LUA_ERRSYNTAX ){
			ShowXenonMessage(L"ERROR",lua_tostring(L,-1));
			lua_close(L);
			Sleep(10000);
			exit(0);
			return;
		}
	     else{
		  lua_pcall(L, 0,0,0);
		}

	//	   ShowXenonMessage(L"DUMBY",luaL_loadfile(L, FilePath.c_str()),0);
		

	
		




	
	
	
	
	
	   executed = true;



	}
		locked = false;
}
//testing
void ZLua::CallFunction(){

}




#endif