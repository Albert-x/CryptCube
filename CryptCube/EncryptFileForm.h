#pragma once

#include "Form.h"

// CEncryptFileForm 窗体视图

class CEncryptFileForm : public CForm
{
	DECLARE_DYNCREATE(CEncryptFileForm)

public:
	CEncryptFileForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CEncryptFileForm();

public:
	enum { IDD = IDD_ENCRYPT_FILE };
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


