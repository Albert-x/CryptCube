#pragma once

#include "Form.h"

// CCodeCalcForm 窗体视图

class CCodeCalcForm : public CForm
{
	DECLARE_DYNCREATE(CCodeCalcForm)

public:
	CCodeCalcForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeCalcForm();

public:
	enum { IDD = IDD_CODE_CALC };
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
		afx_msg void OnBnClickedButton2();
		afx_msg void OnBnClickedButton3();
		afx_msg void OnBnClickedButton9();
};


