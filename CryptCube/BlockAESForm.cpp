// BlockAESForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockAESForm.h"
#include "BlockAES.h"
#include "CStringConvert.h"

// CBlockAESForm

IMPLEMENT_DYNCREATE(CBlockAESForm, CForm)

CBlockAESForm::CBlockAESForm()
	: CForm(CBlockAESForm::IDD)
	, m_stateRadioAnsi(FALSE)
{

}

CBlockAESForm::~CBlockAESForm()
{
}

void CBlockAESForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INPUT, m_ctrlListInput);
	DDX_Control(pDX, IDC_LIST_CHUSHI, m_ctrlListChushi);
	DDX_Control(pDX, IDC_LIST_INPUT_9LUN, m_ctrlList9lun);
	DDX_Control(pDX, IDC_LIST_INPUT_ZUIZHONG, m_ctrlListzuihou);
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
	DDX_Control(pDX, IDC_BUTTON_CHUSHI, m_btnChushi);
	DDX_Control(pDX, IDC_BUTTON_LUN, m_btnLun);
	DDX_Control(pDX, IDC_BUTTON_ZUIHOU, m_btnZuihou);
	DDX_Control(pDX, IDC_BUTTON_KEY, m_btnKey);
}

BEGIN_MESSAGE_MAP(CBlockAESForm, CForm)

	ON_BN_CLICKED(IDC_BUTTON_KEY, &CBlockAESForm::OnBnClickedButtonKey)
	ON_BN_CLICKED(IDC_BUTTON_CHUSHI, &CBlockAESForm::OnBnClickedButtonChushi)
	ON_BN_CLICKED(IDC_BUTTON_LUN, &CBlockAESForm::OnBnClickedButtonLun)
	ON_BN_CLICKED(IDC_BUTTON_ZUIHOU, &CBlockAESForm::OnBnClickedButtonZuihou)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CBlockAESForm::OnEnChangeEditPlaintext)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CBlockAESForm::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CBlockAESForm::OnBnClickedRadioUnicode)
	ON_EN_CHANGE(IDC_EDIT_KEY, &CBlockAESForm::OnEnChangeEditKey)
END_MESSAGE_MAP()


// CBlockAESForm 诊断

#ifdef _DEBUG
void CBlockAESForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CBlockAESForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


void CBlockAESForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	InitListCtrl(m_ctrlListInput);
	InitListCtrl(m_ctrlListChushi);
	InitListCtrl(m_ctrlList9lun);
	InitListCtrl(m_ctrlListzuihou);


	// 初始化完成标志位
	m_bInitControl= TRUE;

}

// CBlockAESForm 消息处理程序



// 限制输入框的字符长度
BOOL CBlockAESForm::PreTranslateMessage(MSG* pMsg)
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
				// ANSI方式允许输入16个字节
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 16)//len -1 才是长度
					bDo = false;	
			}
			else
			{
				// Unicode方式允许输入8个字符
				if(CStrT2CStrW(m_strPlainText).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 8)
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


void CBlockAESForm::InitListCtrl(CListCtrl &ctrlList)
{
	ctrlList.SetExtendedStyle(LVS_EX_REGIONAL);
	LONG lStyle = ctrlList.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |=LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	ctrlList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);


	CImageList   m_l; 
	m_l.Create(1,31,TRUE|ILC_COLOR32,1,0); 
	ctrlList.SetImageList(&m_l,LVSIL_SMALL);
	//ctrlList.get
	ctrlList.InsertColumn(0,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(1,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(2,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(3,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertItem(0,_T(""));
	ctrlList.InsertItem(1,_T(""));
	ctrlList.InsertItem(2,_T(""));
	ctrlList.InsertItem(3,_T(""));
}


void CBlockAESForm::EmptyListCtrl(CListCtrl &ctrlList)
{

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ctrlList.SetItemText(i,j,_T(""));
		}
	}

}



// AES加密过程
void CBlockAESForm::DoEncrypt()
{
	// 判断明文和密钥是否为空，为空则不计算。
	if((!m_strPlainTextHex.GetLength())||(!m_strKeyHex.GetLength())) 
	{

		m_strCipherTextHex.Empty();
		m_strCipherText.Empty();


		EmptyListCtrl(m_ctrlListInput);
		EmptyListCtrl(m_ctrlListChushi);
		EmptyListCtrl(m_ctrlList9lun);
		EmptyListCtrl(m_ctrlListzuihou);

		m_btnChushi.EnableWindow(FALSE);
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
	// AES加密
	m_pAES = new AES(szSourceKey);

	m_pAES->Cipher(szPlaintextData,m_strPlainTextHex.GetLength()/2);

	// CipherTextA 
	CStringA CipherTextA;

	// 用“字节”型数据分析字符串
	BYTE *binText = (BYTE*)(LPCSTR)szPlaintextData;

	// 一个字节一个字节的输出十六进制数据
	for( int i = 0; i < 16; ++i )
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



	AesShow();

	UpdateData(FALSE);

}

void CBlockAESForm::AesShow()
{
		m_btnChushi.EnableWindow(TRUE);
		m_btnLun.EnableWindow(TRUE);
		m_btnZuihou.EnableWindow(TRUE);
		m_btnKey.EnableWindow(TRUE);

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				m_strListInput[i][j].Format(_T("%02X"),m_pAES-> szShowInput[i][j]);
				m_strListChushi[i][j].Format(_T("%02X"),m_pAES-> szShowChushi[i][j]);
				m_strList9lun[i][j].Format(_T("%02X"),m_pAES-> szShow9lun[i][j]);
				m_strListzuihou[i][j].Format(_T("%02X"),m_pAES-> szShowZuihou[i][j]);

			}
		}

		UpdateListCtrl(m_ctrlListInput,m_strListInput);
		UpdateListCtrl(m_ctrlListChushi,m_strListChushi);
		UpdateListCtrl(m_ctrlList9lun,m_strList9lun);
		UpdateListCtrl(m_ctrlListzuihou,m_strListzuihou);

}



void CBlockAESForm::UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ctrlList.SetItemText(i,j,strList[i][j]);
		}
	}

}



void CBlockAESForm::OnBnClickedButtonKey()
{
	
	// 44个扩展密钥

	for(int n=0;n<44;n++) dlgKey.m_strKey[n].Empty();

	int k=0;
	for(int n=0;n<11;n++) 
	{
		for(int i=0;i<4;i++)
		{
			for(int j=3;j>=0;j--)
			{
				dlgKey.m_strKey[k].AppendFormat(_T("%02X"),m_pAES->w[n][j][i]);
			}
			k++;
		}

	}


	dlgKey.DoModal();
}

void CBlockAESForm::OnBnClickedButtonChushi()
{


	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			dlgChushi.m_strInput[i][j].Format(_T("%02X"),m_pAES->szShowInput[i][j]);
			dlgChushi.m_strWi[i][j].Format(_T("%02X"),m_pAES->w[0][i][j]);
			dlgChushi.m_strOutput[i][j].Format(_T("%02X"),m_pAES->szShowChushi[i][j]);

		}
	}

	dlgChushi.DoModal();
}

void CBlockAESForm::OnBnClickedButtonLun()
{
	for(int n=0;n<9;n++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				dlgLun.m_strInput[n][i][j].Format(_T("%02X"),m_pAES->sz9lunShowInput[n][i][j]);
				dlgLun.m_strSubBytes[n][i][j].Format(_T("%02X"),m_pAES->sz9lunShowSubBytes[n][i][j]);
				dlgLun.m_strShiftRows[n][i][j].Format(_T("%02X"),m_pAES->sz9lunShowShiftRows[n][i][j]);
				dlgLun.m_strMixColumns[n][i][j].Format(_T("%02X"),m_pAES->sz9lunShowMixColumns[n][i][j]);
				dlgLun.m_strWi[n][i][j].Format(_T("%02X"),m_pAES->w[n+1][i][j]);
				dlgLun.m_strOutput[n][i][j].Format(_T("%02X"),m_pAES->sz9lunShowOutput[n][i][j]);
			}
		}
	}

	dlgLun.DoModal();
	dlgLun.m_bInitControl=  FALSE;

}

void CBlockAESForm::OnBnClickedButtonZuihou()
{

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			dlgZuihou.m_strInput[i][j].Format(_T("%02X"),m_pAES->szShow9lun[i][j]);
			dlgZuihou.m_strSubBytes[i][j].Format(_T("%02X"),m_pAES->szZuihouShowSubBytes[i][j]);
			dlgZuihou.m_strShiftRows[i][j].Format(_T("%02X"),m_pAES->szZuihouShowShiftRows[i][j]);
			dlgZuihou.m_strWi[i][j].Format(_T("%02X"),m_pAES->w[10][i][j]);
			dlgZuihou.m_strOutput[i][j].Format(_T("%02X"),m_pAES->szShowZuihou[i][j]);

		}
	}



	dlgZuihou.DoModal();
}

void CBlockAESForm::OnEnChangeEditPlaintext()
{
	UpdateData(TRUE);

	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 对复制的长数据进行截断
		if(CStrT2CStrA(m_strPlainText).GetLength()>16)
		m_strPlainText = CStrA2CStrT(CStrT2CStrA(m_strPlainText).Left(16));

		// 计算ANSI方式的十六进制编码
		m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	}
	else
	{
		// Unicode方式


		// 对复制的长数据进行截断
		if(CStrT2CStrW(m_strPlainText).GetLength()>8)
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(8));

		//计算Unicode方式的十六进制编码
		m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	}

	UpdateData(FALSE);
	DoEncrypt();

}


void CBlockAESForm::OnEnChangeEditKey()
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


void CBlockAESForm::OnBnClickedRadioAnsi()
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
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(8)) ;
		m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(8)) ;
		m_strCipherText = CStrW2CStrT(CStrT2CStrW(m_strCipherText).Left(8)) ;
		UpdateData(FALSE);

		// 重新计算十六进制的值
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();
	}
}

void CBlockAESForm::OnBnClickedRadioUnicode()
{
	// 和点击点击ANSI时相同的操作
	OnBnClickedRadioAnsi();
}

