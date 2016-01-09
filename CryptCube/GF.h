#pragma once


// GF 对话框

class GF : public CDialog
{
	DECLARE_DYNAMIC(GF)

public:
	GF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GF();

// 对话框数据
	enum { IDD = IDD_GF_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CBrush m_BkBrush; 
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString GF::change(int num);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
