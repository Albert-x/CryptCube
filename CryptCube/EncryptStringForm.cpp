// EncryptStringForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "EncryptStringForm.h"


// CEncryptStringForm

IMPLEMENT_DYNCREATE(CEncryptStringForm, CForm)

CEncryptStringForm::CEncryptStringForm()
	: CForm(CEncryptStringForm::IDD)
{

}

CEncryptStringForm::~CEncryptStringForm()
{
}

void CEncryptStringForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEncryptStringForm, CForm)
END_MESSAGE_MAP()


// CEncryptStringForm ���

#ifdef _DEBUG
void CEncryptStringForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CEncryptStringForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CEncryptStringForm ��Ϣ�������
