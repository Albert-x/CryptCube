#pragma once
#include "Form.h"

// HighPki �Ի���

class HighPki : public CForm
{
	DECLARE_DYNCREATE(HighPki)

public:
	HighPki();   // ��׼���캯��
	virtual ~HighPki();

// �Ի�������
	enum { IDD = IDD_HIGH_PKI };

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
