#pragma once
#include "shockwaveflash1.h"


// FlsahRsa 对话框

class FlsahRsa : public CDialog
{
	DECLARE_DYNAMIC(FlsahRsa)

public:
	FlsahRsa(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlsahRsa();

// 对话框数据
	enum { IDD = IDD_FLASH_RSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
