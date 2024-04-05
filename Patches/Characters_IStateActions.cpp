#include "Characters_IStateActions.h"


namespace CIStateActions{

	int OtherCharacterUpdateSome(int a1){
	

	int v1 = a1-0x60;

	int c94 = *(_DWORD *)(v1 + 0xC94);
	int* c944 = *(int **)(v1 + 0xC94);

	int s = *(DWORD*)(v1 + 0xC88);
	int Z = *(DWORD*)(v1 + 0xC8C);
	int Z1 = *(DWORD*)(Z + 0x160);
	int s1 = *(DWORD*)(s+0xC);
	int s2 = *(DWORD*)(s+0x14);
	if (InputData::gc->wPressedButtons & XINPUT_GAMEPAD_B){
		//*(_BYTE *)(v1 + 0xAA8) = *(_BYTE *)(v1 + 0xAA8) == 0 ? 1 :0;
		//*(_BYTE *)(v1 + 0xAA4) = 1;
	
		 
	}

	if (c94)
	{
		auto r = *(StateA2P**)(c94+0x140+0x30+0x24);
		if (r){
			auto v4 = r->pdword0->dword0->pfunc4(r->pdword0);


			auto a1x = (struct_v1*)a1;
			auto v11 = a1x->pfloat690;

			if (v4->field_110 > 0.0){
				
			
				// ChrChangeState((struct_v1*)a1, 0x1F); //1F (DRIFT)

		

			
				
				///*(_DWORD *)(0x54 * *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x1C) + *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x10) + 4) |= 0xAu;
			//	ShowXenonMessage(L"MSG",(int)(_DWORD *)(0x54 * *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x1C) + *(_DWORD *)(*(_DWORD *)(v1 + 0xC94) + 0x10) + 4),0);



			}
		}
	}


	return BranchTo(0x822B8498,int,a1);

}

	int RidersCharacterStateHelperHandler(int *a1){

		BranchTo(0x822A8AB0,int,a1);

		int* v3 = a1 + 4;
		DWORD* po = (DWORD*)(0x54 * a1[6] + *v3);
		DWORD* pX = (DWORD*)(0x54 * a1[7] + *v3);

		DWORD* v8 = (_DWORD *)(0x54 * a1[6] + a1[4]);


		auto r = *(StateA2P**)((int)a1+0x140+0x30+0x24);
		auto v4 = r->pdword0->dword0->pfunc4(r->pdword0);
		if (v4){

			if (v4->field_10 < -correct_stick){	
				pX[1] |= 0xA0000000;

			}
			else if (v4->field_10 > correct_stick){
				pX[1] |= 0xC0000000;
			}

			if (v4->field_100 >= 1.0){
				//	ShowXenonMessage(L"MSG","T");
				//	pX[1] |= 0x21000000;
				//	pX[1] |= 0x21000000;
				//pX[1] |= 0x200;
			}


		}



		return (int)a1;



	}




	int __fastcall SkillFlyStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v22;
	DWORD result = 2;


	if (v4->field_8 == 0){
		return result;
	}

	result = 1;
	v22 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	*v22 |= 0x40000u;

	

	return result;

}

int __fastcall SwimingStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v18;


	if ( v4->field_0 <= 0 )
		*(float *)(a1 + 0x48) = 0.0;
	else
		*(float *)(a1 + 0x48) = *(float *)(a1 + 0x48) + (float)v4->field_0 / 100;
	if ( *(float *)(a1 + 0x48) > 0.5 )
	{
		result = 1;
		v18 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v18 |= 0x80u;
		*(float *)(a1 + 0x48) = 0.0;
	}


	return result;

}
int __fastcall HoldHandsStateAddaptiveBROKE(int a1, StateA2P *a2, _DWORD *a3){

	int v5; // r29
	int v6; // r9
	int v7; // r8
	int v8; // r10
	int v9; // r11
	bool v10; // cr58
	char v11; // r11
	int v12; // r11
	bool v13; // cr58
	char v14; // r11
	_DWORD ***v15; // r31
	_DWORD ***v16; // r30
	char v20; // r11
	unsigned __int8 v21; // r9
	int result; // r3
	int v25; // r6
	int v29; // r11
	int v30; // r11
	int v31; // r9
	int *v35; // r11
	float v36[3]; // [sp+50h] [-40h] BYREF
	float v37; // [sp+5Ch] [-34h]

	
	v5 = 2;
	v6 = *(_DWORD *)(InputSomeUnkStatic + 0x14);
	if ( v6 <= 0 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		v7 = 0;
	else
		v7 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
	if ( v6 <= 1 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		v8 = 0;
	else
		v8 = *(_DWORD *)(*(_DWORD *)(InputSomeUnkStatic + 0x24) + 4);
	v9 = *(_DWORD *)(v7 + 0x6C);
	if ( !v9 || (v10 = v9 == 3, v11 = 0, v10) )
		v11 = 1;
	if ( !v11 )
		goto LABEL_38;
	v12 = *(_DWORD *)(v8 + 0x6C);
	if ( !v12 || (v13 = v12 == 3, v14 = 0, v13) )
		v14 = 1;
	if ( !v14 )
		goto LABEL_38;
	v15 = *(_DWORD ****)(v7 + 0xC94);
	v16 = *(_DWORD ****)(v8 + 0xC94);
	if ( !((unsigned __int8 (__fastcall *)(_DWORD ***, StateA2P *))(*v15)[0x1A])(v15, a2)
		|| !((unsigned __int8 (__fastcall *)(_DWORD ***))(*v16)[0x1A])(v16) )
	{
		goto LABEL_38;
	}


	struct_v35* _R31 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v15[0x51] + 4))(*v15[0x51]);
	struct_v35* _R3 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v16[0x51] + 4))(*v16[0x51]);
	v20 = 0;
	if (_R31->field_100 >= 1.0 )
		v20 = 1;
	v21 = 0;
	if ( _R3->field_100 >= 1.0)
		v21 = 1;



	if ( v20 || v21 )
	{

		v25 = 2;
		if ( v20 )
		{



			v25 = 1;
			v29 = 0x54 * a3[2] + *a3;
			*(_DWORD *)(v29 + 0x14) |= 0x200u;

		}
		v30 = v21;
		v31 = 2;
		if ( v30 )
		{
				v31 = 1;
				v35 = (int *)(0x54 * a3[2] + *a3);
				v35[5] |= 0x200u;
		
		}
		if ( v25 == 1 || (v5 = 2, v31 == 1) )
			v5 = 1;
LABEL_38:
		*(_DWORD *)(a1 + 0x4C) = v5;
		result = v5;
		goto LABEL_28;
	}
	result = *(_DWORD *)(a1 + 0x4C);
	*(_DWORD *)(a1 + 0x4C) = result;
LABEL_28:
	
	return result;
}


int __fastcall BdAcceleStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	  _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	  if (_R3->field_28 >= 0.65) {

		 DWORD* v14 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		    *v14 |= 0x8000u;
			 result = 1;

	  }



	  return result;

}


int __fastcall HoldHandsStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	int v5; // r29
	int v6; // r9
	int v7; // r8
	int v8; // r10
	int v9; // r11
	bool v10; // cr58
	char v11; // r11
	int v12; // r11
	bool v13; // cr58
	char v14; // r11
	_DWORD ***v15; // r31
	_DWORD ***v16; // r30
	char v20; // r11
	unsigned __int8 v21; // r9

	int v25; // r6
	int v29; // r11
	int v30; // r11
	int v31; // r9
	int *v35; // r11
	float v36[3]; // [sp+50h] [-40h] BYREF
	float v37; // [sp+5Ch] [-34h]

	
auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
DWORD result = 2;
v35 = (int *)(0x54 * a3[2] + *a3);


v5 = 2;
v6 = *(_DWORD *)(InputSomeUnkStatic + 0x14);
if ( v6 <= 0 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
v7 = 0;
else
v7 = **(_DWORD **)(InputSomeUnkStatic + 0x24);
if ( v6 <= 1 || *(_DWORD *)(InputSomeUnkStatic + 0x24) == *(_DWORD *)(InputSomeUnkStatic + 0x28) )
v8 = 0;
else
v8 = *(_DWORD *)(*(_DWORD *)(InputSomeUnkStatic + 0x24) + 4);
v9 = *(_DWORD *)(v7 + 0x6C);
if ( !v9 || (v10 = v9 == 3, v11 = 0, v10) )
v11 = 1;
if ( !v11 )
goto LABEL_38;
v12 = *(_DWORD *)(v8 + 0x6C);
if ( !v12 || (v13 = v12 == 3, v14 = 0, v13) )
v14 = 1;
if ( !v14 )
goto LABEL_38;


v15 = *(_DWORD ****)(v7 + 0xC94);
v16 = *(_DWORD ****)(v8 + 0xC94);


struct_v35* P1 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v15[0x51] + 4))(*v15[0x51]);
struct_v35* P2 = (struct_v35*)(*(int (__fastcall **)(_DWORD*))(**v16[0x51] + 4))(*v16[0x51]);



	if (P1->field_100 >= 1.0 && P2->field_100 >= 1.0){
		v35 = (int *)(0x54 * a3[2] + *a3);
		v35[5] |= 0x200u;
		result = 1;
	}
	else{

	
		result = 2;
	}
	

LABEL_38:

	if (result != 1){
		v35 = (int *)(0x54 * a3[2] + *a3);
		*(short*)((int)&v35[5] + 0x2)  = 0;
	}

	*(_DWORD *)(a1 + 0x4C) = result;



return result;
}
int __fastcall ShakeStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 2;
	DWORD* v59;

		if ( v4->field_5C > 0.0)
		{


			result = 0;
			if (*(float *)(a1 + 0x74) > 5.0){ //ONLY THIS PART

				result = 1;
				v59 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
				*(v59)  |= 0x44u;
				*(float *)(a1 + 0x74) = 0.0;

			}
			*(_DWORD *)(a1 + 0x64) = 1;
			*(_DWORD *)(a1 + 0x68) = 1;
			*(float *)(a1 + 0x6C) +=0.5*MBKinnectInput->PclsXbox360System->GameSpeed; 
			*(float *)(a1 + 0x74) +=0.25*MBKinnectInput->PclsXbox360System->GameSpeed; 

		}

	
	return result;

}
int __fastcall SteamWipeAddaptive(int a1, StateA2P *a2, int a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v59;

	if ( v4->field_5C > 0.0)
	{


	 //  *(_DWORD *)(0x54 * *(_DWORD *)(a3 + 8) + *(_DWORD *)a3 + 0x14) |= 0x8000u;
	   *(_DWORD *)(0x54 * *(_DWORD *)(a3 + 8) + *(_DWORD *)a3 + 0x14) |= 0x10000u;
		if (v4->field_60 != 0.0){
			_WORD v = *(_WORD *)(a3 + 0x4E);
			*(_WORD *)(a3 + 0x4E) = clamp( v + (int)(-v4->field_60 * 14.0 *MBKinnectInput->PclsXbox360System->GameSpeed),-640,640);

		}
		if (v4->field_10 != 0.0){
			_WORD v = *(_WORD *)(a3 + 0x4C);
			*(_WORD *)(a3 + 0x4C) = clamp( v + (int)(v4->field_10 * 14.0 *MBKinnectInput->PclsXbox360System->GameSpeed),-480,480);

		}

		result = 0;

	
	//	*(_WORD *)(a3 + 0x4A) = 100;
		//*(_WORD *)(a3 + 0x48) = 100;


	}


	return result;

}

int __fastcall CatchLRStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;
	byte* v8;
	DWORD *v49 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x4);
	DWORD *v50 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
	v8 = (_BYTE *)(0x54 * a3[2] + *a3 + 0x53);

	if ( v4->field_100 != 0.0)
	{

		*(_BYTE *)(a1 + 0x50)  = 0;
		*(_BYTE *)(a1 + 0x51)  = 1;
		DWORD v46 = *(_BYTE *)(a1 + 0x50); //ARMS SOME
		DWORD v44 = *(_BYTE *)(a1 + 0x51);

		*(_DWORD *)(a1 + 0x4C) = 1;
		*(float *)(a1 + 0x48) = 1.0;

		if ( v46 != v44 )
			*(_DWORD *)(a1 + 0x4C) = (2 * v46 + v44) << 0x1D;
		//v49 = 0x54 * *(_DWORD *)(*(&v27 + 1) + 8) + *(_DWORD *)*(&v27 + 1);
		*v49  |=  (2 * v46 + v44) << 0x1D;


		//	v50 = 0x54 * *(_DWORD *)(*(&v27 + 1) + 8) + *(_DWORD *)*(&v27 + 1);
		*v50  = (__ROL4__(*(unsigned __int8 *)(a1 + 0x51), 1) + *(unsigned __int8 *)(a1 + 0x50)) << 0x11;


	}


	return result;

	return result;
}




int __fastcall JumpStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD* v17;
	DWORD result = 0;



	if (_R3->field_4 != 1.0)
	{
		result = 2;
		*(_DWORD *)(a1 + 88) = 1;
		*(_DWORD *)(a1 + 92) = 1;
	}
	else
	{
		result = 1;
		v17 = (_DWORD *)(84 * a3[2] + *a3 + 4);
		*v17 |= 0x200u;
		*(_DWORD *)(a1 + 88) = -1;
		*(_DWORD *)(a1 + 92) = -1;
	}

	return result;
}

int __fastcall CrouschStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 2;

	if (_R3->field_8 > 0){
        auto v16 = MBKinnectInput->PclsXbox360System;
		DWORD v15 = *(float *)(a1 + 72) < 6.0;
		float v17 = (float)((float)(v16->SpeedSome * (float)v15) + *(float *)(a1 + 72));
	    *(float *)(a1 + 72) = (float)(v16->SpeedSome * (float)v15) + *(float *)(a1 + 72);
		if ( v17 < 6.0 )
		{
			result = 0;
		}
		else
		{
			result = 1;
			DWORD* v19 = (_DWORD *)(84 * a3[2] + *a3 + 4);
			*v19 |= 0x7000u;
		}
	}
	else{
		result = 2;
		*(float *)(a1 + 72) = 0.0;
	}
	
	return result;
}
int __fastcall KickDashStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	//field_30 HOLD_A FIELD_34 RELEASE A
    struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;

	int v19 = 0x54 * a3[2] + *a3;


	DWORD v12 = a2->field_64->dword14;
	DWORD v13 = a2->field_60->dword14;

	DWORD v15;



	v15 = 0x54 * a3[2] + *a3;


	int v8 = a2->field_64->dword14;
	int v9 = a2->field_60->dword14;

	*(&_R3->field_2B0 + v8) = 2;
	*(&_R3->field_2B0 + v9) = 2;

	if (_R3->field_30 == 1.0){

		*(_BYTE *)(a1 + 0x48)=1;
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x800000u; //Preapare	
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x400000u; // Do Fake Side
		result = 0;
	}
	else if (_R3->field_34 == 1.0){

		*(_BYTE *)(a1 + 0x48) = 0;
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x1000000; //Do Dash	
		*(_DWORD *)(v15 + 4)= *(_DWORD *)(v15 + 4) | 0x400000u; // Do Fake Side
		result = 1;
	}
	else{
		*(_BYTE *)(a1 + 0x48)  = 0;
		result = 2;
	}











END:



	return result;
}

int __fastcall ArmsUPStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){


	double v5; // fp0
	int v6; // r11
	double v7; // fp0
	int v8; // r11
	int result; // r3
	int v10; // r11
	_DWORD *v11; // r10

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	if ( v4->field_60 > 0.0 )
	{
		v6 = 84 * a3[2] + *a3;
		*(_DWORD *)(v6 + 4) |= 0x80u;
	}
;
	if ( v4->field_60 > 0.0 )
	{
		v8 = 84 * a3[2] + *a3;
		*(_DWORD *)(v8 + 4) |= 0x40u;
	}
	if ( (*(_DWORD *)(84 * a3[2] + *a3 + 4) & 0xC0) != 192 )
		return 2;
	result = 1;
	v10 = 84 * a3[2] + *a3;
	*(_DWORD *)(v10 + 4) |= 0x10000000u;
	v11 = (_DWORD *)(84 * a3[2] + *a3 + 20);
	*v11 |= 0x120u;
	return result;
}

int __fastcall TrickROTStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	double v5; // fp0
	int v6; // r11
	double v7; // fp0
	int v8; // r11
	int result; // r3
	DWORD* v10; // r11
	_DWORD *v11; // r10

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	double centerX = 0.0; // Center X position of the joystick
	double centerY = 0.0; // Center Y position of the joystick

	float StickX = -((v4->field_284  *2.0) -1.0) ;
	float StickY = v4->field_28;

	if ( (StickX + StickY) != 0 && *(float *)(a1 + 0x48) != 1){

		*(float *)(a1 + 0x48) = 1;
		*(float *)(a1 + 0x4C) = fmod(    (std::atan2(StickY,StickX) * (180.0 / 3.14) )+ 360.0,360.0 ); 
		return 1;

	}


	if (*(float *)(a1 + 0x48) == 1){
		if ((StickX + StickY) == 0) return 1;
		float prevAngle = *(float *)(a1 + 0x4C);
		float angle = fmod((std::atan2(StickY,StickX) * (180.0 / 3.14))+ 360.0,360.0 ); 
		*(float *)(a1 + 0x4C) = angle;

		// Further processing based on the updated angle
		if (prevAngle != angle) {

			float result_angle = 0.0f;
			if (abs(angle - prevAngle ) > 180){
				 if (angle > prevAngle) result_angle = (angle - prevAngle - 360);
				 else result_angle = (angle-prevAngle + 360 );
			}
			else{
				result_angle = angle - prevAngle;
			}

			// Additional actions based on the angle comparison
			result = 1;
			*(_BYTE *)(a1 + 0x50) = 1;
			*(float *)(0x54 * a3[2] + *a3 + 0x38) += (result_angle) * (1.0/180.0);
			// Other operations as needed

			// Setting a flag for the operation
			v10 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
			*v10 |= 0x800u;
		}
		
	}

	return 1;


}


int __fastcall SideStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD result;
	


	result = 2;
	v16 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	v17 = (_DWORD *)(0x54 * a3[2] + *a3 + 20);
	//*v16 |= 0x400000u;
	*v17 |= 0x2000u;

	return result;

}



int __fastcall AcceleLRStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	if (_R3->field_28 >= 0.65) {

		DWORD* v14 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		*v14 |= 0x8000u;
		result = 1;

	}



	return result;



}

int __fastcall InflatorAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		result =1 ;
		*(_BYTE *)(a1 + 0x48) = 0xFF;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x400u;
		
		//	}


	}



	return result;


}

int __fastcall HammerHandAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{


		result =1 ;

		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x1u;
	
		//	}


	}



	return result;

}

int __fastcall OverThrowAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		*(_DWORD *)(a1 + 0x4C) =1;
		result =1 ;
		*(_BYTE *)(a1 + 0x48) = 0xFF;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x8u;



	}



	return result;


}

int __fastcall UnderThrowAddaptive(int a1, StateA2P *a2, _DWORD *a3){



	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		*(_DWORD *)(a1 + 0x4C) =1;
		result =1 ;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x10u;

	}



	return result;


}

int __fastcall UnderSwingAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;

	if ( v4->field_5C > 0.0)
	{

		*(_DWORD *)(a1 + 0x48) =0;
		result =1 ;
		v7 = (_DWORD *)(0x54 * a3[2] + *a3 + 0x14);
		*v7 |= 0x2u;

	}



	return result;
}

int __fastcall FrontLeverAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;

	DWORD v39 = (DWORD)(0x54 * a3[2] + *a3);
	DWORD v40 = a3[2];

	double v41;


	if (v4->field_58 == 0){
		return result;
	}


	*(_BYTE *)(v39 + 0x52) =  (((byte)(v4->field_58 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * v40 + *a3 + 0x52) )
	{
		result = 1;
		*(_DWORD *)(0x54 * v40 + *a3 + 0x14) |= 0x1000u;
	}


	return result;
}

int __fastcall HandleStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;

	DWORD v39 = (DWORD)(0x54 * a3[2] + *a3);
	DWORD v40 = a3[2];

	double v41;


	if (v4->field_58 == 0){

		if (*(_BYTE *)(v39 + 0x53) != 0)
			*(_BYTE *)(v39 + 0x53) = 0;
		return result;
	}


	*(_BYTE *)(v39 + 0x53) =  (((byte)(v4->field_58 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * v40 + *a3 + 0x53) )
	{
		result = 1;
		*(_DWORD *)(0x54 * v40 + *a3 + 0x14) |= 0x4000u;
	}


	return result;
}


int __fastcall FrontCurveStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);



	*(_BYTE *)(0x54 * a3[2] + *a3 + 0x51) =  (((byte)(-v4->field_20 *1.0*100.0)));

	if ( *(_BYTE *)(0x54 * a3[2] + *a3 + 0x51) )
		*(_DWORD *)(0x54 * a3[3] + *a3 + 0x14) |= 0x800u;


	return 0;
}


int __fastcall CatchStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){
	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD result = 0;
	DWORD* v7;
	byte* v8;
	DWORD v49 = (_DWORD )(0x54 * a3[2] + *a3 );
	DWORD v50 = (_DWORD )(0x54 * a3[2] + *a3 );
	v8 = (_BYTE *)(0x54 * a3[2] + *a3 + 0x53);

	if ( v4->field_10 != 0.0)
	{
		*(unsigned __int8 *)(v4 + 0x49) = 1;
		*(unsigned __int8 *)(v4 + 0x48) = 0;
		int v46 = *(unsigned __int8 *)(v4 + 0x49);
		int v44 = *(unsigned __int8 *)(v4 + 0x48);

		if ( (unsigned __int8)v46 != v44 )
			*(_DWORD *)(v4 + 0x4C) = (2 * v46 + v44) << 0x1D;

		*(_DWORD *)(v49 + 4) |= 0x40u;
		*(_DWORD *)(v50 + 20) |= 0x80u;


	}


	return result;
}

int __fastcall BrakeVStateAdaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	if (_R3->field_10C == 1.0){

		*(float *)(a1 + 0x48) +=MBKinnectInput->PclsXbox360System->GameSpeed;

		///	if (*(float *)(a1 + 0x48) > 60.0){

		//	std::stringstream ss;
		//	ss << std::hex << (0x54 * a3[2] + *a3 + 4);
		//	DebugLogRestore::log.push_back(new std::string(ss.str().c_str()));

		_R3->field_2E4 = 2;
		_R3->field_2F4 = 2;
		result = 1;
		DWORD *v9;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0x64;
		v9 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		*v9 |= 0x100u;

		//	}

	}
	else{
		_R3->field_2E4 = 0;
		_R3->field_2F4 = 0;

		result = 2;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0;
		*(float *)(a1 + 0x48) = 0.0;
	}









	return result;


}

int __fastcall BrakeStateAdaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35 *_R3; // r3	
	DWORD result = 0;
	_R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	if (_R3->field_10C == 1.0){

		*(float *)(a1 + 0x48) +=MBKinnectInput->PclsXbox360System->GameSpeed;

		//if (*(float *)(a1 + 0x48) > 1.0){

		//	std::stringstream ss;
		//	ss << std::hex << (0x54 * a3[2] + *a3 + 4);
		//	DebugLogRestore::log.push_back(new std::string(ss.str().c_str()));
		_R3->field_2E4 = 2;
		_R3->field_2F4 = 2;
		result = 1;
		DWORD *v9;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = (((byte)(abs(_R3->field_28) *1.0*100.0)));




		v9 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
		*v9 |= 0x100u;
		*v9 |= 0x400000u; // Force allow to do it ( need find where originally this requires condition is & 0x400000u or else brake wont work)

		//}

	}
	else{
		_R3->field_2E4 = 0;
		_R3->field_2F4 = 0;

		result = 2;
		*(_BYTE *)(0x54 * a3[2] + *a3 + 0x50) = 0;
		*(float *)(a1 + 0x48) = 0.0;
	}



	return result;
}




int __fastcall ChargeStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	struct_v35* _R3 = a2->pdword0->dword0->pfunc4(a2->pdword0);
	DWORD* v22;
	DWORD result = 0;

	if ( _R3->field_8 >= 1.0)
	{

		
		v22 = (_DWORD *)(84 * a3[2] + *a3 + 4);
		*v22 |= 0x7000u;
		return 1;
	}

	return 0;
}





int __fastcall SkillPowerNormalGear(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v27;
	DWORD result = 0;
	DWORD v9= 0;
	DWORD v56 = 0x54 * a3[2] + *a3;

	DWORD cond = 0;

	if (v4->field_104 == 1.0){

		cond |= 0x80000u;
		result = 1;
	}
	if (v4->field_108 == 1.0){

		cond |= 0x100000u;
		result = 1;
	}

	if ( v4->field_104 == 1.0 || v4->field_108 == 1.0 ){

		*(_DWORD *)(v56 + 4) |= cond;
	}




	return result;
}

int __fastcall StanceStateAddaptive(int a1, StateA2P *a2, _DWORD *a3){

	auto v4 = a2->pdword0->dword0->pfunc4(a2->pdword0);

	DWORD* v16;
	DWORD* v17;
	DWORD* v177;
	DWORD* v27;
	DWORD result = 0;
	DWORD v9= 0;

	if (v4->field_48 == 0){



		return 0;
	}
	DWORD v11 = a2->field_68;


	DWORD po = *(_DWORD *)(0x54 * a3[2] + *a3 + 0x48);


	DWORD va = po == 0 ? 1 : 0;

	*(_DWORD *)(0x54 * a3[2] + *a3 + 0x48)= va;

	DWORD Side = 0;

	a2->field_68  = va;
	if (va == 0){

		Side = 1;
		a2->field_64 = (struct_field_64*)ST1[1];
		a2->field_60 = (struct_field_60*)ST1[0];
		result = 0;
	}
	else if ( va == 1){
		Side = 2;
		a2->field_64 = (struct_field_64*)ST1[0];
		a2->field_60 = (struct_field_60*)ST1[1];
		result = 0;
	}


	result = 2;

	*(_DWORD *)(0x54 * a3[2] + *a3 + 0x48) = va;
	v27 = (_DWORD *)(0x54 * a3[2] + *a3 + 4);
	v177 = (_DWORD *)(0x54 * a3[2] + *a3 + 20);
	*v27 |= 0x200000u;




	return result;

}






	void Install()
	{


		WRITE_DWORD(0x8226086C,0x60000000); //fix free hand timer
		WRITE_DWORD(0x82260754,0x60000000); //fix free hand timer

		WRITE_DWORD(0x821A2484,0x822C8958);// Bike Move Fix



		WRITE_DWORD(0x82B09EA4,OtherCharacterUpdateSome);
		WRITE_DWORD(0x82B09EB4,OtherCharacterUpdateSome);

		//	WRITE_DWORD(0x82B09F14,DriftStateHandle);


		WRITE_DWORD(0x821A21F8,RidersCharacterStateHelperHandler);
		WRITE_DWORD(0x821A237C,SkillFlyStateAddaptive);

		//	WRITE_DWORD(0x821A2590,UUUUUUUUUUUUUUUUUUUUAD);
		//	WRITE_DWORD(0x822C422C,0x60000000);
		WRITE_DWORD(0x821A2368,JumpStateAddaptive);


		WRITE_DWORD(0x821A23D0,TrickROTStateAddaptive);

		WRITE_DWORD(0x821A232C,ArmsUPStateAddaptive);
		//WRITE_DWORD(0x821A238C,Dummy);
		//WRITE_DWORD(0x821A2378,Dummy);
		WRITE_DWORD(0x821A2358,HoldHandsStateAddaptive);
		//WRITE_DWORD(0x821A23A8,Dummy);
		//WRITE_DWORD(0x821A23BC,Dummy);
		WRITE_DWORD(0x821A2454,AcceleLRStateAddaptive); //Accell
		//WRITE_DWORD(0x821A2454,Dummy);
		WRITE_DWORD(0x821A245C,BrakeVStateAdaptive);
		//WRITE_DWORD(0x821A246C,CatchStateAddaptive);
		WRITE_DWORD(0x821A247C,ChargeStateAddaptive); //Not this Real (it not charge jump and this some)
		//WRITE_DWORD(0x821A2484,Dummy);
		//WRITE_DWORD(0x821A2484,Dummy);
		WRITE_DWORD(0x821A2494,KickDashStateAddaptive); // Bike
		WRITE_DWORD(0x821A249C,SkillPowerNormalGear);
		//WRITE_DWORD(0x821A2428,SideStateAddaptive); //Requires To DO 
		WRITE_DWORD(0x821A244C,StanceStateAddaptive);
		WRITE_DWORD(0x821A2418,KickDashStateAddaptive);
		WRITE_DWORD(0x821A23F4,BrakeStateAdaptive);
		//  WRITE_DWORD(0x821A2404,CatchLRStateAddaptive); //CATCHLR
		WRITE_DWORD(0x821A23E4,BdAcceleStateAddaptive);
		WRITE_DWORD(0x821A243C,SkillPowerNormalGear);
		WRITE_DWORD(0x821A233C,CrouschStateAddaptive);
		//WRITE_DWORD(0x821A2344,Dummy);
		WRITE_DWORD(0x821A24C4,OverThrowAddaptive);
		WRITE_DWORD(0x821A24FC,UnderThrowAddaptive);
		WRITE_DWORD(0x821A24E8,UnderSwingAddaptive);
		WRITE_DWORD(0x821A24B0,HammerHandAddaptive);
		WRITE_DWORD(0x821A24D4,ShakeStateAddaptive);
		WRITE_DWORD(0x821A2548,InflatorAddaptive);

		WRITE_DWORD(0x821A2510,FrontCurveStateAddaptive);


		WRITE_DWORD(0x821A2524,FrontLeverAddaptive);
		WRITE_DWORD(0x821A2570,SwimingStateAddaptive);
		WRITE_DWORD(0x821A2534,HandleStateAddaptive);
		WRITE_DWORD(0x821A255C,SteamWipeAddaptive);
	}

}