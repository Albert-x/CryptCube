#pragma once
#include "shockwaveflash1.h"


// FlashDsa 对话框

class FlashDsa : public CDialog
{
	DECLARE_DYNAMIC(FlashDsa)

public:
	FlashDsa(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashDsa();

// 对话框数据
	enum { IDD = IDD_FLASH_DSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
