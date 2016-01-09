// KofMFCRibbonButton.cpp : 实现文件
//

#include "stdafx.h"  
#include "RibbonButton.h"  
  
const int nLargeButtonMarginX = 5;
const int nLargeButtonMarginY = 1;

const int nSmallButtonMarginX = 3;
const int nSmallButtonMarginY = 3;

const int nDefaultPaneButtonMargin = 2;
//////////////////////////////////////////////////////////////////////////  
// CKofMFCRibbonButton  
  
IMPLEMENT_DYNAMIC(CKofMFCRibbonButton, CMFCRibbonButton)  
  
CKofMFCRibbonButton::CKofMFCRibbonButton()  
: CMFCRibbonButton()  
{  
}  
  
CKofMFCRibbonButton::~CKofMFCRibbonButton()  
{  
}  
  

CSize CKofMFCRibbonButton::GetRegularSize(CDC* pDC)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arSubItems.GetSize(); i++)
	{
		ASSERT_VALID(m_arSubItems [i]);
		m_arSubItems [i]->SetParentCategory(m_pParent);
	}

	if (m_bQuickAccessMode || m_bFloatyMode)
	{
		return GetCompactSize(pDC);
	}

	if (!HasLargeMode())
	{
		return GetIntermediateSize(pDC);
	}

	CSize sizeImageLarge = GetImageSize(RibbonImageLarge);
	CSize sizeImageSmall = GetImageSize(RibbonImageSmall);

	if (IsApplicationButton())
	{
		return sizeImageLarge;
	}

	const int cxExtra = GetGroupButtonExtraWidth();

	if (sizeImageLarge == CSize(0, 0) || m_bTextAlwaysOnRight)
	{
		if (m_bTextAlwaysOnRight && sizeImageLarge != CSize(0, 0))
		{
			sizeImageSmall = CSize(sizeImageLarge.cx + 2, sizeImageLarge.cy + 2);
			m_szMargin.cy = 5;
		}

		int cx = sizeImageSmall.cx + 2 * m_szMargin.cx;

		if (m_sizeTextRight.cx > 0)
		{
			cx += m_szMargin.cx + m_sizeTextRight.cx;
		}

		int cy = max(sizeImageSmall.cy, m_sizeTextRight.cy) + 2 * m_szMargin.cy;

		if (sizeImageSmall.cy == 0)
		{
			cy += 2 * m_szMargin.cy;
		}

		if (HasMenu())
		{
			cx += GetDropDownImageWidth();

			if (m_bIsDefaultCommand && m_nID != -1 && m_nID != 0 && m_sizeTextRight.cx > 0)
			{
				cx += m_nMenuArrowMargin;
			}
		}

		if (IsDefaultMenuLook() && !IsQATMode())
		{
			cx += 2 * AFX_TEXT_MARGIN;
		}

		return CSize(cx + cxExtra, cy);
	}

	SetMargin(CSize(nLargeButtonMarginX, nLargeButtonMarginY));

	if (IsDefaultPanelButton())
	{
		sizeImageLarge.cx += 2 *(m_szMargin.cx + 1);
	}

	int cx = max(sizeImageLarge.cx + 2 * m_szMargin.cx, m_sizeTextBottom.cx + 5);

	if (IsDefaultPanelButton())
	{
		cx += nDefaultPaneButtonMargin;
	}

	if (IsDefaultMenuLook())
	{
		cx += 2 * AFX_TEXT_MARGIN;
	}

	const int cyText = max(m_sizeTextBottom.cy, sizeImageLarge.cy + 1);
	const int cy = sizeImageLarge.cy + cyText + 1;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	return CSize(cx + cxExtra + 3, cy - 12);
	///////////////////////////////////////////////////////////////////////////////////////////////////
}


void CKofMFCRibbonButton::OnCalcTextSize(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_strText.IsEmpty() || IsApplicationButton())
	{
		m_sizeTextRight = CSize(0, 0);
		m_sizeTextBottom = CSize(0, 0);
		return;
	}

	if (m_sizeTextRight != CSize(0, 0) && m_sizeTextBottom != CSize(0, 0))
	{
		// Already calculated
		return;
	}

	// Text placed on right will be always single line:

	const CString strDummyAmpSeq = _T("\001\001");
	CString strText = m_strText;
	strText.Replace(_T("&&"), strDummyAmpSeq);
	strText.Remove(_T('&'));
	strText.Replace(strDummyAmpSeq, _T("&"));

	if (m_bAlwaysShowDescription && !m_strDescription.IsEmpty())
	{
		CFont* pOldFont = pDC->SelectObject(&afxGlobalData.fontBold);
		ENSURE(pOldFont != NULL);

		m_sizeTextRight = pDC->GetTextExtent(strText);

		pDC->SelectObject(pOldFont);

		// Desciption will be draw below the text(in case of text on right only)
		int nTextHeight = 0;
		int nTextWidth = 0;

		strText = m_strDescription;

		for (int dx = m_sizeTextRight.cx; dx < m_sizeTextRight.cx * 10; dx += 10)
		{
			CRect rectText(0, 0, dx, 10000);

			nTextHeight = pDC->DrawText(strText, rectText, DT_WORDBREAK | DT_CALCRECT);

			nTextWidth = rectText.Width();

			if (nTextHeight <= 2 * m_sizeTextRight.cy)
			{
				break;
			}
		}

		m_sizeTextRight.cx = max(m_sizeTextRight.cx, nTextWidth);
		m_sizeTextRight.cy += min(2 * m_sizeTextRight.cy, nTextHeight) + 2 * m_szMargin.cy;
	}
	else
	{
		// Text placed on right will be always single line:
		m_sizeTextRight = pDC->GetTextExtent(strText);
	}

	CSize sizeImageLarge = GetImageSize(RibbonImageLarge);

	if (sizeImageLarge == CSize(0, 0))
	{
		m_sizeTextBottom = CSize(0, 0);
	}
	else
	{
		// Text placed on bottom will occupy large image size and 1-2 text rows:
		m_sizeTextBottom = DrawBottomText(pDC, TRUE /*bCalcOnly*/);
	}
}



void CKofMFCRibbonButton::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	

	BOOL bIsDisabled = m_bIsDisabled;
	BOOL bIsDroppedDown = m_bIsDroppedDown;
	BOOL bIsHighlighted = m_bIsHighlighted;
	BOOL bMenuHighlighted = m_bIsMenuHighlighted;
	BOOL bCommandHighlighted = m_bIsCommandHighlighted;

	const int cxDropDown = GetDropDownImageWidth();

	if (m_bIsDisabled && HasMenu())
	{
		if (m_bIsDefaultCommand || (!m_bIsDefaultCommand && !(m_nID == 0 || m_nID == (UINT)-1)))
		{
			m_bIsHighlighted = FALSE;
		}
		else
		{
			m_bIsDisabled = FALSE;
		}
	}

	if (m_bToBeClosed)
	{
		m_bIsDroppedDown = FALSE;
	}

	if (m_bIsFocused)
	{
		m_bIsHighlighted = TRUE;
		m_bIsMenuHighlighted = TRUE;
		m_bIsCommandHighlighted = TRUE;
	}

	CRect rectMenuArrow;
	rectMenuArrow.SetRectEmpty();

	if (HasMenu())
	{
		rectMenuArrow = m_rect;

		rectMenuArrow.left = rectMenuArrow.right - cxDropDown - m_nMenuArrowMargin;
		if (m_sizeTextRight.cx == 0 && !m_bQuickAccessMode)
		{
			rectMenuArrow.left -= 2;
		}

		rectMenuArrow.bottom -= m_nMenuArrowMargin;

		if (m_bIsDefaultCommand)
		{
			m_rectMenu = m_rect;

			m_rectMenu.left = m_rectMenu.right - cxDropDown - m_nMenuArrowMargin - 1;

			m_rectCommand = m_rect;
			m_rectCommand.right = m_rectMenu.left;

			m_bMenuOnBottom = FALSE;
		}
	}

	CSize sizeImageLarge = GetImageSize(RibbonImageLarge);
	CSize sizeImageSmall = GetImageSize(RibbonImageSmall);

	CRect rectText = m_rect;
	BOOL bDrawText = !IsApplicationButton() && !m_bQuickAccessMode && !m_bFloatyMode;

	if (m_bQuickAccessMode || m_bFloatyMode)
	{
		bDrawText = FALSE;
	}
	else if (m_bCompactMode)
	{
		bDrawText = FALSE;
	}
	else if (sizeImageLarge != CSize(0, 0) && !m_bMenuOnBottom && m_bIsLargeImage)
	{
		if (!m_rectMenu.IsRectEmpty())
		{
			m_rectMenu.left -= cxDropDown;
			m_rectCommand.right = m_rectMenu.left;
		}

		rectMenuArrow.OffsetRect(-cxDropDown / 2, 0);
	}

	const RibbonImageType imageType = m_bIsLargeImage ? RibbonImageLarge : RibbonImageSmall;

	CSize sizeImage = GetImageSize(imageType);
	BOOL bDrawDefaultImage = FALSE;

	if ((m_bQuickAccessMode || m_bFloatyMode) && sizeImage == CSize(0, 0))
	{
		// Use default image:
		sizeImage = CSize(16, 16);

		if (afxGlobalData.GetRibbonImageScale() != 1.)
		{
			sizeImage.cx = (int)(.5 + afxGlobalData.GetRibbonImageScale() * sizeImage.cx);
			sizeImage.cy = (int)(.5 + afxGlobalData.GetRibbonImageScale() * sizeImage.cy);
		}

		bDrawDefaultImage = TRUE;
	}

	CRect rectImage = m_rect;
	rectImage.DeflateRect(m_szMargin);

	if (IsApplicationButton())
	{
		rectImage.left += (rectImage.Width () - sizeImage.cx) / 2;
		rectImage.top  += (rectImage.Height () - sizeImage.cy) / 2;
	}
	else if (m_bIsLargeImage && !m_bTextAlwaysOnRight)
	{
		rectImage.left = rectImage.CenterPoint().x - sizeImage.cx / 2;
		rectImage.top += m_szMargin.cy + 1;

		if (!bDrawText)
		{
			rectImage.top = rectImage.CenterPoint().y - sizeImage.cy / 2;
		}
	}
	else
	{
		rectImage.top = rectImage.CenterPoint().y - sizeImage.cy / 2;
	}

	rectImage.right = rectImage.left + sizeImage.cx;
	rectImage.bottom = rectImage.top + sizeImage.cy;

	if (m_bIsLargeImage && !m_bTextAlwaysOnRight && HasMenu() && m_bIsDefaultCommand)
	{
		m_rectMenu = m_rect;
		m_rectMenu.top = rectImage.bottom + 3;

		m_rectCommand = m_rect;
		m_rectCommand.bottom = m_rectMenu.top;

		m_bMenuOnBottom = TRUE;
	}

	COLORREF clrText = (COLORREF)-1;

	if (!IsApplicationButton())
	{
		clrText = OnFillBackground(pDC);
	}

	if (IsMenuMode() && IsChecked() && sizeImage != CSize(0, 0))
	{
		CMFCVisualManager::GetInstance()->OnDrawRibbonMenuCheckFrame(pDC, this, rectImage);
	}

	//------------
	// Draw image:
	//------------
	if (bDrawDefaultImage)
	{
		CMFCVisualManager::GetInstance()->OnDrawDefaultRibbonImage(pDC, rectImage, m_bIsDisabled, m_bIsPressed, m_bIsHighlighted);
	}
	else
	{
		BOOL bIsRibbonImageScale = afxGlobalData.IsRibbonImageScaleEnabled();

		if (IsMenuMode() && !m_bIsLargeImage)
		{
			if (m_pParentMenu == NULL || !m_pParentMenu->IsMainPanel())
			{
				afxGlobalData.EnableRibbonImageScale(FALSE);
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////
		rectImage.top +=7;
		///////////////////////////////////////////////////////////////////////////////////////////////////
		DrawImage(pDC, imageType, rectImage);
		afxGlobalData.EnableRibbonImageScale(bIsRibbonImageScale);
	}

	//-----------
	// Draw text:
	//-----------
	if (bDrawText)
	{
		CFont* pOldFont = NULL;

		rectText = m_rect;
		UINT uiDTFlags = 0;

		COLORREF clrTextOld = (COLORREF)-1;

		if (bIsDisabled && (m_bIsDefaultCommand || (!m_bIsDefaultCommand && !(m_nID == 0 || m_nID == (UINT)-1))))
		{
			if (m_bQuickAccessMode)
			{
				clrText = CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarTextColor(TRUE);
			}
			else
			{
				clrTextOld = pDC->SetTextColor( clrText == (COLORREF)-1 ? CMFCVisualManager::GetInstance()->GetToolbarDisabledTextColor() : clrText);
			}
		}
		else if (clrText != (COLORREF)-1)
		{
			clrTextOld = pDC->SetTextColor(clrText);
		}

		if (m_bIsLargeImage && !m_bTextAlwaysOnRight)
		{
			DrawBottomText(pDC, FALSE);
			rectMenuArrow.SetRectEmpty();
		}
		else
		{
			rectText.left = rectImage.right;

			if (m_nImageOffset > 0)
			{
				rectText.left = m_rect.left + m_nImageOffset + 3 * m_szMargin.cx;
			}
			else if (sizeImage.cx != 0)
			{
				rectText.left += GetTextOffset();
			}

			uiDTFlags = DT_SINGLELINE | DT_END_ELLIPSIS;



			if (!m_bAlwaysShowDescription || m_strDescription.IsEmpty())
			{
				uiDTFlags |= DT_VCENTER;
			}
			else
			{
				pOldFont = pDC->SelectObject(&afxGlobalData.fontBold);
				ENSURE(pOldFont != NULL);

				rectText.top += max(0, (m_rect.Height() - m_sizeTextRight.cy) / 2);
			}

			int nTextHeight = DrawRibbonText(pDC, m_strText, rectText, uiDTFlags);

			if (pOldFont != NULL)
			{
				pDC->SelectObject(pOldFont);
			}

			if (m_bAlwaysShowDescription && !m_strDescription.IsEmpty())
			{
				rectText.top += nTextHeight + m_szMargin.cy;
				rectText.right = m_rect.right - m_szMargin.cx;

				pDC->DrawText(m_strDescription, rectText, DT_WORDBREAK | DT_END_ELLIPSIS);
			}

			if (nTextHeight == m_sizeTextRight.cy && m_bIsLargeImage && HasMenu())
			{
				rectMenuArrow = m_rect;
				rectMenuArrow.DeflateRect(m_nMenuArrowMargin, m_nMenuArrowMargin * 2);
				rectMenuArrow.right -= 2;

				int cyMenu = CMenuImages::Size().cy;

				if (afxGlobalData.GetRibbonImageScale() > 1.)
				{
					cyMenu = (int)(.5 + afxGlobalData.GetRibbonImageScale() * cyMenu);
				}

				rectMenuArrow.top = rectMenuArrow.bottom - cyMenu;
				rectMenuArrow.bottom = rectMenuArrow.top + CMenuImages::Size().cy;
			}
		}

		if (clrTextOld != (COLORREF)-1)
		{
			pDC->SetTextColor(clrTextOld);
		}
	}

	if (!IsApplicationButton())
	{
		if (!rectMenuArrow.IsRectEmpty())
		{
			CMenuImages::IMAGES_IDS id = afxGlobalData.GetRibbonImageScale() > 1. ? CMenuImages::IdArrowDownLarge : CMenuImages::IdArrowDown;

			if (IsMenuMode())
			{
				BOOL bIsRTL = FALSE;

				CMFCRibbonBar* pTopLevelRibbon = GetTopLevelRibbonBar();
				if (pTopLevelRibbon->GetSafeHwnd() != NULL)
				{
					bIsRTL = (pTopLevelRibbon->GetExStyle() & WS_EX_LAYOUTRTL);
				}

				id = bIsRTL ? CMenuImages::IdArrowLeftLarge : CMenuImages::IdArrowRightLarge;
			}

			CRect rectWhite = rectMenuArrow;
			rectWhite.OffsetRect(0, 1);

			CMenuImages::Draw(pDC, id, rectWhite, CMenuImages::ImageWhite);
			CMenuImages::Draw(pDC, id, rectMenuArrow, m_bIsDisabled ? CMenuImages::ImageGray : CMenuImages::ImageBlack);
		}

		OnDrawBorder(pDC);
	}

	m_bIsDisabled = bIsDisabled;
	m_bIsDroppedDown = bIsDroppedDown;
	m_bIsHighlighted = bIsHighlighted;
	m_bIsMenuHighlighted = bMenuHighlighted;
	m_bIsCommandHighlighted = bCommandHighlighted;
}





CSize CKofMFCRibbonButton::DrawBottomText(CDC* pDC, BOOL bCalcOnly)
{
	ASSERT_VALID(this);

	if (m_pParent == NULL)
	{
		return CSize(0, 0);
	}

	if (m_strText.IsEmpty())
	{
		return CSize(0, 0);
	}

	ASSERT_VALID(m_pParent);

	const CSize sizeImageLarge = m_pParent->GetImageSize(TRUE);
	if (sizeImageLarge == CSize(0, 0))
	{
		ASSERT(FALSE);
		return CSize(0, 0);
	}

	CSize sizeText = pDC->GetTextExtent(m_strText);

	const int nTextLineHeight = sizeText.cy;
	int nMenuArrowWidth = (HasMenu() || IsDefaultPanelButton()) ?(CMenuImages::Size().cx) : 0;

	if (nMenuArrowWidth != NULL && afxGlobalData.GetRibbonImageScale() > 1.)
	{
		nMenuArrowWidth = (int)(.5 + afxGlobalData.GetRibbonImageScale() * nMenuArrowWidth);
	}

	if (bCalcOnly)
	{
		const CString strDummyAmpSeq = _T("\001\001");

		m_nWrapIndex = -1;
		int nTextWidth = 0;

		if (m_arWordIndexes.GetSize() == 0) // 1 word
		{
			nTextWidth = sizeText.cx;
		}
		else
		{
			nTextWidth = 32767;

			for (int i = 0; i < m_arWordIndexes.GetSize(); i++)
			{
				int nIndex = m_arWordIndexes [i];

				CString strLineOne = m_strText.Left(nIndex);

				if (!IsDefaultPanelButton())
				{
					strLineOne.Replace(_T("&&"), strDummyAmpSeq);
					strLineOne.Remove(_T('&'));
					strLineOne.Replace(strDummyAmpSeq, _T("&"));
				}

				const int cx1 = pDC->GetTextExtent(strLineOne).cx;

				CString strLineTwo = m_strText.Mid(nIndex + 1);

				if (!IsDefaultPanelButton())
				{
					strLineTwo.Replace(_T("&&"), strDummyAmpSeq);
					strLineTwo.Remove(_T('&'));
					strLineTwo.Replace(strDummyAmpSeq, _T("&"));
				}

				const int cx2 = pDC->GetTextExtent(strLineTwo).cx + nMenuArrowWidth;

				int nWidth = max(cx1, cx2);

				if (nWidth < nTextWidth)
				{
					nTextWidth = nWidth;
					m_nWrapIndex = nIndex;
				}
			}
		}

		if (nTextWidth % 2)
		{
			nTextWidth--;
		}

		CSize size(nTextWidth, nTextLineHeight * 2);
		return size;
	}

	int y = m_rect.top + nLargeButtonMarginY + sizeImageLarge.cy + 5;
	CRect rectMenuArrow(0, 0, 0, 0);

	if (IsDefaultPanelButton())
	{
		y += nDefaultPaneButtonMargin;
	}

	CRect rectText = m_rect;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	rectText.top = y+12;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	UINT uiDTFlags = DT_SINGLELINE | DT_CENTER;
	if (IsDefaultPanelButton())
	{
		uiDTFlags |= DT_NOPREFIX;
	}

	if (m_nWrapIndex == -1)
	{
		// Single line text
		pDC->DrawText(m_strText, rectText, uiDTFlags);

		if (HasMenu() || IsDefaultPanelButton())
		{
			rectMenuArrow = m_rect;

			rectMenuArrow.top = y + nTextLineHeight + 2;
			rectMenuArrow.left = m_rect.CenterPoint().x - CMenuImages::Size().cx / 2 - 1;
		}
	}
	else
	{
		CString strLineOne = m_strText.Left(m_nWrapIndex);
		pDC->DrawText(strLineOne, rectText, uiDTFlags);

		rectText.top = y + nTextLineHeight;
		rectText.right -= nMenuArrowWidth;

		CString strLineTwo = m_strText.Mid(m_nWrapIndex + 1);
		pDC->DrawText(strLineTwo, rectText, uiDTFlags);

		if (HasMenu() || IsDefaultPanelButton())
		{
			rectMenuArrow = rectText;

			rectMenuArrow.top += 2;
			rectMenuArrow.left = rectText.right -(rectText.Width() - pDC->GetTextExtent(strLineTwo).cx) / 2;
		}
	}

	if (!rectMenuArrow.IsRectEmpty())
	{
		int nMenuArrowHeight = CMenuImages::Size().cy;

		if (afxGlobalData.GetRibbonImageScale() > 1.)
		{
			nMenuArrowHeight = (int)(.5 + afxGlobalData.GetRibbonImageScale() * nMenuArrowHeight);
		}

		rectMenuArrow.bottom = rectMenuArrow.top + nMenuArrowHeight;
		rectMenuArrow.right = rectMenuArrow.left + nMenuArrowWidth;

		CRect rectWhite = rectMenuArrow;
		rectWhite.OffsetRect(0, 1);

		CMenuImages::IMAGES_IDS id = afxGlobalData.GetRibbonImageScale() > 1. ? CMenuImages::IdArrowDownLarge : CMenuImages::IdArrowDown;

		CMenuImages::Draw(pDC, id, rectWhite, CMenuImages::ImageWhite);
		CMenuImages::Draw(pDC, id, rectMenuArrow, m_bIsDisabled ? CMenuImages::ImageGray : CMenuImages::ImageBlack);
	}

	return CSize(0, 0);
}



