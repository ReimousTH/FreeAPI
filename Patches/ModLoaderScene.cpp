#include "ModLoaderScene.h"


namespace ModLoader{

	


	std::string MainScene::mpath = "game:\\mods\\";
	std::string MainScene::mpath_relative = "mods\\";

	const int MainScene::PreLoadLimit = 10;

	std::map<int,ModInfo> MainScene::ModLoadedData;

	ModInfo* MainScene::LoadModaData(int index,const char* cFileName){
		ModInfo mdata;
		mdata.mod_code_name  = cFileName;
		mdata.mod_name = cFileName;
		mdata.mod_author = cFileName;
		mdata.preload = false;
		ModLoadedData[index] = mdata;
		return &ModLoadedData[index];
	}



	DWORD WINAPI BackGroundThreadEx(LPVOID lpParameter) {
		MainScene *mscene = (MainScene *)lpParameter;

		while (true){
			if (mscene->CurrentBackground != mscene->PreviousBackground){
				mscene->PreviousBackground = mscene->CurrentBackground;

				if (mscene->CurrentBackground == ""){
					mscene->BackGroundElement.SetImagePath(L"");
				}
				else{
					std::wstringstream sstream; sstream << mscene->CurrentBackground.c_str();
					mscene->BackGroundElement.SetImagePath(sstream.str().c_str());
				}

			}

		}
		


		return 0;
	}
	void MainScene::PreLoadModData(int index){

		ModInfo* info = &ModLoadedData[index];
		std::stringstream fd; fd << mpath << "" << info->mod_code_name ;
		ModLoadedData[index].mod_folder = fd.str();

		if (ModLoadedData[index].ProcessLuaFile(info->GetPath("info.lua")) == false) return;
		info->InitDataFromLua();


			




	}

	void MainScene::GetModsData()
	{

		this->ModList.DeleteItems(0,this->ModList.GetItemCount());
		int cc = 0;
		WIN32_FIND_DATA fd;
		HANDLE hFind = FindFirstFile((mpath + "*").c_str(), &fd);
		if (hFind != INVALID_HANDLE_VALUE)
		{
			do
			{
				if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (strcmp(fd.cFileName, ".") != 0 && strcmp(fd.cFileName, "..") != 0)
					{
					 	ModInfo* mdata = LoadModaData(cc,fd.cFileName);
						ModList.InsertItems(ModList.GetItemCount(),1);
						ModList.SetText(ModList.GetItemCount() - 1,mdata->GetCodeModNameAsWSTR().c_str());
						PreLoadModData(cc);
						
						cc++;


					}
				}
			} while (FindNextFile(hFind, &fd));
			FindClose(hFind);
		}



	}



	HRESULT MainScene::OnInit(XUIMessageInit* pInitData, BOOL& bHandled)
	{
		
		GetChildById(L"InfoBox",&this->InfoBoxScene);
		GetChildById(L"ModList",&this->ModList);
		if (InfoBoxScene){
			this->InfoBoxScene.GetChildById(L"Name",&this->NameElement);
			this->InfoBoxScene.GetChildById(L"Author",&this->AuthorElement);
			GetChildById(L"XuiImage1",&this->BackGroundElement);
		}
		BackGroundElementMutex = false;
		GetModsData();


		DWORD tID;
		this->BackGroundThread = CreateThread(NULL,
			NULL,
			(LPTHREAD_START_ROUTINE)BackGroundThreadEx,
			(LPVOID)this,
			0,
			&tID);



		return S_OK;
		
	}



	HRESULT MainScene::OnRender(XUIMessageRender *pRenderData, BOOL& bHandled)
	{
		//Update
		int index = this->ModList.GetCurSel();
		if (selected_index != index){

			selected_index = index;
			SelectItemByIndex(index);
			previous_index = selected_index;

			
		}
		return S_OK;

	}



	MainScene::~MainScene()
	{
		CloseHandle(BackGroundThread);
	}

	void MainScene::SelectItemByIndex(int index)
	{
		ModInfo* data =   &ModLoadedData[index];
		ModInfo* prevdata =   &ModLoadedData[previous_index];
		this->ModList.SetCurSel(index);


		this->NameElement.SetText(data->GetModNameAsWSTR().c_str());
		this->AuthorElement.SetText(data->GetModAuthorAsWSTR().c_str());
		//if (data->mod_background != ""){

		data->BackGroundElement = this->BackGroundElement;
		
		if (data->mod_background == ""){
			this->CurrentBackground = "";
		}
		else{
			std::stringstream strms; strms << "..\\mods\\" << data->mod_code_name.c_str() <<  "\\" << data->mod_background.c_str();
			this->CurrentBackground = strms.str();
		}
	


	}

	std::wstring ModInfo::GetCodeModNameAsWSTR()
	{
		std::wstringstream _wstr;
		_wstr << this->mod_code_name.c_str();

		return _wstr.str();

	}

	std::wstring ModInfo::GetModNameAsWSTR()
	{
		std::wstringstream _wstr;
		_wstr << this->mod_name.c_str();

		return _wstr.str();
	}

	std::wstring ModInfo::GetModAuthorAsWSTR()
	{
		std::wstringstream _wstr;
		_wstr << this->mod_author.c_str();

		return _wstr.str();
	}

	bool ModInfo::ProcessLuaFile(std::string path)
	{

		std::string modPath = path;
		std::ifstream fileStream(modPath, std::ios::in);

		if (fileStream.is_open())
		{
		
			// Load the mod information from the Lua file
			fileStream.close();

			this->InitBaseLua();
			this->mod_lua.LoadLua(modPath.c_str());
			return true;


		}
		return false;
	
	}

	void ModInfo::InitBaseLua()
	{
		this->mod_lua.OpenLua();
		this->mod_lua.OpenLuaMy();
		this->mod_lua.RegisterFunction("PLoad",Lua_PreLoad);


	}

	void ModInfo::InitDataFromLua()
	{
		if (this->mod_lua.L == NULL) return;
		this->mod_name = this->mod_lua.GetGlobalString("Name");
		this->mod_author = this->mod_lua.GetGlobalString("Author");
		this->mod_background = this->mod_lua.GetGlobalString("BackGround");
	//	this->mod_lua.CallFunction("Preload",LUA_TLIGHTUSERDATA,(void*)this);
		this->preload = true;

	}

	bool ModInfo::isPreload()
	{
		return this->preload_files.size()> 0  ? true : false;
	}

	bool ModInfo::FilePreloaded(std::string file)
	{
		return this->preload_files.find(file) != this->preload_files.end();
	}

	std::string ModInfo::GetPath(std::string file)
	{
	
		std::stringstream modPath; modPath << this->mod_folder.c_str() <<  "\\" << file;
		return modPath.str();

	}

	std::wstring ModInfo::GetWPath(std::string file)
	{
		std::wstringstream modPath; modPath << this->mod_folder.c_str() <<  "\\" << file.c_str();
		return modPath.str();
	}


	int ModInfo::Lua_PreLoad(lua_State* L)
	{
		ModInfo* data  = (ModInfo*)lua_touserdata(L,1);

		const char* file_path = lua_tostring(L, 2);
		const char* file_root_dir = data->mod_folder.c_str();
		std::stringstream filepath_str; filepath_str << file_root_dir << "\\" << file_path;
		std::string filepath = filepath_str.str();

		std::ifstream fileStream(filepath, std::ios::in | std::ios::binary);

		if (fileStream.is_open())
		{
			// Get the size of the file
			fileStream.seekg(0, std::ios::end);
			std::streampos fileSize = fileStream.tellg();
			fileStream.seekg(0, std::ios::beg);


			void* _buffer =  malloc(fileSize);
			data->preload = true;
			data->preload_files[file_path] = _buffer;
			free(_buffer);

			fileStream.close();

	
			return 1; // Return 1 to indicate that we pushed one value to the stack
		}
		else
		{
			// Handle the case where the file doesn't exist
			lua_pushnil(L);
			return 1;
		}
	}

	HRESULT MainAPP::RegisterXuiClasses()
	{

		MainScene::Register();
		return S_OK;

	}

	HRESULT MainAPP::UnregisterXuiClasses()
	{
		MainScene::Unregister();

		return S_OK;
	}

	void MainAPP::Process()
	{
		this->Init(XuiD3DXTextureLoader);


		this->RegisterDefaultTypeface( L"Arial Unicode MS", L"file://game:/media/xarialuni.ttf" );
		//this->RegisterDefaultTypeface( L"New Rodin", L"file://game:/media/xarialuni.ttf" );
		HRESULT isskin = this->LoadSkin( L"file://game:/media/simple_scene_skin.xur" );
		HRESULT isscene =  this->LoadFirstScene( L"file://game:/media/", L"simple_scene.xur", NULL );

		
		

		this->Run();
		this->Uninit();
	}

}