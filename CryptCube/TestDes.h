#pragma once
#include "shockwaveflash1.h"


// TestDes 对话框

class TestDes : public CDialog
{
	DECLARE_DYNAMIC(TestDes)

public:
	TestDes(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDes();

// 对话框数据
	enum { IDD = IDD_TEST_DES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
