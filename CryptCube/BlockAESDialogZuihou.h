#pragma once

#include "Dialog.h" 
// CBlockAESDialogZuihou 对话框

class CBlockAESDialogZuihou : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogZuihou)

public:
	CBlockAESDialogZuihou(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlockAESDialogZuihou();

// 对话框数据
	enum { IDD = IDD_BLOCK_AES_ZUIHOU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);


	CString m_strInput[4][4];
	CString m_strSubBytes[4][4];
	CString m_strShiftRows[4][4];
	CString m_strWi[4][4];
	CString m_strOutput[4][4];

	CListCtrl m_ctrlInput;
	CListCtrl m_ctrlSubBytes;
	CListCtrl m_ctrlShiftRows;
	CListCtrl m_ctrlWi;
	CListCtrl m_ctrlOutput;
};