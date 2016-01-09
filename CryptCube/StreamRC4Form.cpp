// StreamRC4Form.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "StreamRC4Form.h"
#include "CStringConvert.h"


// CStreamRC4Form

IMPLEMENT_DYNCREATE(CStreamRC4Form, CForm)

CStreamRC4Form::CStreamRC4Form()
	: CForm(CStreamRC4Form::IDD)
	, m_stateRadioAnsi(FALSE)
{

}

CStreamRC4Form::~CStreamRC4Form()
{
}

void CStreamRC4Form::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RC4_PLAIN, m_strPlainText);
	DDV_MaxChars(pDX, m_strPlainText, 1024);
	DDX_Text(pDX, IDC_EDIT_RC4_PLAIN_HEX, m_strPlainTextHex);
	//DDV_MaxChars(pDX, m_strPlainTextHex, 16);
	DDX_Text(pDX, IDC_EDIT_RC4_KEY, m_strKey);
	DDV_MaxChars(pDX, m_strKey, 1024);
	DDX_Text(pDX, IDC_EDIT_RC4_KEY_HEX, m_strKeyHex);
	//DDV_MaxChars(pDX, m_strKeyHex, 16);
	DDX_Text(pDX, IDC_EDIT_RC4_CIPHER, m_strCipherText);
	//DDV_MaxChars(pDX, m_strCipherText, 8);
	DDX_Text(pDX, IDC_EDIT_RC4_CIPHER_HEX, m_strCipherTextHex);
	//DDV_MaxChars(pDX, m_strCipherTextHex, 16);
	//DDX_Control(pDX, IDC_EDIT_RC4_PLAIN, m_ctrlPlainText);
	//DDX_Control(pDX, IDC_EDIT_RC4_KEY, m_ctrlKey);
	DDX_Radio(pDX, IDC_RADIO_ANSI, m_stateRadioAnsi);
	DDX_Control(pDX, IDC_SPIN_SBOX, m_spinSbox);
	DDX_Text(pDX, IDC_EDIT_SBOX, m_strSbox);
	DDX_Control(pDX, IDC_EDIT_SBOX, m_ctrlSbox);
	DDX_Control(pDX, IDC_BUTTON_CHUSHI, m_btnChushi);
	DDX_Control(pDX, IDC_BUTTON_KBOX, m_btnKBox);
	DDX_Control(pDX, IDC_BUTTON_ZHIHUAN, m_btnZhihuan);
	DDX_Control(pDX, IDC_BUTTON_DIEDAI, m_btnDiedai);
}

BEGIN_MESSAGE_MAP(CStreamRC4Form, CForm)
	ON_EN_CHANGE(IDC_EDIT_RC4_PLAIN, &CStreamRC4Form::OnEnChangeEditPlain)
	ON_EN_CHANGE(IDC_EDIT_RC4_KEY, &CStreamRC4Form::OnEnChangeEditKey)
	ON_EN_CHANGE(IDC_EDIT_SBOX, &CStreamRC4Form::OnEnChangeEditSbox)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CStreamRC4Form::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CStreamRC4Form::OnBnClickedRadioUnicode)
	ON_BN_CLICKED(IDC_BUTTON_CHUSHI, &CStreamRC4Form::OnBnClickedButtonChushi)
	ON_BN_CLICKED(IDC_BUTTON_KBOX, &CStreamRC4Form::OnBnClickedButtonKBox)
	ON_BN_CLICKED(IDC_BUTTON_ZHIHUAN, &CStreamRC4Form::OnBnClickedButtonZhihuan)
	ON_BN_CLICKED(IDC_BUTTON_DIEDAI, &CStreamRC4Form::OnBnClickedButtonDiedai)
END_MESSAGE_MAP()


// CStreamRC4Form 诊断

#ifdef _DEBUG
void CStreamRC4Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CStreamRC4Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CStreamRC4Form 消息处理程序


void CStreamRC4Form::OnInitialUpdate()
{
	CForm::OnInitialUpdate();

	// 初始化DES话结构
	m_pRC4= new RC4();

	m_strSbox = _T("256");
    m_spinSbox.SetRange(1, 256);
	UpdateData(FALSE);

	// 初始化完成标志位
	m_bInitControl= TRUE;

}


void CStreamRC4Form::DoEncrypt()
{
	UpdateData(TRUE);

// 判断明文和密钥是否为空，为空则不计算。
	if((m_strPlainTextHex.IsEmpty())||(m_strKeyHex.IsEmpty())) 
	{
		m_strCipherText.Empty();
		m_strCipherTextHex.Empty();

		m_btnChushi.EnableWindow(FALSE);
		m_btnKBox.EnableWindow(FALSE);
		m_btnZhihuan.EnableWindow(FALSE);
		m_btnDiedai.EnableWindow(FALSE);
		UpdateData(FALSE);
		return;
	}


	////////////////////////////////////////////////////////////////////////////////
	// 获取明文和密文，ANSI方式存储的二进制数据


	// 整理字符串
	memset(szSourceKey,0,2049);
	memset(szPlaintextData,0,2049);

	//将明文十六进制转换为ANSI方式存储的字符串
	for( int i = 0; i < m_strPlainTextHex.GetLength(); i+=2 )
	{
		CString strTemp=m_strPlainTextHex.Mid(i,2);
		int nhex = _tcstoul(strTemp, 0, 16);

		szPlaintextData[i/2]=nhex;
	}

	//将密钥十六进制转换为ANSI方式存储的字符串
	for( int i = 0; i < m_strKeyHex.GetLength(); i+=2 )
	{
		CString strTemp=m_strKeyHex.Mid(i,2);
		int nhex = _tcstoul(strTemp, 0, 16);

		szSourceKey[i/2]=nhex;
	}

	szPlaintextData[m_strPlainTextHex.GetLength()/2]=_T('\0');
	szSourceKey[m_strKeyHex.GetLength()/2]=_T('\0');



	////////////////////////////////////////////////////////////////////////////////
	// RC4加密

	// 设置Sbox的大小
	m_pRC4->g_SBoxSize=_ttoi(m_strSbox);
	m_pRC4->SetKey(szSourceKey, m_strKeyHex.GetLength()/2);
	m_pRC4->Setup();
	m_pRC4->Encrypt(szPlaintextData, m_strPlainTextHex.GetLength()/2);


	// CipherTextA 
	CStringA CipherTextA;

	// 用“字节”型数据分析字符串
	BYTE *binText = (BYTE*)(LPCSTR)szPlaintextData;

	// 一个字节一个字节的输出十六进制数据
	for( int i = 0; i < m_strPlainTextHex.GetLength()/2; ++i )
	{
		// 让转换后的字符两个两个的显示出来
		CipherTextA.AppendFormat("%02X" ,binText[i]);
	}

	m_strCipherTextHex = CStrA2CStrT(CipherTextA);


	////////////////////////////////////////////////////////////////////////////////
	// 将十六进制转换成字符串
	if(FALSE == m_stateRadioAnsi)
	{

		// 以ANSI方式的转换密文十六进制为字符串
		m_strCipherText=AnsiHex2Text(m_strCipherTextHex);
	}
	else
	{
		// 以Unicode方式的转换密文十六进制为字符串
		m_strCipherText=UnicodeHex2Text(m_strCipherTextHex);
	}

	RC4Show();

	UpdateData(FALSE);
}


void CStreamRC4Form::RC4Show()
{

	m_btnChushi.EnableWindow(TRUE);
	m_btnKBox.EnableWindow(TRUE);
	m_btnZhihuan.EnableWindow(TRUE);
	m_btnDiedai.EnableWindow(TRUE);

}



void CStreamRC4Form::OnEnChangeEditPlain()
{
	UpdateData(TRUE);

	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 计算ANSI方式的十六进制编码
		m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	}
	else
	{
		// Unicode方式

		//计算Unicode方式的十六进制编码
		m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	}
	UpdateData(FALSE);
	DoEncrypt();
}

void CStreamRC4Form::OnEnChangeEditKey()
{
	UpdateData(TRUE);

	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 计算ANSI方式的十六进制编码
		m_strKeyHex = Text2AnsiHex(m_strKey);

	}
	else
	{
		// Unicode方式

		//计算Unicode方式的十六进制编码
		m_strKeyHex = Text2UnicodeHex(m_strKey);
	}
	UpdateData(FALSE);
	DoEncrypt();
}

void CStreamRC4Form::OnEnChangeEditSbox()
{
	if(TRUE == m_bInitControl)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strSbox);

		if(nLun > 256)
		{
			nLun = 256;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strSbox.Format(_T("%d"), nLun);

		UpdateData(FALSE);
		DoEncrypt();
	}
}

void CStreamRC4Form::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);

	// 重新计算
	OnEnChangeEditPlain();
	OnEnChangeEditKey();
	UpdateData(FALSE);
}

void CStreamRC4Form::OnBnClickedRadioUnicode()
{
	// 和点击点击ANSI时相同的操作
	OnBnClickedRadioAnsi();
}

void CStreamRC4Form::OnBnClickedButtonChushi()
{

	// 初始SBOX对话框
	dlgChushi.m_strTitle.Format(_T("RC4加密过程 - 初始S-Box"));


	// 填充SBOX数据

	unsigned int k=0;
	for(unsigned int i=0;i<16;i++)
	{
		for(unsigned int j=0;j<16;j++)
		{
			if(k<m_pRC4->g_SBoxSize) dlgChushi.m_strBox[i][j].Format(_T("%02X"),m_pRC4->m_SBoxChushi[k]);
			else dlgChushi.m_strBox[i][j].Format(_T(""));
			k++;
		}
	}

	dlgChushi.DoModal();
}

void CStreamRC4Form::OnBnClickedButtonKBox()
{
	// KBOX对话框
	dlgKBox.m_strTitle.Format(_T("RC4加密过程 - K-Box"));

	// 填充KBOX数据
	unsigned int k=0;
	for(unsigned int i=0;i<16;i++)
	{
		for(unsigned int j=0;j<16;j++)
		{
			if(k<m_pRC4->g_SBoxSize) dlgKBox.m_strBox[i][j].Format(_T("%02X"),m_pRC4->m_KBox[k]);
			else dlgKBox.m_strBox[i][j].Format(_T(""));
			k++;
		}
	}
	dlgKBox.DoModal();
}

void CStreamRC4Form::OnBnClickedButtonZhihuan()
{
	// 置换SBOX对话框
	dlgZhihuan.m_strTitle.Format(_T("RC4加密过程 - 置换S-Box"));

	// 填充SBOX数据
	unsigned int k=0;
	for(unsigned int i=0;i<16;i++)
	{
		for(unsigned int j=0;j<16;j++)
		{
			if(k<m_pRC4->g_SBoxSize) dlgZhihuan.m_strBox[i][j].Format(_T("%02X"),m_pRC4->m_SBoxZhihuan[k]);
			else dlgZhihuan.m_strBox[i][j].Format(_T(""));
			k++;
		}
	}

	dlgZhihuan.DoModal();
}

void CStreamRC4Form::OnBnClickedButtonDiedai()
{
	// 迭代值对话框
	dlgDiedai.m_strTitle.Format(_T("RC4加密过程 - 迭代值"));
	dlgDiedai.nLen= m_strPlainTextHex.GetLength()/2;
	dlgDiedai.m_pRC4= m_pRC4;
	dlgDiedai.DoModal();
}
