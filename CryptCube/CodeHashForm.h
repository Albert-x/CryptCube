#pragma once

#include "Form.h"
#include "afxcmn.h"

// CCodeHashForm 窗体视图

class CCodeHashForm : public CForm
{
	DECLARE_DYNCREATE(CCodeHashForm)

public:
	CCodeHashForm();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate();

	afx_msg void OnDropFiles(HDROP hDropInfo);

	DECLARE_MESSAGE_MAP()
public:
	// 显示各种HASH码的列表框
	CListCtrl m_ctrlListHash;
	void InitListCtrl();

	static UINT DoHashMD5(LPVOID param);
	static UINT DoHashMD2(LPVOID param);
	static UINT DoHashSHA1(LPVOID param);
	static UINT DoHashSHA(LPVOID param);
	//static UINT DoHashSHA512(LPVOID param);
	// 文件的路径
	CString m_strFilePath;
	afx_msg void OnBnClickedButtonOpen();
	void DoHash();
};


