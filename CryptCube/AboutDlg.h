#pragma once
#include "Dialog.h"

// CAboutDlg �Ի���

class CAboutDlg : public CMyDialog
{
	DECLARE_DYNAMIC(CAboutDlg)

public:
	CAboutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClickSyslinkHomepage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkDonate(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkMail(NMHDR *pNMHDR, LRESULT *pResult);
	static void OnAppDonate();
	static void OnAppWebsite();
	afx_msg void OnNMClickSyslinkQq(NMHDR *pNMHDR, LRESULT *pResult);
};
