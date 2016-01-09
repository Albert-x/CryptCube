#pragma once

#include "Dialog.h" 
#include "afxcmn.h"

// CBlockAESDialogChushi 对话框

class CBlockAESDialogChushi : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogChushi)

public:
	CBlockAESDialogChushi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlockAESDialogChushi();

// 对话框数据
	enum { IDD = IDD_BLOCK_AES_CHUSHI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog(); // 构造后第一次调用

	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);

	CString m_strInput[4][4];
	CString m_strWi[4][4];
	CString m_strOutput[4][4];
	CListCtrl m_ctrlInput;
	CListCtrl m_ctrlWi;
	CListCtrl m_ctrlOutput;
	afx_msg void OnBnClickedOk();
};
