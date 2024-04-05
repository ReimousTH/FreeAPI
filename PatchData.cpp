#include "PatchData.h"



namespace PatchData{


	
 void InstallGB()
{
	
	HookV2::IsNotEmulatedHardWare =  HookV2::CheckIsNotEmulatedHardWare();
	KernelR::Install();
	DLL_LUA_INSTALL();
	if (CommonLua.error){ ShowXenonMessage(L"MSG",CommonLua.error_msg); return ;}

	if (CommonLua.GetGlobalBoolean("DeltaTimer")){DeltaTimerU::Install();}

	InputData::Install();
	InputData::Install_Actions();
	InputData::Install_CommonActions();
	InputData::Install_CutsceneActions();
	InputData::Install_MenuActions();
	InputData::Install_TitleActions();
	CIStateActions::Install();
	ModLoader::Install();

}

}