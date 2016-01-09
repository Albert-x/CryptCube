#pragma once



// CPublicKeyRSAForm ������ͼ
#include "Form.h"
#include "afxwin.h"

#define WM_UPDATEMY_DATA WM_USER + 500


class CPublicKeyRSAForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyRSAForm)

public:
	CPublicKeyRSAForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPublicKeyRSAForm();

public:
	enum { IDD = IDD_PUBLICKEY_RSA };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	LRESULT  OnUpdateMyData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:

	void InitComboBox();
	afx_msg void OnCbnSelchangeCrtstP();
	afx_msg void OnCbnSelchangeCrtstQ();
	static UINT RandomE(LPVOID param);
	afx_msg void OnCbnDropdownCrtstP();
	afx_msg void OnCbnKillfocusCrtstP();
	afx_msg void OnCbnDropdownCrtstQ();
	afx_msg void OnCbnKillfocusCrtstQ();
	void DoRSA();
	void EmptyKey();
	afx_msg void OnCbnSelchangeCrtstE();
	void Encrypt();
	void Decrypt();
	afx_msg void OnEnChangeEditPlain();
	afx_msg void OnEnChangeEditCipher();

	UINT n, d, e;

	// �����ɹ�˽Կ��P Q E������
	CComboBox m_ctrlComboP;
	CComboBox m_ctrlComboQ;
	CComboBox m_ctrlComboE;
	CString m_strComboP;
	CString m_strComboQ;
	CString m_strComboE;

	// �����ɹ�˽Կ���Ĺ�Կ��˽Կ
	CString m_strPKe;
	CString m_strPKn;
	CString m_strSKd;
	CString m_strSKn;

	////////////////////////////////////
	// ����ʾ����P Q E
	CString m_strEditP;
	CString m_strEditQ;
	CString m_strEditE;

	// ����ʾ�����м����
	CString m_strShowP;
	CString m_strShowQ;
	CString m_strShowN;
	CString m_strShowP2;
	CString m_strShowQ2;
	CString m_strShowN2;
	CString m_strShowD;

	// ����ʾ���Ĺ�Կ��˽Կ
	CString m_strShowPKe;
	CString m_strShowPKn;
	CString m_strShowSKd;
	CString m_strShowSKn;

	////////////////////////////////////
	// �����ܡ��Ĺ�Կ������
	CString m_strEnPKn;
	CString m_strEnPKe;
	CString m_strPlain;

	// �����ܡ����м����
	CString m_strPlainM;
	CString m_strPlainE;
	CString m_strPlainN;

	// �����ܡ��������
	CString m_strCipherResult;
	

	////////////////////////////////////
	// �����ܡ��Ĺ�Կ������
	CString m_strDeSKn;
	CString m_strDeSKd;
	CString m_strCipher;

	// �����ܡ����м����
	CString m_strCipherC;
	CString m_strCipherD;
	CString m_strCipherN;

	// �����ܺ󡱵�����
	CString m_strPlainResult;

	// ���̱߳�־
	BOOL m_bInThread;


};


