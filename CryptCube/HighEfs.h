#pragma once

#include "Form.h"

// HighEfs �Ի���

class HighEfs : public CForm
{
	DECLARE_DYNCREATE(HighEfs)

public:
	HighEfs();   // ��׼���캯��
	virtual ~HighEfs();

// �Ի�������
	enum { IDD = IDD_HIGH_EFS };

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
