#pragma once
#include "shockwaveflash1.h"


// FlashAffine 对话框

class FlashAffine : public CDialog
{
	DECLARE_DYNAMIC(FlashAffine)

public:
	FlashAffine(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashAffine();

// 对话框数据
	enum { IDD = IDD_FLASH_AFFINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
