#pragma once
#include "Dialog.h" 
#include "afxcmn.h"

// CBlockAESDialogKey 对话框

class CBlockAESDialogKey : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogKey)

public:
	CBlockAESDialogKey(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlockAESDialogKey();

// 对话框数据
	enum { IDD = IDD_BLOCK_AES_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;

	CString m_strKey[44];
};
