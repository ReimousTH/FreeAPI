#pragma once

#ifndef __InputData__
#define __InputData__



#include "../HookV2.h"
#include "../RidersFree.h"

#include <xtl.h>
#include "AtgInput.h"
#include "AtgSignIn.h"


#include "DLL_LUA.h"


#include <string>
#include <vector>
#include <list>


namespace InputData{
	

	extern ATG::GAMEPAD* gc;
	extern ATG::GAMEPAD* gc2P;

	extern int P1SLOT;
	extern int P2SLOT;

	extern bool LuaBehaviour;


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

		bool Menu_DPAD_UP_RELEASE;
		bool Menu_DPAD_DOWN_RELEASE;
		bool Menu_DPAD_UP_HOLD;
		bool Menu_DPAD_DOWN_HOLD;

		bool MENU_BUTTON_A_HOLD;
		bool MENU_BUTTON_A_RELEASE;

		bool MENU_BUTTON_X_HOLD;
		bool MENU_BUTTON_X_RELEASE;

		bool MENU_BUTTON_B;
		bool MENU_BUTTON_Y;
		bool Menu_START_BUTTON_PRESS;
		float StickForceX;
		float StickForceY;
		float BackHoldTime;
		float SelectHoldTime;
	};


	extern NukFakeDeviceHelpers NuiFakeDeviceHP1;
	extern NukFakeDeviceHelpers NuiFakeDeviceHP2;
	extern NukFakeDeviceHelpers* NuiFakeDevicePO[2];

	extern struct_v35 NuiFakeDevice;
	extern DWORD NuiFakeDeviceEZ[4096];
	extern struct_dword300 NuiFakeDeviceExtra;


	extern struct_v35 NuiFakeDeviceP2;
	extern DWORD NuiFakeDeviceEZP2[4096];
	extern struct_dword300 NuiFakeDeviceExtraP2;
	
	extern bool onceX;


	extern byte Gamemode690H[0x300];
	extern byte Gamemode690H1[0x300];

	extern DWORD Expo[0x4000];
	extern DWORD Expo1[0x4000];


	//Debug
	extern DWORD ShowUI;
	static DWORD ForcePauseGame;
	static bool once;

	extern std::vector<std::string> DebugLog;



	void Install();
	
}

#endif