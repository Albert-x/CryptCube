#pragma once


// KofMFCRibbonBar

class CKofMFCRibbonQuickAccessToolBar : public CMFCRibbonQuickAccessToolBar  
{  
    friend class CKofMFCRibbonBar;  
};  
  
//////////////////////////////////////////////////////////////////////////  
// CKofMFCRibbonBar  
  
class CKofMFCRibbonBar : public CMFCRibbonBar  
{  
    DECLARE_DYNAMIC(CKofMFCRibbonBar)  
  
public:  
    CKofMFCRibbonBar(BOOL bReplaceFrameCaption = TRUE);  
    virtual ~CKofMFCRibbonBar();  
  
protected:  
    virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);  
    DECLARE_MESSAGE_MAP()  
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pos) ;
	afx_msg void OnLButtonDblClk(UINT uINT, CPoint pos) ;
	//afx_msg void OnLButtonDown(UINT uINT, CPoint pos);
};  