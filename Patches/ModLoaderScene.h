#pragma once



#include "../HookV2.h"
#include "../RidersFree.h"


#include <string>
#include <locale>
#include <codecvt>

#include <vector>

#include <xam.h>



#include <xtl.h>
#include <xui.h>
#include <xuiapp.h>
#include <stdio.h>
#include <assert.h>
#include <xaudio2.h>



#include <xbdm.h>
#include <xcompress.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "InputData.h"
#include <fstream>



namespace ModLoader{


	struct ModInfo{
		bool preload;
		std::string mod_folder;
		std::string mod_code_name;
		std::string mod_name;
		std::string mod_author;
		std::string mod_background;

		HANDLE ActiveThread;
		bool CancelThread;

		CXuiImageElement BackGroundElement;
	

		ZLuaN mod_lua;
		std::map<std::string,void*> preload_files;



	public:
		std::wstring GetCodeModNameAsWSTR();
		std::wstring GetModNameAsWSTR();
		std::wstring GetModAuthorAsWSTR();
		bool ProcessLuaFile(std::string path);
		void InitBaseLua();
		void InitDataFromLua();
		bool isPreload();
		bool FilePreloaded(std::string file);
		std::string GetPath(std::string file);
		std::wstring GetWPath(std::string file);



		static int Lua_PreLoad(lua_State* L);

	};


	class MainScene : CXuiSceneImpl{

	protected:
		CXuiElement InfoBoxScene;
		CXuiList ModList;
		//other
		CXuiTextElement NameElement;
		CXuiTextElement AuthorElement;
	public:
		CXuiImageElement BackGroundElement;
	
	protected:

		XUI_BEGIN_MSG_MAP()
			XUI_ON_XM_INIT( OnInit )
			XUI_ON_XM_RENDER(OnRender)
			//	XUI_ON_XM_KEYDOWN( OnKeyDown )
		XUI_END_MSG_MAP()

			HRESULT OnInit( XUIMessageInit* pInitData, BOOL& bHandled );
			HRESULT OnRender(XUIMessageRender *pRenderData, BOOL& bHandled);
			~MainScene();




	public:
	    bool BackGroundElementMutex;
		int selected_index;
		int previous_index;
		std::string CurrentBackground;
		std::string PreviousBackground;

		static std::map<int,ModInfo> ModLoadedData;
		HANDLE BackGroundThread;
    private:
		static std::string mpath;
		static std::string mpath_relative;
		static const int PreLoadLimit;
		

		void GetModsData();
	
		ModInfo* MainScene::LoadModaData(int index,const char* cFileName);
		void MainScene::PreLoadModData(int index);
		void SelectItemByIndex(int);


	public:
		XUI_IMPLEMENT_CLASS( MainScene, L"MainScene", XUI_CLASS_SCENE );



	};




	class MainAPP : public CXuiModule{

	public:	void Process();
	protected:
		// Override RegisterXuiClasses so that CMyApp can register classes.
		virtual HRESULT RegisterXuiClasses();

		// Override UnregisterXuiClasses so that CMyApp can unregister classes. 
		virtual HRESULT UnregisterXuiClasses();

	

		



	};

}