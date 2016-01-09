#pragma once
#include "shockwaveflash1.h"


// TestDsa 对话框

class TestDsa : public CDialog
{
	DECLARE_DYNAMIC(TestDsa)

public:
	TestDsa(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDsa();

// 对话框数据
	enum { IDD = IDD_TEST_DSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
