#pragma once
#include "shockwaveflash1.h"


// CFlashEcc 对话框

class CFlashEcc : public CDialog
{
	DECLARE_DYNAMIC(CFlashEcc)

public:
	CFlashEcc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlashEcc();

// 对话框数据
	enum { IDD = IDD_FLASH_ECC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//CShockwaveflash1 m_flashShow;
	CShockwaveflash1 m_flashShow;
};
