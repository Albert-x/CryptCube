#pragma once

#include "Form.h"

// CCodeUrlForm ������ͼ

class CCodeUrlForm : public CForm
{
	DECLARE_DYNCREATE(CCodeUrlForm)

public:
	CCodeUrlForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CCodeUrlForm();

public:
	enum { IDD = IDD_CODE_URL };
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


