#pragma once


// HashSHA1Lun 对话框

class HashSHA1Lun : public CDialogEx
{
	DECLARE_DYNAMIC(HashSHA1Lun)

public:
	HashSHA1Lun(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HashSHA1Lun();

// 对话框数据
	enum { IDD = IDD_Hash_SHA1_Lun };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_l1;
//	CString m_l2;
	CString m_l10;
	CString m_l11;
	CString m_l12;
	CString m_l13;
	CString m_l14;
	CString m_l15;
	CString m_l16;
	CString m_l17;
	CString m_l18;
	CString m_l19;
	CString m_l2;
	CString m_l20;
	CString m_l21;
	CString m_l22;
	CString m_l23;
	CString m_l24;
	CString m_l25;
	CString m_l3;
	CString m_l4;
//	CString m_l5;
//	CString m_l6;
	CString m_l6;
	CString m_l7;
	CString m_l8;
	CString m_l9;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void init(void);
	virtual BOOL OnInitDialog();
	bool m_bInitControl1;
	void OnEnChangeEdit1sha1Page(void);
	void lun(void);
	void go(void);
};
