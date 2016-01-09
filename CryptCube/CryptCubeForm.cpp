// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// CryptCubeForm.cpp : CCryptCubeForm 类的实现
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

// CCryptCubeForm 构造/析构

CCryptCubeForm::CCryptCubeForm()
	: CForm(CCryptCubeForm::IDD)

{
	// TODO: 在此处添加构造代码

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
//	// TODO: 在此处通过修改
//	//  CREATESTRUCT cs 来修改窗口类或样式
	
return CForm::PreCreateWindow(cs);
	
}

void CCryptCubeForm::OnInitialUpdate()
{

	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	ModifyStyle(-1,WS_CHILD | WS_VISIBLE | WS_DLGFRAME); //做为子窗体，可见
	ModifyStyleEx(-1,0);  //去掉Form体凹陷
	ImageFromIDResource();
	
}

// CCryptCubeForm 诊断

#ifdef _DEBUG
void CCryptCubeForm::AssertValid() const
{
	CForm::AssertValid();
}

void CCryptCubeForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}

CCryptCubeDoc* CCryptCubeForm::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCryptCubeDoc)));
	return (CCryptCubeDoc*)m_pDocument;
}
#endif //_DEBUG


// CCryptCubeForm 消息处理程序



BOOL CCryptCubeForm::OnEraseBkgnd(CDC* pDC)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
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

//从PNG资源文件设置窗口背景
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