#pragma once

// CBlockIDEAForm 窗体视图
#include "Form.h"

#include "BlockIDEADialogKey.h"
#include "BlockIDEADialogZuiHou.h"
#include "BlockIDEADialogLun.h"
#include "BlockIDEA.h"

class CBlockIDEAForm : public CForm
{
	DECLARE_DYNCREATE(CBlockIDEAForm)

public:
	CBlockIDEAForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CBlockIDEAForm();

public:
	enum { IDD = IDD_BLOCK_IDEA };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()

public:

	void DoEncrypt();
	CBlockIDEADialogKey dlgKey;
	CBlockIDEADialogZuihou dlgZuihou;
	CBlockIDEADialogLun dlgLun;
	afx_msg void OnBnClickedButtonLun();
	afx_msg void OnBnClickedButtonKey();
	afx_msg void OnBnClickedButtonZuihou();

	// ANSI编码方式
	BOOL m_stateRadioAnsi;

	// 明文字符串
	CString m_strPlainText;
	// 明文字符串十六进制
	CString m_strPlainTextHex;
	// 密钥字符串
	CString m_strKey;
	// 密钥字符串十六进制
	CString m_strKeyHex;
	// 密文字符串
	CString m_strCipherText;
	// 密文字符串十六进制
	CString m_strCipherTextHex;

	// 明文输入框
	CEdit m_ctrlPlainText;

	// 密钥输入框
	CEdit m_ctrlKey;
	// 密文输入框
	CEdit m_ctrlCipherText;

	afx_msg void OnEnChangeEditPlaintext();
	afx_msg void OnEnChangeEditKey();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();
	CButton m_btnLun;
	CButton m_btnZuihou;
	CButton m_btnKey;
	IDEA *m_pIDEA;
	IDEAkey m_EK;
};


