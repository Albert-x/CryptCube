#pragma once
#include "Form.h"
#include "CustomButton.h"
#include "afxwin.h"
// CFlash 对话框
#define FSURL	_T("FSBH.swf")
class CFlash : public CForm
{
	DECLARE_DYNCREATE(CFlash)

public:
	CFlash();   // 标准构造函数
	virtual ~CFlash();

// 对话框数据
	enum { IDD = IDD_FLASH };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:

	//CCustomButton m_RSA;
	//CCustomButton m_RSA;
	//CCustomButton m_fang;
	CCustomButton m_RSA;
	CCustomButton m_fang;
	CCustomButton m_AES;
	CCustomButton m_DES;
	CCustomButton m_RC4;
	afx_msg void OnBnClickedButton4();
};
