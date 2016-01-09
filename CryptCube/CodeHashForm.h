#pragma once

#include "Form.h"
#include "afxcmn.h"

// CCodeHashForm ������ͼ

class CCodeHashForm : public CForm
{
	DECLARE_DYNCREATE(CCodeHashForm)

public:
	CCodeHashForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CCodeHashForm();

public:
	enum { IDD = IDD_CODE_HASH };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate();

	afx_msg void OnDropFiles(HDROP hDropInfo);

	DECLARE_MESSAGE_MAP()
public:
	// ��ʾ����HASH����б��
	CListCtrl m_ctrlListHash;
	void InitListCtrl();

	static UINT DoHashMD5(LPVOID param);
	static UINT DoHashMD2(LPVOID param);
	static UINT DoHashSHA1(LPVOID param);
	static UINT DoHashSHA(LPVOID param);
	//static UINT DoHashSHA512(LPVOID param);
	// �ļ���·��
	CString m_strFilePath;
	afx_msg void OnBnClickedButtonOpen();
	void DoHash();
};


