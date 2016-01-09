#pragma once

#include "Form.h"
// CWeiClass 对话框

class CWeiClass : public CForm
{
	DECLARE_DYNCREATE(CWeiClass)

public:
	CWeiClass();   // 标准构造函数
	virtual ~CWeiClass();

// 对话框数据
	enum { IDD = IDD_WEICLASS };
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
