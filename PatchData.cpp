#include "PatchData.h"

#include <d3d9.h>
#include <d3dx9.h>

namespace PatchData{


	
 void InstallGB()
{
	
	HookV2::IsNotEmulatedHardWare =  HookV2::CheckIsNotEmulatedHardWare();
	KernelR::Install();
	DLL_LUA_INSTALL();
	if (CommonLua.error){ ShowXenonMessage(L"MSG",CommonLua.error_msg); return ;}
	if (CommonLua.GetGlobalBoolean("DeltaTimer")){DeltaTimerU::Install();}
	if (CommonLua.GetGlobalBoolean("DebugMode")){ZLuaN::EnableDebugOutput = true;}
	InputData::Install();
	InputData::Install_Actions();
	InputData::Install_CommonActions();
	InputData::Install_CutsceneActions();
	InputData::Install_MenuActions();
	InputData::Install_TitleActions();
	CIStateActions::Install();
	ModLoader::Install();
	//NetplayRFIX::Install();

/*
IDirect3DDevice9*   pDevice = 0;
	// Установка разрешения экрана
	int screenWidth = 680;
	int screenHeight = 720;

	// Установка разрешения рендеринга
	int renderWidth = 1280;
	int renderHeight = 720;

	// Установка вьюпорта
	D3DVIEWPORT9 viewport;
	ZeroMemory(&viewport, sizeof(viewport));
	viewport.X = 0;
	viewport.Y = 0;
	viewport.Width = screenWidth;
	viewport.Height = screenHeight;
	viewport.MinZ = 0.0f;
	viewport.MaxZ = 1.0f;
	pDevice->SetViewport(&viewport);

	// Настройка матрицы проекции
	D3DXMATRIX projectionMatrix;
	D3DXMatrixOrthoLH(&projectionMatrix, renderWidth, renderHeight, 0.0f, 1.0f);
	pDevice->StretchRect(0,0,0,0,0);



*/

}

}