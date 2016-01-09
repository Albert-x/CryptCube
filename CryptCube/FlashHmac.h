#pragma once
#include "shockwaveflash1.h"


// FlashHmac 对话框

class FlashHmac : public CDialog
{
	DECLARE_DYNAMIC(FlashHmac)

public:
	FlashHmac(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashHmac();

// 对话框数据
	enum { IDD = IDD_HMAC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
