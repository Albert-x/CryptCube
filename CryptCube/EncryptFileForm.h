#pragma once

#include "Form.h"

// CEncryptFileForm ������ͼ

class CEncryptFileForm : public CForm
{
	DECLARE_DYNCREATE(CEncryptFileForm)

public:
	CEncryptFileForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CEncryptFileForm();

public:
	enum { IDD = IDD_ENCRYPT_FILE };
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


