#pragma once
#include "shockwaveflash1.h"


// TestDsa �Ի���

class TestDsa : public CDialog
{
	DECLARE_DYNAMIC(TestDsa)

public:
	TestDsa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestDsa();

// �Ի�������
	enum { IDD = IDD_TEST_DSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
