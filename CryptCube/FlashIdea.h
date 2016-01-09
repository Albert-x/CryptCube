#pragma once
#include "shockwaveflash1.h"


// CFlashIdea 对话框

class CFlashIdea : public CDialog
{
	DECLARE_DYNAMIC(CFlashIdea)

public:
	CFlashIdea(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlashIdea();

// 对话框数据
	enum { IDD = IDD_FLASH_IDEA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
