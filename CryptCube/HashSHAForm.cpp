// HashSHA1Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSHAForm.h"
#include"HashSHA1.h"
#include "CStringConvert.h"
#include"HashSHA1Sum.h"
#include"HashSHA1Key.h"
#include"HashSHA1Lun.h"
// CHashSHAForm
extern ULONG a[10];
extern ULONG M[16];

IMPLEMENT_DYNCREATE(CHashSHAForm, CForm)

CHashSHAForm::CHashSHAForm()
	: CForm(CHashSHAForm::IDD)
	, m_stateRadioAnsi(FALSE)
{

	result = _T("");
	shastr = _T("");
	m_strM1 = _T("");
	m_strM10 = _T("");
	m_strM11 = _T("");
	m_strM12 = _T("");
	m_strM13 = _T("");
	m_strM14 = _T("");
	m_strM15 = _T("");
	m_strM16 = _T("");
	m_strM2 = _T("");
	m_strM3 = _T("");
	m_strM4 = _T("");
	m_strM5 = _T("");
	m_strM6 = _T("");
	m_strM7 = _T("");
	m_strM8 = _T("");
	m_strM9 = _T("");
}

CHashSHAForm::~CHashSHAForm()
{
}

void CHashSHAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_EDIT_PLAINTEXT, m_shastr);
	DDX_Control(pDX, IDC_EDIT_CIPHERTEXT_HEX, m_result);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT, shastr);
	DDX_Control(pDX, IDC_BUTTON1, m_btln1);
	DDX_Control(pDX, IDC_BUTTON2, m_btln2);
	DDX_Control(pDX, IDC_BUTTON3, m_btln3);
	DDX_Radio(pDX, IDC_RADIO_ANSI, m_stateRadioAnsi);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX1, m_strM1);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX10, m_strM10);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX11, m_strM11);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX12, m_strM12);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX13, m_strM13);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX14, m_strM14);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX15, m_strM15);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX16, m_strM16);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX2, m_strM2);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX3, m_strM3);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX4, m_strM4);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX5, m_strM5);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX6, m_strM6);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX7, m_strM7);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX8, m_strM8);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX9, m_strM9);
}

BEGIN_MESSAGE_MAP(CHashSHAForm, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &CHashSHAForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CHashSHAForm::OnBnClickedRadioAnsi)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CHashSHAForm::OnEnChangeEditPlaintext)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CHashSHAForm::OnBnClickedRadioUnicode)
	ON_BN_CLICKED(IDC_BUTTON3, &CHashSHAForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CHashSHAForm::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHashSHAForm ���

#ifdef _DEBUG
void CHashSHAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CHashSHAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


void CHashSHAForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	m_btln1.EnableWindow(FALSE);
	m_btln2.EnableWindow(FALSE);
	m_btln3.EnableWindow(FALSE);
	// ��ʼ����ɱ�־λ
	m_bInitControl= TRUE;

	// TODO: �ڴ����ר�ô����/����û���
}


// CHashSHAForm ��Ϣ�������

BOOL CHashSHAForm::PreTranslateMessage(MSG* pMsg)
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
			m_shastr.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == shastr.GetLength())
				bDo = false ;
		//���������Ŀ�������ֽ���
			CString strPlainChar;
			strPlainChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������48���ֽ�
				if(CStrT2CStrA(shastr).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 48)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������24���ַ�
				if(CStrT2CStrW(shastr).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 24)
					bDo = false;	
			}

			if(bDo)
				return true;
}
	}
	return CForm::PreTranslateMessage(pMsg);
}





void CHashSHAForm::OnEnChangeEditPlaintext()
{
	UpdateData(TRUE);

	 //�жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
	//	// ANSI��ʽ

	//	// ����ANSI��ʽ��ʮ�����Ʊ���
		result = Text2AnsiHex(result);

	}
	else
	{
	//	// Unicode��ʽ

	//	//����Unicode��ʽ��ʮ�����Ʊ���
		result = Text2UnicodeHex(result);
	}

    UpdateData(FALSE);
	 // �ж����ĺ���Կ�Ƿ�Ϊ�գ�Ϊ���򲻼��㡣
	if((!shastr.GetLength())) 
	{

		result.Empty();
		m_btln1.EnableWindow(FALSE);
		m_btln2.EnableWindow(FALSE);
		m_btln3.EnableWindow(FALSE);
			
		m_strM10 = _T("");
		m_strM11 = _T("");
		m_strM12 = _T("");
		m_strM13 = _T("");
		m_strM14 = _T("");
		m_strM15 = _T("");
		m_strM16 = _T("");
		m_strM1 = _T("");
		m_strM2 = _T("");
		m_strM3 = _T("");
		m_strM4 = _T("");
		m_strM5 = _T("");
		m_strM6 = _T("");
		m_strM7 = _T("");
		m_strM8 = _T("");
		m_strM9 = _T("");
		UpdateData(FALSE);
		return;
	}
	m_btln1.EnableWindow(TRUE);
	m_btln2.EnableWindow(TRUE);
	m_btln3.EnableWindow(TRUE);
	DoEncrypt();

}
void CHashSHAForm::DoEncrypt()
{
	UpdateData(TRUE);
	
	 unsigned char* input;
	 unsigned char* output;
	CString str1,str2;
	 SHA1 sha1;
	 output=(unsigned char*)malloc((shastr.GetLength()*64)*sizeof(unsigned char*));
	  for(unsigned int j=0;j<(shastr.GetLength()*64);j++)
	{
		output[j]=0;
	}
	if(FALSE == m_stateRadioAnsi)
	{
	// ��ANSI��ʽ��ת�������ַ���Ϊʮ������
	
	 sha1.SHA_GO((BYTE*)(const char*)CStrT2CStrA(shastr).GetBuffer(),output,shastr.GetLength());    
	for(int i=0;i<5;i++)
		{
		    str1.Format("%x",*(sha1.H+i));
            str2+=str1;	
		}
     m_result.SetWindowText(str2);
	 	m_strM1.Format("%08X",M[0]); //**********************************
		m_strM2.Format("%08X",M[1]);
		m_strM3.Format("%08X",M[2]);
		m_strM4.Format("%08X",M[3]);
		m_strM5.Format("%08X",M[4]);
		m_strM6.Format("%08X",M[5]);
		m_strM7.Format("%08X",M[6]);
		m_strM8.Format("%08X",M[7]);
		m_strM9.Format("%08X",M[8]);
		m_strM10.Format("%08X",M[9]);
		m_strM11.Format("%08X",M[10]);
		m_strM12.Format("%08X",M[11]);
		m_strM13.Format("%08X",M[12]);
		m_strM14.Format("%08X",M[13]);
		
		m_strM15.Format("%08X",M[14]);
		m_strM16.Format("%08X",M[15]); //**********************************
	 result=str2;
     
	}
	else
	{
		// ��Unicode��ʽ��ת�������ַ���Ϊʮ������
	 sha1.SHA_GO((BYTE*)(const char*)CStrT2CStrW(shastr).GetBuffer(),output,shastr.GetLength());    
	for(int i=0;i<5;i++)
		{
		    str1.Format("%x",*(sha1.H+i));
            str2+=str1;	
		}
     m_result.SetWindowText(str2);
	m_strM1.Format("%08X",M[0]); //**********************************
		m_strM2.Format("%08X",M[1]);
		m_strM3.Format("%08X",M[2]);
		m_strM4.Format("%08X",M[3]);
		m_strM5.Format("%08X",M[4]);
		m_strM6.Format("%08X",M[5]);
		m_strM7.Format("%08X",M[6]);
		m_strM8.Format("%08X",M[7]);
		m_strM9.Format("%08X",M[8]);
		m_strM10.Format("%08X",M[9]);
		m_strM11.Format("%08X",M[10]);
		m_strM12.Format("%08X",M[11]);
		m_strM13.Format("%08X",M[12]);
		m_strM14.Format("%08X",M[13]);
		
		m_strM15.Format("%08X",M[14]);
		m_strM16.Format("%08X",M[15]); //**********************************
	 result=str2;
		
	}
	UpdateData(FALSE);

}

void CHashSHAForm::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();

	}
	else
	{
		// Unicode��ʽ

		//ѡ��Unicode��ʽ����ȡ������ַ�Ϊ24��
		shastr = CStrW2CStrT(CStrT2CStrW(shastr).Left(24)) ;
		UpdateData(FALSE);

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
	}
}




void CHashSHAForm::OnBnClickedRadioUnicode()
{
	// �͵�����ANSIʱ��ͬ�Ĳ���
	OnBnClickedRadioAnsi();
}

void CHashSHAForm::OnBnClickedButton1()
{

	INT_PTR nRes;
		HashSHA1Key keyDIG;
	nRes=keyDIG.DoModal();
	if(IDC_BUTTON3 ==nRes)
		return;


}
void CHashSHAForm::OnBnClickedButton2()
{
	
	INT_PTR nRes;
		HashSHA1Lun lunDIG;
	nRes=lunDIG.DoModal();
	if(IDC_BUTTON3 ==nRes)
		return;
}

void CHashSHAForm::OnBnClickedButton3()
{
	UpdateData(TRUE);
	INT_PTR nRes;
		HashSHA1Sum sumDIG;
	sumDIG.m_digist.Format(result);
	UpdateData(FALSE);
	nRes=sumDIG.DoModal();
	if(IDC_BUTTON3 ==nRes)
		return;
}



