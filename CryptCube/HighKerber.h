#pragma once

#include "shockwaveflash1.h"

// CHighKerber 对话框

class CHighKerber : public CDialog
{
	DECLARE_DYNAMIC(CHighKerber)

public:
	CHighKerber(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHighKerber();

// 对话框数据
	enum { IDD = IDD_KERBER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
