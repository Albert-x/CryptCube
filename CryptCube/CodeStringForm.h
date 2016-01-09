#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeStringForm 窗体视图

class CCodeStringForm : public CForm
{
	DECLARE_DYNCREATE(CCodeStringForm)

public:
	CCodeStringForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeStringForm();

public:
	enum { IDD = IDD_CODE_STRING };
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
	// 存储待转换的文本
	CString m_strNormal;
	// 存储ansi编码方式的十六进制字符串
	CString m_strHexAnsi;
	// 存储Unicode编码方式的十六进制字符串
	CString m_strHexUnicode;
	// 存储UniBigEnd编码方式的十六进制字符串
	CString m_strHexUniBigEnd;
	// 存储UTF8编码方式的十六进制字符串
	CString m_strHexUTF8;
	// 存储UTF7编码方式的十六进制字符串
	CString m_strHexUTF7;
	// 储存Base64编码方式的ASCII字符串
	CString m_strBase64;
	afx_msg void OnEnChangeEditStringNormal();
	afx_msg void OnEnChangeEditHexAnsi();
	afx_msg void OnEnChangeEditHexUnicode();
	afx_msg void OnEnChangeEditHexUnibigend();
	afx_msg void OnEnChangeEditHexUtf8();
	afx_msg void OnEnChangeEditHexUtf7();
	afx_msg void OnEnChangeEditBase64();
	// 待转换的文本框
	CEdit m_editNormal;
	// ansi码的文本框
	CEdit m_editHexAnsi;
	// Unicode的文本框
	CEdit m_editHexUnicode;
	// UniBigEnd的文本框
	CEdit m_editHexUniBigEnd;
	// UTF8的文本框
	CEdit m_editHexUTF8;
	// UTF7的文本框
	CEdit m_editHexUTF7;
	// Base64的文本框
	CEdit m_editBase64;
};


