// WeiClass.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "WeiClass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWeiClass �Ի���

IMPLEMENT_DYNCREATE(CWeiClass, CForm)

CWeiClass::CWeiClass()
	: CForm(CWeiClass::IDD)
{

}

CWeiClass::~CWeiClass()
{
}

void CWeiClass::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWeiClass, CForm)
END_MESSAGE_MAP()


// CWeiClass ��Ϣ�������
#ifdef _DEBUG
void CWeiClass::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CWeiClass::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 