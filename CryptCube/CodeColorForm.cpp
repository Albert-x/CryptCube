// CodeColorForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeColorForm.h"


// CCodeColorForm

IMPLEMENT_DYNCREATE(CCodeColorForm, CForm)

CCodeColorForm::CCodeColorForm()
	: CForm(CCodeColorForm::IDD)
{

}

CCodeColorForm::~CCodeColorForm()
{
}

void CCodeColorForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeColorForm, CForm)
END_MESSAGE_MAP()


// CCodeColorForm 诊断

#ifdef _DEBUG
void CCodeColorForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeColorForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeColorForm 消息处理程序
