// Form.cpp : 实现文件
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



// 解决单行输入框的的快捷键无法响应的问题
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
	pFont->CreatePointFont(100, _T("微软雅黑"));
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
	//return(CFormView::OnCtlColor(pDC, pWnd, nCtlColor));
	return hbr;

}


BOOL CForm::OnEraseBkgnd(CDC* pDC)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    CBrush backBrush(RGB(255, 255, 255));  //要设置的颜色
	//CBrush backBrush(RGB(226, 244, 254));  //要设置的颜色
    // 保存旧画刷
    CBrush* pOldBrush = pDC->SelectObject(&backBrush);
    CRect rect;
    pDC->GetClipBox(&rect);     // 擦掉所要画的区域
    pDC->PatBlt(rect.left, rect.top, rect.Width(),
    rect.Height(), PATCOPY);
    pDC->SelectObject(pOldBrush);
    return TRUE;
    //return CFormView::OnEraseBkgnd(pDC);
}

BOOL CForm::PreCreateWindow(CREATESTRUCT& cs) 
{ 
    // TODO: 在此处通过修改 
    //  CREATESTRUCT cs 来修改窗口类或样式 
    //cs.style &= ~WS_BORDER; /* 去除视图凹陷效果 */ 

    return CFormView::PreCreateWindow(cs); 
} 