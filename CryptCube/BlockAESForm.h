#pragma once


#include "Form.h"
#include "afxcmn.h"

#include "BlockAESDialogChushi.h"
#include "BlockAESDialogKey.h"
#include "BlockAESDialogZuiHou.h"
#include "BlockAESDialogLun.h"

#include "BlockAES.h"
#include "afxwin.h"

// CBlockAESForm 窗体视图

class CBlockAESForm : public CForm
{
	DECLARE_DYNCREATE(CBlockAESForm)

public:
	CBlockAESForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CBlockAESForm();

public:
	enum { IDD = IDD_BLOCK_AES };
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



	afx_msg void OnBnClickedButtonKey();
	void InitListCtrl(CListCtrl &ctrlList);
	void EmptyListCtrl(CListCtrl &ctrlList);

	CBlockAESDialogChushi dlgChushi;
	CBlockAESDialogKey dlgKey;
	CBlockAESDialogZuihou dlgZuihou;
	CBlockAESDialogLun dlgLun;

	BOOL m_bInitControl;

	afx_msg void OnBnClickedButtonChushi();
	afx_msg void OnBnClickedButtonLun();
	afx_msg void OnBnClickedButtonZuihou();
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);
	void DoEncrypt();
	void AesShow();
	// DES加密
	AES *m_pAES;


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
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();
	afx_msg void OnEnChangeEditKey();
	CButton m_btnChushi;
	CButton m_btnLun;
	CButton m_btnZuihou;
	CButton m_btnKey;


	CString m_strListInput[4][4];
	CString m_strListChushi[4][4];
	CString m_strList9lun[4][4];
	CString m_strListzuihou[4][4];

	CListCtrl m_ctrlListInput;
	CListCtrl m_ctrlListChushi;
	CListCtrl m_ctrlList9lun;
	CListCtrl m_ctrlListzuihou;

};


