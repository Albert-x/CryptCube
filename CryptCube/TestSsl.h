#pragma once
#include "shockwaveflash1.h"


// TestSsl �Ի���

class TestSsl : public CDialog
{
	DECLARE_DYNAMIC(TestSsl)

public:
	TestSsl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestSsl();

// �Ի�������
	enum { IDD = IDD_TEST_SSL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
