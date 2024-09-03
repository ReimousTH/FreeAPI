#include "InputData_Actions.h"


namespace InputData{
	
	
	
int __declspec( naked ) sub_82494658HH(int a1){
	__asm{
		    mflr      r12		    
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
	

			stfd      fp31, -0x40(r1)
			addi      r31, r1, -0x1F0

		
			lis r11,0x8249
			ori r11,r11,0x4668 
			mtctr r11
			bctr r11
	}
}

HOOK(int,__fastcall,sub_82494658,0x82494658,int result){




	 
	 sub_82494658HH(result);
	 if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
		 //	int some = *(int*)( off_83E52FA0 + 0xD4);
		//	*(int*)( some + 0x7C) = 0;


	 }
	 // (*(int*)((int)KinnectNuiBox::Instance + 0x50 
	 if (NearKinnectNuiBox::Instance){

		 int tuto = *(int*)((int)KinnectNuiBox::Instance + 0x50);
		 // if ((int)*(byte*)(tuto + 0x85D) == 1)
		 DWORD pass = true;
		 if (MessageBoxInputMB )
		 {
			 if ( *(_DWORD *)(MessageBoxInputMB + 0xC) ){
				 pass = false;
			 }
		 }
		 if (pass)
		 {
			 if (gc->wPressedButtons & XINPUT_GAMEPAD_START){

				 *(_DWORD *)(MainTitlev144Actions + 0x1540)=(DWORD)L"pauseopen";
			 }

			 if (gc->wPressedButtons & XINPUT_GAMEPAD_A)
			 {
				 *(_DWORD *)(result + 5440) = (DWORD)L"ok";
	
			 }
			 if (gc->wPressedButtons & XINPUT_GAMEPAD_B)
			 {
				 *(_DWORD *)(result + 5440) = (DWORD)L"back";
			 }

		 }


	 }




	if (gc && result && !NearKinnectNuiBox::Instance ){

		DWORD pass = true;

		if (MessageBoxInputMB )
		{
		
			if ( *(_DWORD *)(MessageBoxInputMB + 0xC) ){
				pass = false;
			}

		}
		if (pass)
		{
			if (gc->wPressedButtons & XINPUT_GAMEPAD_A)
			{
				//*(_DWORD *)(result + 5440) = (DWORD)L"ok";
			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_B)
			{
			//	*(_DWORD *)(result + 5440) = (DWORD)L"back";
			}

			if (gc->wPressedButtons & XINPUT_GAMEPAD_START){
				*(_DWORD *)(result + 5440)=(DWORD)L"start";


			}
			

			if (gc->wPressedButtons & XINPUT_GAMEPAD_X){
//				*(_DWORD *)(result + 5440)=(DWORD)L"rulesetting";

			}


		}

		

		
	


		if (gc->wLastButtons & XINPUT_GAMEPAD_START){
			hold_start_time+=MBKinnectInput->PclsXbox360System->GameSpeed;;
		}
		else{
			hold_start_time = 0.0;
		}



		//if (gc->wPressedButtons & XINPUT_GAMEPAD_Y ){
		//	*(_DWORD *)(result + 5440)=(DWORD)L"pause";
			//  ShowXenonMessage(L"Paause","	");
		//	hold_start_time = 0.0;
	//	}



	}







	return result;


}


HOOK(int,__fastcall,sub_8224C6F8,0x8224C6F8,int a1){
	int v1; // r11
	bool v2; // cr58
	unsigned __int8 v3; // r11

	v1 = *(_DWORD *)(a1 + 0x828);
	if ( !v1 || (v2 = *(_BYTE *)(v1 + 0x7B) == 0, v3 = 1, v2) )
		v3 = 0;

	if (ForcePauseGame) v3 = 1;

	return v3;
}


HOOK(int*,__fastcall,sub_823FAEC0,0x823FAEC0,int a1)
{
	char v1; // r27
	int v3; // r25
	int *result; // r3
	int v5; // r11
	_DWORD *v6; // r30
	int v7; // r26
	int v8; // r11
	int v9; // r11
	int v10; // r3
	char v11; // r11
	char v12; // r30
	_DWORD *v13; // r11
	int v14; // r9
	int v15; // r4
	int v16; // r11
	int v17; // [sp+58h] [-48h] BYREF
	int v18; // [sp+5Ch] [-44h] BYREF


	v1 = 0;
	v3 = *(_DWORD *)(a1 + 4);
	result = (int*)GetEngineGlobalParams();
	v5 = *(_DWORD *)(a1 + 0x44);
	if ( v5 == 2 )
	{
		v16 = *(_DWORD *)(a1 + 0xC);
		*(_DWORD *)(a1 + 0x7C) = 8;
		*(_DWORD *)(v16 + 0x38) &= 0xFFFFFFFC;
		++*(_DWORD *)(a1 + 0x44);
		goto LABEL_27;
	}
	if ( v5 == 3 )
	{
		v6 = *(_DWORD **)(NearKinnectNuiBox::Instance + 0x50);
		result = (int *)(*(int (__fastcall **)(_DWORD *))(*v6 + 0x1C))(v6);// 8224C720
		if ( (_BYTE)result )
			v7 = *(_DWORD *)(v6[0x20A] + 0x68);
		else
			v7 = 8;


	



		v8 = *(_DWORD *)(a1 + 0x7C);

		if (!ShowUI){
			v7 = 0;
		}



		if ( v7 != v8 )
		{


			if ( v7 == 8 )
			{
				if ( *(_BYTE *)(a1 + 0x80) )
				{
					if ( *(int *)(InputSomeUnkStatic + 0x14) <= 0
						|| *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
					{
						v9 = 0;
					}
					else
					{
						v9 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
					}
					if ( *(_DWORD *)(v9 + 0x9A8) == 2
						|| (v1 = 1,
						v10 = (int)*sub_82230F38((DWORD*)&v17, NearKinnectNuiBox::Instance),
						result = (int *)(*(int (__fastcall **)(int))(*(_DWORD *)v10 + 0x28))(v10),
						v11 = 1,
						(_BYTE)result) )
					{
						v11 = 0;
					}
					v12 = v11;
					if ( (v1 & 1) != 0 )
						result = boostsomex(&v18);
					if ( v12 )
						result = (int *)sub_82408998(v3, 0, 0);
					if ( *(_DWORD *)(NearKinnectNuiBox::Instance + 0x9C) == 1 )
					{
						*((_DWORD *)off_83E52FA0 + 0x39) = 0;
						*(_DWORD *)(a1 + 0x7C) = 8;
						goto LABEL_27;
					}
				}
			}
			else if ( v8 == 8 )
			{
				result = (int *)sub_82408998(v3, 1, 0);
				if ( *(_DWORD *)(NearKinnectNuiBox::Instance + 0x9C) == 1 )
				{
					v13 = (DWORD*)off_83E52FA0;
					v14 = *((_DWORD *)off_83E52FB4 + 0x1A);
					v15 = *((_DWORD *)off_83E52FB4 + 0x14);
					*((_DWORD *)off_83E52FA0 + 0x3A) = (int)flt_82B34BD8;
					result = (int *)(v14 + 0x28);
					v13[0x3B] = 0x276;
					v13[0x37] = v14 + 0x28;
					v13[0x39] = 0xFFFFFFFF;
					v13[0x38] = v15;
				}
			}
		}
		*(_DWORD *)(a1 + 0x7C) = v7;
	}
LABEL_27:

	return result;
}


	void Install_Actions()
	{

		//EXTRA


		INSTALL_HOOK(sub_8224C6F8); // +

		if (ZLuaN::TogeableHud) INSTALL_HOOK(sub_823FAEC0); //+




		hold_start_time = 0.0f;
		INSTALL_HOOK(sub_82494658);
	}

}