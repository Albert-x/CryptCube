#pragma once
#include "shockwaveflash1.h"


// FlashSha 对话框

class FlashSha : public CDialog
{
	DECLARE_DYNAMIC(FlashSha)

public:
	FlashSha(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashSha();

// 对话框数据
	enum { IDD = IDD_FLASH_SHA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
