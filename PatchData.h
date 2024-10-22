#pragma once

#include <xtl.h>

#include "HookV2.h"
#include "Basics.h"
#include "All06Functions.h"
#include "IdaExports.h"
#include "RidersFree.h"



#include "Patches/DLL_LUA.h"
#include "Patches/KernelReplacement.h"

#include "Patches/InputData.h"
#include "Patches/InputData_Actions.h"
#include "Patches/InputData_CommonActions.h"
#include "Patches/InputData_CutSceneActions.h"
#include "Patches/InputData_MenuActions.h"
#include "Patches/InputData_TitleActions.h"
#include "Patches/Characters_IStateActions.h"

#include "Patches/DeltaTimerUpdate.h"

#include "Patches/ModLoader.h"
#include "Patches/NetPlayFiX.h"



namespace PatchData{
	void InstallGB();
}
