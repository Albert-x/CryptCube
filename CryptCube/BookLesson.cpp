// BookLesson.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BookLesson.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// BookLesson

IMPLEMENT_DYNCREATE(BookLesson, CForm)

BookLesson::BookLesson()
	: CForm(BookLesson::IDD)
{

}

BookLesson::~BookLesson()
{
}

void BookLesson::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(BookLesson, CForm)
END_MESSAGE_MAP()


// BookLesson ���

#ifdef _DEBUG
void BookLesson::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void BookLesson::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// BookLesson ��Ϣ�������
