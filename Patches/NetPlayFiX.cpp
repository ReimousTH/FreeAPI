#include "NetPlayFiX.h"

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <iomanip>
namespace NetplayRFIX{


	int __declspec( naked ) sub_8248B560H(_DWORD* a1){
		__asm{
			mflr      r12

				std       r18, -0x78(r1)
				std       r19, -0x70(r1)
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


				addi      r31, r1, -0x180
				stwu      r1, -0x180(r1)
				lis r11,0x8248
				ori r11,r11,0xB570 
				mtctr r11
				bctr r11
		}
	}

	


	LPCWSTR MapsIndexed[] = {
		L"Dolphin Resort",
		L"Rocky Bridge",
		L"Frozen Forest",
		L"Metropolis Speedway",
		L"Magma Rift",
		L"Forgotten Tomb",
		L"Final Factory",
		L"Metal City"

	};
	
	std::string convert_wstring_to_string(const std::wstring& wstr) {
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.to_bytes(wstr);
	}

	HOOK(int,__fastcall,sub_8248B560,0x8248B560,XNLive* XNLive){

	//	ShowXenonMessage(L"MSG",PendingCount,0);

		
		_DWORD** PtrXNQOS = (_DWORD **)XNLive->XNQOS;
		int PendingCount = (int)PtrXNQOS[1];
		

		if ( !PendingCount || (unsigned int)(BranchTo(0x824D1B98,DWORD) - XNLive->dword38) > 20000 )// pending == 0
		{
			if ( XNLive->XSessionSearchResuts->dwSearchResults ){

				std::wstring sessionID = L"Sessions : {\r\n";
				LPCWSTR* g_pwstrButtonsX = new LPCWSTR[XNLive->XSessionSearchResuts->dwSearchResults + 1];
				g_pwstrButtonsX[0] = L"Cancel";


				for (int i = 0; i < XNLive->XSessionSearchResuts->dwSearchResults; i++) {
					// Construct the string "Session[i]" with the value of i
					std::wstringstream ss;
					ss << L"Session[" << i << L"] : ";
					std::wstring sessionStr = ss.str();

					sessionID += sessionStr;

					
					XSESSION_SEARCHRESULT* SS = &XNLive->XSessionSearchResuts->pResults[i];
					/*
			
					SS->cProperties = 0x10;
				
					
					SS->pProperties = new _XUSER_PROPERTY[0x10];
					SS->pProperties[0].dwPropertyId = 0x10000006u;
					SS->pProperties[0].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[0].value.nData = 0;



					// 1,1,1 IS PERFECT DEFAULT 
					//BUTTONS
					SS->pProperties[1].dwPropertyId = 0x10000012;
					SS->pProperties[1].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[1].value.nData = 1;


					//BUTTONS
					SS->pProperties[2].dwPropertyId = 0x10000013;
					SS->pProperties[2].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[2].value.nData = 1;


					//USES IN BUTTONS  (IS ONLINE TAG???, no freeze anymore) //MODE PROPERTY
					SS->pProperties[3].dwPropertyId = 0x1000000F;
					SS->pProperties[3].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[3].value.nData = 1;







					SS->pProperties[4].dwPropertyId = 0x10000010;
					SS->pProperties[4].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[4].value.nData = 0;

					SS->pProperties[5].dwPropertyId = 0x10000011;
					SS->pProperties[5].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[5].value.nData = 0;

					SS->pProperties[6].dwPropertyId = 0x1000000D;
					SS->pProperties[6].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[6].value.nData = 0;

					SS->pProperties[7].dwPropertyId = 0x1000000E;
					SS->pProperties[7].value.type = XUSER_DATA_TYPE_INT32;
					SS->pProperties[7].value.nData = 0;

					SS->pProperties[8].dwPropertyId = 0x40008109;
					SS->pProperties[8].value.type = XUSER_DATA_TYPE_UNICODE;
					SS->pProperties[8].value.string.pwszData = L"XeniaUser16532";

					SS->pProperties[9].dwPropertyId = 0x10008109;
					SS->pProperties[9].value.type = XUSER_DATA_TYPE_UNICODE;
					SS->pProperties[9].value.string.pwszData = L"Missing:HostName";


				*/
				
			
					
	
					std::wstringstream wss;
					wss << std::hex << std::setfill(L'0');
					for (size_t i = 0; i < 8; i++) {
						wss << std::setw(2) << static_cast<unsigned>(SS->info.sessionID.ab[i]);
					}
					sessionID += wss.str();

					sessionID += L"\t";
				//	t->hostInfo.hostAddress.ina.S_un.S_un_b.s_b1 = IP_VEC[0];
				

				//	t->hostInfo.hostAddress.inaOnline.S_un.S_un_b.s_b1 = IP_VEC[0];
	

					std::wstringstream wss2;
		
					for (size_t i = 0; i < 4; i++) {
						wss2  << static_cast<unsigned>((&SS->info.hostAddress.ina.S_un.S_un_b.s_b1)[i]);
						wss2 << L".";
					}
					sessionID += wss2.str();

					std::stringstream wss3;

					for (size_t i = 0; i < 4; i++) {
						
						wss3 <<":" << SS->info.hostAddress.wPortOnline;
					}
		

					//Works perfect, but still stuck in freeze , why?
					//does something missing
					std::vector<HStruct>* vec =  (std::vector<HStruct>*)XNLive->dword58;
					HStruct sessionDATA;



					sessionDATA.field_0 = std::string(convert_wstring_to_string(wss2.str()));
					sessionDATA.field_0 += wss3.str();
					sessionDATA.SearchResult = SS;
					sessionDATA.field_20 = (int)SS;
					//vec->push_back(sessionDATA);

					std::wstring map_name = L"Dolphin Resort";



					sessionID += L"\r\n";
					g_pwstrButtonsX[i+1] = (new std::wstring(sessionStr))->c_str();

				}

	
		
		
				MESSAGEBOX_RESULT result;
				result.dwButtonPressed = -1;
				XOVERLAPPED m_Overlapped; 
				XShowMessageBoxUI(ATG::SignIn::GetSignedInUser(),L"Lobby",sessionID.c_str(),XNLive->XSessionSearchResuts->dwSearchResults + 1,g_pwstrButtonsX,XNLive->XSessionSearchResuts->dwSearchResults,XMB_ALERTICON,&result,&m_Overlapped); 
		
				
				while (!( XHasOverlappedIoCompleted( &m_Overlapped ) )){					
				}
				if (result.dwButtonPressed == 0) return sub_8248B560H((_DWORD*)XNLive);

		
			
				XSESSION_SEARCHRESULT* Lobby = &XNLive->XSessionSearchResuts->pResults[result.dwButtonPressed-1];
				memset((void*)(XNLiveSomeStatic + 0x67),0,0x54);
				XINVITE_INFO* t = (XINVITE_INFO*)(XNLiveSomeStatic + 0x67);
				t->dwTitleID = 0x5345084D;
				t->hostInfo = Lobby->info;

				*(_BYTE *)(XNLiveSomeStatic + 0x61) = 1;
				*(_BYTE *)(XNLiveSomeStatic + 0x65) = 1;
				*(_BYTE *)(XNLiveSomeStatic + 0x66) = 0;
				*(_BYTE *)(XNLiveSomeStatic + 0xBB) = 0;
				
	

			}
		}

		/*
		
		if ( !PendingCount || (unsigned int)(BranchTo(0x824D1B98,DWORD) - XNLive->dword38) > 20000 )// pending == 0
		{
			if ( XNLive->XSessionSearchResuts->dwSearchResults ){

				std::wstring sessionID = L"Sessions : {\r\n";
				LPCWSTR* g_pwstrButtonsX = new LPCWSTR[XNLive->XSessionSearchResuts->dwSearchResults + 1];
				g_pwstrButtonsX[0] = L"Cancel";


				for (int i = 0; i < XNLive->XSessionSearchResuts->dwSearchResults; i++) {
	
					XSESSION_SEARCHRESULT* SS = &XNLive->XSessionSearchResuts->pResults[i];
				
					XUSER_PROPERTY* old = SS->pProperties;

		
					

				//	SS->dwFilledPrivateSlots = 1;
					SS->pProperties = new XUSER_PROPERTY[SS->cProperties + 1];
					memcpy(SS->pProperties,old,sizeof(XUSER_PROPERTY)*SS->cProperties);
					SS->cProperties +=1;



				    XUSER_PROPERTY* prop  =   	&SS->pProperties[SS->cProperties-1];
					//MISSING DATA
					prop->dwPropertyId = X_PROPERTY_GAMER_HOSTNAME;
					prop->value.string.pwszData = L"Ryzx123";
					prop->value.type = XUSER_DATA_TYPE_UNICODE;


				}


			}
		}
*/


	


	

		return sub_8248B560H((_DWORD*)XNLive);
	}


	int __declspec( naked ) sub_82486A0H8(int a1){
		__asm{
			mflr      r12
			 stw       r12, -8(r1)
			 std       r31, -0x10(r1)
			 stwu      r1, -0x60(r1)

				lis r11,0x8248
				ori r11,r11,0x6A18 
				mtctr r11
				bctr r11
		}
	}



	HOOK(int,__fastcall,sub_82486A08,0x82486A08,int a1){


	
		if ( !*(_DWORD *)(XNLiveSomeStatic + 0x28) )
		{
	BranchTo(0x8248B948,int,a1 + 0x50,&std::string(""),1);
		}
	
		return sub_82486A0H8(a1);

	}


	int __declspec( naked ) sub_8248B948H(int a1,std::string* a2){
		__asm{
				mflr      r12
				stw       r12, -8(r1)
				std		  r29,	-0x20(r1)
				std		  r30,	-0x18(r1)	
				std       r31, -0x10(r1)

				addi      r31, r1, -0x80
				stwu      r1, -0x80(r1)

				lis r11,0x8248
				ori r11,r11,0xB958 
				mtctr r11
				bctr r11
		}
	}		


	DWORD NUM = 0;
	HOOK(int,__fastcall,sub_8248B948,0x8248B948,int a1,std::string* a2){

	DWORD val;
	__asm{
		mr val,r5

	}
	DebugLogPushValueHEX(val);
		return sub_8248B948H(a1,&std::string("Ryzx123"));

	}

	HOOK(int,__fastcall,sub_8247BBF0,0x8247BBF0,struct_UIRingController* a1){

		ItemNRElement* v28_mem = (ItemNRElement *)(*(int (__fastcall **)(int *, int, int))(*MainHeap + 16))(MainHeap, 576, 16);
		ItemNRElement* v29 = (ItemNRElement *)BranchTo(0x824640F8,int,v28_mem, a1, 0, 0, 2);
		DWORD v29_boost_container[2] = {0};
		v29_boost_container[0] = (int)v29;

		BranchTo(0x8244E838,int,&v29_boost_container[1],v29);
		BranchTo(0x824807F0,int,&a1->dword12C, &v29_boost_container);
		boostsomex((int*)&v29_boost_container[1]);



		return 0;
	}

	void Install()
	{
	//	INSTALL_HOOK(sub_8247BBF0);

	//	INSTALL_HOOK(sub_8248B948);
	//	INSTALL_HOOK(sub_82486A08);

	INSTALL_HOOK(sub_8248B560);

		//NETPLAY
		//INSTALL_HOOK(sub_8248B560); //
	}

}