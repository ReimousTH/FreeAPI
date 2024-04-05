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

	HOOK(int,__fastcall,sub_8248B560,0x8248B560,_DWORD* a1){

		XNQOS* ptr =  new XNQOS();
		//	*(XNQOS **)(a1 + 0x5C) = ptr;
		ptr->cxnqos = 1;
		ptr->cxnqosPending = 1;

		return sub_8248B560H(a1);
	}


	void Install()
	{
		//NETPLAY
		//INSTALL_HOOK(sub_8248B560); //
	}

}