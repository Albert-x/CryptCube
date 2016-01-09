#pragma once
#include "shockwaveflash1.h"


// FlashDes 对话框

class FlashDes : public CDialog
{
	DECLARE_DYNAMIC(FlashDes)

public:
	FlashDes(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FlashDes();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
	afx_msg void OnBnClickedCancel();
};
