
#pragma once
#include "Dialog.h" 
#include "BlockIDEA.h"
// CBlockIDEADialogZuihou 对话框

class CBlockIDEADialogZuihou : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockIDEADialogZuihou)

public:
	CBlockIDEADialogZuihou(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlockIDEADialogZuihou();

// 对话框数据
	enum { IDD = IDD_BLOCK_IDEA_ZUIHOU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog(); // 构造后第一次调用
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();
	DECLARE_MESSAGE_MAP()

public:
	CImage m_Image;

	CString m_strW81;
	CString m_strW82;
	CString m_strW83;
	CString m_strW84;
	CString m_strZ48;
	CString m_strZ49;
	CString m_strZ50;
	CString m_strZ51;
	CString m_strY1;
	CString m_strY2;
	CString m_strY3;
	CString m_strY4;
	IDEA *m_pIDEA;


	afx_msg void OnBnClickedOk();
};
