#pragma once


// XTIME �Ի���

class XTIME : public CDialog
{
	DECLARE_DYNAMIC(XTIME)

public:
	XTIME(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XTIME();

// �Ի�������
	enum { IDD = IDD_XTIME_DIALOG };
	

protected:
	CBrush m_BkBrush; 
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CString XTIME::change(int num);
	//virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnBnClickedReturn();
};
