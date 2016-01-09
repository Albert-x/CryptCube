// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CryptCubeForm.cpp : CCryptCubeForm ���ʵ��
//

#include "stdafx.h"
#include "CryptCube.h"

#include "CryptCubeDoc.h"
#include "CryptCubeForm.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCryptCubeForm

IMPLEMENT_DYNCREATE(CCryptCubeForm, CForm)

BEGIN_MESSAGE_MAP(CCryptCubeForm, CForm)

	ON_WM_ERASEBKGND()

END_MESSAGE_MAP()

// CCryptCubeForm ����/����

CCryptCubeForm::CCryptCubeForm()
	: CForm(CCryptCubeForm::IDD)

{
	// TODO: �ڴ˴���ӹ������

}

CCryptCubeForm::~CCryptCubeForm()
{
}

void CCryptCubeForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BOOL CCryptCubeForm::PreCreateWindow(CREATESTRUCT& cs)
{
//	// TODO: �ڴ˴�ͨ���޸�
//	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
return CForm::PreCreateWindow(cs);
	
}

void CCryptCubeForm::OnInitialUpdate()
{

	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	ModifyStyle(-1,WS_CHILD | WS_VISIBLE | WS_DLGFRAME); //��Ϊ�Ӵ��壬�ɼ�
	ModifyStyleEx(-1,0);  //ȥ��Form�尼��
	ImageFromIDResource();
	
}

// CCryptCubeForm ���

#ifdef _DEBUG
void CCryptCubeForm::AssertValid() const
{
	CForm::AssertValid();
}

void CCryptCubeForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}

CCryptCubeDoc* CCryptCubeForm::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCryptCubeDoc)));
	return (CCryptCubeDoc*)m_pDocument;
}
#endif //_DEBUG


// CCryptCubeForm ��Ϣ�������



BOOL CCryptCubeForm::OnEraseBkgnd(CDC* pDC)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CRect rect;
	GetClientRect( &rect ) ;
	CRect imageRect ;

	imageRect.left = 0 ;
	imageRect.top = 0 ; 
	imageRect.bottom =  m_Image.GetHeight() ;
	imageRect.right =  m_Image.GetWidth() ;
	//pDC->SetStretchBltMode( STRETCH_HALFTONE ) ;
	m_Image.Draw( pDC->m_hDC , rect ,  imageRect ) ;

    return TRUE;
}

//��PNG��Դ�ļ����ô��ڱ���
BOOL CCryptCubeForm::ImageFromIDResource()
{
	UINT nID = IDP_BACKGROUND;
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