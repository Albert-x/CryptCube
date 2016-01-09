#pragma once
#include "shockwaveflash1.h"


// FlashAes 对话框

class FlashAes : public CDialog
{
	DECLARE_DYNAMIC(FlashAes)

public:
	FlashAes(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashAes();

// 对话框数据
	enum { IDD = IDD_FLASH_AES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
