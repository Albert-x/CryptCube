#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeStringForm ������ͼ

class CCodeStringForm : public CForm
{
	DECLARE_DYNCREATE(CCodeStringForm)

public:
	CCodeStringForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CCodeStringForm();

public:
	enum { IDD = IDD_CODE_STRING };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	// �洢��ת�����ı�
	CString m_strNormal;
	// �洢ansi���뷽ʽ��ʮ�������ַ���
	CString m_strHexAnsi;
	// �洢Unicode���뷽ʽ��ʮ�������ַ���
	CString m_strHexUnicode;
	// �洢UniBigEnd���뷽ʽ��ʮ�������ַ���
	CString m_strHexUniBigEnd;
	// �洢UTF8���뷽ʽ��ʮ�������ַ���
	CString m_strHexUTF8;
	// �洢UTF7���뷽ʽ��ʮ�������ַ���
	CString m_strHexUTF7;
	// ����Base64���뷽ʽ��ASCII�ַ���
	CString m_strBase64;
	afx_msg void OnEnChangeEditStringNormal();
	afx_msg void OnEnChangeEditHexAnsi();
	afx_msg void OnEnChangeEditHexUnicode();
	afx_msg void OnEnChangeEditHexUnibigend();
	afx_msg void OnEnChangeEditHexUtf8();
	afx_msg void OnEnChangeEditHexUtf7();
	afx_msg void OnEnChangeEditBase64();
	// ��ת�����ı���
	CEdit m_editNormal;
	// ansi����ı���
	CEdit m_editHexAnsi;
	// Unicode���ı���
	CEdit m_editHexUnicode;
	// UniBigEnd���ı���
	CEdit m_editHexUniBigEnd;
	// UTF8���ı���
	CEdit m_editHexUTF8;
	// UTF7���ı���
	CEdit m_editHexUTF7;
	// Base64���ı���
	CEdit m_editBase64;
};


