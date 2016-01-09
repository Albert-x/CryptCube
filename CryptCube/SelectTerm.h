#pragma once

#include "Form.h"
#include "Dictionary.h"
// CSelectTerm 对话框

class CSelectTerm : public CForm
{
	DECLARE_DYNCREATE(CSelectTerm)

public:
	CSelectTerm();   // 标准构造函数
	virtual ~CSelectTerm();
	HICON m_hIcon;
	DICTIONARY dic;
// 对话框数据
	enum { IDD = IDD_SHUYU };
	#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
