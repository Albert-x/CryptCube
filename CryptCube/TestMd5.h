#pragma once
#include "shockwaveflash1.h"


// TestMd5 对话框

class TestMd5 : public CDialog
{
	DECLARE_DYNAMIC(TestMd5)

public:
	TestMd5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestMd5();

// 对话框数据
	enum { IDD = IDD_TEST_MD5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
