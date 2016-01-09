#pragma once


// KofMFCRibbonButton

  
//////////////////////////////////////////////////////////////////////////  
// CKofMFCRibbonButton  
  
class CKofMFCRibbonButton : public CMFCRibbonButton  
{  
    DECLARE_DYNAMIC(CKofMFCRibbonButton)  
  
public:  
    CKofMFCRibbonButton(); 

    CKofMFCRibbonButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex=-1, int nLargeImageIndex=-1, BOOL bAlwaysShowDescription=FALSE)
        :  CMFCRibbonButton(nID, lpszText, nSmallImageIndex, nLargeImageIndex, bAlwaysShowDescription)
    {}
    CKofMFCRibbonButton(UINT nID, LPCTSTR lpszText, HICON hIcon, BOOL bAlwaysShowDescription=FALSE, HICON hIconSmall=NULL, BOOL bAutoDestroyIcon=FALSE, BOOL bAlphaBlendIcon=FALSE)
        :  CMFCRibbonButton(nID, lpszText, hIcon, bAlwaysShowDescription, hIconSmall, bAutoDestroyIcon, bAlphaBlendIcon)
    {}
    virtual ~CKofMFCRibbonButton();  
  
protected:  
	virtual CSize GetRegularSize(CDC* pDC);
	virtual void OnCalcTextSize(CDC* pDC);
    virtual void OnDraw(CDC* pDC);
	CSize DrawBottomText(CDC* pDC, BOOL bCalcOnly);
};  