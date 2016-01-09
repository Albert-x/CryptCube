#pragma once

#include "Form.h"

// CCodeUrlForm 窗体视图

class CCodeUrlForm : public CForm
{
	DECLARE_DYNCREATE(CCodeUrlForm)

public:
	CCodeUrlForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeUrlForm();

public:
	enum { IDD = IDD_CODE_URL };
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


