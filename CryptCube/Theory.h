#pragma once

#include "Form.h"
// CTheory �Ի���

class CTheory : public CForm
{
	DECLARE_DYNCREATE(CTheory)

public:
	CTheory();   // ��׼���캯��
	virtual ~CTheory();

// �Ի�������
	enum { IDD = IDD_THEORY };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
