#pragma once
#include "shockwaveflash1.h"


// TestSsl 对话框

class TestSsl : public CDialog
{
	DECLARE_DYNAMIC(TestSsl)

public:
	TestSsl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestSsl();

// 对话框数据
	enum { IDD = IDD_TEST_SSL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
