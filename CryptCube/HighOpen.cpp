// HighOpen.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighOpen.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHighOpen 对话框

IMPLEMENT_DYNCREATE(CHighOpen, CForm)

CHighOpen::CHighOpen()
	: CForm(CHighOpen::IDD)
{

}

CHighOpen::~CHighOpen()
{
}

void CHighOpen::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHighOpen, CForm)
	ON_BN_CLICKED(IDC_BUTTON2, &CHighOpen::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CHighOpen::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHighOpen 消息处理程序
#ifdef _DEBUG
void CHighOpen::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CHighOpen::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
void CHighOpen::OnBnClickedButton2()
{
	ShellExecute(NULL,"open","flashSource\\OpenSSL.exe",NULL,NULL,SW_SHOWNORMAL);
	
}

void CHighOpen::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL,"open","flashSource\\OpenSSL_evp.exe",NULL,NULL,SW_SHOWNORMAL);
	
}
