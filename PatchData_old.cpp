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



//////////////


bool FPS_LIMIT_60 = 0;









DWORD DPAD_LEFT_RING = false;
DWORD DPAD_RIGHT_RING = false;
DWORD MENU_BUTTON_A = false;
DWORD MENU_BUTTON_Y = false;


DWORD P1Slot = 0;
DWORD P2Slot = 1;

const byte ConnectSessionID[8] = {0,0,0,0,0,0,0,0};



ZLua CommonLua = ZLua("game:\\common\\test.lua");


static ATG::GAMEPAD* gc = &ATG::Input::m_Gamepads[P1Slot];
static ATG::GAMEPAD* gc2P = &ATG::Input::m_Gamepads[P2Slot];









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
			memcpy((void*)ADDR(i),(void*)0x8227CC80,strlen(cu)/2);
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


//static byte NuiFakeDeviceExUnk[2048];









bool Button_A_Hold = false;
bool Button_X_Hold = false;
bool Button_Y_Toggle = false;
bool Menu_START_BUTTON_PRESS = false;

byte BrakePreLoadD0[] = {0x3E,0xA3,0xD7,0x0A,0xBE,0x99,0x1F,0xEB,0xC0,0x02,0xDC,0xBD,0x3F,0x80,0x00,0x00};
byte BrakePreLoadE0[] = {0x3E,0xA6,0x32,0xF8,0xBF,0x27,0xE8,0xE1,0xC0,0x05,0x6F,0x92,0x3F,0x80,0x00,0x00};
byte BrakePreLoad110[] = {0x3D,0xB7,0x32,0x3E,0xBE,0x97,0x3C,0xB6,0xC0,0x01,0x83,0xCA,0x3F,0x80,0x00,0x00};
byte BrakePreLoad210[] = {0x3E,0xA5,0x10,0xCD,0xBE,0x99,0x1F,0xEB,0xC0,0x02,0xDC,0xBD,0x3F,0x80,0x00,0x00};
byte BrakePreLoad250[] = {0x3D,0xB9,0x91,0x62,0xBE,0x97,0x20,0x2A,0xC0,0x01,0x3F,0xDD,0x3F,0x80,0x00,0x00};



bool once = false;
DWORD seg_83E52F84Fake[1000];
DWORD InputSomeUnkStaticA0Fake[100];
DWORD dword_83E53144Fake[100];




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



int __fastcall UUUUUUUUUUUUUUUUUUUUAD(int result)
{


return BranchTo(0x822CEB10,int,result);
}




HOOK(int,__fastcall,sub_82ACC28C,0x82ACC28C){

	
	return 0;
}

int DriftStateHandle(int a1){

return a1;

}




float test = 0.0;




HOOK(float,__fastcall,sub_82A54518,0x82A54518,int a1){

	return 0.0;
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

			*(float *)(v11 + 384) = *(float *)(v12 + 40) + *(float *)(v11 + 384) +  gc->fX1 * MBKinnectInput->PclsXbox360System->GameSpeed / (10.0*v9);
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
	v4 = v3->PclsXbox360System;
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

//	v4->GameSpeed = GameSpeed;
//	v4->gap38[0x20] = (int)FrameRateValue;
//	v4->dword1C = (int)CalculatedFrameRateEX;
//	v4->gap38[0x21] = 1;
//	*(float *)&v4->gap8[4] = FrameRateValue;
//	*(float *)&v4->gap8[8] = CalculatedFrameRate;
//	v4->CameraSpeed = GameSpeed;
//	*(float *)v4->gap18 = GameSpeed;




	return result;

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















int __declspec( naked ) InputOrGraphicStuffh(int a1){
	__asm{
		mflr      r12
			stw       r12, -8(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			lis r11,0x824A
			ori r11,r11,0x0468
			mtctr r11
			bctr r11
	}
}


HOOK(int,__fastcall,InputOrGraphicStuff,0x824A0458,int a1){




	 int result = InputOrGraphicStuffh(a1);






	 return result;




}
clock_t start, end; 
time_t startt, endt; 
int cc = 0;

LARGE_INTEGER ticks;
LARGE_INTEGER ticksend;


int __fastcall clsXbox360System_Func01(int a1)
{
	if (cc % 2 == 0)
	{
		start = clock();
		time(&startt);
		QueryPerformanceCounter(&ticks);
	}
	if (cc % 2 != 0){
		end = clock();
		time(&endt);
		QueryPerformanceCounter(&ticksend);
	}



	if (end != 0 && start != 0){

		//ShowXenonMessage(L"Msg",end-start,0);

		unsigned long long local = 6;
		if (end > local){
			
			Sleep((end-start-local));

			
		}

		end = 0;
		start = 0;


	}



	cc++;
	return *(unsigned __int8 *)(a1 + 0x5A);
}





LARGE_INTEGER t1;
LARGE_INTEGER t2;

double CurrentTime;
HOOK(int,__fastcall,sub_82211C08,0x82211C08,struct_MBKinnectInput* atgu){
	



	QueryPerformanceCounter(&FrameStart);




	return 	BranchTo(   *( int*)((*(int*)&MBKinnectInput->PclsXbox360System->gap0) +0x4)     ,int,MBKinnectInput);
		



}

unsigned float FPS_LIMIT =  60;
float FPS_LIMIT_CALC = (1.0/(float)FPS_LIMIT)*1000.0;
float FPS_LIMIT_CALC_T = (1.0/(float)FPS_LIMIT);

float secondsElapsedGlobal = 0.0f; //

HOOK(int,__fastcall,sub_82211ECC,0x82211ECC,struct_MBKinnectInput* atg){


	//if (NearKinnectNuiBox::Instance)
	{

	
	
		
		float secondsElapsed  = GetDeltaFrameE();

//		ShowXenonMessage(L"MSG",secondsElapsed,0);
		secondsElapsedGlobal = 0.0f;
		if (FPS_LIMIT_CALC_T  > secondsElapsed){ // IF GAME Faster than 60 FPS

			
		//	ShowXenonMessage(L"msg",secondsElapsedGlobal,0);
			SleepEx(FPS_LIMIT_CALC - secondsElapsed,false);
		}

		if (FPS_LIMIT_CALC_T  < secondsElapsed){ // IF Game Slowe Than 60 Fps
			
			secondsElapsedGlobal = secondsElapsed-FPS_LIMIT_CALC_T;
		}



		//FPS =  1/ secondsElapsed






	}

	
	return 	BranchTo(   *( int*)((*(int*)&MBKinnectInput->PclsXbox360System->gap0) +0x4)     ,int,MBKinnectInput);


}




#pragma region DeltaUpdateFunctuinsAndHooks




HOOKN(void,__fastcall ,sub_822AA29C,0x822AA2A8){

	__asm{
		mflr r12
		stw r12,-8(r1)
		stwu r1,-0x10(r1)


		bl GetDeltaFrameEX
		fmr fp11,fp1


	
		addi r11,r1,0x10
		lfs       fp0, 0x60(r11)
		lfs       fp13, 0x64(r11)
		lfs       fp12, 0x68(r11)

		//lwz       r11, 0x16A0(r11)
	//	lwz       r10, 0x18(r11)
		//lfs       fp11, 0x28(r10)

		addi r1,r1,0x10
		lwz r12,-8(r1)
		mtlr r12
		blr
	}

}


HOOKN(void,__fastcall,sub_8227B658,0x8227B658){
	__asm{
			mflr r12
			stw r12,-8(r1)
			stwu r1,-0x10(r1)
	}


	{
		float ffp  = 0.0f;
	}




	__asm{

			fmr fp31,ffp
		    addi r1,r1,0x10
			lwz r12,-8(r1)
			mtlr r12
			blr
	}
}


HOOKN(void,__fastcall,sub_8227B648,0x8227B648){
	__asm{
		   mflr r12
			stw r12,-8(r1)
			stwu r1,-0x10(r1)
	}


	__asm{


		fsubs     fp11, fp13, fp0
		bl GetDeltaFrameE
		fmr fp30,fp1
		fsubs     fp10, fp12, fp0
		fdivs     fp31, fp11, fp10
	}


	__asm{

		
			addi r1,r1,0x10
			lwz r12,-8(r1)
			mtlr r12
			blr
	}


}



HOOKN(void,__fastcall,sub_822AB780,0x822AB780){
	__asm{
		    mflr r12
			stw r12,-8(r1)
			stwu r1,-0x10(r1)
	}


	__asm{


			
			bl GetDeltaFrameEX
			lfs       fp0, 0x748(r31)
			fmuls fp1,fp1,fp0


	
	}


	__asm{


		addi r1,r1,0x10
			lwz r12,-8(r1)
			mtlr r12
			blr
	}


}

int _declspec( naked ) sub_0x822C0BECH(){
	__asm{

		li r27,0x0
		sth       r27, 0xB8(r1)
		blr

	}

}

HOOK(int,__fastcall,sub_0x822C0BEC,0x822C0BEC,struct_v1 *v2,int v4,float a1){
	
	
	*(float *)&v2->field_8F4 = (float)*(_DWORD *)(v4 + 4);        // OnStart First Value
	*(float *)&v2->field_8F8 = *(float *)v4 / (float)a1;
	v2->pfloat690->float_C48 = 0.0;
	


	return sub_0x822C0BECH();


}

HOOK(int,__fastcall,sub_0x822C0A20,0x822C0A24,struct_v1 *v2,int v4){


	__int64 v5;
	struct_pfloat690* v7 = v2->pfloat690;


	float v8 = *(float *)&v2->field_8F8;

	float* field_8F4 = (float*)&v2->field_8F4;

	

	*field_8F4 = *field_8F4 - MBKinnectInput->PclsXbox360System->SpeedSome;


	float field_8F4_pre = *field_8F4;

	v7->floatC44 =   (float)( field_8F4_pre* field_8F4_pre )* v8;

	if ( field_8F4_pre <= 0.0 )
	{
		v2->pfloat690->floatC44 = 0.0;
		auto v10 = *(float *)v4;
		auto v11 = v2->pfloat690;
		auto v12 = (*(_DWORD *)(v4 + 4) + 1) * *(_DWORD *)(v4 + 4) / 2;
		auto v78 = v12 ;
		v11->float_C48 = (float)v10 / (float)v78;
		auto v13 = v2->pfloat690;
		if ( v13->float_C48 < 0.0099999998 )
			v13->float_C48 = 0.0099999998;
		auto v14 = v2->field_968 + 1;
		v2->dword954 = 2;
		v2->field_968 = v14;
	}

	return 0;

}


#pragma endregion DeltaUpdateFunctuinsAndHooks








//Camera
HOOK(int,__fastcall,sub_8227BB98,0x8227BCCC,unsigned int a1,unsigned int stack,unsigned int params){



	XMVECTORF32* _s50 = (XMVECTORF32*)(stack + 0x50);
	XMVECTORF32* _sF0 = (XMVECTORF32*)(stack + 0xF0);
	XMVECTORF32* _s100 = (XMVECTORF32*)(stack + 0x100);

	_s50->f[0]= 0;
	_s50->f[1]=  0;
	_s50->f[2]= 0;
	_s50->f[3]= 0;

	_sF0->f[0] = 0;
	_sF0->f[2] = 0;
	_sF0->f[3] = 0;
	_sF0->f[4] = 0;

	_s100->f[0] = 0;
	_s100->f[2] = 0;
	_s100->f[3] = 0;
	_s100->f[4] = 0;





	return 0;

}

void GlobalInstall(){




	//Do Lua First
	//CommonLua.DoFile(true);


	gc = &ATG::Input::m_Gamepads[CommonLua.GetGlobalIntNew((char*)"Gamepad_Slots.P1",true)];
	gc2P = &ATG::Input::m_Gamepads[CommonLua.GetGlobalIntNew((char*)"Gamepad_Slots.P2",true)];

	FPS_LIMIT_60 = CommonLua.GetGlobalBool("FPS_LIMIT_60");



	float valu = CommonLua.GetGlobalFloat("FPS_LIMIT");
	if ( valu!= 0.0 ){

		FPS_LIMIT =  valu;
		FPS_LIMIT_CALC = (1.0/(float)FPS_LIMIT)*1000.0;
		FPS_LIMIT_CALC_T = (1.0/(float)FPS_LIMIT);
		FrameDelay = 1000 / FPS_LIMIT;

	}




	//WRITE_DWORD(0x821AAA54,clsXbox360System_Func01);

	if (FPS_LIMIT_60){


	//	WRITE_DWORD(0x8227BCC0,0x7FC3F378);
	//	WRITE_DWORD(0x8227BCC4,0x7C240B78);
	//	WRITE_DWORD(0x8227BCC8,0x7D655B78);
			


//		INSTALL_HOOKR(sub_8227BB98);
		INSTALL_HOOKR(sub_82211C08);

		// INSTALL_HOOKR(sub_82211ECC);

		//--beq cr6, -(0x82211EE4-0x82211C04)
		WRITE_DWORD(0x82211EE4,0x419AFD20);
		INSTALL_HOOK(GameSpeedControllerUpdate);


#pragma region Delta_Update

		INSTALL_HOOK(sub_822A9F58);

		WRITE_NOP(0x822C0BE4,1);
		WRITE_NOP(0x822C0A14,0x32);


		WRITE_NOP(0x822C11C8,1);
		WRITE_NOP(0x822C0FFC,0x32);


		WRITE_DWORD(0x82B09ED4,TrickRampTypeA_360);
		WRITE_DWORD(0x82B09ED8,TrickRampTypeA_360_B);

		//WRITE_DWORD(0x822C0A1C,0x7FE3FB78); // mr r3,r31
		//WRITE_DWORD(0x822C0A20,0x7FC4F378); // mr r3,r31
		//WRITE_NOP(0x822C0A34,42);
		//INSTALL_HOOKR(sub_0x822C0A20);



		//WRITE_DWORD(0x822C0BE0,0x7FE3FB78); // mr r3,r31
		//WRITE_DWORD(0x822C0BE4,0x7FC4F378); // mr r4,r30
		//WRITE_DWORD(0x822C0BE8,0xFC200090); // mr r4,r30
		//INSTALL_HOOKR(sub_0x822C0BEC);


		//INSTALL_HOOKR(sub_822AB780);

		//INSTALL_HOOKR(sub_8227B648);


		//INSTALL_HOOKR(sub_8227B658);
		//WRITE_NOP(0x8227B668,1);

		//INSTALL_HOOKR(sub_822AA29C);


#pragma endregion Delta_Update









	}



	INSTALL_HOOK(InputOrGraphicStuff); //USELES




	//CommonLua.GetGlobalInt("ConnectPort")
	
	
	//SetSessionID();



	INSTALL_HOOK(EtxProducerRegistersFake); //+
	//INSTALL_HOOK(sub_8248B438);

	//ShowXenonMessage(L"MSG",(int)&GameSpeed,0);
//	WRITE_DWORD((0x8222B568),0x3D000000 | (ADDRESS_HIGHER((DWORD)&GameSpeed) & 0xFFFF));
//	WRITE_DWORD((0x8222B580),0xC0080000 | (ADDRESS_LOWER((DWORD)&GameSpeed) & 0xFFFF));
	

//	INSTALL_HOOK(sub_822A4770);// Fix Cailibration Global

	
	//INSTALL_HOOK(sub_8222B520);


	INSTALL_HOOK(XamShowNuiSigninUIE); //+
	INSTALL_HOOK(XamShowNuiDeviceSelectorUI); //+
	INSTALL_HOOK(sub_824D0CE8); //+



	//NETPLAY
	INSTALL_HOOK(sub_8248B560); //+


	WRITE_DWORD(0x8222CA38,0x4E800020); //+
	WRITE_DWORD(0x8226086C,0x60000000); //fix free hand timer +
	WRITE_DWORD(0x82260754,0x60000000); //fix free hand timer +



	WRITE_DWORD(0x82456B14,0x4800004C); //SURSOR +



	//Others Fixes (fro input)
	WRITE_DWORD(0x82222B80,0x4E800020);  //+
	WRITE_DWORD(0x8222302C,0x60000000);// +
	WRITE_DWORD(0x82223084,0x60000000); // +

	
	
	WRITE_DWORD(0x821A2484,0x822C8958);// Bike Move Fix +



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

	INSTALL_HOOK(sub_82ACB43C); //Fake XamNuiGetDeviceStatus +
	//INSTALL_HOOK(sub_82A54518); //fixall
	INSTALL_HOOK(sub_823DC2D0); // +
	INSTALL_HOOK(sub_82452198); //+
	

#ifndef TTT// +
 
	

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
	INSTALL_HOOK(SelfViewUpdate); //+

	

	INSTALL_HOOK(sub_82494658); //+



//	INSTALL_HOOK(sub_822AB3B0);


	//INSTALL_HOOK(sub_8226D7B0);
	//INSTALL_HOOK(sub_82287200);
	//INSTALL_HOOK(sub_82251018);
	//INSTALL_HOOK(sub_82452FF0)
	//INSTALL_HOOK(sub_824A0458); //Just Attack to update input with game speed
	INSTALL_HOOK(sub_8246A6D0); //MoveFuckingCursorInputDetection +

	//WRITE_DWORD(0x824543CC,0x7FE3FB78);
//	WRITE_DWORD(0x823F3144,0x7FC3F378);
//	WRITE_DWORD(0x8245435C,0x7FE3FB78);







	//INSTALL_HOOK(sub_82A54AE0); //ThisIsMaybeConfirmInput Required Special Param That means is Will be Runned(in lua for now)(just Remote commands)
	INSTALL_HOOK(sub_823EF348); //MessageBoxInputResult +
	WRITE_DWORD(0x821A8D34,sub_824578F0); // +
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
	if (lua_isboolean(this->L,-1)){
		return lua_toboolean(this->L,-1);
		lua_pop(this->L,1);
	}
	return false;

}
float ZLua::GetGlobalFloat(const char* string){

	lua_getglobal(this->L,string);
	if (lua_isnumber(this->L,-1)){
		return lua_tonumber(this->L,-1);
		lua_pop(this->L,1);
	}
	return 0.0;

}
int ZLua::GetGlobalInt(const char* string){


	lua_getglobal(this->L,string);

	if (lua_isnumber(this->L,-1)){
		return lua_tonumber(this->L,-1);
		lua_pop(this->L,1);
	}

	return 0;
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