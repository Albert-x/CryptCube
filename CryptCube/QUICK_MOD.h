#pragma once
//#include"SkinH.h"
//#include "SkinH.h"
//#pragma comment(lib,"SkinH.lib")
// QUICK_MOD 对话框

class QUICK_MOD : public CDialog
{
	DECLARE_DYNAMIC(QUICK_MOD)

public:
	QUICK_MOD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QUICK_MOD();
	CBrush m_BkBrush; 
// 对话框数据
	enum { IDD = IDD_QUICK_MOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCalButton();
	afx_msg void OnBnClickedShow();
	afx_msg void OnBnClickedRep();
};
