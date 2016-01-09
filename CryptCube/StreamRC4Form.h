#pragma once



// CStreamRC4Form ������ͼ
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
	CStreamRC4Form();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	// ���������
	//CEdit m_ctrlPlainText;
	// ��Կ�����
	//CEdit m_ctrlKey;
	// ���������

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


