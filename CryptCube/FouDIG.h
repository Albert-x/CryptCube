#pragma once

#include "HashMD5.h"

// CFouDIG 对话框

class CFouDIG : public CDialogEx
{
	DECLARE_DYNAMIC(CFouDIG)

public:
	CFouDIG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFouDIG();

	// 对话框数据
	enum { IDD = IDD_FOUR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	//afx_msg void OnBnClickedButton1();
	CString m_strPage1;
	CString m_strPage2;
	BOOL m_bInitControl1;
	BOOL m_bInitControl2;
	afx_msg void OnBnClickedButton1Prev();
	afx_msg void OnBnClickedButton1Next();
	afx_msg void OnEnChangeEdit1Md5Page();
	afx_msg void OnBnClickedButton2Prev();
	afx_msg void OnEnChangeEdit2Md5Page();
	afx_msg void OnBnClickedButton2Next();
	afx_msg void OnEnChangeEdit72();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	void CFouDIG::SlowLun1(int f);
	void CFouDIG::SlowLun2(int f,int ff);


	afx_msg void OnBnClickedButton3();
	MD5 *m_pMD5;
	afx_msg void OnEnChangeEdit5Cm();
	afx_msg void OnEnChangeEdit2Cb();
	CString m_a1;
	CString m_a2;
	CString m_b1;
	CString m_b2;
	CString m_c1;
	CString m_c2;
	CString m_d1;
	CString m_d2;
	//ULONG n[4][16];
	void init(void);
	CString m_1F;
	CString m_1G;
	CString m_1H;
	CString m_1I;
	CString m_2F;
	//	CEdit m_2G;
	CString m_2H;
	CString m_2G;
	CString m_2I;
	CString m_3F;
	CString m_3G;
	CString m_3H;
	CString m_3I;
	CString m_4F;
	CString m_4G;
	CString m_4H;
	CString m_4I;
	CString m_ca1;
	CString m_cb;
	CString m_ca2;
	//	CEdit m_cf;
	CString m_cf;
	CString m_cm;
	CString m_ct;
	CString m_cs;
	//	void XX(unsigned long A, unsigned long B, unsigned long C, unsigned long D, unsigned long X, unsigned long S, unsigned long T);
	//	void X(unsigned long B, unsigned long C, unsigned long D);
	//	void XX(unsigned long A, unsigned long B, unsigned long C, unsigned long D,unsigned long X,  unsigned long S, unsigned long T,int lun);
	ULONG X(unsigned long B, unsigned long C, unsigned long D, int lun);
	void XX(unsigned long A, unsigned long B, unsigned long C, unsigned long D, unsigned long x, int S, unsigned long T, int lun);

	//	unsigned long RotateLeft1(unsigned long x, unsigned long n)
	//	{
	//		return 0;
	//	}
	unsigned long RotateLeft1(unsigned long x, int n);
	CString m_5F;
	CString m_5G;
	afx_msg void OnEnChangeEdit4I();
};
