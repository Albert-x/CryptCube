#pragma once

#include "Form.h"

// CEncryptStringForm ������ͼ

class CEncryptStringForm : public CForm
{
	DECLARE_DYNCREATE(CEncryptStringForm)

public:
	CEncryptStringForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CEncryptStringForm();

public:
	enum { IDD = IDD_ENCRYPT_STRING };
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


