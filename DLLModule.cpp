#pragma warning(push)
#pragma warning(disable: 4101)
#pragma warning(pop)


#include "PatchData.h"



//-----------------------------------------------------------------------------
// Name: DllMain()
// Desc: The function which is called at initialization/termination of the process
//       and thread and whenever LoadLibrary() or FreeLibrary() are called.
//       The DllMain routine should not be used to load another module or call a
//       routine that may block.
//-----------------------------------------------------------------------------





BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
                     )
{






//	lua_State* a = luaL_newstate();

	



	

	//luaL_loadfile(a,"game:\\Test.lua");
	//luaL_loadstring(a,"x=42");

	//lua_getfield(a,0,"x");




	//lua_Number x = 	lua_tonumberx(a,1,0);
	



    switch (ul_reason_for_call)
    {

    case DLL_PROCESS_ATTACH:
	
	
		PatchData::InstallGB();
		//lua_Reader
		//lua_load(L,
		//luaL_dofile(LS,"game:\\start.lua");





		 // MPatches::INSTALL_PATCH(MPatches::TAILS_GAUGE);
//DebugCHR();
		//main();

	     // MPatches::INSTALL_PATCH(MPatches::CharacterSwitcher);
		  //MPatches::INSTALL_PATCH(MPatches::SpindashNew);
	//	MPatches::INSTALL_PATCH(MPatches::TAILS_GAUGE);
	//	MPatches::INSTALL_PATCH(MPatches::TAGPATCH);
		
	//w	MPatches::INSTALL_PATCH(MPatches::UITable3B);
		//MPatches::INSTALL_PATCH(MPatches::PhysicsRestoration);



		
//		MPatches::INSTALL_PATCH(MPatches::SpindashNew);
		
		//MPatches::INSTALL_PATCH(MPatches::SonicSwitchFast);

	//	OmegaHoverFix::GlobalInstall();




		
	

		
		

		


		
		
		

	
		//XCReateFile()
	 
		

		
		//Hook::DataSection_NR_ReHook((void*)0x82219320,MarathonRework::ContextPlayerSonicHOOK);
		//Hook::DataSection_NR_ReHook((void*)0x82219530,MarathonRework::ContextPlayerSonicCoreHOOK);



		
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;

    }
    return TRUE;
}

//-----------------------------------------------------------------------------
// Desc: Export a global constant variable
//-----------------------------------------------------------------------------
extern "C" const TCHAR szModuleName[] = TEXT("DLLModule.dll");

//-----------------------------------------------------------------------------
// Name: Function1()
// Desc: Export function
//-----------------------------------------------------------------------------




