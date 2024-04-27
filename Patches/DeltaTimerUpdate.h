#pragma once


#include "../HookV2.h"
#include "../RidersFree.h"
#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"


#include <string>
#include <vector>
#include <xtl.h>


namespace DeltaTimerU{
	

#pragma region FPS_LIMIT


	extern LARGE_INTEGER FrameStart;
	extern LARGE_INTEGER FrameStartfrequency;



	static void GetDeltaFrameStart(){

		QueryPerformanceCounter(&FrameStart);
		QueryPerformanceFrequency(&FrameStartfrequency);

	}

	static double GetDeltaFrameCurrent(){

		LARGE_INTEGER currentCount, frequency;
		QueryPerformanceCounter(&currentCount);
		QueryPerformanceFrequency(&frequency);

		return static_cast<double>(currentCount.QuadPart - FrameStart.QuadPart) / frequency.QuadPart;

	}



#pragma endregion FPS_LIMIT

	void Install();
	
}