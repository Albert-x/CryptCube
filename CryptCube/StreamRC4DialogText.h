#pragma once
#include "Dialog.h" 
#include "afxcmn.h"
// CStreamRC4DialogText �Ի���

class CStreamRC4DialogText : public CMyDialog
{
	DECLARE_DYNAMIC(CStreamRC4DialogText)

public:
	CStreamRC4DialogText(CWnd* pParent = NULL);   // ��׼���캯��
	virtual BOOL OnInitDialog(); // ������һ�ε���
	virtual ~CStreamRC4DialogText();

// �Ի�������
	enum { IDD = IDD_STREAM_RC4_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()

public:

	CString m_strTitle;
	CString m_strBox[16][16];
	void UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[16]);
	void InitListCtrl(CListCtrl &ctrlList);
	CListCtrl m_ctrlBox;
};
