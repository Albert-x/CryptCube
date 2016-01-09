#pragma once

#include "Dialog.h" 
// CBlockAESDialogZuihou �Ի���

class CBlockAESDialogZuihou : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogZuihou)

public:
	CBlockAESDialogZuihou(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlockAESDialogZuihou();

// �Ի�������
	enum { IDD = IDD_BLOCK_AES_ZUIHOU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4]);


	CString m_strInput[4][4];
	CString m_strSubBytes[4][4];
	CString m_strShiftRows[4][4];
	CString m_strWi[4][4];
	CString m_strOutput[4][4];

	CListCtrl m_ctrlInput;
	CListCtrl m_ctrlSubBytes;
	CListCtrl m_ctrlShiftRows;
	CListCtrl m_ctrlWi;
	CListCtrl m_ctrlOutput;
};