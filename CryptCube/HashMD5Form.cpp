// HashMD5Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashMD5Form.h"
#include "FouDIG.h"
#include "HashSum.h"
#include "CStringConvert.h"
// CHashMD5Form
extern ULONG m[16];               //*******************************************//
extern ULONG n[4][16];//*******************************************//
extern ULONG a[4];
IMPLEMENT_DYNCREATE(CHashMD5Form, CForm)

CHashMD5Form::CHashMD5Form()
	: CForm(CHashMD5Form::IDD)
	, m_stateRadioAnsi(FALSE)
{

	//  m_strM2 = _T("");
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
}

CHashMD5Form::~CHashMD5Form()
{
}

void CHashMD5Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT, m_strPlainText);
	DDX_Text(pDX, IDC_EDIT_CIPHERTEXT_HEX, m_strCipherTextHex);
	DDX_Radio(pDX, IDC_RADIO_ANSI, m_stateRadioAnsi);
	DDX_Control(pDX, IDC_EDIT_PLAINTEXT, m_ctrlPlainText);
	DDX_Control(pDX, IDC_BUTTON1, m_btln1);
	DDX_Control(pDX, IDC_BUTTON2, m_btln2);
	//  DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX1, m_strM2);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX10, m_strM10);
	//  DDX_Control(pDX, IDC_EDIT_PLAINTEXT_HEX11, m_strM11);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX11, m_strM11);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX12, m_strM12);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX13, m_strM13);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX14, m_strM14);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX15, m_strM15);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX16, m_strM16);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX1, m_strM1);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX2, m_strM2);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX3, m_strM3);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX4, m_strM4);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX5, m_strM5);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX6, m_strM6);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX7, m_strM7);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX8, m_strM8);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT_HEX9, m_strM9);
}

BEGIN_MESSAGE_MAP(CHashMD5Form, CForm)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CHashMD5Form::OnEnChangeEditPlaintext)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CHashMD5Form::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CHashMD5Form::OnBnClickedRadioUnicode)
	ON_EN_CHANGE(IDC_EDIT_CIPHERTEXT_HEX, &CHashMD5Form::OnEnChangeEditCiphertextHex)
	ON_BN_CLICKED(IDC_BUTTON1, &CHashMD5Form::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHashMD5Form::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CHashMD5Form::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHashMD5Form ���

#ifdef _DEBUG
void CHashMD5Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CHashMD5Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG



void CHashMD5Form::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	m_btln1.EnableWindow(FALSE);
	m_btln2.EnableWindow(FALSE);

	// ��ʼ����ɱ�־λ
	m_bInitControl= TRUE;

}


// CHashMD5Form ��Ϣ�������




// �����������ַ�����
BOOL CHashMD5Form::PreTranslateMessage(MSG* pMsg)
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
				// ANSI��ʽ��������48���ֽ�
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 48)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������24���ַ�
				if(CStrT2CStrW(m_strPlainText).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 24)
					bDo = false;	
			}

			if(bDo)
				return true;

		}


	}

	return CForm::PreTranslateMessage(pMsg);
}





void CHashMD5Form::OnEnChangeEditPlaintext()
{
	UpdateData(TRUE);

	 //�жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
	//	// ANSI��ʽ

	//	// ����ANSI��ʽ��ʮ�����Ʊ���
		m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	}
	else
	{
	//	// Unicode��ʽ

	//	//����Unicode��ʽ��ʮ�����Ʊ���
		m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	}

    UpdateData(FALSE);

    // �ж����ĺ���Կ�Ƿ�Ϊ�գ�Ϊ���򲻼��㡣
	if((!m_strPlainText.GetLength())) 
	{

		m_strCipherTextHex.Empty();
		m_btln1.EnableWindow(FALSE);
		m_btln2.EnableWindow(FALSE);
		
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
	DoEncrypt();
}


void CHashMD5Form::DoEncrypt()
{

	// ˢ�¿ؼ��ĳ�Ա����
	UpdateData(TRUE);


//	m_pMD5 = new MD5();
	CString strvalue;
	// ���ַ���ת����ʮ������
	if(FALSE == m_stateRadioAnsi)
	{
		
		// ��ANSI��ʽ��ת�������ַ���Ϊʮ������
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrA(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
	   /* m_pMD5->Update( (BYTE*)(const char*)CStrT2CStrA(m_strPlainText).GetBuffer(), m_strPlainText.GetLength());
		strvalue.Format(_T("%u"),m[0]);
		GetDlgItem(IDC_EDIT_PLAINTEXT_HEX1)->SetWindowText(strvalue);*/
		m_strM1.Format("%08X",m[0]); //**********************************
		m_strM2.Format("%08X",m[1]);
		m_strM3.Format("%08X",m[2]);
		m_strM4.Format("%08X",m[3]);
		m_strM5.Format("%08X",m[4]);
		m_strM6.Format("%08X",m[5]);
		m_strM7.Format("%08X",m[6]);
		m_strM8.Format("%08X",m[7]);
		m_strM9.Format("%08X",m[8]);
		m_strM10.Format("%08X",m[9]);
		m_strM11.Format("%08X",m[10]);
		m_strM12.Format("%08X",m[11]);
		m_strM13.Format("%08X",m[12]);
		m_strM14.Format("%08X",m[13]);
		
		m_strM15.Format("%08X",m[14]);
		m_strM16.Format("%08X",m[15]); //**********************************


		
	}
	else
	{
		// ��Unicode��ʽ��ת�������ַ���Ϊʮ������
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrW(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
		m_strM1.Format("%08X",m[0]);//**********************************
		m_strM2.Format("%08X",m[1]);
		m_strM3.Format("%08X",m[2]);
		m_strM4.Format("%08X",m[3]);
		m_strM5.Format("%08X",m[4]);
		m_strM6.Format("%08X",m[5]);
		m_strM7.Format("%08X",m[6]);
		m_strM8.Format("%08X",m[7]);
		m_strM9.Format("%08X",m[8]);
		m_strM10.Format("%08X",m[9]);
		m_strM11.Format("%08X",m[10]);
		m_strM12.Format("%08X",m[11]);
		m_strM13.Format("%08X",m[12]);
		m_strM14.Format("%08X",m[13]);
		m_strM15.Format("%08X",m[14]);
		m_strM16.Format("%08X",m[15]); //**********************************
		//m_strM16.Format("%08X",n[0][0]);
	}



	




	UpdateData(FALSE);

}

void CHashMD5Form::OnBnClickedRadioAnsi()
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
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(24)) ;
		UpdateData(FALSE);

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
	}
}

void CHashMD5Form::OnBnClickedRadioUnicode()
{
	// �͵�����ANSIʱ��ͬ�Ĳ���
	OnBnClickedRadioAnsi();
}


void CHashMD5Form::OnEnChangeEditCiphertextHex()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CForm::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CHashMD5Form::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CHashSum sumDIG;
	sumDIG.m_digist=m_strCipherTextHex;
	nRes=sumDIG.DoModal();
	if(ID_HASH_MD5==nRes)
		return;
}


void CHashMD5Form::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CFouDIG fouDIG;
	/*fouDIG.n[0][0]=n[0][0];
	fouDIG.n[0][1]=n[0][1];
	fouDIG.n[0][2]=n[0][2];
	fouDIG.n[0][3]=n[0][3];
	fouDIG.n[0][4]=n[0][4];
	fouDIG.n[0][5]=n[0][5];
	fouDIG.n[0][6]=n[0][6];
	fouDIG.n[0][7]=n[0][7];
	fouDIG.n[0][8]=n[0][8];
	fouDIG.n[0][9]=n[0][9];
	fouDIG.n[0][10]=n[0][10];
	fouDIG.n[0][11]=n[0][11];
	fouDIG.n[0][12]=n[0][12];
	fouDIG.n[0][13]=n[0][13];
	fouDIG.n[0][14]=n[0][14];
	fouDIG.n[0][15]=n[0][15];*/

	
	nRes=fouDIG.DoModal();
	if(ID_HASH_MD5==nRes)
		return;


}
