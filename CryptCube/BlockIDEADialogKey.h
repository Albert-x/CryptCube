#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
// CBlockIDEADialogKey �Ի���

class CBlockIDEADialogKey : public CMyDialog
{
	DECLARE_DYNAMIC(CBlockIDEADialogKey)

public:
	CBlockIDEADialogKey(CWnd* pParent = NULL);   // ��׼���캯��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	virtual ~CBlockIDEADialogKey();

// �Ի�������
	enum { IDD = IDD_BLOCK_IDEA_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;
	CString m_strKey[52];
};
