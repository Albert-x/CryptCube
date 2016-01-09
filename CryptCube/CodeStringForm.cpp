// CodeStringForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeStringForm.h"
#include "CStringConvert.h"

// CCodeStringForm

IMPLEMENT_DYNCREATE(CCodeStringForm, CForm)

CCodeStringForm::CCodeStringForm()
	: CForm(CCodeStringForm::IDD)
	, m_strNormal(_T(""))
	, m_strHexAnsi(_T(""))
	, m_strHexUnicode(_T(""))
	, m_strHexUniBigEnd(_T(""))
	, m_strHexUTF8(_T(""))
	, m_strHexUTF7(_T(""))
	, m_strBase64(_T(""))
{

}

CCodeStringForm::~CCodeStringForm()
{
}

void CCodeStringForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING_NORMAL, m_strNormal);
	//DDV_MaxChars(pDX, m_strNormal, 1000);
	DDX_Text(pDX, IDC_EDIT_HEX_ANSI, m_strHexAnsi);
	//DDV_MaxChars(pDX, m_strHexANSI, 4000);
	DDX_Text(pDX, IDC_EDIT_HEX_UNICODE, m_strHexUnicode);
	//DDV_MaxChars(pDX, m_strHexUnicode, 4000);
	DDX_Text(pDX, IDC_EDIT_HEX_UNIBIGEND, m_strHexUniBigEnd);
	//DDV_MaxChars(pDX, m_strHexUniBigEnd, 4000);
	DDX_Text(pDX, IDC_EDIT_HEX_UTF8, m_strHexUTF8);
	//DDV_MaxChars(pDX, m_strHexUTF8, 6000);
	DDX_Text(pDX, IDC_EDIT_HEX_UTF7, m_strHexUTF7);
	//DDV_MaxChars(pDX, m_strHexUTF7, 10000);
	DDX_Text(pDX, IDC_EDIT_BASE64, m_strBase64);
	DDX_Control(pDX, IDC_EDIT_STRING_NORMAL, m_editNormal);
	DDX_Control(pDX, IDC_EDIT_HEX_ANSI, m_editHexAnsi);
	DDX_Control(pDX, IDC_EDIT_HEX_UNICODE, m_editHexUnicode);
	DDX_Control(pDX, IDC_EDIT_HEX_UNIBIGEND, m_editHexUniBigEnd);
	DDX_Control(pDX, IDC_EDIT_HEX_UTF8, m_editHexUTF8);
	DDX_Control(pDX, IDC_EDIT_HEX_UTF7, m_editHexUTF7);
	DDX_Control(pDX, IDC_EDIT_BASE64, m_editBase64);
}

BEGIN_MESSAGE_MAP(CCodeStringForm, CForm)

	ON_EN_CHANGE(IDC_EDIT_STRING_NORMAL, &CCodeStringForm::OnEnChangeEditStringNormal)
	ON_EN_CHANGE(IDC_EDIT_HEX_ANSI, &CCodeStringForm::OnEnChangeEditHexAnsi)
	ON_EN_CHANGE(IDC_EDIT_HEX_UNICODE, &CCodeStringForm::OnEnChangeEditHexUnicode)
	ON_EN_CHANGE(IDC_EDIT_HEX_UNIBIGEND, &CCodeStringForm::OnEnChangeEditHexUnibigend)
	ON_EN_CHANGE(IDC_EDIT_HEX_UTF8, &CCodeStringForm::OnEnChangeEditHexUtf8)
	ON_EN_CHANGE(IDC_EDIT_HEX_UTF7, &CCodeStringForm::OnEnChangeEditHexUtf7)
	ON_EN_CHANGE(IDC_EDIT_BASE64, &CCodeStringForm::OnEnChangeEditHexUtf7)
END_MESSAGE_MAP()


// CCodeStringForm ���

#ifdef _DEBUG
void CCodeStringForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeStringForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeStringForm ��Ϣ�������


//����ԭʼ�ı������������ݷ����仯��ʱ��ִ�д˷���
void CCodeStringForm::OnEnChangeEditStringNormal()
{
	UpdateData();//�����пؼ���ֵȡ����Ա����

	//����ANSI��ʽ��ʮ�����Ʊ���
	m_strHexAnsi = Text2AnsiHex(m_strNormal);

	//����Unicode��ʽ��ʮ�����Ʊ���
	m_strHexUnicode = Text2UnicodeHex(m_strNormal);

	//����UniBigEnd��ʽ��ʮ�����Ʊ���
	m_strHexUniBigEnd = Text2UniBigEndHex(m_strNormal);

	//����UTF8��ʽ��ʮ�����Ʊ���
	m_strHexUTF8 = Text2Utf8(m_strNormal);

	//����UTF7��ʽ��ʮ�����Ʊ���
	m_strHexUTF7 = Text2Utf7(m_strNormal);

	//�ѳ�Ա������ֵ�����ؼ�
	UpdateData(FALSE);
}

void CCodeStringForm::OnEnChangeEditHexAnsi()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexAnsi);
	if( -1 != nCheckHex )
	{
		m_strHexAnsi.Delete(nCheckHex);
		m_editHexAnsi.SetWindowText(m_strHexAnsi);
		m_editHexAnsi.SetSel(nCheckHex,nCheckHex,TRUE);
		return;
	}

	m_strNormal = AnsiHex2Text(m_strHexAnsi);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}

void CCodeStringForm::OnEnChangeEditHexUnicode()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexUnicode);
	if( -1 != nCheckHex )
	{
		m_strHexUnicode.Delete(nCheckHex);
		m_editHexUnicode.SetWindowText(m_strHexUnicode);
		m_editHexUnicode.SetSel(nCheckHex,nCheckHex,TRUE);
		return;
	}

	m_strNormal = UnicodeHex2Text(m_strHexUnicode);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}

void CCodeStringForm::OnEnChangeEditHexUnibigend()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexUniBigEnd);
	if( -1 != nCheckHex )
	{
		m_strHexUniBigEnd.Delete(nCheckHex);
		m_editHexUniBigEnd.SetWindowText(m_strHexUniBigEnd);
		m_editHexUniBigEnd.SetSel(nCheckHex,nCheckHex,TRUE);
		return;
	}
	m_strNormal = UniBigEndHex2Text(m_strHexUniBigEnd);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}

void CCodeStringForm::OnEnChangeEditHexUtf8()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexUTF8);
	if( -1 != nCheckHex )
	{
		m_strHexUTF8.Delete(nCheckHex);
		m_editHexUTF8.SetWindowText(m_strHexUTF8);
		m_editHexUTF8.SetSel(nCheckHex,nCheckHex,TRUE);
		return;
	}
	m_strNormal = Utf82Text(m_strHexUTF8);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}

void CCodeStringForm::OnEnChangeEditHexUtf7()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexUTF7);
	if( -1 != nCheckHex )
	{
		m_strHexUTF7.Delete(nCheckHex);
		m_editHexUTF7.SetWindowText(m_strHexUTF7);
		m_editHexUTF7.SetSel(nCheckHex,nCheckHex,TRUE);
		return;
	}
	m_strNormal = Utf72Text(m_strHexUTF7);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}

void CCodeStringForm::OnEnChangeEditBase64()
{
	UpdateData();

	//����������ַ�
	int nCheckHex = CStrCheckHex(m_strHexUTF7);
	if (-1 != nCheckHex)
	{
		m_strBase64.Delete(nCheckHex);
		m_editBase64.SetWindowText(m_strHexUTF7);
		m_editBase64.SetSel(nCheckHex, nCheckHex, TRUE);
		return;
	}
	m_strNormal = Base642Text(m_strBase64);

	UpdateData(FALSE);

	OnEnChangeEditStringNormal();

}