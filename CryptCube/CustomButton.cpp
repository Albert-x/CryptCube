// CustomButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CustomButton.h"


// CCustomButton

IMPLEMENT_DYNAMIC(CCustomButton, CButton)

CCustomButton::CCustomButton()
{
	m_IsPressed = FALSE;
}

CCustomButton::~CCustomButton()
{
}


BEGIN_MESSAGE_MAP(CCustomButton, CButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CCustomButton ��Ϣ�������


void CCustomButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CRect rect;
	GetClientRect(rect);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	//���ñ���͸��
	dc.SetBkMode(TRANSPARENT);
	//����һ��λͼ��ˢ
	CBrush m_Brush;									//������ˢ����
	m_Brush.CreateStockObject(NULL_BRUSH);				//������ˢ
	dc.SelectObject(&m_Brush);
	if(m_IsPressed)
	{
		CPen pen(PS_SOLID,2,RGB(255,0,0));
		dc.SelectObject(&pen);
		//����λͼ��С���ð�ť��ʾ����
		HRGN h_rgn = CreateEllipticRgn(0,0,rect.Width(),rect.Height()); 
		SetWindowRgn(h_rgn,true);
		dc.Ellipse(0,0,rect.Width(),rect.Height());
		dc.SetTextColor(RGB(255,255,0));
	}
	else
	{
		CPen pen(PS_SOLID,2,RGB(255,255,255));
		dc.SelectObject(&pen);
		//����λͼ��С���ð�ť��ʾ����
		HRGN h_rgn = CreateEllipticRgn(0,0,rect.Width(),rect.Height()); 
		SetWindowRgn(h_rgn,true);
		dc.Ellipse(0,0,rect.Width(),rect.Height());
		dc.SetTextColor(RGB(255,255,0));
	}
	//���ư�ť�ı�
	CString str;
	GetWindowText(str);
	dc.DrawText(str,CRect(0,0,rect.right,rect.bottom),
		DT_CENTER|DT_VCENTER|DT_SINGLELINE);	
	dc.DeleteDC();
}

void CCustomButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_IsPressed = TRUE;
	CButton::OnLButtonDown(nFlags, point);
}


void CCustomButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_IsPressed = FALSE;
	CButton::OnLButtonUp(nFlags, point);
}

BOOL CCustomButton::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default

	return true;//CButton::OnEraseBkgnd(pDC);
}
