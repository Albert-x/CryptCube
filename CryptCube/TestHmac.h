#pragma once
#include "shockwaveflash1.h"


// TestHmac �Ի���

class TestHmac : public CDialog
{
	DECLARE_DYNAMIC(TestHmac)

public:
	TestHmac(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestHmac();

// �Ի�������
	enum { IDD = IDD_TEST_HMAC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
