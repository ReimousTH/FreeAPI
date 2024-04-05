#include "InputData_CommonActions.h"


namespace InputData{


	DWORD ProcessDpadMoveRing(int* a1){
		DWORD result = 0;
		int index = (*a1)-1;
		if (index == -1 ){
			index = 0;

		}
	

		if (NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT > 0 &&  NuiFakeDevicePO[index]->DPAD_LEFT_RING == true ){

			result = (int)-NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT;
			NuiFakeDevicePO[index]->DPAD_LEFT_RING = false;
			NuiFakeDevicePO[index]->DPAD_LEFT_RING_COUNT = 0;
		}

		if (NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT > 0 &&  NuiFakeDevicePO[index]->DPAD_RIGHT_RING == true ){
			result = (int)NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT;
			NuiFakeDevicePO[index]->DPAD_RIGHT_RING = false;
			NuiFakeDevicePO[index]->DPAD_RIGHT_RING_COUNT = 0;
		}
		return result;

	}


	int __declspec(naked) sub_8246A6D0H(int result,int a2s){
		__asm{
			mflr r12
				std       r23, -0x50(r1)
				std       r24, -0x48(r1)
				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				addi      r12, r1, -0x50
				stfd      fp28, -0x20(r12)
				stfd      fp29, -0x18(r12)
				stfd      fp30, -0x10(r12)
				stfd      fp31, -8(r12)
				lis r11,0x8246
				ori r11,r11,0xA6E0
				mtctr r11
				bctr
		}
	}


	HOOK(int,__fastcall,sub_8246A6D0,0x8246A6D0,int* a1,int a2){


		DWORD v5;
		DWORD v6;
		int result = 0;

		result = ProcessDpadMoveRing(a1);

		return sub_8246A6D0H((int)a1,a2) | result;
	}


	int __declspec(naked) sub_823EF348H(int result,int a2s){
		__asm{
			mflr r12
				std       r20, -0x68(r1)
				std       r21, -0x60(r1)
				std       r22, -0x58(r1)
				std       r23, -0x50(r1)
				std       r24, -0x48(r1)
				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stfd      fp31, -0x70(r1)
				stwu      r1, -0xC0(r1)
				lis r11,0x823E
				ori r11,r11,0xF358
				mtctr r11
				bctr
		}
	}

	HOOK(int,__fastcall,sub_823EF348,0x823EF348,int a1,int a2){


		DWORD result = 3;

		if (gc->wPressedButtons & XINPUT_GAMEPAD_B){
			result= 1;
		}
		else if (gc->wPressedButtons & XINPUT_GAMEPAD_X){
			result= 0;
		}
		if (result == 3){
			return sub_823EF348H(a1,a2);
		}


		return result;
	}



	void Install_CommonActions()
	{
		INSTALL_HOOK(sub_8246A6D0);
		INSTALL_HOOK(sub_823EF348); //MessageBoxInputResult
	}

}