#pragma once

#include "Form.h"
// CHighPgp �Ի���

class CHighPgp : public CForm
{
	DECLARE_DYNCREATE(CHighPgp)

public:
	CHighPgp();   // ��׼���캯��
	virtual ~CHighPgp();

// �Ի�������
	enum { IDD = IDD_HIGH_PGP };

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