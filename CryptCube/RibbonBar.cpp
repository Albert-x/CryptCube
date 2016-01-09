// KofMFCRibbonBar.cpp : 实现文件
//

#include "stdafx.h"  
#include "RibbonBar.h"  
#include "MainFrm.h"
#include "resource.h"
static const int nXTabMargin = 14;  
static const int nYTabMargin = 5;  
  
static const int nXMargin = 2;  
static const int nYMargin = 2;  
//////////////////////////////////////////////////////////////////////////  
// CKofMFCRibbonBar  
  
IMPLEMENT_DYNAMIC(CKofMFCRibbonBar, CMFCRibbonBar)  
  
CKofMFCRibbonBar::CKofMFCRibbonBar(BOOL bReplaceFrameCaption /*= TRUE*/)  
: CMFCRibbonBar(bReplaceFrameCaption)  
{  
}  
  
CKofMFCRibbonBar::~CKofMFCRibbonBar()  
{  
}  
  
BEGIN_MESSAGE_MAP(CKofMFCRibbonBar, CMFCRibbonBar)  
	ON_WM_CONTEXTMENU()
	ON_WM_LBUTTONDBLCLK()
	
END_MESSAGE_MAP()  
  


void  CKofMFCRibbonBar::OnContextMenu(CWnd* pWnd, CPoint pos) 
{
	
}
void  CKofMFCRibbonBar::OnLButtonDblClk(UINT uINT, CPoint pos) 
{
}

CSize CKofMFCRibbonBar::CalcFixedLayout( BOOL bStretch, BOOL bHorz )  
{  
    ASSERT_VALID(this);  
  
    CClientDC dc(this);  
  
    CFont* pOldFont = dc.SelectObject(GetFont());  
    ENSURE(pOldFont != NULL);  
  
    TEXTMETRIC tm;  
    dc.GetTextMetrics(&tm);  
  
    //“标题”的高度  
    m_nCaptionHeight = 0;  
  
    if (m_bReplaceFrameCaption)  
    {  
        m_nCaptionHeight = GetSystemMetrics(SM_CYCAPTION) + 1;  
  
		if (afxGlobalData.IsDwmCompositionEnabled())
        {  
            m_nCaptionHeight += GetSystemMetrics(SM_CYSIZEFRAME);  
        }  
    }  
  
    int cy = 0;  
  
    CSize sizeMainButton = m_sizeMainButton;  
    double scale = afxGlobalData.GetRibbonImageScale();  
    if (scale > 1.)  
    {  
        sizeMainButton.cx = (int)(.5 + scale * sizeMainButton.cx);  
        sizeMainButton.cy = (int)(.5 + scale * sizeMainButton.cy);  
    }  
  
    if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL)  
    {  
        cy = m_nCaptionHeight;  
    }  
    else  
    {  
        if (m_bRecalcCategoryHeight)  
        {  
            m_nCategoryHeight = 0;  
        }  
  
        //“选项卡”的高度  
        m_nTabsHeight = tm.tmHeight + 2 * nYTabMargin;  
  
        if (m_bRecalcCategoryHeight)  
        {  
            for (int i = 0; i < m_arCategories.GetSize(); i++)  
            {  
                CMFCRibbonCategory* pCategory = m_arCategories [i];  
                ASSERT_VALID(pCategory);  
  
				//////////////////////////////////////////////////////////////////////////////////// 
                m_nCategoryHeight = max(m_nCategoryHeight, pCategory->GetMaxHeight(&dc))-75;  
				////////////////////////////////////////////////////////////////////////////////////
            }  
            m_bRecalcCategoryHeight = FALSE;  
        }  
  
        CKofMFCRibbonQuickAccessToolBar *pQAToolbar = (CKofMFCRibbonQuickAccessToolBar *)&m_QAToolbar;

        const CSize sizeAQToolbar = pQAToolbar->GetRegularSize(&dc);  
  
        if (IsQuickAccessToolbarOnTop())  
        {  
            m_nCaptionHeight = max(m_nCaptionHeight, sizeAQToolbar.cy + (TRUE ? 0 : (2 * nYMargin)));  
        }  
  
        //“快速访问工具栏”的高度  
        const int nQuickAceesToolbarHeight = IsQuickAccessToolbarOnTop() ? 0 : sizeAQToolbar.cy;  
        //“分类”的高度  
		////////////////////////////////////////////////////////////////////////////////////
        const int nCategoryHeight = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) ? 0 : m_nCategoryHeight;  
		////////////////////////////////////////////////////////////////////////////////////
  
        cy = nQuickAceesToolbarHeight + nCategoryHeight + max( m_nCaptionHeight + m_nTabsHeight, m_sizeMainButton.cy + nYMargin);  
    }  
  
    if (afxGlobalData.IsDwmCompositionEnabled())  
    {  
        if (GetParent()->IsZoomed() && m_bReplaceFrameCaption)  
        {  
            cy += ::GetSystemMetrics(SM_CYSIZEFRAME) - 2;  
        }  
    }  
  
    dc.SelectObject(pOldFont);  

	

    return CSize(32767, cy);  
}  