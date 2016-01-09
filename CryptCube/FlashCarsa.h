#pragma once
#include "shockwaveflash1.h"


// FlashCarsa 对话框

class FlashCarsa : public CDialog
{
	DECLARE_DYNAMIC(FlashCarsa)

public:
	FlashCarsa(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashCarsa();

// 对话框数据
	enum { IDD = IDD_FLASH_CARSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
