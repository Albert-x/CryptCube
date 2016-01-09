// Execise.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "Execise.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CExecise 对话框

IMPLEMENT_DYNCREATE(CExecise,CForm)

CExecise::CExecise()
	: CForm(CExecise::IDD)
{

}

CExecise::~CExecise()
{
}

void CExecise::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExecise, CForm)
END_MESSAGE_MAP()


// CExecise 消息处理程序
#ifdef _DEBUG
void CExecise::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CExecise::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 