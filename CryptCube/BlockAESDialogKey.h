#pragma once
#include "Dialog.h" 
#include "afxcmn.h"

// CBlockAESDialogKey �Ի���

class CBlockAESDialogKey : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockAESDialogKey)

public:
	CBlockAESDialogKey(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlockAESDialogKey();

// �Ի�������
	enum { IDD = IDD_BLOCK_AES_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;

	CString m_strKey[44];
};
