#include "InputData_TitleActions.h"


namespace InputData{


	HOOK(int,__fastcall,sub_82452198 ,0x82452198 ,int a1){

		if ((gc->wLastButtons & XINPUT_GAMEPAD_START) | (gc->wLastButtons  & XINPUT_GAMEPAD_X) ){
			return 1;
		}
		return 0;

	}

	void Install_TitleActions()
	{
		INSTALL_HOOK(sub_82452198);	
	}

}