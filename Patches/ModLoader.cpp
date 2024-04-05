#include "ModLoader.h"


namespace ModLoader{

	std::vector<HANDLE> _Files = std::vector<HANDLE>();
	


	int __declspec( naked ) sub_8249D028H(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){
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
				stwu      r1, -0x200(r1)
				mr        r30, r8
				lis r11,0x8249
				ori r11,r11,0xD038
				mtctr r11
				bctr r11
		}
	}

	int __declspec( naked ) sub_8249D028HX(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){
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
				stwu      r1, -0x200(r1)
				mr        r30, r8
				lis r11,0x8249
				ori r11,r11,0xD038
				mtctr r11
				bctr
		}
	}








	int __declspec( naked ) sub_8249D028_Remade(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){

		__asm{
			mflr      r12


				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw r12,-8(r1)

				stwu      r1, -0x200(r1)
				mr        r30, r8
				mr        r25, r3
				mr        r29, r4
				mr        r28, r5
				mr        r31, r6
				mr        r27, r7
				mr        r8, r9
				mr        r26, r10
				cmplwi    cr6, r9, 0
				bne       cr6, loc_8249D064
				//	bl        sub_82211440()

				lis r11,0x8221
				ori r11,r11,0x1440
				mtctr r11
				bctrl

				lwz       r8, 4(r3)
loc_8249D064:                           
			cmplwi    cr6, r30, 0
				beq       cr6, loc_8249D074
				li        r11, 1
				stw       r11, 0(r30)
loc_8249D074:                           
			li        r10, 1
				stw       r30, 0x54(r1)
				mr        r9, r26
				mr        r7, r31
				mr        r6, r28
				mr        r5, r29
				mr        r4, r27
				addi      r3, r1, 0x70
				//bl        sub_8249EC20
				//qASMBranch(r11,0x8249,0xEC20)
				lis r11,0x8249
				ori r11,r11,0xEC20
				mtctr r11
				bctrl


				rlwinm    r11, r31, 0,26,26
				li        r10, 0
				cmplwi    cr6, r11, 0
				std       r10, 0x60(r1)
				beq       cr6, loc_8249D0F0
				lwz       r31, 0x8C(r25)
				mr        r3, r31
				lwz       r11, 0(r31)
				lwz       r10, 8(r11)
				mtctr     r10
				bctrl
				addi      r4, r1, 0x70
				addi      r3, r25, 0x20
				//	bl        loc_8249DD08
				//qASMBranch(r11,0x8249,0xDD08)

				lis r11,0x8249
				ori r11,r11,0xDD08
				mtctr r11
				bctrl

				lwz       r9, 0(r31)
				mr        r3, r31
				lwz       r8, 0xC(r9)
				mtctr     r8
				bctrl
				ld        r3, 0x60(r1)
				addi      r1, r1, 0x200
				ld       r25, -0x40(r1)
				ld       r26, -0x38(r1)
				ld       r27, -0x30(r1)
				ld       r28, -0x28(r1)
				ld       r29, -0x20(r1)
				ld       r30, -0x18(r1)
				ld       r31, -0x10(r1)
				lwz       r12, -8(r1)
				mtlr r12
				blr
loc_8249D0F0:                          
			lwz       r11, 0x1A0(r1)
				addi      r4, r1, 0x70
				mr        r3, r25
				cmplwi    cr6, r11, 0
				bne       cr6, loc_8249D11C
				addi      r11, r1, 0x60
				stw       r11, 0x1A0(r1)
				//bl        loc_8249CEB0
				//qASMBranch(r11,0x8249,0xCEB0)


				lis r11,0x8249
				ori r11,r11,0xCEB0
				mtctr r11
				bctrl

				ld        r3, 0x60(r1)
				addi      r1, r1, 0x200



				ld       r25, -0x40(r1)
				ld       r26, -0x38(r1)
				ld       r27, -0x30(r1)
				ld       r28, -0x28(r1)
				ld       r29, -0x20(r1)
				ld       r30, -0x18(r1)
				ld       r31, -0x10(r1)
				lwz       r12, -8(r1)
				mtlr r12
				blr

loc_8249D11C:                           
			//bl        loc_8249CEB0
			//	qASMBranch(r11,0x8249,0xCEB0)

			lis r11,0x8249
				ori r11,r11,0xCEB0
				mtctr r11
				bctrl


				lwz       r11, 0x1A0(r1)
				ld        r3, 0(r11)
				addi      r1, r1, 0x200
				ld       r25, -0x40(r1)
				ld       r26, -0x38(r1)
				ld       r27, -0x30(r1)
				ld       r28, -0x28(r1)
				ld       r29, -0x20(r1)
				ld       r30, -0x18(r1)
				ld       r31, -0x10(r1)
				lwz       r12, -8(r1)
				mtlr r12
				blr

		}

	}

	int SaveParams[] = {0,0,0,0,0,0,0,0};
	HOOK(int,__fastcall,sub_8249D028,0x8249D028,int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8){



		DWORD result;


		std::string stru = std::string((char*)a2);
		stru.insert(6,"mods\\");



		const char* full_path = stru.c_str();
		if (stru.find(std::string("_ST")) !=std::string::npos){
ShowXenonMessage(L"MSG",full_path);
		}

		

		// Open the file for reading
		HANDLE hFile = CreateFile( full_path, GENERIC_READ, 0, NULL,		OPEN_EXISTING, 0, NULL );
		if (hFile != INVALID_HANDLE_VALUE){
			
			result = sub_8249D028_Remade(a1,(int)full_path,a3,a4,a5,a6,a7,a8);
		}
		else{

			result = sub_8249D028_Remade(a1,a2,a3,a4,a5,a6,a7,a8);

		}


		








		return result;

	}

	typedef struct _UNICODE_STRING {
		USHORT Length;
		USHORT MaximumLength;
		PWSTR  Buffer;
	} UNICODE_STRING, *PUNICODE_STRING;

	typedef struct _OBJECT_ATTRIBUTES {
		ULONG Length;
		HANDLE RootDirectory;
		PUNICODE_STRING ObjectName;
		ULONG Attributes;
		PVOID SecurityDescriptor;
		PVOID SecurityQualityOfService;
	} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;




	int NTCreateFileReplace(
		DWORD Handle,
		DWORD dwDesiredAccess,
		PWSTR attributes


		){

			CreateFile("ASF",0x200,0,0,0,0,0);
		
				// Now you can use lpFileName in your function logic
		ShowXenonMessage(L"MSG", attributes);
			

		return BranchTo(0x82ACB58C,int,Handle,dwDesiredAccess,attributes);
	}

	HANDLE __declspec( naked ) sub_824D0F28H(__in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile){
		__asm{
			    mflr r12
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0xC0(r1)
				mr        r29, r3
				lis r11,0x824D
				ori r11,r11,0x0F38
				mtctr r11
				bctr
		}
	}


	HANDLE __declspec( naked ) ReadFile_NEWH(__in        HANDLE hFile,
		__out_bcount_part_opt(nNumberOfBytesToRead, *lpNumberOfBytesRead) LPVOID lpBuffer,
		__in        DWORD nNumberOfBytesToRead,
		__out_opt   LPDWORD lpNumberOfBytesRead,
		__inout_opt LPOVERLAPPED lpOverlapped){
			__asm{
				    mflr r12
					std       r28, -0x28(r1)
					std       r29, -0x20(r1)
					std       r30, -0x18(r1)
					std       r31, -0x10(r1)
					stw       r12, -0x8(r1)
					stwu      r1, -0x90(r1)
					mr        r30, r3
					lis r11,0x824D
					ori r11,r11,0x12A0
					mtctr r11
					bctr
			}
	}



	HOOK(HANDLE,__fastcall,ReadFile_NEW,0x824D1290,    __in        HANDLE hFile,
		__out_bcount_part_opt(nNumberOfBytesToRead, *lpNumberOfBytesRead) LPVOID lpBuffer,
		__in        DWORD nNumberOfBytesToRead,
		__out_opt   LPDWORD lpNumberOfBytesRead,
		__inout_opt LPOVERLAPPED lpOverlapped){

			
		





		
			HANDLE result =  ReadFile_NEWH(hFile,lpBuffer,nNumberOfBytesToRead,lpNumberOfBytesRead,lpOverlapped);

			for (std::vector<HANDLE>::iterator it = _Files.begin(); it != _Files.end(); it++) {
				if (*it == hFile) {
					// Erase the element from the vector
					it = _Files.erase(it);

					//while (true){
					//	ATG::Input::GetMergedInput(0);
					//	if (InputData::gc->wLastButtons & XINPUT_GAMEPAD_X) break;
				//	}
					//ShowXenonMessage(L"MSG","replacefile");
				

					// Adjust the iterator to point to the correct position after erasing
					if (it == _Files.end()) {

						break; // Exit the loop if the iterator reaches the end
					}
				}
			}

			return result;


	}

	HOOK(HANDLE,__fastcall,CreateFileA_NEW,0x824D0F28,   __in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile){

			std::string _str = std::string(lpFileName);
			_str.insert(6,"mods\\");
			const char* path = _str.c_str();
			LPCSTR _file_name = lpFileName;

			bool push = false;
			
			if ( CreateFile( path, GENERIC_READ, 0, NULL,		OPEN_EXISTING, 0, NULL ) != INVALID_HANDLE_VALUE){
				//
				_file_name = _str.c_str();
				push = true;
		
			}
			
		//	if (InputData::gc->wLastButtons & XINPUT_GAMEPAD_Y) ShowXenonMessage(L"MSG",lpFileName);
		
		    HANDLE handle =  sub_824D0F28H(_file_name,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
			if (push){
				_Files.push_back(handle);
			}



		return handle;
	}

	void Install()
	{
		INSTALL_HOOK(CreateFileA_NEW);
		INSTALL_HOOK(ReadFile_NEW);
		//INSTALL_HOOK(sub_8249D028);
		//WRITE_DWORD(0x82AD036C,NTCreateFileReplace);
	}

}