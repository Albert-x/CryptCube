#pragma once



// CStreamRC4Form 窗体视图
#include "Form.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "StreamRC4.h"
#include "StreamRC4DialogList.h"
#include "StreamRC4DialogText.h"

class CStreamRC4Form : public CForm
{
	DECLARE_DYNCREATE(CStreamRC4Form)

public:
	CStreamRC4Form();           // 动态创建所使用的受保护的构造函数
	virtual ~CStreamRC4Form();

public:
	enum { IDD = IDD_STREAM_RC4 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	DECLARE_MESSAGE_MAP()

public:

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
	//CEdit m_ctrlPlainText;
	// 密钥输入框
	//CEdit m_ctrlKey;
	// 密文输入框

	afx_msg void OnEnChangeEditPlain();
	afx_msg void OnEnChangeEditKey();
	CSpinButtonCtrl m_spinSbox;

	CString m_strSbox;
	CEdit m_ctrlSbox;
	CButton m_btnChushi;
	CButton m_btnKBox;
	CButton m_btnZhihuan;
	CButton m_btnDiedai;

	RC4 *m_pRC4;

	unsigned char szSourceKey[2049],szPlaintextData[2049];

	void DoEncrypt();
	void RC4Show();
	afx_msg void OnEnChangeEditSbox();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();

	BOOL m_bInitControl;
	afx_msg void OnBnClickedButtonChushi();
	afx_msg void OnBnClickedButtonKBox();
	afx_msg void OnBnClickedButtonZhihuan();
	afx_msg void OnBnClickedButtonDiedai();

	CStreamRC4DialogText dlgChushi;
	CStreamRC4DialogText dlgKBox;
	CStreamRC4DialogText dlgZhihuan;
	CStreamRC4DialogList dlgDiedai;



};


