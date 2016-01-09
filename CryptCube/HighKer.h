#pragma once

#include "Form.h"
// HighKer 对话框

class HighKer : public CForm
{
	DECLARE_DYNCREATE(HighKer)

public:
	HighKer();   // 标准构造函数
	virtual ~HighKer();

// 对话框数据
	enum { IDD = IDD_HIGH_KER };
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
