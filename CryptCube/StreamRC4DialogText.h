#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
// CStreamRC4DialogText 对话框

class CStreamRC4DialogText : public CMyDialog
{
	DECLARE_DYNAMIC(CStreamRC4DialogText)

public:
	CStreamRC4DialogText(CWnd* pParent = NULL);   // 标准构造函数
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	virtual ~CStreamRC4DialogText();

// 对话框数据
	enum { IDD = IDD_STREAM_RC4_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()

public:

	CString m_strTitle;
	CString m_strBox[16][16];
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[16]);
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlBox;
};
