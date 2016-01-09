#pragma once

#include "Form.h"
// CHighOpen 对话框

class CHighOpen : public CForm
{
	DECLARE_DYNCREATE(CHighOpen)

public:
	CHighOpen();   // 标准构造函数
	virtual ~CHighOpen();

// 对话框数据
	enum { IDD = IDD_HIGH_OPEN };

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};