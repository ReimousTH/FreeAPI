//--------------------------------------------------------------------------------------
// AtgInput.cpp
//
// Input helper functions for samples
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------


#include "AtgInput.h"

namespace FTG
{

//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------

// Instance of static member variables
GAMEPAD   Input::m_Gamepads[4];
GAMEPAD   Input::m_DefaultGamepad;




inline FLOAT CThumbstickvalue( SHORT sThumbstickValue, SHORT sDeadZone )
{
    if( sThumbstickValue > +sDeadZone )
    {
        return (sThumbstickValue-sDeadZone) / (32767.0f-sDeadZone);
    }
    if( sThumbstickValue < -sDeadZone )
    {
        return (sThumbstickValue+sDeadZone+1.0f) / (32767.0f-sDeadZone);
    }
    return 0.0f;
}


//--------------------------------------------------------------------------------------
// Name: GetInput()
// Desc: Processes input from the gamepads
//--------------------------------------------------------------------------------------
VOID Input::GetPInput( GAMEPAD* pGamepads )
{

    static BOOL init = FALSE;
    if( FALSE == init )
    {
        ZeroMemory( m_Gamepads,        sizeof(m_Gamepads) );
        ZeroMemory( &m_DefaultGamepad, sizeof(m_DefaultGamepad) );
        init = TRUE;
    }


    if( NULL == pGamepads )
        pGamepads = m_Gamepads;

    
    for( DWORD i=0; i < XUSER_MAX_COUNT; i++ )
    {
        // Read the input state
        XINPUT_STATE InputState;
        BOOL bWasConnected = pGamepads[i].xConnected;
        pGamepads[i].xConnected = ( XInputGetState( i, &InputState ) == ERROR_SUCCESS ) ? TRUE : FALSE;

   
        pGamepads[i].xRemoved  = (  bWasConnected && !pGamepads[i].xConnected ) ? TRUE : FALSE;
        pGamepads[i].xInserted = ( !bWasConnected &&  pGamepads[i].xConnected ) ? TRUE : FALSE;

        if( FALSE == pGamepads[i].xConnected )
            continue;

    
        if( TRUE == pGamepads[i].xInserted )
        {
            ZeroMemory( &pGamepads[i], sizeof(m_Gamepads[i]) );
            pGamepads[i].xConnected = TRUE;
            pGamepads[i].xInserted  = TRUE;
            XInputGetCapabilities( i, XINPUT_FLAG_GAMEPAD, &pGamepads[i].xinput_caps );
        }

      
        memcpy( &pGamepads[i], &InputState.Gamepad, sizeof(XINPUT_GAMEPAD) );

        pGamepads[i].left_stick_x = CThumbstickvalue( pGamepads[i].sThumbLX, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE );
        pGamepads[i].left_stick_y = CThumbstickvalue( pGamepads[i].sThumbLY, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE );
        pGamepads[i].right_stick_x = CThumbstickvalue( pGamepads[i].sThumbRX, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE );
        pGamepads[i].right_stick_y = CThumbstickvalue( pGamepads[i].sThumbRY, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE );


        pGamepads[i].PressedButtons = ( pGamepads[i].HoldButtons ^ pGamepads[i].wButtons ) & pGamepads[i].wButtons;
        pGamepads[i].HoldButtons    = pGamepads[i].wButtons;

        BOOL bPressed = ( pGamepads[i].bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD );

        if( bPressed )
            pGamepads[i].IsPressedLeftTrigger = !pGamepads[i].HoldLeftTrigger;
        else
            pGamepads[i].IsPressedLeftTrigger = FALSE;

  
        pGamepads[i].HoldLeftTrigger = bPressed;


        bPressed = ( pGamepads[i].bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD );

        if( bPressed )
            pGamepads[i].IsPressedRightTrigger = !pGamepads[i].HoldRightTrigger;
        else
            pGamepads[i].IsPressedRightTrigger = FALSE;

   
        pGamepads[i].HoldRightTrigger = bPressed;

   
        pGamepads[i].XUIndex = i;
    }
}


//--------------------------------------------------------------------------------------
// Name: ClampToShort()
// Desc: Takes an integer input and clamps it to fit in a short, to avoid wrapping.
//--------------------------------------------------------------------------------------
SHORT ClampToShort(INT input)
{
    // Use min/max from windef.h. Define NOMINMAX if you don't want these
    // macros defined.
    input = min(input, SHRT_MAX);
    input = max(input, SHRT_MIN);
    return (SHORT)input;
}


//--------------------------------------------------------------------------------------
// Name: GetAllInput()
// Desc: Processes input from all gamepads and merge it into one input. This is done for
//       expediency in samples and is not typically useful or advised for games.
//       If the pdwActiveGamePadsMask is non-NULL, then returns active gamepads.
//       
//--------------------------------------------------------------------------------------
GAMEPAD* Input::ProcessAllInput( DWORD dwMask, DWORD* pdwActiveGamePadsMask )
{
    // Get input for ALL the gamepads
    GetPInput();

    return &m_DefaultGamepad;
}

} // namespace FTG
