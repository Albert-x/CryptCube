// HighSSL.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighSSL.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// HighSSL 对话框

IMPLEMENT_DYNCREATE(HighSSL, CForm)




BEGIN_MESSAGE_MAP(HighSSL, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &HighSSL::OnBnClickedButton1)
END_MESSAGE_MAP()

HighSSL::HighSSL()
	: CForm(HighSSL::IDD)
{

}

HighSSL::~HighSSL()
{
}

void HighSSL::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}
// HighSSL 消息处理程序

#ifdef _DEBUG
void HighSSL::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighSSL::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
void HighSSL::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//ShellExecute(NULL,"open","flashSource\\HighSSL.swf",NULL,NULL,SW_SHOWNORMAL);
		TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}	CString strFileName = strCurDrt;
	strFileName += "flashSource\\HighSSL.swf"; //以上为获的绝对路径
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);
}
