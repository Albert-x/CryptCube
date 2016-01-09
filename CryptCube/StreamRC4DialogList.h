#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
#include "StreamRC4.h"
// CStreamRC4DialogList �Ի���

class CStreamRC4DialogList : public CMyDialog
{
	DECLARE_DYNAMIC(CStreamRC4DialogList)

public:
	CStreamRC4DialogList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	virtual ~CStreamRC4DialogList();

// �Ի�������
	enum { IDD = IDD_STREAM_RC4_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()

public:
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlKey;
	RC4 *m_pRC4;
	int nLen;
	CString m_strTitle;
};
