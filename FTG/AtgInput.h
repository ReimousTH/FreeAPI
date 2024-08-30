#pragma once
#include <xtl.h>

namespace FTG
{


struct GAMEPAD : public XINPUT_GAMEPAD
{

	DWORD      XUIndex;
	XINPUT_CAPABILITIES xinput_caps;
	BOOL       xConnected;
	BOOL       xInserted;
	BOOL       xRemoved;
    FLOAT      left_stick_x;
    FLOAT      left_stick_y;
    FLOAT      right_stick_x;
    FLOAT      right_stick_y;
    WORD       HoldButtons;
    BOOL       HoldLeftTrigger;
    BOOL       HoldRightTrigger;
    WORD       PressedButtons;
    BOOL       IsPressedLeftTrigger;
    BOOL       IsPressedRightTrigger;
    static SHORT LTHUMB_DEADZONE;
    static SHORT RTHUMB_DEADZONE;
};



class Input
{
public:

    static GAMEPAD   m_Gamepads[4];
    static GAMEPAD   m_DefaultGamepad;
    static VOID GetPInput( GAMEPAD* pGamepads = NULL );
    static GAMEPAD* ProcessAllInput( DWORD dwMask = 0, DWORD* pdwActiveGamePadsMask = NULL );
};

} // namespace FTG

