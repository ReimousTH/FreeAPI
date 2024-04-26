#include "NetPlayFiX.h"


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

	


	


	HOOK(int,__fastcall,sub_8248B560,0x8248B560,XNLive* XNLive){

	//	ShowXenonMessage(L"MSG",PendingCount,0);

		_DWORD** PtrXNQOS = (_DWORD **)XNLive->XNQOS;
		int PendingCount = (int)PtrXNQOS[1];

		if ( !PendingCount || (unsigned int)(BranchTo(0x824D1B98,DWORD) - XNLive->dword38) > 20000 )// pending == 0
		{
			if ( XNLive->dword44->count ){
				BranchTo(0x8248B948,int,XNLive->dword58,&std::string("255.255.255.255:36000"),0);
			}
		}


	


	

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
	BranchTo(0x8248B948,int,a1 + 0x50,&std::string("id: ae0059a6d51fbee7,flags: 1071,hostAddress: 26.175.28.206,publicSlotsCount: 7,privateSlotsCount: 1,openPrivateSlotsCount: 1,filledPublicSlotsCount: 1,filledPrivateSlotsCount: 0,port: 36000"),1);
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


	HOOK(int,__fastcall,sub_8248B948,0x8248B948,int a1,std::string* a2){


		return sub_8248B948H(a1,&std::string("26.81.243.181"));

	}

	void Install()
	{
		INSTALL_HOOK(sub_8248B948);
	//	INSTALL_HOOK(sub_82486A08);

		//INSTALL_HOOK(sub_8248B560);

		//NETPLAY
		//INSTALL_HOOK(sub_8248B560); //
	}

}