#pragma once
#include "shockwaveflash1.h"


// TestMd5 �Ի���

class TestMd5 : public CDialog
{
	DECLARE_DYNAMIC(TestMd5)

public:
	TestMd5(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestMd5();

// �Ի�������
	enum { IDD = IDD_TEST_MD5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
