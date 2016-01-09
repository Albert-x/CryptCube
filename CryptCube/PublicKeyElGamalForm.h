#pragma once



// CPublicKeyElGamalForm ������ͼ
#include "Form.h"
#include "PublicKeyElGamal.h"

class CPublicKeyElGamalForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyElGamalForm)

public:
	CPublicKeyElGamalForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPublicKeyElGamalForm();

public:
	enum { IDD = IDD_PUBLICKEY_ELGAMAL };
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
	LRESULT  OnReadMyData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	void InitComboBox();

	// �����ɹ�˽Կ��P Q E������
	CComboBox m_ctrlComboQ;
	CComboBox m_ctrlComboA;
	CComboBox m_ctrlComboX;
	CString m_strComboQ;
	CString m_strComboA;
	CString m_strComboX;

	static UINT InitComboBox(LPVOID param);
	static UINT SetComboBoxThread(LPVOID param);
	void SetComboBoxAX(int q);
	void DoElGamal();
	void Encrypt();
	void Decrypt();
	void EmptyKey();

	afx_msg void OnCbnSelchangeCrtstQ();
	afx_msg void OnCbnSelchangeCrtstA();
	afx_msg void OnCbnSelchangeCrtstX();
	ElGamal *m_pElGamal;

	// ��ԿY
	CString m_strY;

	// ��Կ�м����
	CString m_strShowQ;
	CString m_strShowA;
	CString m_strShowX;
	CString m_strShowQ2;
	CString m_strShowA2;
	CString m_strShowX2;
	CString m_strShowY;

	// ���ܹ���
	CString m_strEnM;
	CString m_strEnQ;
	CString m_strEnA;
	CString m_strEnY;
	CString m_strEnX;
	CString m_strEnC1;
	CString m_strEnX2;
	CString m_strEnA2;
	CString m_strEnQ2;
	CString m_strEnK;
	CString m_strEnX3;
	CString m_strEnY2;
	CString m_strEnQ4;
	CString m_strEnC2;
	CString m_strEnK2;
	CString m_strEnM2;
	CString m_strC2;
	CString m_strC1;
	CString m_strEnQ5;

	// ���ܹ���
	CString m_strDeC1;
	CString m_strDeC2;
	CString m_strDeQ;
	CString m_strDeX;
	CString m_strDeC3;
	CString m_strDeX2;
	CString m_strDeQ2;
	CString m_strDeK;
	CString m_strDeK2;
	CString m_strDeK3;
	CString m_strDeC4;
	CString m_strDeM;
	CString m_strM;

	afx_msg void OnEnChangeEditPlain();
	afx_msg void OnEnChangeEditCipher1();
	afx_msg void OnEnChangeEditCipher2();

	// ���̱߳�־
	BOOL m_bInThread;

};


