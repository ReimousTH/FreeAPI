#include "KernelReplacement.h"

namespace KernelR{
	
	
	HOOK(int*,__fastcall,sub_82ACB43C,0x82ACB43C,int a1){

		*(int*)(a1+0xC)=3;
		return (int*)a1;
	}

	//Convert NUI to Normal One
	HOOK(DWORD,__stdcall,sub_824D0CE8,0x824D0CE8,__in DWORD dwTrackingID,__in DWORD dwUserIndex,__in_z LPCWSTR wszTitle,__in_z LPCWSTR wszText,__in DWORD cButtons,__in_opt LPCWSTR* pwszButtons,__in DWORD dwFocusButton,__in DWORD dwFlags,__out PMESSAGEBOX_RESULT pResult,__inout_opt PXOVERLAPPED pOverlapped){

		return XShowMessageBoxUI(dwUserIndex,wszTitle,wszText,cButtons,pwszButtons,dwFocusButton,dwFlags,pResult,pOverlapped);

	}

	HOOK(int,__fastcall,XamShowNuiSigninUIE,0x82ACB39C,_DWORD a1,_DWORD a2){

		return XShowSigninUI(a1,a2);
	}


	HOOK(int,__fastcall,EtxProducerRegistersFake,0x82ACC28C,int Array1, int Array2, int Flag1, int Flag2, int Flag3, _ETX_PRODUCER* ETX){

		//*a6 = 0x1;

		return 0;
	}




	HOOK(DWORD,__stdcall,XamShowNuiDeviceSelectorUI,0x82ACB3EC,__in    DWORD dwTrackingID,__in    DWORD dwUserIndex,__in    DWORD dwContentType,__in    DWORD dwContentFlags,__in    ULARGE_INTEGER uliBytesRequested,__out   PXCONTENTDEVICEID pDeviceID,__inout PXOVERLAPPED pOverlapped){

		return XShowDeviceSelectorUI(dwUserIndex,dwContentType,dwContentFlags,uliBytesRequested,pDeviceID,pOverlapped);
	}





	// Define the prototype of XamContentOpenFile
	extern "C" DWORD XamContentOpenFile(int a1,const char* name,const char* path,unsigned int Flags1,unsigned int Flags2,unsigned int Flags3,unsigned int Flags4);



	HOOK(int,__fastcall,XamContentOpenFileS,0x82ACBEEC,int a1,const char* name,const char* path,unsigned int Flags1,unsigned int Flags2,unsigned int Flags3,unsigned int Flags4){
		
		//XContentCreate(0xFF,"nuiidentity",
		if (strcmp(name,"stexemplar") == 0){
			return 0;
		}
		else if (strcmp(name,"nuiidentity") == 0){
			return 0;
		}
	
		return XamContentOpenFile(a1,name,path,Flags1,Flags2,Flags3,Flags4);
	}

	void Install()
	{
		if (!HookV2::IsNotEmulatedHardWare){
					INSTALL_HOOK(XamContentOpenFileS);
		}

		//INSTALL_HOOK(sub_82211798);
		WRITE_DWORD(0x8222CA38,0x4E800020); //ShowKinectRequieredMessage
		INSTALL_HOOK(sub_82ACB43C); //Fake XamNuiGetDeviceStatus
	
		//INSTALL_HOOK(EtxProducerRegistersFake);
	
		INSTALL_HOOK(XamShowNuiSigninUIE);
		INSTALL_HOOK(XamShowNuiDeviceSelectorUI);
		INSTALL_HOOK(sub_824D0CE8);
	}

}