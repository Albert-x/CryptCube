// EncryptFileForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "EncryptFileForm.h"


// CEncryptFileForm

IMPLEMENT_DYNCREATE(CEncryptFileForm, CForm)

CEncryptFileForm::CEncryptFileForm()
	: CForm(CEncryptFileForm::IDD)
{

}

CEncryptFileForm::~CEncryptFileForm()
{
}

void CEncryptFileForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEncryptFileForm, CForm)
END_MESSAGE_MAP()


// CEncryptFileForm ���

#ifdef _DEBUG
void CEncryptFileForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CEncryptFileForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CEncryptFileForm ��Ϣ�������
