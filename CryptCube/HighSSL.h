#pragma once
#include "Form.h"

// HighSSL �Ի���

class HighSSL : public CForm
{
	DECLARE_DYNCREATE(HighSSL)

public:
	HighSSL();   // ��׼���캯��
	virtual ~HighSSL();

// �Ի�������
	enum { IDD = IDD_HIGH_SSL };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
