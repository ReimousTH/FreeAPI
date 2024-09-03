#include "ModLoader.h"
#include <locale>
#include <codecvt>
#include <string>

namespace ModLoader{

	std::vector<HANDLE> _Files = std::vector<HANDLE>();
	std::map<HANDLE,std::vector<std::string>> _FilesMAP = std::map<HANDLE,std::vector<std::string>>();
	std::map<HANDLE,std::string> _NTCFILE = std::map<HANDLE,std::string>();
	




	typedef struct _UNICODE_STRING {
		USHORT Length;
		USHORT MaximumLength;
		char*  Buffer;
	} UNICODE_STRING, *PUNICODE_STRING;

	typedef struct _OBJECT_ATTRIBUTES {
		DWORD Length; //FLAG??
		PUNICODE_STRING ObjectName;
		HANDLE RootDirectory;
		ULONG Attributes;
		PVOID SecurityDescriptor;
		PVOID SecurityQualityOfService;
	} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;



	extern "C" int NtCreateFile(	PHANDLE Handle,
		DWORD dwDesiredAccess,
		POBJECT_ATTRIBUTES  attributes,
		DWORD   IoStatusBlock,
		PLARGE_INTEGER     AllocationSize,
		ULONG              FileAttributes,
		ULONG              ShareAccess,
		ULONG              CreateDisposition,
		ULONG              CreateOptions,
		PVOID              EaBuffer,
		ULONG              EaLength);



	int NTCreateFileReplace(
		PHANDLE Handle,
		DWORD dwDesiredAccess,
		POBJECT_ATTRIBUTES  attributes,
		DWORD   IoStatusBlock,
		PLARGE_INTEGER     AllocationSize,
		ULONG              FileAttributes,
		ULONG              ShareAccess,
		ULONG              CreateDisposition,
		ULONG              CreateOptions,
		PVOID              EaBuffer,
		ULONG              EaLength

		){

		
			int result = NtCreateFile(Handle,dwDesiredAccess,attributes,IoStatusBlock,AllocationSize,FileAttributes,ShareAccess,CreateDisposition,CreateOptions,EaBuffer,EaLength);
			if (attributes && attributes->ObjectName->MaximumLength > 0 && attributes->ObjectName->Buffer){

				std::string file_name = std::string(attributes->ObjectName->Buffer,attributes->ObjectName->Length);
				//DebugLogPushValueHEX(file_name);
				_NTCFILE[*Handle]=std::string(file_name);
				DebugLogPushValueHEX(*Handle);
			}
			
	
	
		return 	result;
	}



	extern "C" int NtReadFile(
		HANDLE file,
		HANDLE fevent,
		int ApcRoutine,
		PVOID ApcContext,
		int IoStatusBlock,
		PVOID Buffer,
		DWORD Length,
		PLARGE_INTEGER ByteOffset,
		PULONG Key
		);


	int NTReadFileReplace(	HANDLE file,
		HANDLE fevent,
		int ApcRoutine,
		PVOID ApcContext,
		int IoStatusBlock,
		PVOID Buffer,
		DWORD Length,
		PLARGE_INTEGER ByteOffset,
		PULONG Key){

	
			int result = NtReadFile(file,fevent,ApcRoutine,ApcContext,IoStatusBlock,Buffer,Length,ByteOffset,Key);

			if (_NTCFILE.find(file) != _NTCFILE.end()){
				DebugLogPushValueHEX(_NTCFILE[file]);
				DebugLogPushValueHEX("ByteOffset");
				if (ByteOffset)
				DebugLogPushValueHEX(ByteOffset->QuadPart);
			}

			//if (*(DWORD*)Buffer == 0xFF512ED)
		
			return result;


	}






	DWORD WINAPI LZX_HOOK_UNCOMPRESS(int a1,int a2){
		int r = BranchTo(0x824D42A8,int,a1,a2);

		//ShowXenonMessage(L"G",a1,0);
		//Sleep(100000);

		
		
		return r;
	}



	HANDLE _declspec(naked) CreateFileAOriginal(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile){
		__asm{
				mflr      r12
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw		  r12, -8(r1)
				stwu      r1, -0xC0(r1)
				mr        r29, r3
				lis r11,0x824D
				ori r11,r11,0x0F38
				mtctr r11
				bctr

		}
	}


	HOOK(HANDLE,__fastcall,CreateFileAReplace,0x824D0F28,LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile){

		

		return CreateFileAOriginal(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);



	}

	
	void LoadModData(const char* g_szSaveGame){
		std::ifstream  myFile(g_szSaveGame);
	
		if (myFile.is_open()) {
	
		
			
		}


		myFile.close();
	}

	void SaveModData(const char* g_szSaveGame){
		std::fstream myFile;
	

		myFile.close();
	}
	void ProceedActionDuringSaveContent(void (*action)(const char*),bool readmode = false){
		{
			const char* g_szSaveRoot = "save";
			const char* g_szSaveGame = "save:\\savegame.txt";


			// Create event for asynchronous writing
			HANDLE hEventComplete = CreateEvent( NULL, FALSE, FALSE, NULL );

			if( hEventComplete == NULL )
				ATG::FatalError( "WriteSaveGame: Couldn't create event.\n" );

			XOVERLAPPED xov = {0};
			xov.hEvent = hEventComplete;

			XCONTENT_DATA contentData = {0};
			strcpy_s( contentData.szFileName, "savegame.txt" );
			wcscpy_s( contentData.szDisplayName, L"savegame.txt" );
			contentData.dwContentType = XCONTENTTYPE_SAVEDGAME;
			contentData.DeviceID = 1;

			// Mount the device associated with the display name for writing
			DWORD dwErr = XContentCreate( ATG::SignIn::GetSignedInUser(), g_szSaveRoot, &contentData,
				readmode == true ? XCONTENTFLAG_OPENEXISTING:  XCONTENTFLAG_CREATEALWAYS, NULL, NULL, &xov );
			if( dwErr != ERROR_IO_PENDING )
			{
				CloseHandle( hEventComplete );
		
			}
		
			// Wait on hEventComplete handle
			if( XGetOverlappedResult( &xov, NULL, TRUE ) == ERROR_SUCCESS )
			{
				/*
				HANDLE hFile = CreateFile( g_szSaveGame, GENERIC_WRITE, 0,
					NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );

				if( hFile != INVALID_HANDLE_VALUE )
				{
					DebugLogPushValueHEX("RIGHT");
					// Write dummy data to the file
					CHAR szBuffer[] = "Test save game data.\n";
					DWORD dwWritten;

					if( WriteFile( hFile, ( VOID* )szBuffer, strlen( szBuffer ), &dwWritten, NULL ) == 0 )
					{
						CloseHandle( hFile );
						XContentClose( g_szSaveRoot, &xov );
						XGetOverlappedResult( &xov, NULL, TRUE );
						CloseHandle( hEventComplete );

					}

					CloseHandle( hFile );
				}
				else
				{
		
				}
				*/
				if (action){
					action(g_szSaveGame);
				}
		

			}

			XContentClose( g_szSaveRoot, &xov );

			// Wait for XCloseContent to complete
			XGetOverlappedResult( &xov, NULL, TRUE );

			CloseHandle( hEventComplete );

		
		}

	}

	
	
	void Install()
	{


		//WRITE_DWORD(0x824D45A0,POWERPC_ORIS(10,0,POWERPC_HI((DWORD)LZX_HOOK_UNCOMPRESS)));
		//WRITE_DWORD(0x824D45CC,POWERPC_ORI(7,10,POWERPC_LO((DWORD)LZX_HOOK_UNCOMPRESS)));

	//	INSTALL_HOOK(sub_824F4858);
		//INSTALL_HOOK(sub_82ACBB0C);
		INSTALL_HOOK(CreateFileAReplace);

	//	ProceedActionDuringSaveContent(LoadModData,true);
		MainAPP app;
		app.Process();
	
	

	//	if (MainScene::Changed)
	//		ProceedActionDuringSaveContent(SaveModData);






		//INSTALL_HOOK(ReadFile_NEW);
		//INSTALL_HOOK(sub_8249D028);
		
		
		//WRITE_DWORD(0x82AD036C,NTCreateFileReplace);
		//WRITE_DWORD(0x82AD0370,NTReadFileReplace);
	}

}