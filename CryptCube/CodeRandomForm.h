#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeRandomForm 窗体视图

class CCodeRandomForm : public CForm
{
	DECLARE_DYNCREATE(CCodeRandomForm)

public:
	CCodeRandomForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CCodeRandomForm();

public:
	enum { IDD = IDD_CODE_RANDOM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strPassLength;
	CString m_strPassAmount;
	CComboBox m_pComboPassLength;
	CComboBox m_pComboPassAmount;
	afx_msg void OnBnClickedPassGenerate();
	BOOL m_bCheckUppercase;
	BOOL m_bCheckLowercase;
	BOOL m_bCheckNumber;
	BOOL m_bCheckCharacter;
	BOOL m_bCheckHex;
	BOOL m_bCheckBin;
	afx_msg void OnBnClickedCheckHex();
	afx_msg void OnBnClickedCheckBin();
	CButton m_btnCheckUppercase;
	CButton m_btnCheckLowercase;
	CButton m_btnCheckNumber;
	CButton m_btnCheckCharacter;
	CButton m_btnCheckHex;
	CButton m_btnCheckBin;
	static UINT InitComboboxPassLength(LPVOID param) ;
	static UINT InitComboboxPassAmount(LPVOID param) ;
	static CString RandomCode(int,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,CString);// 根据参数要求随机获得一个指定长度的字符串
	static CString GetChar(BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,CString);// 随机获得一个字符
	afx_msg void OnCbnEditchangeComboPassLength();
	afx_msg void OnCbnEditchangeComboPassAmount();
	afx_msg void OnBnClickedCheckPasscustom();

	CEdit m_editPassCustom;// “自定义字符”编辑框
	CString m_strPassCustom;// “自定义字符”编辑框的值
	CButton m_btnCheckCustom;// “自定义字符”复选框
	BOOL m_bCheckCustom;// “自定义字符”复选框的值
	
	CString m_strPass;
	static UINT PassGenerate(LPVOID param);
	CEdit m_editPass;
	CButton m_btnPassGenerate;
};


