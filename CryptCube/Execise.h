#pragma once

#include "Form.h"
// CExecise �Ի���

class CExecise : public CForm
{
	DECLARE_DYNCREATE(CExecise)

public:
	CExecise();   // ��׼���캯��
	virtual ~CExecise();

// �Ի�������
	enum { IDD = IDD_EXCISE };
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
