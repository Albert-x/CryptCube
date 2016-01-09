#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
#include "StreamRC4.h"
// CStreamRC4DialogList 对话框

class CStreamRC4DialogList : public CMyDialog
{
	DECLARE_DYNAMIC(CStreamRC4DialogList)

public:
	CStreamRC4DialogList(CWnd* pParent = NULL);   // 标准构造函数
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	virtual ~CStreamRC4DialogList();

// 对话框数据
	enum { IDD = IDD_STREAM_RC4_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;
	RC4 *m_pRC4;
	int nLen;
	CString m_strTitle;
};
