#pragma once

#include "Form.h"
// CWeiClass �Ի���

class CWeiClass : public CForm
{
	DECLARE_DYNCREATE(CWeiClass)

public:
	CWeiClass();   // ��׼���캯��
	virtual ~CWeiClass();

// �Ի�������
	enum { IDD = IDD_WEICLASS };
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
