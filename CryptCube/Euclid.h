#pragma once
#include "PublicKeyECCForm.h"
//#include "SkinH.h"
// Euclid 对话框

class Euclid : public CDialog
{
	DECLARE_DYNAMIC(Euclid)

public:
	Euclid(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Euclid();

// 对话框数据
	enum { IDD = IDD_Euclid_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
	HICON m_hIcon;
	CBrush m_BkBrush; 
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	int Euclid::gcd(int a, int b);
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton12();
	//afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);  
	//virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
