// BlockIDEADialogZuihou.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockIDEADialogZuihou.h"


// CBlockIDEADialogZuihou 对话框

IMPLEMENT_DYNAMIC(CBlockIDEADialogZuihou, CMyDialog)

CBlockIDEADialogZuihou::CBlockIDEADialogZuihou(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockIDEADialogZuihou::IDD, pParent)
{

}

CBlockIDEADialogZuihou::~CBlockIDEADialogZuihou()
{
}

void CBlockIDEADialogZuihou::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_W81, m_strW81);
	DDX_Text(pDX, IDC_EDIT_W82, m_strW82);
	DDX_Text(pDX, IDC_EDIT_W83, m_strW83);
	DDX_Text(pDX, IDC_EDIT_W84, m_strW84);

	DDX_Text(pDX, IDC_EDIT_Z48, m_strZ48);
	DDX_Text(pDX, IDC_EDIT_Z49, m_strZ49);
	DDX_Text(pDX, IDC_EDIT_Z50, m_strZ50);
	DDX_Text(pDX, IDC_EDIT_Z51, m_strZ51);


	DDX_Text(pDX, IDC_EDIT_Y1, m_strY1);
	DDX_Text(pDX, IDC_EDIT_Y2, m_strY2);
	DDX_Text(pDX, IDC_EDIT_Y3, m_strY3);
	DDX_Text(pDX, IDC_EDIT_Y4, m_strY4);

}


BEGIN_MESSAGE_MAP(CBlockIDEADialogZuihou, CMyDialog)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDOK, &CBlockIDEADialogZuihou::OnBnClickedOk)
END_MESSAGE_MAP()




BOOL CBlockIDEADialogZuihou::OnInitDialog()
{

	CMyDialog::OnInitDialog();

	ImageFromIDResource();
	if(m_pIDEA!=NULL)
	{

		m_strW81.Format(_T("%04X"), m_pIDEA->usZuihouW[0]);
		m_strW82.Format(_T("%04X"), m_pIDEA->usZuihouW[1]);
		m_strW83.Format(_T("%04X"), m_pIDEA->usZuihouW[2]);
		m_strW84.Format(_T("%04X"), m_pIDEA->usZuihouW[3]);

		m_strZ48.Format(_T("%04X"), m_pIDEA->usZuihouZ[0]);
		m_strZ49.Format(_T("%04X"), m_pIDEA->usZuihouZ[1]);
		m_strZ50.Format(_T("%04X"), m_pIDEA->usZuihouZ[2]);
		m_strZ51.Format(_T("%04X"), m_pIDEA->usZuihouZ[3]);

		m_strY1.Format(_T("%04X"), m_pIDEA->usZuihouY[0]);
		m_strY2.Format(_T("%04X"), m_pIDEA->usZuihouY[1]);
		m_strY3.Format(_T("%04X"), m_pIDEA->usZuihouY[2]);
		m_strY4.Format(_T("%04X"), m_pIDEA->usZuihouY[3]);

		UpdateData(FALSE);
	}
	return TRUE;
}



// CBlockIDEADialogZuihou 消息处理程序
BOOL CBlockIDEADialogZuihou::OnEraseBkgnd(CDC* pDC)
{
	CMyDialog::OnEraseBkgnd(pDC);

    CRect rect;
	GetClientRect( &rect ) ;
	CRect imageRect ;

	imageRect.left = 80 ;
	imageRect.top = 60 ; 
	imageRect.bottom = imageRect.top + m_Image.GetHeight() ;
	imageRect.right = imageRect.left + m_Image.GetWidth() ;

	m_Image.Draw(  pDC->m_hDC,  imageRect ) ;
    return TRUE;

}

//从PNG资源文件设置窗口背景
BOOL CBlockIDEADialogZuihou::ImageFromIDResource()
{

	UINT nID = IDP_IDEA2;
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


void CBlockIDEADialogZuihou::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
}
