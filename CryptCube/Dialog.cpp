// Form.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "Dialog.h"


// CMyDialog

IMPLEMENT_DYNCREATE(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(UINT nIDTemplate, CWnd *pParent)
	: CDialogEx(nIDTemplate, pParent)
{
	
	SetBackgroundColor(RGB(255,255,255));

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


BOOL CMyDialog::OnInitDialog() 
{
	CDialogEx::OnInitDialog();

	OSVERSIONINFOEX os; 

	os.dwOSVersionInfoSize=sizeof(OSVERSIONINFOEX);   
	GetVersionEx((OSVERSIONINFO *)&os);
	if(os.dwPlatformId==VER_PLATFORM_WIN32_NT && os.dwMajorVersion >=5)
	{

	CFont *pFont = new CFont;
	pFont->CreatePointFont(100, _T("微软雅黑"));
	SetFont(pFont);
	CWnd *pWnd   = GetWindow(GW_CHILD);
	while(pWnd   != NULL)
	{
		pWnd-> SetFont(pFont);
		pWnd = pWnd-> GetWindow(GW_HWNDNEXT);
	}
	}

	return TRUE;
}



HBRUSH CMyDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{  
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);   

	switch (nCtlColor)
	{   
	case CTLCOLOR_BTN://按钮？
	case CTLCOLOR_STATIC://我们所需要改画的静态
		{  static   HBRUSH   hbrEdit = ::CreateSolidBrush(RGB(255,255,255));   //设置背景色
		//设置文字的背景色，否则与最初的相同，注意不是和背景色相同
		pDC->SetBkColor(RGB(255,255,255));         
		        
		pDC->SetTextColor(RGB(55, 55, 55));   //设置文字的颜色
		return   hbrEdit;        
		}
	case CTLCOLOR_DLG:
		{
			CBrush*     back_brush;
			COLORREF    color;
			color = (COLORREF) GetSysColor(COLOR_BTNFACE);
			back_brush = new CBrush(color);
			return (HBRUSH) (back_brush->m_hObject);
		}
	}
	//return(CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor));
	return hbr;
}



BOOL CMyDialog::PreCreateWindow(CREATESTRUCT& cs) 
{ 
    // TODO: 在此处通过修改 
    //  CREATESTRUCT cs 来修改窗口类或样式 
    cs.style &= ~WS_BORDER; /* 去除视图凹陷效果 */ 

    return CDialogEx::PreCreateWindow(cs); 
} 