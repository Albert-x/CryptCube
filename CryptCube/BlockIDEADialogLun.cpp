// BlockIDEADialogLun.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockIDEADialogLun.h"


// CBlockIDEADialogLun 对话框

IMPLEMENT_DYNAMIC(CBlockIDEADialogLun, CMyDialog)

CBlockIDEADialogLun::CBlockIDEADialogLun(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockIDEADialogLun::IDD, pParent)
	, m_strX1(_T(""))
	, m_strPage(_T("1"))
{

}

CBlockIDEADialogLun::~CBlockIDEADialogLun()
{
}

void CBlockIDEADialogLun::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_strX1);
	DDX_Text(pDX, IDC_EDIT_X2, m_strX2);
	DDX_Text(pDX, IDC_EDIT_X3, m_strX3);
	DDX_Text(pDX, IDC_EDIT_X4, m_strX4);

	DDX_Text(pDX, IDC_EDIT_Z0, m_strZ0);
	DDX_Text(pDX, IDC_EDIT_Z1, m_strZ1);
	DDX_Text(pDX, IDC_EDIT_Z2, m_strZ2);
	DDX_Text(pDX, IDC_EDIT_Z3, m_strZ3);
	DDX_Text(pDX, IDC_EDIT_Z4, m_strZ4);
	DDX_Text(pDX, IDC_EDIT_Z5, m_strZ5);

	DDX_Text(pDX, IDC_EDIT_W11, m_strW11);
	DDX_Text(pDX, IDC_EDIT_W12, m_strW12);
	DDX_Text(pDX, IDC_EDIT_W13, m_strW13);
	DDX_Text(pDX, IDC_EDIT_W14, m_strW14);

	DDX_Text(pDX, IDC_EDIT_DES_PAGE, m_strPage);
	DDX_Control(pDX, IDC_SPIN_PAGE, m_spinPage);
}


BEGIN_MESSAGE_MAP(CBlockIDEADialogLun, CMyDialog)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_PREV2, &CBlockIDEADialogLun::OnBnClickedButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT2, &CBlockIDEADialogLun::OnBnClickedButtonNext)
	ON_EN_CHANGE(IDC_EDIT_DES_PAGE, &CBlockIDEADialogLun::OnEnChangeEditLunPage)
END_MESSAGE_MAP()



BOOL  CBlockIDEADialogLun::OnInitDialog()
{

	CMyDialog::OnInitDialog();

	ImageFromIDResource();
	m_spinPage.SetRange(1,8);
	m_strPage=_T("1");
	ShowLun(1);
	m_bInitControl= TRUE;
	return TRUE;
}


// CBlockIDEADialogLun 消息处理程序


void CBlockIDEADialogLun::ShowLun(int n = 1)
{
	if(m_pIDEA!=NULL)
	{

		m_strX1.Format(_T("%04X"), m_pIDEA->usLunX[n-1][0]);
		m_strX2.Format(_T("%04X"), m_pIDEA->usLunX[n-1][1]);
		m_strX3.Format(_T("%04X"), m_pIDEA->usLunX[n-1][2]);
		m_strX4.Format(_T("%04X"), m_pIDEA->usLunX[n-1][3]);

		m_strZ0.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][0]);
		m_strZ1.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][1]);
		m_strZ2.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][2]);
		m_strZ3.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][3]);
		m_strZ4.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][4]);
		m_strZ5.Format(_T("%04X"), m_pIDEA->usLunZ[n-1][5]);


		m_strW11.Format(_T("%04X"), m_pIDEA->usLunW[n-1][0]);
		m_strW12.Format(_T("%04X"), m_pIDEA->usLunW[n-1][1]);
		m_strW13.Format(_T("%04X"), m_pIDEA->usLunW[n-1][2]);
		m_strW14.Format(_T("%04X"), m_pIDEA->usLunW[n-1][3]);

		CString strTemp;

		
		if(1==n)
		{
			strTemp.Format(_T("X1"));
			GetDlgItem(IDC_STATIC_X1)->SetWindowText(strTemp);
			strTemp.Format(_T("X2"));
			GetDlgItem(IDC_STATIC_X2)->SetWindowText(strTemp);
			strTemp.Format(_T("X3"));
			GetDlgItem(IDC_STATIC_X3)->SetWindowText(strTemp);
			strTemp.Format(_T("X4"));
			GetDlgItem(IDC_STATIC_X4)->SetWindowText(strTemp);
		}
		else
		{
			strTemp.Format(_T("W%d1"),n-1);
			GetDlgItem(IDC_STATIC_X1)->SetWindowText(strTemp);
			strTemp.Format(_T("W%d2"),n-1);
			GetDlgItem(IDC_STATIC_X2)->SetWindowText(strTemp);
			strTemp.Format(_T("W%d3"),n-1);
			GetDlgItem(IDC_STATIC_X3)->SetWindowText(strTemp);
			strTemp.Format(_T("W%d4"),n-1);
			GetDlgItem(IDC_STATIC_X4)->SetWindowText(strTemp);
		}
		

		strTemp.Format(_T("Z%d"),0+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z0)->SetWindowText(strTemp);
		strTemp.Format(_T("Z%d"),1+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z1)->SetWindowText(strTemp);
		strTemp.Format(_T("Z%d"),2+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z2)->SetWindowText(strTemp);
		strTemp.Format(_T("Z%d"),3+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z3)->SetWindowText(strTemp);
		strTemp.Format(_T("Z%d"),4+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z4)->SetWindowText(strTemp);
		strTemp.Format(_T("Z%d"),5+(n-1)*6);
		GetDlgItem(IDC_STATIC_Z5)->SetWindowText(strTemp);

		strTemp.Format(_T("W%d1"),n);
		GetDlgItem(IDC_STATIC_W11)->SetWindowText(strTemp);
		strTemp.Format(_T("W%d2"),n);
		GetDlgItem(IDC_STATIC_W12)->SetWindowText(strTemp);
		strTemp.Format(_T("W%d3"),n);
		GetDlgItem(IDC_STATIC_W13)->SetWindowText(strTemp);
		strTemp.Format(_T("W%d4"),n);
		GetDlgItem(IDC_STATIC_W14)->SetWindowText(strTemp);

		UpdateData(FALSE);

	}

}

BOOL CBlockIDEADialogLun::OnEraseBkgnd(CDC* pDC)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

	CMyDialog::OnEraseBkgnd(pDC);

    CRect rect;
	GetClientRect( &rect ) ;
	CRect imageRect ;

	imageRect.left = 30 ;
	imageRect.top = 17 ; 
	imageRect.bottom = imageRect.top + m_Image.GetHeight() ;
	imageRect.right = imageRect.left + m_Image.GetWidth() ;

	m_Image.Draw(  pDC->m_hDC,  imageRect ) ;
    return TRUE;

}

//从PNG资源文件设置窗口背景
BOOL CBlockIDEADialogLun::ImageFromIDResource()
{

	UINT nID = IDP_IDEA1;
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
void CBlockIDEADialogLun::OnBnClickedButtonPrev()
{
	UpdateData(TRUE);
	if(_ttoi(m_strPage)>1) m_strPage.Format(_T("%d"),_ttoi(m_strPage)-1);
		else m_strPage.Format(_T("%d"),8);

	UpdateData(FALSE);
	OnEnChangeEditLunPage();
}

void CBlockIDEADialogLun::OnBnClickedButtonNext()
{
	UpdateData(TRUE);
	if(_ttoi(m_strPage)<8) m_strPage.Format(_T("%d"),_ttoi(m_strPage)+1);
		else m_strPage.Format(_T("%d"),1);
	UpdateData(FALSE);
	OnEnChangeEditLunPage();
}

void CBlockIDEADialogLun::OnEnChangeEditLunPage()
{
	if(TRUE == m_bInitControl)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strPage);

		if(nLun > 9)
		{
			nLun = 9;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strPage.Format(_T("%d"), nLun);
		UpdateData(FALSE);

	ShowLun(nLun);

	}
}
