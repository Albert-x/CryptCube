#pragma once


// HashSHA1Sum �Ի���

class HashSHA1Sum : public CDialogEx
{
	DECLARE_DYNAMIC(HashSHA1Sum)

public:
	HashSHA1Sum(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HashSHA1Sum();

// �Ի�������
	enum { IDD = IDD_Hash_SHA1_SUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_digist;
	CString m_a1;
	CString m_a2;
	CString m_a3;
	CString m_a4;
	CString m_a5;
	CString m_b1;
	CString m_b2;
	CString m_b3;
	CString m_b4;
	CString m_b5;
	CString m_c1;
	CString m_c2;
	CString m_c3;
	CString m_c4;
	CString m_c5;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
