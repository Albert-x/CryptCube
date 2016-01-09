#pragma once



// CPublicKeyDHForm ������ͼ
#include "Form.h"
#include "PublicKeyElGamal.h"

class CPublicKeyDHForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyDHForm)

public:
	CPublicKeyDHForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPublicKeyDHForm();

public:
	enum { IDD = IDD_PUBLICKEY_DH };
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

	// �����ɹ�˽Կ��P Q XA XB������
	CComboBox m_ctrlComboQ;
	CComboBox m_ctrlComboA;
	CComboBox m_ctrlComboXA;
	CComboBox m_ctrlComboXB;
	CString m_strComboQ;
	CString m_strComboA;
	CString m_strComboXA;
	CString m_strComboXB;

	ElGamal *m_pElGamal;

	static UINT InitComboBox(LPVOID param);
	static UINT SetComboBoxThread(LPVOID param);
	void SetComboBoxAX(int q);
	void EmptyKey();
	void DoDH();
	afx_msg void OnCbnSelchangeCrtstQ();
	afx_msg void OnCbnSelchangeCrtstA();
	afx_msg void OnCbnSelchangeCrtstXa();
	afx_msg void OnCbnSelchangeCrtstXb();

	CString m_strUserAA;
	CString m_strUserAXa;
	CString m_strUserAQ;
	CString m_strUserAYa;

	CString m_strUserBA;
	CString m_strUserBXb;
	CString m_strUserBQ;
	CString m_strUserBYb;

	CString m_strPubUserAYb;
	CString m_strPubUserAXa;
	CString m_strPubUserAQ;
	CString m_strPubUserAK;

	CString m_strPubUserBYa;
	CString m_strPubUserBXb;
	CString m_strPubUserBQ;
	CString m_strPubUserBK;

	// ���̱߳�־
	BOOL m_bInThread;

};


