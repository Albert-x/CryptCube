#pragma once
#include "shockwaveflash1.h"


// TestDes �Ի���

class TestDes : public CDialog
{
	DECLARE_DYNAMIC(TestDes)

public:
	TestDes(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestDes();

// �Ի�������
	enum { IDD = IDD_TEST_DES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
