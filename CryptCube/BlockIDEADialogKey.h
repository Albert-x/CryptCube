#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
// CBlockIDEADialogKey 对话框

class CBlockIDEADialogKey : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockIDEADialogKey)

public:
	CBlockIDEADialogKey(CWnd* pParent = NULL);   // 标准构造函数
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	virtual ~CBlockIDEADialogKey();

// 对话框数据
	enum { IDD = IDD_BLOCK_IDEA_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;
	CString m_strKey[52];
};
