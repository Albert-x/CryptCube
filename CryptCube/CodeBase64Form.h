#pragma once

#include "Form.h"

// CCodeBase64Form ������ͼ

class CCodeBase64Form : public CForm
{
	DECLARE_DYNCREATE(CCodeBase64Form)

public:
	CCodeBase64Form();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CCodeBase64Form();

public:
	enum { IDD = IDD_CODE_BASE64 };
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


