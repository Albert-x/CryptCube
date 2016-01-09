#pragma once



// CPublicKeyRSAForm 窗体视图
#include "Form.h"
#include "afxwin.h"

#define WM_UPDATEMY_DATA WM_USER + 500


class CPublicKeyRSAForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyRSAForm)

public:
	CPublicKeyRSAForm();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
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

	// “生成公私钥”P Q E下拉框
	CComboBox m_ctrlComboP;
	CComboBox m_ctrlComboQ;
	CComboBox m_ctrlComboE;
	CString m_strComboP;
	CString m_strComboQ;
	CString m_strComboE;

	// “生成公私钥”的公钥、私钥
	CString m_strPKe;
	CString m_strPKn;
	CString m_strSKd;
	CString m_strSKn;

	////////////////////////////////////
	// “演示”的P Q E
	CString m_strEditP;
	CString m_strEditQ;
	CString m_strEditE;

	// “演示”的中间过程
	CString m_strShowP;
	CString m_strShowQ;
	CString m_strShowN;
	CString m_strShowP2;
	CString m_strShowQ2;
	CString m_strShowN2;
	CString m_strShowD;

	// “演示”的公钥、私钥
	CString m_strShowPKe;
	CString m_strShowPKn;
	CString m_strShowSKd;
	CString m_strShowSKn;

	////////////////////////////////////
	// “加密”的公钥、明文
	CString m_strEnPKn;
	CString m_strEnPKe;
	CString m_strPlain;

	// “加密”的中间过程
	CString m_strPlainM;
	CString m_strPlainE;
	CString m_strPlainN;

	// “加密”后的密文
	CString m_strCipherResult;
	

	////////////////////////////////////
	// “解密”的公钥、明文
	CString m_strDeSKn;
	CString m_strDeSKd;
	CString m_strCipher;

	// “解密”的中间过程
	CString m_strCipherC;
	CString m_strCipherD;
	CString m_strCipherN;

	// “解密后”的明文
	CString m_strPlainResult;

	// 多线程标志
	BOOL m_bInThread;


};


