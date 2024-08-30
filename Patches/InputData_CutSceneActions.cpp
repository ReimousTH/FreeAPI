#include "InputData_CutSceneActions.h"


namespace InputData{



	HOOK(int,__fastcall,sub_823DC2D0,0x823DC2D0,int a1){


		DWORD result = 0;
		if (gc){
			if (gc->HoldButtons & XINPUT_GAMEPAD_START  | (gc->HoldButtons  & XINPUT_GAMEPAD_X) ){

				if (  *(_DWORD *)(a1 + 0x3AC)  == 0)   *(_DWORD *)(a1 + 0x3AC) = 1;

				*(float *)(a1 + 0x3B0) += MBKinnectInput->PclsXbox360System->GameDelta * (float)1.0;

				if (*(float *)(a1 + 0x3B0) < 45.0){
					result  = 1;

			 }
				else{
					result = 2;
					*(float *)(a1 + 0x3B0) = 45.0;
					*(_DWORD *)(a1 + 0x3AC) = 2;
			 }

			}
			else{
				*(_DWORD *)(a1 + 0x3AC) = 0;
				if ( *(float *)(a1 + 0x3B0) > 0.0){
					*(float *)(a1 + 0x3B0)-= MBKinnectInput->PclsXbox360System->GameDelta * (float)2.0;
				}

			}
		}

		return result;
	}

	void Install_CutsceneActions()
	{
			INSTALL_HOOK(sub_823DC2D0);
	}

}