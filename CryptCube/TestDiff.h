#pragma once
#include "shockwaveflash1.h"


// TestDiff 对话框

class TestDiff : public CDialog
{
	DECLARE_DYNAMIC(TestDiff)

public:
	TestDiff(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDiff();

// 对话框数据
	enum { IDD = IDD_TEST_ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
