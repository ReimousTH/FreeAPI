#pragma once


#include "../HookV2.h"
#include "../RidersFree.h"
#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"


#include <string>
#include <vector>

#include <xam.h>
#include <xtl.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "InputData.h"

namespace ModLoader{

	extern std::vector<HANDLE> _Files;

	void Install();
	
}