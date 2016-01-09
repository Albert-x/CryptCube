// Form.cpp : ʵ���ļ�
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
	pFont->CreatePointFont(100, _T("΢���ź�"));
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
	case CTLCOLOR_BTN://��ť��
	case CTLCOLOR_STATIC://��������Ҫ�Ļ��ľ�̬
		{  static   HBRUSH   hbrEdit = ::CreateSolidBrush(RGB(255,255,255));   //���ñ���ɫ
		//�������ֵı���ɫ���������������ͬ��ע�ⲻ�Ǻͱ���ɫ��ͬ
		pDC->SetBkColor(RGB(255,255,255));         
		        
		pDC->SetTextColor(RGB(55, 55, 55));   //�������ֵ���ɫ
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
    // TODO: �ڴ˴�ͨ���޸� 
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ 
    cs.style &= ~WS_BORDER; /* ȥ����ͼ����Ч�� */ 

    return CDialogEx::PreCreateWindow(cs); 
} 