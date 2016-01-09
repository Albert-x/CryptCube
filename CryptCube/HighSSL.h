#pragma once
#include "Form.h"

// HighSSL 对话框

class HighSSL : public CForm
{
	DECLARE_DYNCREATE(HighSSL)

public:
	HighSSL();   // 标准构造函数
	virtual ~HighSSL();

// 对话框数据
	enum { IDD = IDD_HIGH_SSL };
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
	afx_msg void OnBnClickedButton1();
};
