#pragma once
#include "shockwaveflash1.h"


// CFlashElg 对话框

class CFlashElg : public CDialog
{
	DECLARE_DYNAMIC(CFlashElg)

public:
	CFlashElg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlashElg();

// 对话框数据
	enum { IDD = IDD_FLASH_ELG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
