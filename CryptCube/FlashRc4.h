#pragma once
#include "shockwaveflash1.h"


// FlashRc4 对话框

class FlashRc4 : public CDialog
{
	DECLARE_DYNAMIC(FlashRc4)

public:
	FlashRc4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashRc4();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_FLASH_RC4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
