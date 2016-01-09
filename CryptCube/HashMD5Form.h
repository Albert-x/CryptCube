#pragma once



// CHashMD5Form ������ͼ
#include "Form.h"
//#include "md5.h"
#include "HashMD5.h"
#include "afxwin.h"
//extern uint32 m[16];
class CHashMD5Form : public CForm
{
	DECLARE_DYNCREATE(CHashMD5Form)

public:
	CHashMD5Form();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CHashMD5Form();

public:
	enum { IDD = IDD_HASH_MD5 };
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
	// ANSI���뷽ʽ
	BOOL m_stateRadioAnsi;

	// �����ַ���ʮ������
	CString m_strCipherTextHex;
	// �����ַ���
	CString m_strPlainText;
	// �����ַ���ʮ������
	CString m_strPlainTextHex;

	BOOL m_bInitControl;
	afx_msg void OnEnChangeEditPlaintext();
	void DoEncrypt();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();
	CEdit m_ctrlPlainText;

	MD5 *m_pMD5;
	//md5 mdd5;
	afx_msg void OnEnChangeEditCiphertextHex();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CButton m_btln1;
	CButton m_btln2;

	//	CString m_strM2;
	CString m_strM10;
	//	CEdit m_strM11;
	CString m_strM11;
	CString m_strM12;
	CString m_strM13;
	CString m_strM14;
	CString m_strM15;
	CString m_strM16;
	CString m_strM1;
	CString m_strM2;
	CString m_strM3;
	CString m_strM4;
	CString m_strM5;
	CString m_strM6;
	CString m_strM7;
	CString m_strM8;
	CString m_strM9;
};


