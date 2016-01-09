#pragma once
#include "shockwaveflash1.h"


// FlashDiff 对话框

class FlashDiff : public CDialog
{
	DECLARE_DYNAMIC(FlashDiff)

public:
	FlashDiff(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashDiff();

// 对话框数据
	enum { IDD = IDD_FLASH_DIFF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
