#pragma once

#include "Form.h"
// HighKer �Ի���

class HighKer : public CForm
{
	DECLARE_DYNCREATE(HighKer)

public:
	HighKer();   // ��׼���캯��
	virtual ~HighKer();

// �Ի�������
	enum { IDD = IDD_HIGH_KER };
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
