#pragma once

#include "Form.h"

// CHelpForm ������ͼ

class CHelpForm : public CForm
{
	DECLARE_DYNCREATE(CHelpForm)

public:
	CHelpForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CHelpForm();

public:
	enum { IDD = IDD_HELP };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();
	DECLARE_MESSAGE_MAP()
	CImage m_Image;
};


