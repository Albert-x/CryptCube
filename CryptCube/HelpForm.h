#pragma once

#include "Form.h"

// CHelpForm 窗体视图

class CHelpForm : public CForm
{
	DECLARE_DYNCREATE(CHelpForm)

public:
	CHelpForm();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();
	DECLARE_MESSAGE_MAP()
	CImage m_Image;
};


