#pragma once
#include "Dialog.h" 
#include "afxwin.h"

// CBlockAESDialogLun �Ի���

class CBlockAESDialogLun : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogLun)

public:
	CBlockAESDialogLun(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlockAESDialogLun();

// �Ի�������
	enum { IDD = IDD_BLOCK_AES_LUN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);


	CString m_strInput[9][4][4];
	CString m_strSubBytes[9][4][4];
	CString m_strShiftRows[9][4][4];
	CString m_strMixColumns[9][4][4];
	CString m_strWi[9][4][4];
	CString m_strOutput[9][4][4];

	CListCtrl m_ctrlInput;
	CListCtrl m_ctrlSubBytes;
	CListCtrl m_ctrlShiftRows;
	CListCtrl m_ctrlMixColumns;
	CListCtrl m_ctrlWi;
	CListCtrl m_ctrlOutput;

	BOOL m_bInitControl;

	CButton m_btnPrew;
	afx_msg void OnBnClickedButtonNext();
	CButton m_btnNext;
	afx_msg void OnBnClickedButtonPrew();
	CString m_strPage;
	CSpinButtonCtrl m_spinPage;
	afx_msg void OnEnChangeEditLunPage();
};

