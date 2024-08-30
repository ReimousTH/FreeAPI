#pragma once



#include "../HookV2.h"
#include "../RidersFree.h"



#include <string>
#include <vector>

#include <xam.h>
#include <xtl.h>
#include <xbdm.h>
#include <xcompress.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "InputData.h"

#include "ModLoaderScene.h"

#include <iostream>
#include <fstream>


namespace ModLoader{

	extern std::vector<HANDLE> _Files;

	void Install();
	
}