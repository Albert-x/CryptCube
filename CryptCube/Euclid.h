#pragma once
#include "PublicKeyECCForm.h"
//#include "SkinH.h"
// Euclid �Ի���

class Euclid : public CDialog
{
	DECLARE_DYNAMIC(Euclid)

public:
	Euclid(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Euclid();

// �Ի�������
	enum { IDD = IDD_Euclid_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
