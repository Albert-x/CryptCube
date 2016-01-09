#pragma once

#include "Form.h"

// CEncryptStringForm 窗体视图

class CEncryptStringForm : public CForm
{
	DECLARE_DYNCREATE(CEncryptStringForm)

public:
	CEncryptStringForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CEncryptStringForm();

public:
	enum { IDD = IDD_ENCRYPT_STRING };
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


