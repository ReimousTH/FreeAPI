//--------------------------------------------------------------------------------------
// AtgSignIn.cpp
//
// Handler for automatic signin
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "AtgSignIn.h"


namespace ATG
{

//--------------------------------------------------------------------------------------
// Static members
//--------------------------------------------------------------------------------------

DWORD  SignIn::m_dwMinUsers                   = 0;     
DWORD  SignIn::m_dwMaxUsers                   = 4;     
BOOL   SignIn::m_bRequireOnlineUsers          = FALSE; 
DWORD  SignIn::m_dwSignInPanes                = 4;     
HANDLE SignIn::m_hNotification                = NULL;  
DWORD  SignIn::m_dwSignedInUserMask           = 0;     
DWORD  SignIn::m_dwNumSignedInUsers           = 0;     
DWORD  SignIn::m_dwOnlineUserMask             = 0;     
DWORD  SignIn::m_dwFirstSignedInUser          = (DWORD)-1;
BOOL   SignIn::m_bSystemUIShowing             = FALSE; 
BOOL   SignIn::m_bNeedToShowSignInUI          = FALSE; 
BOOL   SignIn::m_bMessageBoxShowing           = FALSE;
BOOL   SignIn::m_bSigninUIWasShown            = FALSE;
XOVERLAPPED SignIn::m_Overlapped              = {0};
LPCWSTR SignIn::m_pwstrButtons[2]             = { L"Exit", L"Sign In" };
MESSAGEBOX_RESULT SignIn::m_MessageBoxResult  = {0};

//--------------------------------------------------------------------------------------
// Name: Initialize()
// Desc: Sets up variables and creates notification listener
//--------------------------------------------------------------------------------------
VOID SignIn::Initialize( DWORD dwMinUsers,
                         DWORD dwMaxUsers,
                         BOOL bRequireOnlineUsers,
                         DWORD dwSignInPanes )
{


    // Assign variables
    m_dwMinUsers = dwMinUsers;
    m_dwMaxUsers = dwMaxUsers;
    m_bRequireOnlineUsers = bRequireOnlineUsers;
    m_dwSignInPanes = dwSignInPanes;

    // Register our notification listener
    m_hNotification = XNotifyCreateListener( XNOTIFY_SYSTEM | XNOTIFY_LIVE );
    if( m_hNotification == NULL || m_hNotification == INVALID_HANDLE_VALUE )
    {
       
    }

    // Query who is signed in
    QuerySigninStatus();
}


//--------------------------------------------------------------------------------------
// Name: QuerySigninStatus()
// Desc: Query signed in status of all users.
//--------------------------------------------------------------------------------------
VOID SignIn::QuerySigninStatus()
{
    m_dwSignedInUserMask = 0;
    m_dwOnlineUserMask = 0;

    // Count the signed-in users
    m_dwNumSignedInUsers = 0;
    m_dwFirstSignedInUser = ( DWORD )-1;

    for( UINT nUser = 0;
         nUser < XUSER_MAX_COUNT;
         nUser++ )
    {
        XUSER_SIGNIN_STATE State = XUserGetSigninState( nUser );

        if( State != eXUserSigninState_NotSignedIn )
        {
            // Check whether the user is online
            BOOL bUserOnline =
                State == eXUserSigninState_SignedInToLive;

            m_dwOnlineUserMask |= bUserOnline << nUser;

            // If we want Online users only, only count signed-in users
            if( !m_bRequireOnlineUsers || bUserOnline )
            {
                m_dwSignedInUserMask |= ( 1 << nUser );

                if( m_dwFirstSignedInUser == ( DWORD )-1 )
                {
                    m_dwFirstSignedInUser = nUser;
                }

                ++m_dwNumSignedInUsers;
            }
        }
    }

    // check to see if we need to invoke the signin UI
    m_bNeedToShowSignInUI = !AreUsersSignedIn();
}

//--------------------------------------------------------------------------------------
// Name: Update()
// Desc: Does required per-frame processing for signin
//--------------------------------------------------------------------------------------
DWORD SignIn::Update()
{
	return 0;
}

//--------------------------------------------------------------------------------------
// Name: CheckPrivilege()
// Desc: Test to see if a user has a required privilege
//--------------------------------------------------------------------------------------
BOOL SignIn::CheckPrivilege( DWORD dwController, XPRIVILEGE_TYPE priv )
{
	return FALSE;
}

} // namespace ATG
