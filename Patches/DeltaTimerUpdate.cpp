#pragma once
#include "DeltaTimerUpdate.h"

#include "../HookV2.h"
#include "../RidersFree.h"
#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"


#include <string>
#include <vector>


namespace DeltaTimerU{
	

	HOOK(int,__fastcall,sub_82211C08,0x82211C08,struct_MBKinnectInput* atgu){



		GetDeltaFrameStart();




		return  MBKinnectInput->PclsXbox360System->__vftable->GetFlag5A(MBKinnectInput->PclsXbox360System);




	}
	HOOK(int,__fastcall,GameSpeedControllerUpdate,0x824B1588,clsXbox360System *a1){

		double v3; // fp11
		double v4; // fp0

		struct_v2* v2; // r3
		v2 = (struct_v2*)sub_82211440();

		v3 = a1->GameSpeed;                           // GameSpeed
		v4 = a1->CameraSpeed; //Base Speed 

		MBKinnectInput->Xbox360Timer->TimerValue = 1.0;
		int StartTick = MBKinnectInput->Xbox360Timer->StartDeltaTime;
		int EndTick = MBKinnectInput->Xbox360Timer->__vftable->GetDeltaTime(MBKinnectInput->Xbox360Timer);
		float fixed_ticks = (float)(EndTick-StartTick)/1000000.0;


	   //ShowXenonMessage(L"msg",(float)GetDeltaFrameCurrent(),0);
	 //  ShowXenonMessage(L"msg",(float)fixed_ticks,0);

		fixed_ticks*=1.25;


		float step = fixed_ticks;


		MBKinnectInput->Xbox360Timer->TickCount = (EndTick-StartTick) *0.016666668 *1.25;

		//ShowXenonMessage(L"MSG",(int)MBKinnectInput->Xbox360Timer->TickCount,0);

	
		a1->GameDelta = step;
		a1->GameSpeed = step;


		a1->CameraSpeed =step;


		a1->field_34 = step * 0.016666668;
		a1->field_30 =  step * 0.016666668;
		a1->field_2C =  step * 0.016666668 * 1000.0 ;



		a1->field_24 =   step * 0.016666668;

		//0.0166666666666667

		//60 FPS
		//16..??

		a1->field_20 =  step * 0.016666668 * 1000.0 ;

		//0.2
		//0.1
	
	
		//	a1->CameraSpeed = a1->SpeedSome;




		return 0;



	}


	int __declspec( naked ) sub_822A9F5H8(struct_v1* a1,int a2,int a3,double a4){
		__asm{
			mflr r12
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)


				stfd      fp31, -0x30(r1)
				stwu      r1, -0xB0(r1)

				lis r11,0x822A
				ori r11,r11,0x9F68
				mtctr r11
				bctr r11

		}
	}


	HOOK(int,__fastcall,sub_822A9F58,0x822A9F58,struct_v1 * a1,int a2,int a3,double a4){

		sub_822A9F5H8(a1,a2,a3,a4);


		float* v2 = (float*)a2;

		//	 v2[0] = 0.0;
		//	 v2[1] = 0.0;
		//	 v2[2] = 0.1;
		//	 v2[3] = 1.0;



		return 0;



	}

	void __fastcall TrickRampTypeA_360_B(struct_v1 *a1){



		int v4 = *(int*)((char*)0x82B09D7C + (a1->byte644 * 4)) + 0x10 * (a1->byte646 +    (a1->byte646 * 2));

		if (a1->field_968 == 1){
			//	ShowXenonMessage(L"MSG",*(float *)v4,0);


			struct_pfloat690* v7 = a1->pfloat690;


			float v8 = *(float *)&a1->field_8F8;

			float* field_8F4 = (float*)&a1->field_8F4;


			*field_8F4 = *field_8F4 - MBKinnectInput->PclsXbox360System->GameDelta * 1.25;


			float field_8F4_pre = *field_8F4;

			v7->floatC44 =   (float)( field_8F4_pre* field_8F4_pre )* v8;

			if ( field_8F4_pre <= 0.0 )
			{
				a1->pfloat690->floatC44 = 0.0;
				auto v10 = *(float *)v4;
				auto v11 = a1->pfloat690;
				auto v12 = (*(_DWORD *)(v4 + 4) + 1) * *(_DWORD *)(v4 + 4) / 2;
				auto v78 = v12 ;
				v11->float_C48 = (float)v10 / (float)v78;
				auto v13 = a1->pfloat690;
				if ( v13->float_C48 < 0.0099999998 )
					v13->float_C48 = 0.0099999998;
				auto v14 = a1->field_968 + 1;
				a1->dword954 = 2;
				a1->field_968 = v14;
			}

		}
		else{


			*(float*)&a1->field_8F4 = (float)*(_DWORD *)(v4 + 4);        // OnStart First Value
		}




		BranchTo(0x822C0F90,int,a1);
	}


	void __fastcall TrickRampTypeA_360(struct_v1 *a1){



		int v4 = *(int*)((char*)0x82B09D7C + (a1->byte644 * 4)) + 0x10 * (a1->byte646 +    (a1->byte646 * 2));

		//ShowXenonMessage(L"MSG",v4,0);

		if (a1->field_968 == 1){
			//	ShowXenonMessage(L"MSG",*(float *)v4,0);


			struct_pfloat690* v7 = a1->pfloat690;


			float v8 = *(float *)&a1->field_8F8;

			float* field_8F4 = (float*)&a1->field_8F4;


			*field_8F4 = *field_8F4 - MBKinnectInput->PclsXbox360System->GameDelta * 1.25;


			float field_8F4_pre = *field_8F4;

			v7->floatC44 =   (float)( field_8F4_pre* field_8F4_pre )* v8;

			if ( field_8F4_pre <= 0.0 )
			{
				a1->pfloat690->floatC44 = 0.0;
				auto v10 = *(float *)v4;
				auto v11 = a1->pfloat690;
				auto v12 = (*(_DWORD *)(v4 + 4) + 1) * *(_DWORD *)(v4 + 4) / 2;
				auto v78 = v12 ;
				v11->float_C48 = (float)v10 / (float)v78;
				auto v13 = a1->pfloat690;
				if ( v13->float_C48 < 0.0099999998 )
					v13->float_C48 = 0.0099999998;
				auto v14 = a1->field_968 + 1;
				a1->dword954 = 2;
				a1->field_968 = v14;
			}

		}
		else{


			*(float*)&a1->field_8F4 = (float)*(_DWORD *)(v4 + 4);        // OnStart First Value
		}




		BranchTo(0x822C09A0,int,a1);
	}



	HOOK(int,__fastcall,sub_8227BB98,0x8227BB98,int a1,int a2){

		XMVECTOR* Position = *(XMVECTOR**)(a1+0x1C);

		XMVECTOR* CameraPosition = (XMVECTOR*)(a1+0x40);

		XMVECTOR* CameraPosition1 = (XMVECTOR*)(a2+0x1B0);
		XMVECTOR* CameraPosition2 = (XMVECTOR*)(a2+0x1D8);
		XMVECTOR* CameraPosition3 = (XMVECTOR*)(a2+0x1C0);


//		*CameraPosition = *Position;
	
		*CameraPosition1 = *Position;


		//*CameraPosition2 = *Position; //Rotation??

		XMVECTOR pos =  {0,0,0,1};;

//		*CameraPosition3 =pos;


		return 1;



	}



	int __declspec( naked ) CharacterBasePhysicsMoveR(struct_v1* thus,XMVECTOR* OutVector,float* VectorS,float delta){
		__asm{
				mflr r12














				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)

				stfd      fp31, -0x30(r1)
				stwu      r1, -0xB0(r1)

				lis r11,0x822A
				ori r11,r11,0x9F68
				mtctr r11
				bctr r11

		}
	}

	HOOK(int,__fastcall,CharacterBasePhysicsMove,0x822A9F58,struct_v1* thus,XMVECTOR* OutVector,float* VectorS,float delta){



	
		return CharacterBasePhysicsMoveR(thus,OutVector,(float*)&thus->float748,MBKinnectInput->PclsXbox360System->GameDelta);
	}


	HOOK(int,__fastcall,sub_822AB3B0,0x822AB3B0,struct_v1* _this){
	
	
		_this->PositionZ+=1;

		return 0;
	}



	LARGE_INTEGER FrameStart = {0};
	LARGE_INTEGER FrameStartfrequency = {0};
	



	HOOK(int,__fastcall,sub_82807008,0x82807008,float *a1, int a2, double a3, double a4, double a5){


		int result; // r3
		__int64 v6; // r11
		double v7; // fp11
		double v8; // fp11
		int v9; // r11
		__int64 v10; // r10

		if ( (a2 & 0x40) != 0 )
			goto LABEL_2;
		HIDWORD(v6) = 0x40000;
		LODWORD(v6) = a2 & 0x1F0000;
		if ( (a2 & 0x1F0000u) > 0x40000 )
		{
			if ( (_DWORD)v6 != 0x80000 )
			{
LABEL_13:
				*a1 = a5;
				return 0;
			}
			v8 = (float)((float)((float)a5 - (float)a3) / (float)((float)a4 - (float)a3));
			v9 = (int)v8;
			if ( v8 < 0.0 )
				--v9;
			LODWORD(v10) = v9;
			HIDWORD(v10) = v9 & 1;
			if ( (v9 & 1) != 0 )
				*a1 = (float)((float)((float)v10 + (float)1.0) * (float)((float)a4 - (float)a3))
				+ (float)((float)a3 - (float)((float)a5 - (float)a3));
			else
				*a1 = -(float)((float)((float)v10 * (float)((float)a4 - (float)a3)) - (float)a5);
			result = 1;
		}
		else
		{
			if ( (a2 & 0x1F0000) != 0x40000 )
			{
				if ( (_DWORD)v6 == 0x10000 )
				{
					if ( a3 <= a5 && a5 < a4 )
						goto LABEL_2;
				}
				else if ( (_DWORD)v6 == 0x20000 )
				{
					if ( a3 > a5 )
					{
						*a1 = a3;
						return 1;
					}
					if ( a4 <= a5 )
					{
						*a1 = a4;
						return 1;
					}
LABEL_2:
					*a1 = a5;
					return 1;
				}
				goto LABEL_13;
			}
			if ( a3 <= a5 && a5 < a4 )
				goto LABEL_2;
			v7 = (float)((float)((float)a5 - (float)a3) / (float)((float)a4 - (float)a3));
			LODWORD(v6) = (int)v7;
			if ( v7 < 0.0 )
				LODWORD(v6) = v6 - 1;
			*a1 = -(float)((float)((float)v6 * (float)((float)a4 - (float)a3)) - (float)a5);
			result = 1;
		}
		return result;
	}


	int __declspec( naked ) sub_82299600H(int result, int R4, int R5, double a4){
		
		__emit(0x1BE00774);
		__asm{

			

				lis r11,0x8229
				ori r11,r11,0x9610
				mtctr r11
			

				lis       r11, -0x7DE8
				lis       r10, -0x7DE9
				lfs       fp0, 0x3DB4(r11)

					bctr

		}
	}



	HOOK(int,__fastcall,sub_82299600,0x82299600,int result, int R4, int R5, double a4){

		return sub_82299600H(result,R4,R5,a4*MBKinnectInput->PclsXbox360System->GameDelta);

	}


	void Install()
	{
//
	//	INSTALL_HOOK(sub_82299600);
		//AnimationPlay
//		INSTALL_HOOK(sub_82807008);

		//INSTALL_HOOK(sub_82807008); --affec animatiosn pretty strange
	//	INSTALL_HOOK(sub_822AB3B0);

		
	
		//INSTALL_HOOK(CharacterBasePhysicsMove);

		INSTALL_HOOKR(sub_82211C08);
		WRITE_DWORD(0x82211EE4,0x419AFD20);
		INSTALL_HOOK(GameSpeedControllerUpdate);

		//INSTALL_HOOK(sub_822A9F58);

		//INSTALL_HOOK(sub_8227BB98);

		WRITE_NOP(0x822C0BE4,1);
		WRITE_NOP(0x822C0A14,0x32);


		WRITE_NOP(0x822C11C8,1);
		WRITE_NOP(0x822C0FFC,0x32);


		WRITE_DWORD(0x82B09ED4,TrickRampTypeA_360);
		WRITE_DWORD(0x82B09ED8,TrickRampTypeA_360_B);

	}

}