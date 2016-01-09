// BlockIDEAForm.cpp : ʵ���ļ�
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


// CBlockIDEAForm ���

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


// CBlockIDEAForm ��Ϣ�������


// �����������ַ�����
BOOL CBlockIDEAForm::PreTranslateMessage(MSG* pMsg)
{

	if(WM_CHAR == pMsg->message)
	{
		////////////////////////////////////////////////��������� /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_PLAINTEXT)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//�Ƿ�������
			const unsigned int chCharCode =  pMsg->wParam;  


			//�����û���������ɾ����,�ʲ�����
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//���ѡ��ȫ��,������������
			int nStart,nEnd;
			m_ctrlPlainText.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strPlainText.GetLength())
				bDo = false ;


			//���������Ŀ�������ֽ���
			CString strPlainChar;
			strPlainChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������8���ֽ�
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 8)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������4���ַ�
				if(CStrT2CStrW(m_strPlainText).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 4)
					bDo = false;	
			}

			if(bDo)
				return true;

		}


		////////////////////////////////////////////////��Կ����� /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_KEY)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//�Ƿ�������
			const unsigned int chCharCode =  pMsg->wParam;  


			//�����û���������ɾ����,�ʲ�����
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//���ѡ��ȫ��,������������
			int nStart,nEnd;
			m_ctrlKey.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strKey.GetLength())
				bDo = false ;


			//���������Ŀ�������ֽ���
			CString strKeyChar;
			strKeyChar.Format(_T("%c"),chCharCode); 	

			strKeyChar.GetLength();

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������16���ֽ�
				if(CStrT2CStrA(m_strKey).GetLength()+CStrT2CStrA(strKeyChar).GetLength() <= 16)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������8���ַ�
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


// DES���ܹ���
void CBlockIDEAForm::DoEncrypt()
{
	// �ж����ĺ���Կ�Ƿ�Ϊ�գ�Ϊ���򲻼��㡣
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

	// ˢ�¿ؼ��ĳ�Ա����
	UpdateData(TRUE);



	////////////////////////////////////////////////////////////////////////////////
	// ��ȡ���ĺ����ģ�ANSI��ʽ�洢�Ķ���������
	unsigned char szSourceKey[17],szPlaintextData[17];

	// �����ַ���
	memset(szSourceKey,0,17);
	memset(szPlaintextData,0,17);


	//������ʮ������ת��ΪANSI��ʽ�洢���ַ���
	for( int i = 0; i < m_strPlainTextHex.GetLength(); i+=2 )
	{
		CString strTemp=m_strPlainTextHex.Mid(i,2);
		int nhex = _tcstoul(strTemp, 0, 16);

		szPlaintextData[i/2]=nhex;
	}

	//����Կʮ������ת��ΪANSI��ʽ�洢���ַ���
	for( int i = 0; i < m_strKeyHex.GetLength(); i+=2 )
	{
		CString strTemp=m_strKeyHex.Mid(i,2);
		int nhex = _tcstoul(strTemp, 0, 16);

		szSourceKey[i/2]=nhex;
	}


	////////////////////////////////////////////////////////////////////////////////
	// IDEA����
	m_pIDEA = new IDEA();
	char c[100]={0},key[100]={0};
	memset(c,0,100);
	memset(key,0,100);
	word16 in[4], dkey[8],out[4];
	char Hex16[100];//16λ����
	
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
	// ��ʮ������ת�����ַ���
	if(FALSE == m_stateRadioAnsi)
	{

		// ��ANSI��ʽ��ת������ʮ������Ϊ�ַ���
		m_strCipherText=AnsiHex2Text(m_strCipherTextHex);
	}
	else
	{
		// ��Unicode��ʽ��ת������ʮ������Ϊ�ַ���
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

	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrA(m_strPlainText).GetLength()>8)
		m_strPlainText = CStrA2CStrT(CStrT2CStrA(m_strPlainText).Left(8));

		// ����ANSI��ʽ��ʮ�����Ʊ���
		m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	}
	else
	{
		// Unicode��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrW(m_strPlainText).GetLength()>4)
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(4));

		//����Unicode��ʽ��ʮ�����Ʊ���
		m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	}

	UpdateData(FALSE);
	DoEncrypt();
}

void CBlockIDEAForm::OnEnChangeEditKey()
{
	UpdateData(TRUE);

	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrA(m_strKey).GetLength()>16)
			m_strKey = CStrA2CStrT(CStrT2CStrA(m_strKey).Left(16));

		// ����ANSI��ʽ��ʮ�����Ʊ���
		m_strKeyHex = Text2AnsiHex(m_strKey);

	}
	else
	{
		// Unicode��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrW(m_strKey).GetLength()>8)
			m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(8));

		//����Unicode��ʽ��ʮ�����Ʊ���
		m_strKeyHex = Text2UnicodeHex(m_strKey);
	}

	UpdateData(FALSE);
	DoEncrypt();
}

void CBlockIDEAForm::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();


	}
	else
	{
		// Unicode��ʽ

		//ѡ��Unicode��ʽ����ȡ������ַ�Ϊ8��
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(4)) ;
		m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(8)) ;
		UpdateData(FALSE);

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();
	}
}

void CBlockIDEAForm::OnBnClickedRadioUnicode()
{
	// �͵�����ANSIʱ��ͬ�Ĳ���
	OnBnClickedRadioAnsi();
}
