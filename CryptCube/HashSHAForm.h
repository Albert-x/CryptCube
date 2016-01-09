#pragma once



// CHashSHAForm 窗体视图
#include "Form.h"
class CHashSHAForm : public CForm
{
	DECLARE_DYNCREATE(CHashSHAForm)

public:
	CHashSHAForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CHashSHAForm();

public:
	enum { IDD = IDD_HASH_SHA };
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
	BOOL m_bInitControl;
	void DoEncrypt();
	CEdit m_shastr;
	CEdit m_result;
	CString result;
	CString shastr;
	CButton m_btln1;
	CButton m_btln2;
	CButton m_btln3;
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedRadioAnsi();
	BOOL m_stateRadioAnsi;
	afx_msg void OnEnChangeEditPlaintext();
	afx_msg void OnBnClickedRadioUnicode();
	CString m_strM1;
	CString m_strM10;
	CString m_strM11;
	CString m_strM12;
	CString m_strM13;
	CString m_strM14;
	CString m_strM15;
	CString m_strM16;
	CString m_strM2;
	CString m_strM3;
	CString m_strM4;
	CString m_strM5;
	CString m_strM6;
	CString m_strM7;
	CString m_strM8;
	CString m_strM9;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};


