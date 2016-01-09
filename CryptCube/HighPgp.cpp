// HighPgp.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighPgp.h"
#include "FlashPgp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHighPgp 对话框

IMPLEMENT_DYNCREATE(CHighPgp,CForm)

CHighPgp::CHighPgp()
	: CForm(CHighPgp::IDD)
{

}

CHighPgp::~CHighPgp()
{
}

void CHighPgp::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHighPgp,CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &CHighPgp::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHighPgp 消息处理程序
#ifdef _DEBUG
void CHighPgp::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CHighPgp::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
void CHighPgp::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFlashPgp pFlash;
	pFlash.DoModal();
	
}
