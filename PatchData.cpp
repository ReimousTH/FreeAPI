#include "PatchData.h"

#include <d3d9.h>
#include <d3dx9.h>

namespace PatchData{


	
 void InstallGB()
{

	int index = 1;
	auto value =  (char *)index + 4 * (unsigned __int8)index + 4 * __ROL4__((unsigned __int8)index, 3);




	
	HookV2::IsNotEmulatedHardWare =  HookV2::CheckIsNotEmulatedHardWare();
	KernelR::Install();
	DLL_LUA_INSTALL();

	

	if (CommonLua.error){ ShowXenonMessage(L"MSG",CommonLua.error_msg);}
	




	InputData::P1SLOT = CommonLua.GetGlobalIntNew("XINPUT_1P",true);
	InputData::P2SLOT = CommonLua.GetGlobalIntNew("XINPUT_2P",true);



	if (CommonLua.GetGlobalBoolean("DeltaTimer")){DeltaTimerU::Install();}
	if (CommonLua.GetGlobalBoolean("DebugMode")){ZLuaN::EnableDebugOutput = true;}
	if ( strcmp(CommonLua.GetGlobalString("HUDMode"),"Togglable") == 0) {ZLuaN::TogeableHud = true;}



	InputData::Install();
	InputData::Install_Actions();
	InputData::Install_CommonActions();
	InputData::Install_CutsceneActions();
	InputData::Install_MenuActions();
	InputData::Install_TitleActions();
	CIStateActions::Install();
	//ModLoader::Install();

	if (CommonLua.GetGlobalBoolean("NetPlayFix") == true && HookV2::IsNotEmulatedHardWare == false)
	{
		NetplayRFIX::Install();
	}
   
//	DebugLogPushValueHEX(X_PROPERTY_GAMER_HOSTNAME);
	/*
	D3DXQUATERNION quat1;
	D3DXVECTOR3 vec;	

	D3DXQUATERNION* vert1 = D3DXQuaternionRotationAxis(&quat1,&vec,0);
	D3DXQUATERNION* vert2 = D3DXQuaternionRotationAxis(&quat1,&vec,0);

	D3DXQUATERNION out;

	float blendFactor = 0.5f; // Пример коэффициента смешивания
	D3DXQUATERNION* interpolatedQuaternion = D3DXQuaternionSlerp(&out, vert1,vert2, blendFactor);



	FXMVECTOR axis1;
	FXMVECTOR axis2;

	XMVECTOR startQuaternion = XMQuaternionRotationAxis(axis1, 1);
	XMVECTOR endQuaternion = XMQuaternionRotationAxis(axis2, 1);


	XMVECTOR interpolatedQuaternionX = XMQuaternionSlerp(startQuaternion, endQuaternion, blendFactor);

*/


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


	pDevice->Present(0,0,0,0);
	pDevice->Clear( 0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		0, 1.0f, 0L );



		*/


}

}