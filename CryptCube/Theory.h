#pragma once

#include "Form.h"
// CTheory 对话框

class CTheory : public CForm
{
	DECLARE_DYNCREATE(CTheory)

public:
	CTheory();   // 标准构造函数
	virtual ~CTheory();

// 对话框数据
	enum { IDD = IDD_THEORY };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
