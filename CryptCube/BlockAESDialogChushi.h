#pragma once

#include "Dialog.h" 
#include "afxcmn.h"

// CBlockAESDialogChushi �Ի���

class CBlockAESDialogChushi : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogChushi)

public:
	CBlockAESDialogChushi(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlockAESDialogChushi();

// �Ի�������
	enum { IDD = IDD_BLOCK_AES_CHUSHI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog(); // ������һ�ε���

	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);

	CString m_strInput[4][4];
	CString m_strWi[4][4];
	CString m_strOutput[4][4];
	CListCtrl m_ctrlInput;
	CListCtrl m_ctrlWi;
	CListCtrl m_ctrlOutput;
	afx_msg void OnBnClickedOk();
};
