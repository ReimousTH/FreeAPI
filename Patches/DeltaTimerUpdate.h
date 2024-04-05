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

	static int FrameDelay;
	static LARGE_INTEGER FrameStart;
	static LARGE_INTEGER FrameEnd;
	static int FrameTime;


	static double GetPerformanceFrequency(){
		LARGE_INTEGER frame;
		QueryPerformanceFrequency(&frame);
		return (double)frame.QuadPart;
	}
	static unsigned long long GetPerformanceCounter(){
		LARGE_INTEGER frame;
		QueryPerformanceCounter(&frame);
		return frame.QuadPart;
	}

	static double GetDeltaFrameStart(){
		double secondsElapsed  = (GetPerformanceCounter()-FrameStart.QuadPart) /  GetPerformanceFrequency() * 1000.0f;
		return secondsElapsed;

	}
	static double GetDeltaFrameE(){
		double secondsElapsed  = (GetPerformanceCounter()-FrameStart.QuadPart) /  GetPerformanceFrequency();
		return secondsElapsed;

	}
	static double GetDeltaFrameEX(){

		return GetDeltaFrameE() * 640.0f ;

	}


#pragma endregion FPS_LIMIT

	void Install();
	
}