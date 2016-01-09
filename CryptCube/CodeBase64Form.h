#pragma once

#include "Form.h"

// CCodeBase64Form 窗体视图

class CCodeBase64Form : public CForm
{
	DECLARE_DYNCREATE(CCodeBase64Form)

public:
	CCodeBase64Form();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeBase64Form();

public:
	enum { IDD = IDD_CODE_BASE64 };
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


