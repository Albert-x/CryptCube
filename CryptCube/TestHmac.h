#pragma once
#include "shockwaveflash1.h"


// TestHmac 对话框

class TestHmac : public CDialog
{
	DECLARE_DYNAMIC(TestHmac)

public:
	TestHmac(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestHmac();

// 对话框数据
	enum { IDD = IDD_TEST_HMAC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
