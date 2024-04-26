#include "InputData_MenuActions.h"


namespace InputData{



	XMVECTOR CursorCenterPos  = {854.0,453.0,-1,-1};
	XMVECTOR CursorP1RingDefaultPos  = {510,367,-1,-1};
	XMVECTOR CursorP2RingDefaultPos  = {755,338,-1,-1};
	XMVECTOR* CursorPositions[]  = {&CursorP1RingDefaultPos,&CursorP2RingDefaultPos};

	bool FixedCheckIsSelectedButton(ItemNRElement* PItemNRElement){

		return IsUIRingCanBeChanged((int)PItemNRElement->ParentOrMainMenuNRInstance)  && IsThatSelector_((DWORD*)PItemNRElement->ParentUIRingController,PItemNRElement->ItemIndexPos) &&
			(PItemNRElement->ItemState & 0x10) == 0;

	}

	bool FixedCheckIsSelectedButtonPressable(ItemNRElement* PItemNRElement){

		return FixedCheckIsSelectedButton(PItemNRElement) && PItemNRElement->ItemFlag != 2;
	}

	void ProcessOKBackButtonsAlternative(int index){
		struct_UIRingController* RingElement = (struct_UIRingController*)BranchTo(0x82457348,int,MainMenuNR::Instance,index); //Get Current Ring Elemeny By Index
		struct_UIRingController* RingElementO = (struct_UIRingController*)BranchTo(0x82457348,int,MainMenuNR::Instance,index ^ 1); //Get Current Ring Elemeny By Index
		
		int last_index = -1;
		if (!RingElement) return;
		if (RingElementO) last_index = index ^ 1;

		//0x200

		bool IsShopButton =false;

		int menu = (int)MainMenuNR::Instance;
		for ( int j = (int)MainMenuNR::Instance->field_24.pint2C; j != (int)MainMenuNR::Instance->field_24.pint30; j += 8 ){
			auto RingElement = *(struct_UIRingController**)j;
			for ( int y = RingElement->dword12C; y != RingElement->dword130; y += 8 ){
				auto PItemNRElement = *(ItemNRElement**)y;
				if (NuiFakeDevicePO[index]->MENU_BUTTON_B){
					if (PItemNRElement->ButtonIconID == 0x1F){
						//ShowXenonMessage(L"MSG","SG");


						NuiFakeDevicePO[index]->MENU_BUTTON_B = false;
						if (BranchTo(0x8245B130,int,PItemNRElement->ParentOrMainMenuNRInstance)){
							BranchTo(0x824603B8,int,PItemNRElement->ParentOrMainMenuNRInstance,(PItemNRElement->ParentUIRingController->Flag0x140 >> 4) & 1);
						}

						break;

					}

					//rule select
				
				}
				//IfButtonIsVisible
				if (  (PItemNRElement->SubStruct.field_4 & 0x01000000) != 0){
					IsShopButton = PItemNRElement->ButtonIconID == 0x20;
				}


				if ( (PItemNRElement->ButtonIconID >=0x21 )  && (PItemNRElement->ButtonIconID <=0x23 ) && ((PItemNRElement->SubStruct.field_4 & 0x01000000) != 0) && NuiFakeDevicePO[index]->MENU_BUTTON_Y){

					DWORD ID = 0;

					switch (PItemNRElement->ButtonIconID){
						case  0x22:
							ID = 0x10;
							break;;
						case 0x21:
							ID = 0xF;
							break;;
						case 0x23:
							ID = 0x31;
							break;
					}
		
			
						BranchTo(0x82454848,int,(_DWORD *)MainMenuNR::Instance, 0, 3,ID); 
						Riders::Sound::PlaySound((int)Riders::Sound::Instance, 0x12,0x8);
				
			
				
					break;
				}

			}
		}


	
		for ( int j = RingElement->dword12C; j != RingElement->dword130; j += 8 ){
			auto PItemNRElement = *(ItemNRElement**)j;


		
			BranchTo(0x82464BD0,int,PItemNRElement); //display once more


			if ((NuiFakeDevicePO[index]->Menu_DPAD_UP_HOLD || NuiFakeDevicePO[index]->Menu_DPAD_DOWN_HOLD  )  && IsUIRingCanBeChanged((int)PItemNRElement->ParentOrMainMenuNRInstance)  && IsThatSelector_((DWORD*)PItemNRElement->ParentUIRingController,PItemNRElement->ItemIndexPos) &&
				(PItemNRElement->ItemState & 0x10) == 0 && PItemNRElement->ItemFlag == 2){


					if (last_index == -1)
						PItemNRElement->SursorVectorPTR = &CursorCenterPos;
					else{
						PItemNRElement->SursorVectorPTR = CursorPositions[index];
					}
					PItemNRElement->UnkSelectedIndexFlag = PItemNRElement->ItemIndexPos;

					PItemNRElement->ItemState |=  1;

					if (PItemNRElement->TargetTimeDelta <= -10){

					}
					else{
						PItemNRElement->TargetTimeDelta +=  MBKinnectInput->PclsXbox360System->SpeedSome;
					}


					if (PItemNRElement->TargetTimeDelta > 0.1 && (RingElement->Flag0x140 & 0x80) != 0){

						PItemNRElement->TargetTimeDelta = -10;
						Riders::Sound::PlaySound((int)Riders::Sound::Instance, 0x12,0xF);

					}


				break;
			}

			if (NuiFakeDevicePO[index]->Menu_DPAD_UP_RELEASE){

				if ( IsUIRingCanBeChanged((int)PItemNRElement->ParentOrMainMenuNRInstance)  && IsThatSelector_((DWORD*)PItemNRElement->ParentUIRingController,PItemNRElement->ItemIndexPos) &&
					(PItemNRElement->ItemState & 0x10) == 0 && PItemNRElement->ItemFlag == 2){
						BranchTo(0X824698D0,int,PItemNRElement,1,0);
						NuiFakeDevicePO[index]->Menu_DPAD_UP_RELEASE = false;
						break;

				}
			}

			if (NuiFakeDevicePO[index]->Menu_DPAD_DOWN_RELEASE){

				if (IsUIRingCanBeChanged((int)PItemNRElement->ParentOrMainMenuNRInstance)  && IsThatSelector_((DWORD*)PItemNRElement->ParentUIRingController,PItemNRElement->ItemIndexPos) &&
					(PItemNRElement->ItemState & 0x10) == 0 && PItemNRElement->ItemFlag == 2){
						BranchTo(0X824698D0,int,PItemNRElement,0,0);
						NuiFakeDevicePO[index]->Menu_DPAD_DOWN_RELEASE = false;
						break;

				}
			}


			if (NuiFakeDevicePO[index]->MENU_BUTTON_A_HOLD){

				//PItemNRElement->UnkSelectedIndexFlag = 1;
			
		
				//&& PItemNRElement->ItemFlag != 6 && !PItemNRElement->ParentUIRingController->gap17C[9]
				if (FixedCheckIsSelectedButtonPressable(PItemNRElement))
				{

					if (last_index == -1)
						PItemNRElement->SursorVectorPTR = &CursorCenterPos;
					else{
						PItemNRElement->SursorVectorPTR = CursorPositions[index];
					}
					PItemNRElement->UnkSelectedIndexFlag = PItemNRElement->ItemIndexPos;
					
					PItemNRElement->ItemState |=  1;

					if (PItemNRElement->TargetTimeDelta <= -10){

					}
					else{
						PItemNRElement->TargetTimeDelta +=  MBKinnectInput->PclsXbox360System->SpeedSome;
					}

					
					if (PItemNRElement->TargetTimeDelta > 0.1 && (RingElement->Flag0x140 & 0x80) != 0){
						
						PItemNRElement->TargetTimeDelta = -10;
						Riders::Sound::PlaySound((int)Riders::Sound::Instance, 0x12,0xF);

					}
		


					break;
				}

			}

			if (NuiFakeDevicePO[index]->MENU_BUTTON_A_RELEASE){

				//PItemNRElement->UnkSelectedIndexFlag = 1;

				//&& PItemNRElement->ItemFlag != 6 && !PItemNRElement->ParentUIRingController->gap17C[9]
				if (FixedCheckIsSelectedButtonPressable(PItemNRElement))
				{
					//buy 
					if (IsShopButton ){
						BranchTo(0x8245FD38,int,PItemNRElement->ParentOrMainMenuNRInstance,PItemNRElement);
						BranchTo(0x8245FD38,int,PItemNRElement->ParentOrMainMenuNRInstance,SomeByteIGuess);
					}
					else{
						*(_DWORD *)(4 * (((PItemNRElement->ParentUIRingController->Flag0x140 >> 4) & 1) + 0x20) + PItemNRElement->ParentOrMainMenuNRInstance) = (DWORD)PItemNRElement;
						(struct_UIRingController *)MAINMENUBIGSUB(
							PItemNRElement->ParentOrMainMenuNRInstance,
							PItemNRElement,
							(PItemNRElement->ParentUIRingController->Flag0x140 >> 4) & 1);
					}
					break;
				}



			}





		}
	}

	int __fastcall sub_824578F0(struct_a11* a1, int a2, int a3){



		ItemNRElement* v33;
		//	if ( !a1->byte7D6 )

			auto v31 = (int)a1 -0x24;
			int i = 0;
			sub_82454320((int)&a1[0xFFFFFFFF].gap721[0x93]);


			int c = 0;
			//1 = Main Main Menu Ring
			//2  Races and next ring,chr select and etc
			//3 Second Player Ring

			std::map<int, std::vector<DWORD>> m;
			m[0x38] = std::vector<DWORD>();
			m[0x39] = std::vector<DWORD>();
			m[0x3A] = std::vector<DWORD>();
			//Seach Mode
			for ( i = *(_DWORD *)(v31 + 0x50); i != *(_DWORD *)(v31 + 0x54); i += 8 ){
				auto RingElement = *(struct_UIRingController**)i;
				if (m.find(RingElement->Tag1) != m.end()){
					m[RingElement->Tag1].push_back((DWORD)RingElement);
				}
			}




			std::vector<boost::shared_ptr<struct_UIRingController>>* _Rings = (std::vector<boost::shared_ptr<struct_UIRingController>>*)(v31 + 0x50);

			ProcessOKBackButtonsAlternative(0);
			ProcessOKBackButtonsAlternative(1);
			


			/*
			for (auto it = _Rings->begin();it != _Rings->end();it++){	

				struct_UIRingController* RingElement = (struct_UIRingController*)it->get();

				std::vector<boost::shared_ptr<ItemNRElement>>* _Items = (std::vector<boost::shared_ptr<ItemNRElement>>*)(&RingElement->dword12C);

				for (auto jt = _Items->begin();jt != _Items->end();jt++){

					ItemNRElement* PItemNRElement = (ItemNRElement*)jt->get();
					if ((PItemNRElement->ItemState & 0xF) == 0){

						if (gc->wPressedButtons  & XINPUT_GAMEPAD_DPAD_UP)
						{
							BranchTo(0x824698D0,int,PItemNRElement,0,0);

						}
						else if (gc->wPressedButtons  & XINPUT_GAMEPAD_DPAD_DOWN)
						{

							BranchTo(0x824698D0,int,PItemNRElement,1,0);
						}
						else if (gc->wPressedButtons  & XINPUT_GAMEPAD_X)
						{



						}


					}

				}





			}
			*/


/*
			for ( i = *(_DWORD *)(v31 + 0x50); i != *(_DWORD *)(v31 + 0x54); i += 8 ){

				auto RingElement = *(struct_UIRingController**)i;
				if ((m.find(RingElement->Tag1) != m.end()))
				{
					auto r =  m[RingElement->Tag1];
					auto it = find(r.begin(),r.end(),(DWORD)RingElement);
					int index = it - r.begin();
					if (m[RingElement->Tag1].size() >= 2 && (index == 1 || index == 3) ){

						for ( int j = RingElement->dword12C; j != RingElement->dword130; j += 8 ){
							auto NR = *(ItemNRElement**)j;
							DWORD result = (DWORD)NR->ParentUIRingController;
							if (gc2P->wPressedButtons & XINPUT_GAMEPAD_A){
								if ((NR->ItemState & 0xF) == 0){

									*(_DWORD *)(4 * (((*(_DWORD *)(NR->ParentUIRingController + 0x140) >> 4) & 1) + 0x20) + NR->ParentOrMainMenuNRInstance) = (DWORD)NR;
									MAINMENUBIGSUB(
										NR->ParentOrMainMenuNRInstance,
										(struct_a2 *)NR ,
										(*(_DWORD *)(NR->ParentUIRingController + 0x140) >> 4) & 1);

								}
							}
						}
					}
					if (m[RingElement->Tag1].size() >= 2 && (index == 0 || index == 2) ){
						for ( int j = RingElement->dword12C; j != RingElement->dword130; j += 8 ){
							auto NR = *(ItemNRElement**)j;
							DWORD result = (DWORD)NR->ParentUIRingController;

							if (gc->wPressedButtons & XINPUT_GAMEPAD_A){

								if ((NR->ItemState & 0xF) == 0){

									*(_DWORD *)(4 * (((*(_DWORD *)(NR->ParentUIRingController + 0x140) >> 4) & 1) + 0x20) + NR->ParentOrMainMenuNRInstance) = (DWORD)NR;
									MAINMENUBIGSUB(
										NR->ParentOrMainMenuNRInstance,
										(struct_a2 *)NR ,
										(*(_DWORD *)(NR->ParentUIRingController + 0x140) >> 4) & 1);


								}
							}
						}
					}
				}
			}
		}
	*/



		return BranchTo(0x824578F0,int,a1,a2,a3);
	}



	void Install_MenuActions()
	{
			WRITE_DWORD(0x821A8D34,sub_824578F0);
	}

}