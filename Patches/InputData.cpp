#include "InputData.h"


namespace InputData{
	


	std::vector<byte> GetIPHelper(const char* st){

		int num = 0;
		int result = 0;
		char* str = new char(strlen(st));
		strcpy(str,st);
		std::vector<byte> v;
		char* chars_array = strtok(str, ".");
		while(chars_array)
		{
			v.push_back((byte)(strtoul(chars_array,NULL,10)));
			chars_array = strtok(NULL, ".");

		}
		return v;

	}




	void SetSessionIP(){

		const char* str =CommonLua.GetGlobalString("ConnectSessionID");
		std::vector<byte> IP_VEC = GetIPHelper(CommonLua.GetGlobalString("ConnectIP"));


		std::stringstream conv;
		const char* ByteArrayString = str;
		std::string ByteArrayStringR = std::string(ByteArrayString);

		ByteArrayStringR.erase(std::remove( ByteArrayStringR.begin(),
			ByteArrayStringR.end(),
			' '),
			ByteArrayStringR.end());


		int len  = ByteArrayStringR.length();
		if (len % 2 != 0){ //Add Extra Zero
			ByteArrayStringR.append("0");
		}
		const char* cu = ByteArrayStringR.c_str();
		byte* bt = new byte[strlen(cu)/2];
		char buff[2] = {0,0};
		for (int i =0 ;i<strlen(cu)/2;i++){
			memcpy((void*)&buff,(void*)((uint)cu + (i*2)),2);
			bt[i] = (uint)(strtoul(buff,NULL,16));

		}




		XINVITE_INFO* t = (XINVITE_INFO*)(XNLiveSomeStatic + 0x67);
		memcpy((void*)t->hostInfo.sessionID.ab,bt,8);
		t->dwTitleID = 0x5345084D;
		t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b1 = IP_VEC[0];
		t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b2 = IP_VEC[1];
		t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b3 = IP_VEC[2];
		t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b4 = IP_VEC[3];
		t->hostInfo.hostAddress.wPortOnline = 36000;
		t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b1 = IP_VEC[0];
		t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b2 = IP_VEC[1];
		t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b3 = IP_VEC[2];
		t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b4 = IP_VEC[3];





	}




	DWORD ResetInputParams(struct_v35* NuiFakeDevice,int id){
		NuiFakeDevice->field_280=0.5;
		NuiFakeDevice->dword310 = 1;
		NuiFakeDevice->dword300->gap0 = 0;
		NuiFakeDevice->dword300->dwTrackingID = 0;
		NuiFakeDevice->field_24 =0;
		NuiFakeDevice->field_20 = 0;

		//field_24 -- Slip of from (possible its int)
		//field_20 -- Move Direction (Left Right)
		NuiFakeDevice->field_4 = -1.0;
		NuiFakeDevice->field_14 = 0.5;
		NuiFakeDevice->field_18 = 0.5;

		NuiFakeDevice->field_84 = 1.0; //Sursor Second
		NuiFakeDevice->field_88 = 1.0; //Sursor Second


		NuiFakeDevice->field_B0 = 0.0;
		NuiFakeDevice->field_B4 = 0.0;


		NuiFakeDevice->field_284 = 0.0;
		NuiFakeDevice->field_2E4 = 0;
		NuiFakeDevice->field_2F4 = 0;


		*(int*)&NuiFakeDevice->dword300->gapex[0]=id;


		return 0;

	}










	DWORD ProcessSingleDpadExtra(ATG::GAMEPAD* gc,bool* DPAD_LEFT_RING,short* DPAD_LEFT_RING_COUNT,short* DPAD_LEFT_RING_COUNT_PRE,float* DPAD_LEFT_RING_TIME,bool* DPAD_LEFT_RING_RELEASED,WORD ControlDPAD){


		if (gc->wPressedButtons & ControlDPAD){
			*DPAD_LEFT_RING_COUNT +=1;
			*DPAD_LEFT_RING = true;


		}
		if (gc->wLastButtons & ControlDPAD){
			*DPAD_LEFT_RING_TIME += 0.1;
			*DPAD_LEFT_RING_RELEASED = false;
			if (        (*DPAD_LEFT_RING_TIME >= 10.0    && *DPAD_LEFT_RING_COUNT_PRE == 0) || (*DPAD_LEFT_RING_TIME >= 1.0    && *DPAD_LEFT_RING_COUNT_PRE > 0)         ) {
				*DPAD_LEFT_RING_TIME = 0.0;
				*DPAD_LEFT_RING_COUNT_PRE += 1;
			}
		}
		else
		{

			*DPAD_LEFT_RING_TIME = 0.0;
			*DPAD_LEFT_RING_RELEASED = true;
		}

		if (*DPAD_LEFT_RING_COUNT_PRE > 0 && *DPAD_LEFT_RING_RELEASED  == true ){
			*DPAD_LEFT_RING_COUNT = *DPAD_LEFT_RING_COUNT_PRE;
			*DPAD_LEFT_RING_COUNT_PRE = 0;


		}
		else if (*DPAD_LEFT_RING_TIME <= 0){
			*DPAD_LEFT_RING = true;
		
		}


		return 0;
	}
	DWORD ProcessSingleDpadsExtra(ATG::GAMEPAD* gc,NukFakeDeviceHelpers* HP,struct_v35* Device){


		ProcessSingleDpadExtra(gc,&HP->DPAD_LEFT_RING,
			&HP->DPAD_LEFT_RING_COUNT,
			&HP->DPAD_LEFT_RING_COUNT_PRE,
			&HP->DPAD_LEFT_RING_TIME,
			&HP->DPAD_LEFT_RING_RELEASED,XINPUT_GAMEPAD_DPAD_LEFT);
		ProcessSingleDpadExtra(gc,&HP->DPAD_RIGHT_RING,
			&HP->DPAD_RIGHT_RING_COUNT,
			&HP->DPAD_RIGHT_RING_COUNT_PRE,
			&HP->DPAD_RIGHT_RING_TIME,
			&HP->DPAD_RIGHT_RING_RELEASED,XINPUT_GAMEPAD_DPAD_RIGHT);
		
		Device->dword300->ConnectionStatus = HP->DPAD_LEFT_RING_COUNT + HP->DPAD_RIGHT_RING_COUNT;

		return 0;

	}



	DWORD  ProcessSingleInput(struct_v35* NuiFakeDevice,struct_dword300 * NuiFakeDeviceExtra,NukFakeDeviceHelpers* HP,ATG::GAMEPAD* gc,int index){


		auto t = (int)(int*)&KinnectNuiBox::Instance->dword78;
		auto t1 = (int)(int*)&KinnectNuiBox::Instance->floatA0;
		auto z = (struct_v35**)(t+(index*4));

		auto z1 = (float*)(t1+(index*4));


		if (gc->wLastButtons & XINPUT_GAMEPAD_BACK){
			HP->SelectHoldTime += 1.0 * MBKinnectInput->PclsXbox360System->GameSpeed;
			if (HP->SelectHoldTime > 2.0){
				*z = 0;
				HP->SelectHoldTime = 0.0;
			}
			return 0 ;
		}
		else{
			HP->SelectHoldTime = 0.0;
		}


		if (gc->bConnected == false){
			if (*z != 0){
				*z = 0;
			}
			return 0;
		}




		else if  (*z != NuiFakeDevice){



			*z=NuiFakeDevice;
			//KinnectNuiBox::Instance->dwordB8 = 3;
			NuiFakeDevice->dword300 = NuiFakeDeviceExtra;
			ResetInputParams(NuiFakeDevice,index);

		}


		//	if (GameRootStateController && (GameRootStateController->GameRootState == 2 |GameRootStateController->GameRootState == 1  ))
		//	{
		//
		//	}

		//	else


		{
			//ShowXenonMessage(L"MSG","B");
			HP->StickForceX =(-gc->fX1+1)/2;
			HP->StickForceX = clamp(HP->StickForceX,0.0,1.0);
			HP->StickForceY = (gc->fY1);
			//StickForceY = clamp(StickForceY,0.0,1.0);
			if (NuiFakeDevice->field_4 != 0){
				NuiFakeDevice->field_4 = 0;
			}
			if (NuiFakeDevice->field_30 != 0)NuiFakeDevice->field_30 = 0;
			if (NuiFakeDevice->field_34 != 0)NuiFakeDevice->field_34 = 0;
			if (NuiFakeDevice->field_24 != 0) NuiFakeDevice->field_24 = 0;
			if (NuiFakeDevice->field_48 != 0) NuiFakeDevice->field_48 = 0;
			if (NuiFakeDevice->field_104 != 0) NuiFakeDevice->field_104 = 0;
			if (NuiFakeDevice->field_108 != 0) NuiFakeDevice->field_108 = 0;





			if (NuiFakeDevice->field_58 != gc->fX1){
				NuiFakeDevice->field_58 = gc->fX1;
			}
			if (NuiFakeDevice->field_284 != HP->StickForceX)
			{
				//-0x168 = Kick Dash Value First
				//-0x28 = Kick Dash Second First
				//0x258
				//0x118
				NuiFakeDevice->field_284 = HP->StickForceX;
				NuiFakeDevice->field_20 = -gc->fX1; // left right
				NuiFakeDevice->dword310 = (NuiFakeDevice->dword310) == 0 ? 1 : 0;
			}
			if (NuiFakeDevice->field_28 != HP->StickForceY)
			{
				if (HP->StickForceY <= -0.75){
					//NuiFakeDevice->field_2C0 = 2;
					//NuiFakeDevice->field_2D0 = 2;
					NuiFakeDevice->field_2E4 = 2;
					NuiFakeDevice->field_2F4 = 2;

					//	memcpy((byte*)&NuiFakeDevice->field_D0 ,(byte*)&BrakePreLoadD0,0x10);
					//	memcpy((byte*)&NuiFakeDevice->field_E0 ,(byte*)&BrakePreLoadE0,0x10);
					//	memcpy((byte*)&NuiFakeDevice->field_110 ,(byte*)&BrakePreLoad110,0x10);
					//	memcpy((byte*)&NuiFakeDevice->field_210 ,(byte*)&BrakePreLoad210,0x10);
					//	memcpy((byte*)&NuiFakeDevice->field_250 ,(byte*)&BrakePreLoad250,0x10);



				}
				NuiFakeDevice->field_28 = HP->StickForceY;
				NuiFakeDevice->dword310 = (NuiFakeDevice->dword310) == 0 ? 1 : 0;

			}


			if (NuiFakeDevice->field_10 != gc->fX2){
				NuiFakeDevice->field_10 = gc->fX2;
			}





			if (gc->bLastRightTrigger){
				NuiFakeDevice->field_5C = 1.0;
			}
			else{
				NuiFakeDevice->field_5C = 0.0;
			}




			if (NuiFakeDevice->field_60 != gc->fY2){
				NuiFakeDevice->field_60 = gc->fY2;

			}

			if (gc->wLastButtons & XINPUT_GAMEPAD_X){
				NuiFakeDevice->field_0 += MBKinnectInput->PclsXbox360System->GameSpeed;
			}
			else{
				if (NuiFakeDevice->field_0 != 0.0)
					NuiFakeDevice->field_0 = 0.0;
			}


			if ((gc->wPressedButtons & XINPUT_GAMEPAD_X) && HP->Button_X_Hold == false){

				NuiFakeDevice->field_30 = 1.0; //Ready
				HP->Button_X_Hold = true;

			}

			if (!(gc->wLastButtons & XINPUT_GAMEPAD_X) && HP->Button_X_Hold == true){
				NuiFakeDevice->field_34 = 1.0; //Do Kick
				HP->Button_X_Hold = false;
			}


			if ((gc->wLastButtons & XINPUT_GAMEPAD_A) && HP->Button_A_Hold == false){
				HP->Button_A_Hold = true;
				//OnEnterAction
				NuiFakeDevice->field_2F4 = 2;
				NuiFakeDevice->field_8 = 1.0;	
			}
			if (!(gc->wLastButtons & XINPUT_GAMEPAD_A) && HP->Button_A_Hold == true){
				HP->Button_A_Hold = false;
				NuiFakeDevice->field_8 = 0.0;
				NuiFakeDevice->field_2F4 = 0;
				NuiFakeDevice->field_2E4 = 0;
				NuiFakeDevice->field_4 = 1.0;
				NuiFakeDevice->field_24 = 1.0;
			}

			if ((gc->wLastButtons & XINPUT_GAMEPAD_B) && HP->Button_B_Hold == false){
				HP->Button_B_Hold = true;
				//OnEnterAction	
				NuiFakeDevice->field_10C = 1.0;	
				NuiFakeDevice->field_110 = 1.0;	
			}
			if (!(gc->wLastButtons & XINPUT_GAMEPAD_B) && HP->Button_B_Hold == true){
				HP->Button_B_Hold = false;
				NuiFakeDevice->field_10C = 0.0;
				NuiFakeDevice->field_110 = 0.0;

			}


			if (gc->wPressedButtons & XINPUT_GAMEPAD_A){
				NuiFakeDevice->field_58 = 1.0;
			}

			if ((gc->wPressedButtons & XINPUT_GAMEPAD_Y)){
				NuiFakeDevice->field_48 = 1.0;

			}






			if ((gc->bLastLeftTrigger) && HP->Button_LT_Hold == false){
				HP->Button_LT_Hold = true;
				//OnEnterAction
				NuiFakeDevice->field_100 = 1.0;	
			}
			if (!(gc->bLastLeftTrigger) && HP->Button_LT_Hold == true){
				HP->Button_LT_Hold = false;
				NuiFakeDevice->field_100 = 0.0;
			}


			if (gc->wPressedButtons & XINPUT_GAMEPAD_LEFT_SHOULDER){

				NuiFakeDevice->field_104 = 1.0;
			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER){

				NuiFakeDevice->field_108 = 1.0;
			}





		}



		//HP->DPAD_LEFT_RING_COUNT = 0;


		//HP->DPAD_RIGHT_RING = false;
		//HP->MENU_BUTTON_A_HOLD = false;
		HP->MENU_BUTTON_B = false;
		HP->MENU_BUTTON_Y = false;
		HP->Menu_START_BUTTON_PRESS = false;
		HP->Menu_DPAD_DOWN = false;
		HP->Menu_DPAD_UP = false;
		HP->MENU_BUTTON_A_RELEASE = false;





		ProcessSingleDpadsExtra(gc,HP,NuiFakeDevice);




		
		if (gc->wLastButtons & XINPUT_GAMEPAD_A){
			HP->MENU_BUTTON_A_HOLD = true;
		}
		if ((gc->wLastButtons & XINPUT_GAMEPAD_A) ==0  && HP->MENU_BUTTON_A_HOLD){
			HP->MENU_BUTTON_A_RELEASE = true;
			HP->MENU_BUTTON_A_HOLD = false;
		}


		if (gc->wPressedButtons & XINPUT_GAMEPAD_B){
			HP->MENU_BUTTON_B = true;
		}
		if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
			HP->MENU_BUTTON_Y = true;
			*(DWORD*)((INT)&NuiFakeDevice->dword300->gap0+0x17C)  = *(DWORD*)((int)&NuiFakeDevice->dword300->gap0+0x17C) == 0 ? 2 : 0;
		}
		if (gc->wPressedButtons & XINPUT_GAMEPAD_BACK){

			ResetInputParams(NuiFakeDevice,index);

		}
		float accelle = 1.0;
		if (gc->wLastButtons & XINPUT_GAMEPAD_X){
			accelle = 2.0;
		}

		if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP){
			HP->Menu_DPAD_UP = true;
		}
		if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN){
			HP->Menu_DPAD_DOWN = true;
		}


		NuiFakeDevice->field_B0 += -gc->fX2 * MBKinnectInput->PclsXbox360System->GameSpeed /100.0 * accelle;
		NuiFakeDevice->field_B4 += -gc->fY2 * MBKinnectInput->PclsXbox360System->GameSpeed /100.0 * accelle;
		//*(float*)((INT)&NuiFakeDevice->dword300->gap0+0x17C+0x4+0x20) += gc->fY2 *MBKinnectInput->dword18->GameSpeed /100.0;


		return 0;
	}




	int __declspec(naked) SelfViewUpdateH(int result){
		__asm{
			mflr r12
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0x80(r1)
				lis r11,0x8243
				ori r11,r11,0x8940 
				mtctr r11
				lbz       r11, 0x200C(r3)
				bctr
		}

	}

	bool onceX = false;


	byte Gamemode690H[0x300]  = {0};
	byte Gamemode690H1[0x300] = {0};


	HOOK(int,__fastcall,SelfViewUpdate,0x82438930,int a1){
	
		if (onceX == false && Static_8219FB14){
			onceX = !onceX;

//			*(_DWORD *)(NearKinnectNuiBox::Instance + 0x9C) = 1;

		//	*(_DWORD *)(*(_DWORD *)(InputSomeUnkStatic + 0x24) + 0) = (_DWORD)&Expo1;
		
		//	BranchTo(0X823B7C08,INT,seg_83E52F84);

			//BranchTo(0x823B87A0,int,seg_83E52F84+4,*(_DWORD *)(InputSomeUnkStatic + 0x14));
			//BranchTo(0x8226D940,int,Static_8219FB14,0,1,&Expo);
			//BranchTo(0x8226D940,int,Static_8219FB14,1,1,&Expo);
		//	BranchTo(0x8226D940,int,Static_8219FB14,0,0,&Gamemode690H,0);
	

		}
	
		if (MainGameRooOrEnginetStaticInstance){
			*(char*)(MainGameRooOrEnginetStaticInstance + 0x7F23) = 1; //Update Device Status
	
		}

	ATG::Input::GetMergedInput();


	if (KinnectNuiBox::Instance){
		if (KinnectNuiBox::Instance->dword78 == 0){
			//KinnectNuiBox::Instance->dword78 = &NuiFakeDevice;
			//KinnectNuiBox::Instance->dwordB8 = 3;

		}


	
		ProcessSingleInput(&NuiFakeDevice,&NuiFakeDeviceExtra,&NuiFakeDeviceHP1,gc,0);

		
		ProcessSingleInput(&NuiFakeDeviceP2,&NuiFakeDeviceExtraP2,&NuiFakeDeviceHP2,gc2P,1);

	

		if ( (gc->wPressedButtons & XINPUT_GAMEPAD_LEFT_THUMB ) &&   (gc->wLastButtons & XINPUT_GAMEPAD_DPAD_UP )){
			ShowUI = !ShowUI;
		}
		if ( (gc->wPressedButtons & XINPUT_GAMEPAD_RIGHT_THUMB )) {

			ForcePauseGame = !ForcePauseGame;

			if (ForcePauseGame){
				sub_8249F9C8((int)MBKinnectInput->field_34, 3u, 2);
			}
			else{
				sub_8249F9C8((int)MBKinnectInput->field_34, 3u, 0);
			}


		}

		if ((gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP) && GameRootStateController &&GameRootStateController->GameRootState == 1){
			 //XINVITE_INFO* t = (XINVITE_INFO*)(XNLiveSomeStatic + 0x67);

			 SetSessionIP();

			 *(_BYTE *)(XNLiveSomeStatic + 0x65) = 1;
	//		 *(_BYTE *)(XNLiveSomeStatic + 0x66) = 0;

			 *(_BYTE *)(XNLiveSomeStatic + 0xBB) = 0;
		}


		if (ForcePauseGame){
		DWORD t1 = (_DWORD )MBKinnectInput[1].field_28;

		DWORD tl_cam = **(int**)(t1 + 0x8);

		float* CameraPosition = (float*)(tl_cam + 0x50);
		float* CameraPositionCenter = (float*)(tl_cam + 0x60); //Center


	

		float* CameraRotation = (float*)(tl_cam + 0x40);
			CameraPosition[0] += gc->fX1;

			if (gc->wLastButtons & XINPUT_GAMEPAD_A){
				CameraPosition[1] += 0.1;
			}
			if (gc->wLastButtons & XINPUT_GAMEPAD_B){
				CameraPosition[1] -= 0.1;
			}

			CameraPosition[2] += gc->fY1;



				float* CameraMetric = (float*)(tl_cam + 0x20);

		

		auto t = ( irr::core::CMatrix4<float>*)(tl_cam + 0x20);
		auto rot = t->getRotationDegrees();

		if (gc->wPressedButtons & XINPUT_GAMEPAD_Y){
			irr::core::vector3d<float> pos_camera;
			irr::core::vector3d<float> TTT;


			pos_camera.X = CameraPosition[0];
			pos_camera.Y = CameraPosition[1];
			pos_camera.Z = CameraPosition[2];

			//CameraPositionCenter[0] = CameraPosition[0];
			//CameraPositionCenter[1] = CameraPosition[1];
			//CameraPositionCenter[2] = CameraPosition[2];
			//CameraPositionCenter[3] = CameraPosition[3];


		//	t->setTranslation(pos_camera);
	
		//	t->setRotationCenter(TTT,pos_camera.invert());
			//t->setTextureTranslate()
		
		
			//t->setRotationCenter(pos_camera,t->getTranslation());
		}
	

		rot.X+=gc->fX2;
		rot.Z += gc->fY2;

	
		rot.Y +=gc->bLastLeftTrigger;
		rot.Y -=gc->bLastRightTrigger;

		




		t->setRotationDegrees(rot);





			//CameraRotation[0] = clamp(CameraRotation[0] + gc->fX2 * 0.01,-1.0,1.0);

			//CameraRotation[1] = clamp(CameraRotation[1] + gc->fY2 * 0.01,-1.0,1.0);

			//CameraRotation[2] = clamp(CameraRotation[2] + gc->fY2 * 0.01,-1.0,1.0);
		}






		//WriteVirtualBytes("0x8229A6D4","60000000")
	    //WriteVirtualBytes("0x8229A6EC","60000000")
		if (seg_83E52F84){
//			*(_DWORD *)(4 * 0 + *(_DWORD *)(seg_83E52F84 + 4)) = (DWORD)&seg_83E52F84Fake;
//			*(_DWORD *)(4 * 1 + *(_DWORD *)(seg_83E52F84 + 4)) = (DWORD)&seg_83E52F84Fake;


//			DWORD v5 = *(_DWORD *)(4 * 0 + *(_DWORD *)(seg_83E52F84 + 4));
//			DWORD v6 = *(_DWORD *)(4 * 1 + *(_DWORD *)(seg_83E52F84 + 4));

//			*(_DWORD **)(v5 + 0x4C) = (DWORD*)&seg_83E52F84Fake;
//			*(_DWORD **)(v6 + 0x4C) = (DWORD*)&seg_83E52F84Fake;


		}
	
	
		//*(byte*)((int)MainTitlev144Actions + 0x1558)=1; //GlobalInputLock




		if (!once){
			once = true;
			*(int*)((int)NUI::Input::Instance + 0x60)=2;
			*(int*)((int)NUI::Input::Instance + 0x220)=2;

		}

	}
	

	if (InputSomeUnkStatic){

		if (*(int*)(InputSomeUnkStatic + 0xA0) == 0){

		//	*(int*)(InputSomeUnkStatic + 0xA0)  = (int)&InputSomeUnkStaticA0Fake;

		}
	}

	if (dword_83E53144 == 0){
		//dword_83E53144 = (int)&dword_83E53144Fake;
	}



	
	return SelfViewUpdateH(a1);
}

	
ATG::GAMEPAD* gc =  &ATG::Input::m_Gamepads[P1SLOT];
ATG::GAMEPAD* gc2P =  &ATG::Input::m_Gamepads[P2SLOT];


NukFakeDeviceHelpers NuiFakeDeviceHP1 = NukFakeDeviceHelpers();
NukFakeDeviceHelpers NuiFakeDeviceHP2 =  NukFakeDeviceHelpers();


NukFakeDeviceHelpers* NuiFakeDevicePO[2] = {&NuiFakeDeviceHP1,&NuiFakeDeviceHP2};


struct_v35 NuiFakeDevice = struct_v35();
DWORD NuiFakeDeviceEZ[4096] = {0};
struct_dword300 NuiFakeDeviceExtra = struct_dword300();


struct_v35 NuiFakeDeviceP2 = struct_v35();
DWORD NuiFakeDeviceEZP2[4096] = {0};
struct_dword300 NuiFakeDeviceExtraP2 = struct_dword300();

DWORD Expo[0x4000] = {0};
DWORD Expo1[0x4000] = {0};



HOOK(int,__fastcall,sub_8229A650,0x8229A650,unsigned int a1){

	int v1; // r10
	int v3; // r10
	int v4; // r9
	int v5; // r11
	_DWORD *v6; // r9

	if ( *((_DWORD *)NearKinnectNuiBox::Instance + 0x27) == 3 )
	{
		v1 = *(_DWORD *)(*((_DWORD *)off_83E53128 + 0x17) + 0x10 * a1 + 4);
		if ( v1 < *(_DWORD *)(InputSomeUnkStatic + 0x14)
			&& *(_DWORD *)(InputSomeUnkStatic + 0x24) != *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		{
			return *(_DWORD *)(4 * v1 + *(_DWORD *)(InputSomeUnkStatic + 0x24));
		}
	}
	else
	{
		v3 = *(_DWORD *)(seg_83E52F84 + 8);
		v4 = *(_DWORD *)(seg_83E52F84 + 4);
		if ( ((v3 - v4) & 0xFFFFFFFC) != 0 && (v3 - v4) >> 2 > a1 )
			v5 = *(_DWORD *)(4 * a1 + *(_DWORD *)(seg_83E52F84 + 4));
		else
			v5 = (int)&Expo;
		v6 = *(_DWORD **)(v5 + 0x4C);
		if ( *v6 < *(_DWORD *)(InputSomeUnkStatic + 0x14)
			&& *(_DWORD *)(InputSomeUnkStatic + 0x24) != *(_DWORD *)(InputSomeUnkStatic + 0x28) )
		{
			return *(_DWORD *)(4 * *v6 + *(_DWORD *)(InputSomeUnkStatic + 0x24));
		}
	}
	return 0;
}



int __declspec( naked ) sub_8229FD40H(int a1,int a2,int* a3){
	__asm{
		mflr r12
			std       r25, -0x30(r1)
			std       r26, -0x38(r1)
			std       r27, -0x30(r1)
			std       r28, -0x28(r1)
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0xA0(r1)
			lwz       r30, 4(r3)
			lis r11,0x8229
			ori r11,r11,0xFD50 
			mtctr r11
			lbz       r11, 0x7FB(r3)
			bctr
	}
}

HOOK(int,__fastcall,sub_8229FD40,0x8229FD40,int a1, int a2, int *a3){



	if (*(_DWORD *)(a1 + 0x690) == 0){

		*(DWORD*)(((int)&Expo)+0x4) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0xC) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x8) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x4C) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0xC8) = (DWORD)&Expo;
		*(DWORD*)(((int)&Expo)+0x74) = (DWORD)&Expo;


		*(_DWORD *)(a1 + 0x690) = (DWORD)&Expo;
	}

	if (*(_DWORD *)(a1 + 0x144) == 0){
		*(_DWORD *)(a1 + 0x144) = (DWORD)&Expo1;
		*(DWORD*)(((int)&Expo1)+0x5C) = (DWORD)&Expo1;

	}


	return sub_8229FD40H(a1,a2,a3);

}

HOOK(int,__fastcall,sub_823B75D8,0x823B75D8,int a1,int a2){

	return (int)&Expo;

}

int __declspec( naked ) sub_824F1F50H(int a1){
	__asm{
		    mflr r12
			stw       r12, -0x8(r1)
			std       r31, -0x10(r1)
			stwu      r1, -0x60(r1)
			lis r11,0x824F
			ori r11,r11,0x1F60
			mtctr r11
			bctr
	}
}



HOOK(int,__fastcall,sub_824F1F50,0x824F1F50,int a1){

	if (a1 <= 0 || a1 <= 0x40000000) return 0;

	return sub_824F1F50H(a1);


		
}


void Install()
	{
		




		
		//INSTALL_HOOK(sub_823B75D8);
		INSTALL_HOOK(sub_824F1F50);
		//INSTALL_HOOK(sub_8229FD40);
		//INSTALL_HOOK(sub_8229FD40);
		//INSTALL_HOOK(sub_8229A650);

	
		onceX = false;

		//Others Fixes (fro input)
	//	WRITE_DWORD(0x82222B80,0x4E800020); 


		WRITE_DWORD(0X82222D28,0x60000000);
		WRITE_DWORD(0X82222CC8,0x60000000);
		WRITE_DWORD(0x82222CB8,0x60000000);
		WRITE_DWORD(0x82222D24,0x60000000);

		WRITE_DWORD(0x8222302C,0x60000000);
		WRITE_DWORD(0x82223084,0x60000000);
		WRITE_DWORD(0x82456B14,0x4800004C); //SURSOR +
		

		INSTALL_HOOK(SelfViewUpdate);










	}

}