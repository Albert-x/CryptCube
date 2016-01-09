#pragma once
#include "shockwaveflash1.h"


// CFlashPgp 对话框

class CFlashPgp : public CDialog
{
	DECLARE_DYNAMIC(CFlashPgp)

public:
	CFlashPgp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlashPgp();

// 对话框数据
	enum { IDD = IDD_FLASH_PGP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
