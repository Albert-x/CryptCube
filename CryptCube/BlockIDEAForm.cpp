// BlockIDEAForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockIDEAForm.h"
#include "BlockIDEADialogKey.h"
#include "BlockIDEADialogZuiHou.h"
#include "BlockIDEADialogLun.h"
#include "CStringConvert.h"

// CBlockIDEAForm

IMPLEMENT_DYNCREATE(CBlockIDEAForm, CForm)

CBlockIDEAForm::CBlockIDEAForm()
	: CForm(CBlockIDEAForm::IDD)
	, m_stateRadioAnsi(FALSE)
{

}

CBlockIDEAForm::~CBlockIDEAForm()
{
}

void CBlockIDEAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_ANSI, m_stateRadioAnsi);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT, m_strPlainText);
	//DDV_MaxChars(pDX, m_strPlainText, 8);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX, m_strPlainTextHex);
	//DDV_MaxChars(pDX, m_strPlainTextHex, 16);
	DDX_Text(pDX, IDC_EDIT_KEY, m_strKey);
	//DDV_MaxChars(pDX, m_strKey, 8);
	DDX_Text(pDX, IDC_EDIT_KEY_HEX, m_strKeyHex);
	//DDV_MaxChars(pDX, m_strKeyHex, 16);
	DDX_Text(pDX, IDC_EDIT_CIPHERTEXT, m_strCipherText);
	//DDV_MaxChars(pDX, m_strCipherText, 8);
	DDX_Text(pDX, IDC_EDIT_CIPHERTEXT_HEX, m_strCipherTextHex);
	//DDV_MaxChars(pDX, m_strCipherTextHex, 16);
	DDX_Control(pDX, IDC_EDIT_PLAINTEXT, m_ctrlPlainText);
	DDX_Control(pDX, IDC_EDIT_KEY, m_ctrlKey);
	DDX_Control(pDX, IDC_EDIT_CIPHERTEXT, m_ctrlCipherText);

	DDX_Control(pDX, IDC_BUTTON_LUN, m_btnLun);
	DDX_Control(pDX, IDC_BUTTON_ZUIHOU, m_btnZuihou);
	DDX_Control(pDX, IDC_BUTTON_KEY, m_btnKey);
}

BEGIN_MESSAGE_MAP(CBlockIDEAForm, CForm)
	ON_BN_CLICKED(IDC_BUTTON_LUN, &CBlockIDEAForm::OnBnClickedButtonLun)
	ON_BN_CLICKED(IDC_BUTTON_KEY, &CBlockIDEAForm::OnBnClickedButtonKey)
	ON_BN_CLICKED(IDC_BUTTON_ZUIHOU, &CBlockIDEAForm::OnBnClickedButtonZuihou)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CBlockIDEAForm::OnEnChangeEditPlaintext)
	ON_EN_CHANGE(IDC_EDIT_KEY, &CBlockIDEAForm::OnEnChangeEditKey)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CBlockIDEAForm::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CBlockIDEAForm::OnBnClickedRadioUnicode)
END_MESSAGE_MAP()


// CBlockIDEAForm 诊断

#ifdef _DEBUG
void CBlockIDEAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CBlockIDEAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


void CBlockIDEAForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

}


// CBlockIDEAForm 消息处理程序


// 限制输入框的字符长度
BOOL CBlockIDEAForm::PreTranslateMessage(MSG* pMsg)
{

	if(WM_CHAR == pMsg->message)
	{
		////////////////////////////////////////////////明文输入框 /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_PLAINTEXT)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//是否作处理
			const unsigned int chCharCode =  pMsg->wParam;  


			//允许用户输入两种删除键,故不处理
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//如果选中全部,可以任意输入
			int nStart,nEnd;
			m_ctrlPlainText.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strPlainText.GetLength())
				bDo = false ;


			//处理输入框的可输入的字节数
			CString strPlainChar;
			strPlainChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI方式允许输入8个字节
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 8)//len -1 才是长度
					bDo = false;	
			}
			else
			{
				// Unicode方式允许输入4个字符
				if(CStrT2CStrW(m_strPlainText).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 4)
					bDo = false;	
			}

			if(bDo)
				return true;

		}


		////////////////////////////////////////////////密钥输入框 /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_KEY)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//是否作处理
			const unsigned int chCharCode =  pMsg->wParam;  


			//允许用户输入两种删除键,故不处理
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//如果选中全部,可以任意输入
			int nStart,nEnd;
			m_ctrlKey.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strKey.GetLength())
				bDo = false ;


			//处理输入框的可输入的字节数
			CString strKeyChar;
			strKeyChar.Format(_T("%c"),chCharCode); 	

			strKeyChar.GetLength();

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI方式允许输入16个字节
				if(CStrT2CStrA(m_strKey).GetLength()+CStrT2CStrA(strKeyChar).GetLength() <= 16)//len -1 才是长度
					bDo = false;	
			}
			else
			{
				// Unicode方式允许输入8个字符
				if(CStrT2CStrW(m_strKey).GetLength()+CStrT2CStrW(strKeyChar).GetLength() <= 8)
					bDo = false;	
			}

			if(bDo)
				return true;

		}


	}

	return CForm::PreTranslateMessage(pMsg);
}




void CBlockIDEAForm::OnBnClickedButtonLun()
{
	dlgLun.m_pIDEA=m_pIDEA;
	dlgLun.DoModal();
	dlgLun.m_bInitControl=  FALSE;
}

void CBlockIDEAForm::OnBnClickedButtonKey()
{
	CString strTemp;
	for(int i=0;i<52;i++)
	{
		strTemp.Format(_T("%04X"),m_EK[i]);
		dlgKey.m_strKey[i]=strTemp;
	}
	
	
	dlgKey.DoModal();
}

void CBlockIDEAForm::OnBnClickedButtonZuihou()
{
	dlgZuihou.m_pIDEA=m_pIDEA;
	dlgZuihou.DoModal();
}


// DES加密过程
void CBlockIDEAForm::DoEncrypt()
{
	// 判断明文和密钥是否为空，为空则不计算。
	if((!m_strPlainTextHex.GetLength())||(!m_strKeyHex.GetLength())) 
	{

		m_strCipherTextHex.Empty();
		m_strCipherText.Empty();

		m_btnLun.EnableWindow(FALSE);
		m_btnZuihou.EnableWindow(FALSE);
		m_btnKey.EnableWindow(FALSE);

		UpdateData(FALSE);
		return;
	}

	// 刷新控件的成员变量
	UpdateData(TRUE);



	////////////////////////////////////////////////////////////////////////////////
	// 获取明文和密文，ANSI方式存储的二进制数据
	unsigned char szSourceKey[17],szPlaintextData[17];

	// 整理字符串
	memset(szSourceKey,0,17);
	memset(szPlaintextData,0,17);


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


	////////////////////////////////////////////////////////////////////////////////
	// IDEA加密
	m_pIDEA = new IDEA();
	char c[100]={0},key[100]={0};
	memset(c,0,100);
	memset(key,0,100);
	word16 in[4], dkey[8],out[4];
	char Hex16[100];//16位密文
	
	word16 Inter[9][4];
	word16 Last[4];

	memcpy(c,szPlaintextData,m_strPlainTextHex.GetLength()/2);
	memcpy(key,szSourceKey,m_strKeyHex.GetLength()/2);

	
	for(int i=0; i<4; i++)
	{
		in[i] = c[i*2] | (c[i*2 +1] << 8);
	}

	for(int i=0; i<8; i++)
	{
		dkey[i] = key[i*2] | (key[i*2 +1] << 8);
	}

	m_pIDEA->en_key_idea(dkey,m_EK);
	m_pIDEA->cipher_idea(in,out,m_EK,Inter,Last);
	m_pIDEA->Result_For_16 (out,Hex16);


	m_strCipherTextHex.Empty();
	for(int i=0;i<16;i++)
	{
		m_strCipherTextHex.AppendFormat(_T("%c"),Hex16[i]);

	}



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


	m_btnLun.EnableWindow(TRUE);
	m_btnZuihou.EnableWindow(TRUE);
	m_btnKey.EnableWindow(TRUE);

	UpdateData(FALSE);

}



void CBlockIDEAForm::OnEnChangeEditPlaintext()
{
	UpdateData(TRUE);

	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 对复制的长数据进行截断
		if(CStrT2CStrA(m_strPlainText).GetLength()>8)
		m_strPlainText = CStrA2CStrT(CStrT2CStrA(m_strPlainText).Left(8));

		// 计算ANSI方式的十六进制编码
		m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	}
	else
	{
		// Unicode方式

		// 对复制的长数据进行截断
		if(CStrT2CStrW(m_strPlainText).GetLength()>4)
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(4));

		//计算Unicode方式的十六进制编码
		m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	}

	UpdateData(FALSE);
	DoEncrypt();
}

void CBlockIDEAForm::OnEnChangeEditKey()
{
	UpdateData(TRUE);

	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 对复制的长数据进行截断
		if(CStrT2CStrA(m_strKey).GetLength()>16)
			m_strKey = CStrA2CStrT(CStrT2CStrA(m_strKey).Left(16));

		// 计算ANSI方式的十六进制编码
		m_strKeyHex = Text2AnsiHex(m_strKey);

	}
	else
	{
		// Unicode方式

		// 对复制的长数据进行截断
		if(CStrT2CStrW(m_strKey).GetLength()>8)
			m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(8));

		//计算Unicode方式的十六进制编码
		m_strKeyHex = Text2UnicodeHex(m_strKey);
	}

	UpdateData(FALSE);
	DoEncrypt();
}

void CBlockIDEAForm::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 重新计算十六进制的值
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();


	}
	else
	{
		// Unicode方式

		//选中Unicode方式，截取输入框字符为8个
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(4)) ;
		m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(8)) ;
		UpdateData(FALSE);

		// 重新计算十六进制的值
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();
	}
}

void CBlockIDEAForm::OnBnClickedRadioUnicode()
{
	// 和点击点击ANSI时相同的操作
	OnBnClickedRadioAnsi();
}
