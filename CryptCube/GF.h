#pragma once


// GF �Ի���

class GF : public CDialog
{
	DECLARE_DYNAMIC(GF)

public:
	GF(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GF();

// �Ի�������
	enum { IDD = IDD_GF_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
