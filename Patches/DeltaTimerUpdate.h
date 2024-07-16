#pragma once


#include "../HookV2.h"
#include "../RidersFree.h"
#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"

#include "InputData.h"
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <xtl.h>

#define _USE_MATH_DEFINES
#include <cmath>


namespace DeltaTimerU{
	
extern int FrameSkipCount;




union float_le{
	struct {
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	};
	unsigned char value[4];

	float_le() {

	}

	float_le(float f) {
		char* _raw = (char*)&f;
		value[0] = _raw[3];
		value[1] = _raw[2];
		value[2] = _raw[1];
		value[3] = _raw[0];

	}

	float inverse(){
		unsigned char evalue[4];
		evalue[0] = value[3];
		evalue[1] = value[2];
		evalue[2] = value[1];
		evalue[3] = value[0];
		return *(float*)&evalue;
	}
	

};



union sfloat {
	struct {
		unsigned char mantissa : 8;
		unsigned char exponent : 7;
		unsigned char sign : 1;
	};
	unsigned char value[2];

	sfloat() {
	}

	sfloat(float_le f) {
		this->sign = f.sign;
		this->mantissa = f.mantissa;
		this->exponent = f.exponent;
	}
	sfloat(float f){
		float_le little = float_le(little);
		sfloat _raw = sfloat(little);
		*this = _raw;
	
	}


	float_le to_float_le(){
		float_le val;
		val.sign = this->sign;
		val.exponent = this->exponent;
		val.mantissa = this->mantissa;
		return val;
	}
	float to_float(){
		float_le val;
		val.sign = this->sign;
		val.exponent = this->exponent;
		val.mantissa = this->mantissa;
		return val.inverse();
	}

	
};





#pragma region FPS_LIMIT


	extern LARGE_INTEGER FrameStart;
	extern LARGE_INTEGER FrameStartfrequency;


	static LARGE_INTEGER GetFraquency(){

		LARGE_INTEGER frag;
		QueryPerformanceFrequency(&frag);
		return frag;
	}
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