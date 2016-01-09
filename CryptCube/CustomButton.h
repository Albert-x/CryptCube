#pragma once

#include "Form.h"
// CCustomButton

class CCustomButton : public CButton
{
	DECLARE_DYNAMIC(CCustomButton)

public:
	CCustomButton();
	virtual ~CCustomButton();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	BOOL m_IsPressed;
protected:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};


