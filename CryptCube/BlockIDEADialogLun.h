#pragma once
#include "Dialog.h" 
#include "BlockIDEA.h"
// CBlockIDEADialogLun �Ի���

class CBlockIDEADialogLun : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockIDEADialogLun)

public:
	CBlockIDEADialogLun(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlockIDEADialogLun();

// �Ի�������
	enum { IDD = IDD_BLOCK_IDEA_LUN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();

	DECLARE_MESSAGE_MAP()

public:
	CImage m_Image;
	CString m_strX1;
	CString m_strX2;
	CString m_strX3;
	CString m_strX4;

	CString m_strZ0;
	CString m_strZ1;
	CString m_strZ2;
	CString m_strZ3;
	CString m_strZ4;
	CString m_strZ5;


	CString m_strW11;
	CString m_strW12;
	CString m_strW13;
	CString m_strW14;
	void ShowLun(int n);
	IDEA *m_pIDEA;
		
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnEnChangeEditLunPage();


	BOOL m_bInitControl;
	CString m_strPage;
	CSpinButtonCtrl m_spinPage;
};
