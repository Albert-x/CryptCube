// HighEfs.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighEfs.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// HighEfs 对话框

IMPLEMENT_DYNCREATE(HighEfs, CForm)

HighEfs::HighEfs()
	: CForm(HighEfs::IDD)
{

}

HighEfs::~HighEfs()
{
}

void HighEfs::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HighEfs, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &HighEfs::OnBnClickedButton1)
END_MESSAGE_MAP()


// HighEfs 消息处理程序
#ifdef _DEBUG
void HighEfs::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighEfs::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
void HighEfs::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL,"open","flashSource\\EFS.exe",NULL,NULL,SW_SHOWNORMAL);

	
}
