// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// CryptCube.h : CryptCube 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CCryptCubeApp:
// 有关此类的实现，请参阅 CryptCube.cpp
//

class CCryptCubeApp : public CWinAppEx
{
public:
	CCryptCubeApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual BOOL ExitInstance();

protected: 
	
	BOOL m_bvisible;
// 实现
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
	virtual void OnUpdateMenupause(CCmdUI* pCmdUI);
	//virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//CMenu pMenu;
	//CMainFrame *pmain;
	DECLARE_MESSAGE_MAP()
};

extern CCryptCubeApp theApp;
