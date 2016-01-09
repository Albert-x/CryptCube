// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CryptCube.h : CryptCube Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCryptCubeApp:
// �йش����ʵ�֣������ CryptCube.cpp
//

class CCryptCubeApp : public CWinAppEx
{
public:
	CCryptCubeApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual BOOL ExitInstance();

protected: 
	
	BOOL m_bvisible;
// ʵ��
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
