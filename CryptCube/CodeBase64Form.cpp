// CodeBase64Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeBase64Form.h"


// CCodeBase64Form

IMPLEMENT_DYNCREATE(CCodeBase64Form, CForm)

CCodeBase64Form::CCodeBase64Form()
	: CForm(CCodeBase64Form::IDD)
{

}

CCodeBase64Form::~CCodeBase64Form()
{
}

void CCodeBase64Form::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeBase64Form, CForm)
END_MESSAGE_MAP()


// CCodeBase64Form ���

#ifdef _DEBUG
void CCodeBase64Form::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeBase64Form::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeBase64Form ��Ϣ�������
