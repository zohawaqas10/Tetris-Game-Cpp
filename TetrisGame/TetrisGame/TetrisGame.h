
// TetrisGame.h : main header file for the TetrisGame application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTetrisGameApp:
// See TetrisGame.cpp for the implementation of this class
//

class CTetrisGameApp : public CWinApp
{
public:
	CTetrisGameApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTetrisGameApp theApp;
