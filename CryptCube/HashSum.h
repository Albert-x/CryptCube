#pragma once


// CHashSum 对话框

class CHashSum : public CDialogEx
{
	DECLARE_DYNAMIC(CHashSum)

public:
	CHashSum(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHashSum();

	// 对话框数据
	enum { IDD = IDD_Hash_SumDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_digist;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CString m_ca1;
	CString m_cb1;
	CString m_cc1;
	CString m_cd1;
	CString m_ca2;
	CString m_cb2;
	CString m_cc2;
	CString m_cd2;
	CString m_ca3;
	CString m_cb3;
	CString m_cc3;
	CString m_cd3;
	afx_msg void OnEnChangeEdit2();
};
