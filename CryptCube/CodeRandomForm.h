#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeRandomForm ������ͼ

class CCodeRandomForm : public CForm
{
	DECLARE_DYNCREATE(CCodeRandomForm)

public:
	CCodeRandomForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	static CString RandomCode(int,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,CString);// ���ݲ���Ҫ��������һ��ָ�����ȵ��ַ���
	static CString GetChar(BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,BOOL,CString);// ������һ���ַ�
	afx_msg void OnCbnEditchangeComboPassLength();
	afx_msg void OnCbnEditchangeComboPassAmount();
	afx_msg void OnBnClickedCheckPasscustom();

	CEdit m_editPassCustom;// ���Զ����ַ����༭��
	CString m_strPassCustom;// ���Զ����ַ����༭���ֵ
	CButton m_btnCheckCustom;// ���Զ����ַ�����ѡ��
	BOOL m_bCheckCustom;// ���Զ����ַ�����ѡ���ֵ
	
	CString m_strPass;
	static UINT PassGenerate(LPVOID param);
	CEdit m_editPass;
	CButton m_btnPassGenerate;
};


