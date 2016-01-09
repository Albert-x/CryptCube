#pragma once


#include "Form.h"
#include "afxwin.h"


#include "BlockDES.h"
#include "afxcmn.h"

// CBlockDESForm ������ͼ

class CBlockDESForm : public CForm
{
	DECLARE_DYNCREATE(CBlockDESForm)

public:
	CBlockDESForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnInitialUpdate(); // ������һ�ε���

	DECLARE_MESSAGE_MAP()
public:


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


	// ���������
	CEdit m_ctrlPlainText;

	// ��Կ�����
	CEdit m_ctrlKey;
	// ���������
	CEdit m_ctrlCipherText;

	// DES����
	DES *m_pDES;




	// ��ǰ����
	CEdit m_ctrlPage;
	// ��������
	CSpinButtonCtrl m_spinPage;
	// ��ǰ����
	CString m_strPage;
	// ��һ�ְ�ť
	CButton m_btnPrevPage;
	// ��һ�ְ�ť
	CButton m_btnNext;
	// 64λ���ĳ�ʼ�û�
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
	// 56λѹ����Կ
	CString m_strKeyCompress;
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnEnChangeEditDesPage();
	// �ս��û�ǰ������
	CString m_strPlainEnd;
	CString m_strFSbox;
};


