#pragma once

#include "InputData.h"


#include "../HookV2.h"
#include "../RidersFree.h"
#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"


#include <string>
#include <vector>


namespace CIStateActions{
	
	static int ST1[] = {0x8218B518,0x8218B4F8};
	static float correct_stick = 0.45f;

	void Install();
	
}