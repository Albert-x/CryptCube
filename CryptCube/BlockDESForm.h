#pragma once


#include "Form.h"
#include "afxwin.h"


#include "BlockDES.h"
#include "afxcmn.h"

// CBlockDESForm 窗体视图

class CBlockDESForm : public CForm
{
	DECLARE_DYNCREATE(CBlockDESForm)

public:
	CBlockDESForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CBlockDESForm();

public:
	enum { IDD = IDD_BLOCK_DES };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);
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
	afx_msg void OnEnChangeEditPlaintext();
	afx_msg void OnEnChangeEditKey();
	afx_msg void OnEnChangeEditCiphertext();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();

	BOOL m_bInitControl;
	afx_msg void OnEnKillfocusEditPlaintext();
	afx_msg void OnEnKillfocusEditKey();
	afx_msg void OnEnKillfocusEditCiphertext();
	void DoEncrypt();
	void DesShow();


	// 明文输入框
	CEdit m_ctrlPlainText;

	// 密钥输入框
	CEdit m_ctrlKey;
	// 密文输入框
	CEdit m_ctrlCipherText;

	// DES加密
	DES *m_pDES;




	// 当前轮数
	CEdit m_ctrlPage;
	// 增加轮数
	CSpinButtonCtrl m_spinPage;
	// 当前轮数
	CString m_strPage;
	// 上一轮按钮
	CButton m_btnPrevPage;
	// 下一轮按钮
	CButton m_btnNext;
	// 64位明文初始置换
	CString m_strChushi;
	// Li
	CString m_strLi;
	// Ri
	CString m_strRi;
	// RiXorKi
	CString m_strRiXorKi;
	// FRiKi
	CString m_strFRiKi;
	// Liplus
	CString m_strLiplus;
	// Riplus
	CString m_strRiplus;
	// Ki
	CString m_strKi;
	// Ci
	CString m_strCi;
	// Di
	CString m_strDi;
	// LeftMove
	CString m_strLeftMove;
	// Ciplus
	CString m_strCiplus;
	// Diplus
	CString m_strDiplus;
	// 56位压缩密钥
	CString m_strKeyCompress;
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnEnChangeEditDesPage();
	// 终结置换前的密文
	CString m_strPlainEnd;
	CString m_strFSbox;
};


