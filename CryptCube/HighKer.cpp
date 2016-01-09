// HighKer.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighKer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// HighKer 对话框

IMPLEMENT_DYNCREATE(HighKer, CForm)

HighKer::HighKer()
	: CForm(HighKer::IDD)
{

}

HighKer::~HighKer()
{
}

void HighKer::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HighKer, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &HighKer::OnBnClickedButton1)
END_MESSAGE_MAP()

#ifdef _DEBUG
void HighKer::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighKer::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
// HighKer 消息处理程序


void HighKer::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//ShellExecute(NULL,"open","flashSource\\Kerberos.swf",NULL,NULL,SW_SHOWNORMAL);
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}	CString strFileName = strCurDrt;
	strFileName += "flashSource\\Kerberos.swf"; //以上为获的绝对路径
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);

}
