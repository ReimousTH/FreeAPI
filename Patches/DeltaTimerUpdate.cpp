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
	
	static float GetRawDeltaTime(){
		LARGE_INTEGER FXC;
		QueryPerformanceFrequency(&FXC);
		int StartTick = MBKinnectInput->Xbox360Timer->StartDeltaTime;
		int EndTick = MBKinnectInput->Xbox360Timer->__vftable->GetDeltaTime(MBKinnectInput->Xbox360Timer);
		float fixed_ticks = (float)(EndTick-StartTick)/((float)FXC.QuadPart);
		return fixed_ticks;	
	}

	static float GetDeltaTime(){
		return GetRawDeltaTime() * 0.016666668;	
	}
	static float GetFPS(){
		return 1.0/GetRawDeltaTime();
	}

	static unsigned long long GetRawDeltaTicks(){
		int StartTick = MBKinnectInput->Xbox360Timer->StartDeltaTime;
		int EndTick = MBKinnectInput->Xbox360Timer->__vftable->GetDeltaTime(MBKinnectInput->Xbox360Timer);
		return EndTick-StartTick;

	}


	HOOK(int,__fastcall,sub_82211C08,0x82211C08,struct_MBKinnectInput* atgu){



		return  MBKinnectInput->PclsXbox360System->__vftable->GetFlag5A(MBKinnectInput->PclsXbox360System);




	}

	HOOK(int,__fastcall,GameSpeedControllerUpdate,0x824B1588,clsXbox360System *a1){

		double FRAMERATE = 60.0;
		double FRAMERATE_PER_FRAME = 1.0/FRAMERATE;

		LARGE_INTEGER PeformanceFraq;
		QueryPerformanceFrequency(&PeformanceFraq);
		MBKinnectInput->Xbox360Timer->TimerValue = 1.0;
		int StartTick = MBKinnectInput->Xbox360Timer->StartDeltaTime;
		int EndTick = MBKinnectInput->Xbox360Timer->__vftable->GetDeltaTime(MBKinnectInput->Xbox360Timer);
		int RTick = EndTick-StartTick;
		double IN_GAME_FRAMERATE = (double)(PeformanceFraq.QuadPart/RTick);

		double v3; // fp11
		double v4; // fp0

		struct_v2* v2; // r3
		v2 = (struct_v2*)GetEngineGlobalParams();

	
		a1->GameSpeed = 1.0;
		a1->CameraSpeed = 1.0;

		
		float delta_ticks = (float)(RTick)/((double)PeformanceFraq.QuadPart);
		float normalized_ticks = delta_ticks /FRAMERATE_PER_FRAME;

		//perf / tick = fps  (60.0 example )
		//tick/perf = true_delta (0.0016 example)
		MBKinnectInput->Xbox360Timer->TickCount = (1.0/(double)(PeformanceFraq.QuadPart / RTick))*1000000;

		//uselee mb
		a1->TickPerSecond = MBKinnectInput->Xbox360Timer->TickCount;
		a1->field_10 = 1.0/IN_GAME_FRAMERATE;
	 	a1->RawFPS =  FRAMERATE; //822ACA28 IT ACTUALLY USED

		//
		DebugLogPushValue(MBKinnectInput->Xbox360Timer->TickCount);
	
		a1->GameDelta = normalized_ticks;
		a1->GameSpeed = 1.0;
		a1->CameraSpeed = 1.0;


		a1->field_34 = normalized_ticks * FRAMERATE_PER_FRAME;
		a1->field_30 =  normalized_ticks * FRAMERATE_PER_FRAME;
		a1->field_2C =  normalized_ticks * FRAMERATE_PER_FRAME * 1000.0 ;


		a1->field_24 =   normalized_ticks * FRAMERATE_PER_FRAME;

		//0.0166666666666667
		//60 FPS
		//16..??

		a1->field_20 =  normalized_ticks * FRAMERATE_PER_FRAME * 1000.0 ;

		a1->field_58 = 0;
		a1->field_5C |=0x01000000;

		//field_44 ???????


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



		int v4 = 0x8218B560 + 0x2A20 + (4 * ((a1->byte646 * 8) + a1->byte646));

		if (a1->field_968 == 1){
			//	ShowXenonMessage(L"MSG",*(float *)v4,0);


			struct_pfloat690* v7 = a1->pfloat690;


			float v8 = *(float *)&a1->field_8F8;

			float* field_8F4 = (float*)&a1->field_8F4;


			*field_8F4 = *field_8F4 - MBKinnectInput->PclsXbox360System->GameDelta;


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


			*field_8F4 = *field_8F4 - MBKinnectInput->PclsXbox360System->GameDelta;


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



	
	int DeltaTimerU::FrameSkipCount = 0;
	HOOK(int,__fastcall,sub_824BB868,0x824BB868,_DWORD* a1){

	

		int v2; // r29
		int v3; // r28
		int v4; // r31
		int result; // r3


		v2 = GetEngineGlobalParams()->field_20;
		v3 = GetEngineGlobalParams()->field_1C;
		v4 = GetEngineGlobalParams()->field_10;

	

		if (MBKinnectInput->Xbox360Timer->TickCount <= 16660){

			BranchTo(0x824E8218,int,D3D__CDevice__GAME,1);

		}
		else{

			BranchTo(0x824E8218,int,D3D__CDevice__GAME, 0x80000000);
		}

		// Check if it's time to render a frame
		
			// Render
			++a1[0x13];
			(*(void (__fastcall **)(_DWORD, _DWORD))(**(_DWORD **)(v2 + 0xC) + 0x20))(*(_DWORD *)(v2 + 0xC), 0);
			(*(void (__fastcall **)(_DWORD *))(*a1 + 0x18))(a1);
			(*(void (__fastcall **)(_DWORD *))(*a1 + 0x1C))(a1);
			(*(void (__fastcall **)(int))(*(_DWORD *)v3 + 0xC))(v3);// 8249BC40	
			// END

	
	
		BranchTo(0x824B1588, int, a1);
		result = BranchTo(0x824BBEB0, int, v2);
		if (v4)
			result = (*(int (__fastcall **)(int))(*(_DWORD *)v4 + 4))(v4);


		return result;

	}


	HOOK(int,__fastcall,sub_824DAEE0,0x824DAEE0,LARGE_INTEGER* a1){
		DWORD value;
		DWORD link;
		__asm { mftb      r11
				mr value,r11
				mflr r12
				mr link,r12
		}



		// Convert hexadecimal value to hexadecimal string
		std::stringstream ss;
		ss << std::hex << link;
		std::string hexString = ss.str();


		if ( ZLuaN::EnableDebugOutput) InputData::DebugLog.push_back(std::string(hexString));

		a1->LowPart = value;
		return 1;
	}


	int __fastcall sub_82497FC0(clsXbox360Timer *a1)
	{

		DWORD link;
		__asm { 

			mflr r12
			mr link,r12
		}
		// Convert hexadecimal value to hexadecimal string
		std::stringstream ss;
		ss << std::hex << link;
		std::string hexString = ss.str();


		if ( ZLuaN::EnableDebugOutput) InputData::DebugLog.push_back(std::string(hexString));


		return BranchTo(0x82497FC0,int,a1);
	}

	int __declspec( naked ) sub_824B08C0H(CamP0x1F0* a1){
		__asm{
				mflr r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)

				addi      r12, r1, -0x20
				stfd      fp28, -0x20(r12)
				stfd      fp29, -0x18(r12)
				stfd      fp30, -0x10(r12)
				stfd      fp31, -8(r12)

				lis r11,0x824B
				ori r11,r11,0x08D0
				mtctr r11
				bctr 
		}
	}
	HOOK(int,__fastcall,sub_824B08C0,0x824B08C0,CamP0x1F0* a1){

		int v18;
		if (*(byte*)&a1->field_28 != 2){

			if (a1->field_1C){

				int v19 = a1->field_1C;
				if ( v19 )
				{
					v18 = (*(int (__fastcall **)(int, clsXbox360Camera *, int))(*(_DWORD *)v19 + 8))(
						v19,
						a1->Camera2,
						a1->field_4);
				}


				float v26 = MBKinnectInput->PclsXbox360System->GameDelta +  *(float*)&a1->field_2C;
				int v27 = a1->field_30;
				*(float*)&a1->field_2C = v26;

				if ( v26 >= v27 )
				{

					((void (__fastcall *)(CamP0x1F0 *))a1->__vftable->func18)(a1);
				}
				if ( !v18 )
				{
					((void (__fastcall *)(CamP0x1F0 *))a1->__vftable->func18)(a1);
					a1->__vftable->func10(a1);
				}



			}
		}
		return sub_824B08C0H(a1);

	}

	int __declspec( naked ) sub_82321BD8H(int a1,int a2,double dlt4){
		__asm{
			mflr r12
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


				stfd      fp29, -0x78(r1)
				stfd      fp30, -0x70(r1)

				lis r11,0x8232
				ori r11,r11,0x1BE8
				mtctr r11
				bctr r11

		}
	}





	HOOK(int,__fastcall,sub_82321BD8,0x82321BD8,int a1,int a2,double dlt){


		uint MainCSS = 4 * (a2 + 84);
		uint MCSS = *(_DWORD *)(MainCSS + a1);


		char back_chain[336]; 
	


		switch (MCSS){

			case 1:
				{
					XMVECTOR* fv8 = (XMVECTOR*)(16 * (a2 + 38) + a1);



					*(XMVECTOR*)&back_chain[128] = *fv8;

		


					*(float *)&back_chain[116] = 0.0;
					*(float *)&back_chain[112] = -BranchTo(0x82A54A00,float,*(float *)(a1 + 52));
					*(float *)&back_chain[120] = BranchTo(0x82A54920,float,*(float *)(a1 + 52));

					//unsigned short* fv12_fixed = (unsigned short*)(2 * (a2 + 192) + a1);
					 float* fv12_fixed_float = (float*)(2 * (a2 + 192) + a1);
					// unsigned short  fv12_fvalue = fv12_fixed[0];
					 float  fv12_fvalue_float = *fv12_fixed_float;

					 if (fv12_fvalue_float >= 90){
						 fv12_fvalue_float = 90;
					 }
					 if ( *(_BYTE *)(a1 + 1008) ){

						 //faster copy
						 *(XMVECTOR*)(a1 + 928) = *fv8;
						 *(float *)(a1 + 932) = *(float *)(a1 + 932) + (float)2.0;
						 BranchTo(0x824B3350,int,MBKinnectInput->field_78,0x12,0xC,a1 + 928,a1 + 944,-1,0,0);

						 *(_BYTE *)(a1 + 1008) = 0;

					 }

					 *(float *)&back_chain[96] = 0.0;
					 *(float *)&back_chain[100] = 0.0;
					 *(_QWORD *)&back_chain[80] = fv12_fvalue_float;
					 *(float *)&back_chain[104] = 0.0;
					 *(float *)&back_chain[108] = 1.0;

					
					 double fv17  = BranchTo(0x82A54920,float,(double)fv12_fvalue_float * (3.14 / 180.0));

					// *(_QWORD *)&back_chain[80] = fv12_fixed[0];

					 float* fv19 = (float*)(4 * (a2 + 200) + a1);
					 fv19[0] = (float)*fv12_fixed_float * fv17 * 20.0; 
					// *(_QWORD *)&back_chain[80] = *fv12_fixed;

					 if ((float)*fv12_fixed_float * fv17 * 20.0 <  (float)*fv12_fixed_float * 15.0 ){
						 fv19[0] = (float)*fv12_fixed_float * 15.0;
					 }
					 bool fv14 = false;

					 if ((float)fv19[0] >= 720.0){
						 fv14 = true;
						BranchTo(0x82284790, int, &back_chain[96], &back_chain[112], (720.0 * 3.14159265358979323846) / 180.0);

					 }
					 else{
						  BranchTo(0x82284790,int,&back_chain[96],&back_chain[112],(float)fv19[0] * (3.14159265358979323846 / 180.0)   );
					 }
			

					 XMVECTOR v94 = XMVectorZero();
					 XMVECTOR v62 = XMVectorSet(1,1,1,1);
					 XMVECTOR v61 = __vor(v94,v62);
					 XMVECTOR v60 = __vpermwi(v62,0xEA);
					 XMVECTOR v59 = __vpermwi(v62,0xBA);
					 XMVECTOR v58 = __vpermwi(v62,0xAE);

					 XMVECTOR* Vector_a1 = (XMVECTOR*)(16 * (a2 + 0x1A) + a1);

					 XMStoreFloat3((XMFLOAT3*)&back_chain[80], -*Vector_a1);
					 *(XMVECTOR*)&back_chain[80] = XMVectorSetW(*Vector_a1, 1.0f);

					 // 0x8E
				
					 v61 = __vrlimi(v61,*(XMVECTOR*)&back_chain[80],0xE,0);

					 *(XMVECTOR*)&back_chain[144] = v60;
					 *(XMVECTOR*)&back_chain[160] = v59;
					 *(XMVECTOR*)&back_chain[176] = v58;
					 *(XMVECTOR*)&back_chain[192] = v61;

					 XMMATRIX* temp1 = reinterpret_cast<XMMATRIX*>(&back_chain[144]);
					 XMVECTOR* temp2 =(XMVECTOR*)(&back_chain[96]);

					 BranchTo(0x823209C0,int,temp1,temp2);


					 *(float *)&back_chain[192] = *(float *)&back_chain[192] + (float)Vector_a1->x;
					 *(float *)&back_chain[196] = *(float *)&back_chain[192] + (float)Vector_a1->y;
					 *(float *)&back_chain[200] = *(float *)&back_chain[192] + (float)Vector_a1->z;

					 XMVECTOR* v55 =  (XMVECTOR *)&back_chain[192];
					 XMVECTOR* v56 =  (XMVECTOR *)&back_chain[128];
					 XMVECTOR v54 =  *v55 + *v56;
					 *v56 = v54;


					 //??
					 *(float *)&back_chain[140] = 1.0;
					 XMVECTOR* temp30 = (XMVECTOR *)&back_chain[112];
					 XMVECTOR* temp31 = (XMVECTOR *)&back_chain[160];
					 *temp30 = *temp31;
					 int         fv34 = 4 * (a2 + 212);
					 int		 fv35 = *(_DWORD *)(fv34 + a1);
					 float*      fv40 = (float *)(fv35 + 256);


					 BranchTo(0x8228D460,int,fv40,(float *)&back_chain[112],(float *)&back_chain[128]);
					 
					 int fv37 = fv35 + 0x60;

					 *(XMVECTOR *)(fv37 + 224)=  *(XMVECTOR *)(fv37 + 176);
					 BranchTo(0x82299600,int,fv35+944,fv35+256,fv35+256,0.0);
					 BranchTo(0x82299600,int,fv35+704,fv35+256,fv35+256,0.0);

					  *(XMVECTOR*)(*(_DWORD *)(fv34 + a1) + 0x170) =  *(XMVECTOR*)&back_chain[128];

					  if (fv14){
						        *(_DWORD *)(MainCSS + a1) = 2;
					  }



					  *fv12_fixed_float +=  MBKinnectInput->PclsXbox360System->GameDelta;

	
					 	
	
				
				



				}
				break;
			case 2:
				sub_82321BD8H(a1,a2,dlt);
				break;	
			default:
				sub_82321BD8H(a1,a2,dlt);
				break;


		}


		


		return a1;

	}




	HOOK(int,__fastcall,ProcessAnimationSpeed,0x823B92C8,int a1)
	{
		int v1; // r11
		double v4; // fp0
		double v5; // fp13
		double (__fastcall *v6)(int); // ctr
		double v7; // fp12
		double v8; // fp1
		double v9; // fp0
		int v10; // r11
		double v11; // fp0

		v1 = *(_DWORD *)(a1 + 52);
		if ( (v1 & 0x10) != 0 )
		{
			return 0;
		}
		v4 = *(float *)(a1 + 0x38);
		v5 = *(float *)(a1 + 0x48);
		v6 = *(double (__fastcall **)(int))(*(_DWORD *)a1 + 32);
		v7 = MBKinnectInput->PclsXbox360System->GameDelta;
		*(_DWORD *)(a1 + 52) = v1 & 0xFFFFFFF7;
		*(float *)(a1 + 0x38) = (float)((float)v7 * (float)v5) + (float)v4;
		v8 = v6(a1);
		v9 = *(float *)(a1 + 0x38);
		if ( v8 <= v9 )
		{
			v10 = *(_DWORD *)(a1 + 52);
			if ( (v10 & 1) == 0 )
			{
				*(_DWORD *)(a1 + 52) = v10 | 8;
			}
			if ( (*(_DWORD *)(a1 + 52) & 4) != 0 )
			{
				v11 = (float)((float)v8 - (float)MBKinnectInput->PclsXbox360System->GameDelta *  1.0/60.0);
			}
			else
			{
				v11 = (float)((float)v9 - (float)v8);
			}
			*(float *)(a1 + 56) = v11;
		}
		return 1;
	}



	void Install()
	{
		INSTALL_HOOK(ProcessAnimationSpeed)
	//	INSTALL_HOOK(sub_82321BD8);
		//LONG
		//824B0894
		//88081F04 ??
		//88081f3c ?? (Just my code)
		//824b0a2c
		//824b0aa8
		//824b0ce4
		//822790c0





		//824B0860  (WHY SEGA)
		//why twice 822790C0 
		INSTALL_HOOK(sub_824B08C0);

		//FLOATS TIME


		WRITE_DWORD(0x824B0A2C,0xC19F002C); //lfs f12,0x2c(r31)
		WRITE_NOP(0x824B0A40,1);

		WRITE_NOP(0x824B0AA8,0xC1BF002C); // lfs f13,0x2c(r31)
		WRITE_NOP(0x824B0AB4,2);



		WRITE_DWORD(0x822790C0,0xC17D002C); // lfs       f11, 0x2C(r29)
		WRITE_DWORD(0x822790D4,0x60000000);




		WRITE_NOP(0x824B0CF0 ,1);
		WRITE_DWORD(0x824B0CF8,0x48000018);
		WRITE_DWORD(0x824B0D14,0x4800002C);

	//	WRITE_DWORD(0x821A9C60,sub_82497FC0);
	//	WRITE_DWORD(0x821A9C64,sub_82497FC0);

		//INSTALL_HOOK(sub_824DAEE0);
	 //  INSTALL_HOOK(sub_824BB868);
//



	//	INSTALL_HOOK(sub_82299600);
		//AnimationPlay
//		INSTALL_HOOK(sub_82807008);

		//INSTALL_HOOK(sub_82807008); --affec animatiosn pretty strange
	//	INSTALL_HOOK(sub_822AB3B0);

		
	
		//INSTALL_HOOK(CharacterBasePhysicsMove);

		//IF CRASHESH
		//INSTALL_HOOKR(sub_82211C08);
		//WRITE_DWORD(0x82211EE4,0x419AFD20);


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