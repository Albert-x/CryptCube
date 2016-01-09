// Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "Form.h"


// CForm

IMPLEMENT_DYNCREATE(CForm, CFormView)

CForm::CForm(UINT nIDTemplate)
	: CFormView(nIDTemplate)
{

}

CForm::~CForm()
{
}

void CForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CForm, CFormView)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



// ������������ĵĿ�ݼ��޷���Ӧ������
BOOL CForm::PreTranslateMessage(MSG* pMsg)
{
	if(IsDialogMessage(pMsg)) return TRUE;
	return CFormView::PreTranslateMessage( pMsg );
}

void CForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

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

}


HBRUSH CForm::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{  
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);   
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
	//return(CFormView::OnCtlColor(pDC, pWnd, nCtlColor));
	return hbr;

}


BOOL CForm::OnEraseBkgnd(CDC* pDC)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CBrush backBrush(RGB(255, 255, 255));  //Ҫ���õ���ɫ
	//CBrush backBrush(RGB(226, 244, 254));  //Ҫ���õ���ɫ
    // ����ɻ�ˢ
    CBrush* pOldBrush = pDC->SelectObject(&backBrush);
    CRect rect;
    pDC->GetClipBox(&rect);     // ������Ҫ��������
    pDC->PatBlt(rect.left, rect.top, rect.Width(),
    rect.Height(), PATCOPY);
    pDC->SelectObject(pOldBrush);
    return TRUE;
    //return CFormView::OnEraseBkgnd(pDC);
}

BOOL CForm::PreCreateWindow(CREATESTRUCT& cs) 
{ 
    // TODO: �ڴ˴�ͨ���޸� 
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ 
    //cs.style &= ~WS_BORDER; /* ȥ����ͼ����Ч�� */ 

    return CFormView::PreCreateWindow(cs); 
} 