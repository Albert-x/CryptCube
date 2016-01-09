#pragma once

// CBlockIDEAForm ������ͼ
#include "Form.h"

#include "BlockIDEADialogKey.h"
#include "BlockIDEADialogZuiHou.h"
#include "BlockIDEADialogLun.h"
#include "BlockIDEA.h"

class CBlockIDEAForm : public CForm
{
	DECLARE_DYNCREATE(CBlockIDEAForm)

public:
	CBlockIDEAForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
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

	// ANSI���뷽ʽ
	BOOL m_stateRadioAnsi;

	// �����ַ���
	CString m_strPlainText;
	// �����ַ���ʮ������
	CString m_strPlainTextHex;
	// ��Կ�ַ���
	CString m_strKey;
	// ��Կ�ַ���ʮ������
	CString m_strKeyHex;
	// �����ַ���
	CString m_strCipherText;
	// �����ַ���ʮ������
	CString m_strCipherTextHex;

	// ���������
	CEdit m_ctrlPlainText;

	// ��Կ�����
	CEdit m_ctrlKey;
	// ���������
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


