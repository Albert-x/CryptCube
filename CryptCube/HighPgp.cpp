// HighPgp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighPgp.h"
#include "FlashPgp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHighPgp �Ի���

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


// CHighPgp ��Ϣ�������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFlashPgp pFlash;
	pFlash.DoModal();
	
}
