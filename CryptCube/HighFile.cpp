// HighFile.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighFile.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// HighFile 对话框

IMPLEMENT_DYNCREATE(HighFile, CForm)

HighFile::HighFile()
	: CForm(HighFile::IDD)
{

}

HighFile::~HighFile()
{
}

void HighFile::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HighFile, CForm)
	ON_BN_CLICKED(IDC_File, &HighFile::OnBnClickedFile)
END_MESSAGE_MAP()

#ifdef _DEBUG
void HighFile::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighFile::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
// HighFile 消息处理程序


void HighFile::OnBnClickedFile()
{
	// TODO: 在此添加控件通知处理程序代码
	//ShellExecute(NULL,"open","flashSource\\HighFile.swf",NULL,NULL,SW_SHOWNORMAL);
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}	CString strFileName = strCurDrt;
	strFileName += "flashSource\\HighFile.swf"; //以上为获的绝对路径
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);
}
