#pragma once
#include "shockwaveflash1.h"


// TestDiff �Ի���

class TestDiff : public CDialog
{
	DECLARE_DYNAMIC(TestDiff)

public:
	TestDiff(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestDiff();

// �Ի�������
	enum { IDD = IDD_TEST_ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
