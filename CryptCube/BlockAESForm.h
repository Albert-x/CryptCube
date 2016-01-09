#pragma once


#include "Form.h"
#include "afxcmn.h"

#include "BlockAESDialogChushi.h"
#include "BlockAESDialogKey.h"
#include "BlockAESDialogZuiHou.h"
#include "BlockAESDialogLun.h"

#include "BlockAES.h"
#include "afxwin.h"

// CBlockAESForm ������ͼ

class CBlockAESForm : public CForm
{
	DECLARE_DYNCREATE(CBlockAESForm)

public:
	CBlockAESForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
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
	// DES����
	AES *m_pAES;


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


