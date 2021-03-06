#pragma once
#include "shockwaveflash1.h"


// FlashMd5 对话框

class FlashMd5 : public CDialog
{
	DECLARE_DYNAMIC(FlashMd5)

public:
	FlashMd5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashMd5();

// 对话框数据
	enum { IDD = IDD_FLASH_MD5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
