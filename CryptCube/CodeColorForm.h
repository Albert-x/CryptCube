#pragma once

#include "Form.h"

// CCodeColorForm 窗体视图

class CCodeColorForm : public CForm
{
	DECLARE_DYNCREATE(CCodeColorForm)

public:
	CCodeColorForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeColorForm();

public:
	enum { IDD = IDD_CODE_COLOR };
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


