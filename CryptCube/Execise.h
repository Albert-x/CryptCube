#pragma once

#include "Form.h"
// CExecise 对话框

class CExecise : public CForm
{
	DECLARE_DYNCREATE(CExecise)

public:
	CExecise();   // 标准构造函数
	virtual ~CExecise();

// 对话框数据
	enum { IDD = IDD_EXCISE };
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
