// CodeUrlForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeUrlForm.h"


// CCodeUrlForm

IMPLEMENT_DYNCREATE(CCodeUrlForm, CForm)

CCodeUrlForm::CCodeUrlForm()
	: CForm(CCodeUrlForm::IDD)
{

}

CCodeUrlForm::~CCodeUrlForm()
{
}

void CCodeUrlForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeUrlForm, CForm)
END_MESSAGE_MAP()


// CCodeUrlForm ���

#ifdef _DEBUG
void CCodeUrlForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeUrlForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeUrlForm ��Ϣ�������
