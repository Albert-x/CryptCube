// Theory.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "Theory.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTheory 对话框

IMPLEMENT_DYNCREATE(CTheory, CForm)

CTheory::CTheory()
	: CForm(CTheory::IDD)
{

}

CTheory::~CTheory()
{
}

void CTheory::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTheory, CForm)
END_MESSAGE_MAP()


// CTheory 消息处理程序
#ifdef _DEBUG
void CTheory::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CTheory::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif