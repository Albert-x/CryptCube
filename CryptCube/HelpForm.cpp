// HelpForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HelpForm.h"


// CHelpForm

IMPLEMENT_DYNCREATE(CHelpForm, CForm)

CHelpForm::CHelpForm()
	: CForm(CHelpForm::IDD)
{

}

CHelpForm::~CHelpForm()
{
}

void CHelpForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHelpForm, CForm)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CHelpForm ���

#ifdef _DEBUG
void CHelpForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CHelpForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CHelpForm ��Ϣ�������


void CHelpForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	ImageFromIDResource();

}

BOOL CHelpForm::OnEraseBkgnd(CDC* pDC)
{

	CForm::OnEraseBkgnd(pDC);

    CRect rect;
	GetClientRect( &rect ) ;
	CRect imageRect ;

	imageRect.left = rect.Width()/2 - m_Image.GetWidth()/2 ;
	imageRect.top = rect.Height()/2 - m_Image.GetHeight()/2 ; 
	imageRect.bottom = imageRect.top + m_Image.GetHeight() ;
	imageRect.right = imageRect.left + m_Image.GetWidth() ;

	m_Image.Draw( pDC->m_hDC , imageRect ) ;

    return TRUE;
}


//��PNG��Դ�ļ����ô��ڱ���
BOOL CHelpForm::ImageFromIDResource()
{
	UINT nID = IDP_HELP;
	LPCTSTR sTR = _T("PNG");
	HINSTANCE hInst = AfxGetResourceHandle();
	HRSRC hRsrc = ::FindResource (hInst,MAKEINTRESOURCE(nID),sTR); // type
	if (!hRsrc)
		return FALSE;

	// load resource into memory
	DWORD len = SizeofResource(hInst, hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(hInst, hRsrc);
	if (!lpRsrc)
		return FALSE;

	// Allocate global memory on which to create stream
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem,lpRsrc,len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem,FALSE,&pstm);

	// load from stream
	if(m_Image.IsNull())m_Image.Load(pstm);
	// free/release stuff
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);
	return TRUE;

}