// BlockDESForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockDESForm.h"

#include "CStringConvert.h"

// CBlockDESForm

IMPLEMENT_DYNCREATE(CBlockDESForm, CForm)

CBlockDESForm::CBlockDESForm()
	: CForm(CBlockDESForm::IDD)
	, m_stateRadioAnsi(FALSE)
	, m_strPlainText(_T(""))
	, m_strPlainTextHex(_T(""))
	, m_strKey(_T(""))
	, m_strCipherText(_T(""))
	, m_strCipherTextHex(_T(""))
	, m_strPage(_T(""))
	, m_strChushi(_T(""))
	, m_strLi(_T(""))
	, m_strRi(_T(""))
	, m_strRiXorKi(_T(""))
	, m_strFRiKi(_T(""))
	, m_strLiplus(_T(""))
	, m_strRiplus(_T(""))
	, m_strKi(_T(""))
	, m_strCi(_T(""))
	, m_strDi(_T(""))
	, m_strLeftMove(_T(""))
	, m_strCiplus(_T(""))
	, m_strDiplus(_T(""))
	, m_strKeyCompress(_T(""))
	, m_strPlainEnd(_T(""))
	, m_strFSbox(_T(""))
{

}

CBlockDESForm::~CBlockDESForm()
{
}

void CBlockDESForm::DoDataExchange(CDataExchange* pDX)
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
	DDX_Control(pDX, IDC_EDIT_DES_PAGE, m_ctrlPage);
	DDX_Control(pDX, IDC_SPIN_PAGE, m_spinPage);
	DDX_Text(pDX, IDC_EDIT_DES_PAGE, m_strPage);
	DDX_Control(pDX, IDC_BUTTON_PREV, m_btnPrevPage);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Text(pDX, IDC_EDIT_PLAIN_CHUSHI, m_strChushi);
	DDX_Text(pDX, IDC_EDIT_PLAIN_LI, m_strLi);
	DDX_Text(pDX, IDC_EDIT_PLAIN_RI, m_strRi);
	DDX_Text(pDX, IDC_EDIT_PLAIN_F_FIRST, m_strRiXorKi);
	DDX_Text(pDX, IDC_EDIT_PLAIN_F_RIKI, m_strFRiKi);
	DDX_Text(pDX, IDC_EDIT_PLAIN_LIPLUS1, m_strLiplus);
	DDX_Text(pDX, IDC_EDIT_PLAIN_RIPLUS1, m_strRiplus);
	DDX_Text(pDX, IDC_EDIT_KEY_SUB, m_strKi);
	DDX_Text(pDX, IDC_EDIT_KEY_CI, m_strCi);
	DDX_Text(pDX, IDC_EDIT_KEY_DI, m_strDi);
	DDX_Text(pDX, IDC_EDIT_KEY_LEFTMOVE, m_strLeftMove);
	DDX_Text(pDX, IDC_EDIT_KEY_CIPLUS1, m_strCiplus);
	DDX_Text(pDX, IDC_EDIT_KEY_DIPLUS1, m_strDiplus);
	DDX_Text(pDX, IDC_EDIT_KEY_56, m_strKeyCompress);
	DDX_Text(pDX, IDC_EDIT_PLAIN_END, m_strPlainEnd);
	DDX_Text(pDX, IDC_EDIT_PLAIN_F_SBOX, m_strFSbox);
}

BEGIN_MESSAGE_MAP(CBlockDESForm, CForm)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CBlockDESForm::OnEnChangeEditPlaintext)
	ON_EN_CHANGE(IDC_EDIT_KEY, &CBlockDESForm::OnEnChangeEditKey)
	ON_EN_CHANGE(IDC_EDIT_CIPHERTEXT, &CBlockDESForm::OnEnChangeEditCiphertext)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CBlockDESForm::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CBlockDESForm::OnBnClickedRadioUnicode)
	ON_EN_KILLFOCUS(IDC_EDIT_PLAINTEXT, &CBlockDESForm::OnEnKillfocusEditPlaintext)
	ON_EN_KILLFOCUS(IDC_EDIT_KEY, &CBlockDESForm::OnEnKillfocusEditKey)
	ON_EN_KILLFOCUS(IDC_EDIT_CIPHERTEXT, &CBlockDESForm::OnEnKillfocusEditCiphertext)
	ON_BN_CLICKED(IDC_BUTTON_PREV, &CBlockDESForm::OnBnClickedButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CBlockDESForm::OnBnClickedButtonNext)
	ON_EN_CHANGE(IDC_EDIT_DES_PAGE, &CBlockDESForm::OnEnChangeEditDesPage)
END_MESSAGE_MAP()



// CBlockDESForm ���

#ifdef _DEBUG
void CBlockDESForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CBlockDESForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CBlockDESForm ��Ϣ�������


// �����������ַ�����
BOOL CBlockDESForm::PreTranslateMessage(MSG* pMsg)
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

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������8���ֽ�
				if(CStrT2CStrA(m_strKey).GetLength()+CStrT2CStrA(strKeyChar).GetLength() <= 8)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������4���ַ�
				if(CStrT2CStrW(m_strKey).GetLength()+CStrT2CStrW(strKeyChar).GetLength() <= 4)
					bDo = false;	
			}

			if(bDo)
				return true;

		}

		////////////////////////////////////////////////��������� /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_CIPHERTEXT)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//�Ƿ�������
			const unsigned int chCharCode =  pMsg->wParam;  


			//�����û���������ɾ����,�ʲ�����
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//���ѡ��ȫ��,������������
			int nStart,nEnd;
			m_ctrlCipherText.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strCipherText.GetLength())
				bDo = false ;


			//���������Ŀ�������ֽ���
			CString strCipherChar;
			strCipherChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������8���ֽ�
				if(CStrT2CStrA(m_strCipherText).GetLength()+CStrT2CStrA(strCipherChar).GetLength() <= 8)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������4���ַ�
				if(CStrT2CStrW(m_strCipherText).GetLength()+CStrT2CStrW(strCipherChar).GetLength() <= 4)
					bDo = false;	
			}

			if(bDo)
				return true;

		}

	}

	return CForm::PreTranslateMessage(pMsg);
}


void CBlockDESForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();

	// ��ʼ��DES���ṹ

    m_spinPage.SetRange(1, 16);

	// ��ʼ����ɱ�־λ
	m_bInitControl= TRUE;


}


// DES���ܹ���
void CBlockDESForm::DoEncrypt()
{

	// �ж����ĺ���Կ�Ƿ�Ϊ�գ�Ϊ���򲻼��㡣
	if((m_strPlainTextHex.IsEmpty())||(m_strKeyHex.IsEmpty())) 
	{
		m_strCipherText.Empty();
		m_strCipherTextHex.Empty();
		m_btnPrevPage.EnableWindow(FALSE);
		m_btnNext.EnableWindow(FALSE);
		m_ctrlPage.EnableWindow(FALSE);
		m_strPage.Empty();
		// 56λѹ����Կ
		m_strKeyCompress.Empty();
		// Ci
		m_strCi.Empty();
		// Di
		m_strDi.Empty();
		// Ciplus
		m_strCiplus.Empty();
		// Diplus
		m_strDiplus.Empty();
		// LeftMove
		m_strLeftMove.Empty();
		// Ki
		m_strKi.Empty();
		// 64λ���ĳ�ʼ�û�
		m_strChushi.Empty();
		// Li
		m_strRi.Empty();
		// Di
		m_strLi.Empty();
		// Liplus
		m_strLiplus.Empty();
		// Riplus
		m_strRiplus.Empty();
		// RiXorKi
		m_strRiXorKi.Empty();
		// FRiKi
		m_strFRiKi.Empty();
		// FSbox
		m_strFSbox.Empty();
		// �ս��û�ǰ������
		m_strPlainEnd.Empty();


		UpdateData(FALSE);
		return;
	}

	// ˢ�¿ؼ��ĳ�Ա����
	UpdateData(TRUE);


	////////////////////////////////////////////////////////////////////////////////
	// ��ȡ���ĺ����ģ�ANSI��ʽ�洢�Ķ���������

	char szSourceKey[8],szPlaintextData[8];

	// �����ַ���
	memset(szSourceKey,0,8);
	memset(szPlaintextData,0,8);

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
	// DES����

	m_pDES = new DES();

	// ������Կ
	m_pDES->InitializeKey(szSourceKey,0);

	// ��ʼ����
	m_pDES->EncryptAnyLength(szPlaintextData,m_strPlainTextHex.GetLength()/2,0);// ���ܴ����ַ������ȣ���Ϊ���ݿ���0������������ݡ�

	
	// �������ʮ������
	m_strCipherTextHex=m_pDES->GetCiphertextInHex();


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

	DesShow();

	UpdateData(FALSE);

}



void CBlockDESForm::DesShow()
{

	m_btnPrevPage.EnableWindow(TRUE);
	m_btnNext.EnableWindow(TRUE);
	m_ctrlPage.EnableWindow(TRUE);

	m_strPage=_T("1");



	// 56λѹ����Կ
	m_strKeyCompress=m_pDES->szShow56Key;
	// Ci
	m_strCi=m_pDES->szShowCi[15];
	// Di
	m_strDi=m_pDES->szShowDi[15];
	// Ciplus
	m_strCiplus=m_pDES->szShowCi[0];
	// Diplus
	m_strDiplus=m_pDES->szShowCi[0];
	// LeftMove
	m_strLeftMove.Format(_T("%d"),Shift_Table[0]);
	// Ki
	m_strKi=m_pDES->szShowSubKeys[0];




	// 64λ���ĳ�ʼ�û�
	m_strChushi=m_pDES->szShowInput;

	// Li
	m_strRi=m_pDES->szShowRi[0];
	// Di
	m_strLi=m_pDES->szShowLi[0];
	// Liplus
	m_strLiplus=m_pDES->szShowLi[1];
	// Riplus
	m_strRiplus=m_pDES->szShowRi[1];
	// RiXorKi
	m_strRiXorKi=m_pDES->szRiXorKi[0];
	// FRiKi
	m_strFRiKi=m_pDES->szFRiKi[0];
	// FSbox
	m_strFSbox=m_pDES->szFSbox[0];
	// �ս��û�ǰ������
	m_strPlainEnd=m_pDES->szShowEnd;

}


// ������������ݸı�ʱ����Ӧ�¼�
void CBlockDESForm::OnEnChangeEditPlaintext()
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


// ��Կ��������ݸı�ʱ����Ӧ�¼�
void CBlockDESForm::OnEnChangeEditKey()
{
	UpdateData(TRUE);

	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrA(m_strKey).GetLength()>8)
			m_strKey = CStrA2CStrT(CStrT2CStrA(m_strKey).Left(8));


		// ����ANSI��ʽ��ʮ�����Ʊ���
		m_strKeyHex = Text2AnsiHex(m_strKey);

	}
	else
	{
		// Unicode��ʽ

		// �Ը��Ƶĳ����ݽ��нض�
		if(CStrT2CStrW(m_strKey).GetLength()>4)
			m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(4));

		//����Unicode��ʽ��ʮ�����Ʊ���
		m_strKeyHex = Text2UnicodeHex(m_strKey);
	}

	UpdateData(FALSE);
	DoEncrypt();
}


// ������������ݸı�ʱ����Ӧ�¼�
void CBlockDESForm::OnEnChangeEditCiphertext()
{

}

// ��ѡ����ANSIʱ����Ӧ�¼�
void CBlockDESForm::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();
		OnEnChangeEditCiphertext();

	}
	else
	{
		// Unicode��ʽ

		//ѡ��Unicode��ʽ����ȡ������ַ�Ϊ4��
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(4)) ;
		m_strKey = CStrW2CStrT(CStrT2CStrW(m_strKey).Left(4)) ;
		m_strCipherText = CStrW2CStrT(CStrT2CStrW(m_strCipherText).Left(4)) ;
		UpdateData(FALSE);

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
		OnEnChangeEditKey();
		OnEnChangeEditCiphertext();
	}

}


// ��ѡ����Unicodeʱ����Ӧ�¼�
void CBlockDESForm::OnBnClickedRadioUnicode()
{
	// �͵�����ANSIʱ��ͬ�Ĳ���
	OnBnClickedRadioAnsi();
}




// ���������ʧȥ����ʱ����Ӧ�¼�
void CBlockDESForm::OnEnKillfocusEditPlaintext()
{

}


// ��Կ�����ʧȥ����ʱ����Ӧ�¼�
void CBlockDESForm::OnEnKillfocusEditKey()
{

}


// ���������ʧȥ����ʱ����Ӧ�¼�
void CBlockDESForm::OnEnKillfocusEditCiphertext()
{

}

void CBlockDESForm::OnBnClickedButtonPrev()
{
	UpdateData(TRUE);
	if(_ttoi(m_strPage)>1) m_strPage.Format(_T("%d"),_ttoi(m_strPage)-1);
		else m_strPage.Format(_T("%d"),16);

	UpdateData(FALSE);
	OnEnChangeEditDesPage();

}

void CBlockDESForm::OnBnClickedButtonNext()
{

	UpdateData(TRUE);
	if(_ttoi(m_strPage)<16) m_strPage.Format(_T("%d"),_ttoi(m_strPage)+1);
		else m_strPage.Format(_T("%d"),1);
	UpdateData(FALSE);
	OnEnChangeEditDesPage();
}

void CBlockDESForm::OnEnChangeEditDesPage()
{
	if(TRUE == m_bInitControl)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strPage);

		if(nLun > 16)
		{
			nLun = 16;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strPage.Format(_T("%d"), nLun);

		
		m_strCi=m_pDES->szShowCi[(15+nLun-1)%16];
		// Di
		m_strDi=m_pDES->szShowDi[(15+nLun-1)%16];
		// Ciplus
		m_strCiplus=m_pDES->szShowCi[(nLun-1)%16];
		// Diplus
		m_strDiplus=m_pDES->szShowDi[(nLun-1)%16];
		// LeftMove
		m_strLeftMove.Format(_T("%d"),Shift_Table[nLun-1]);
		// Ki
		m_strKi=m_pDES->szShowSubKeys[nLun-1];




		// 64λ���ĳ�ʼ�û�
		m_strChushi=m_pDES->szShowInput;

		// Li
		m_strRi=m_pDES->szShowRi[(nLun-1)%16];
		// Di
		m_strLi=m_pDES->szShowLi[(nLun-1)%16];
		// Liplus
		m_strLiplus=m_pDES->szShowLii[(nLun-1)%16];
		// Riplus
		m_strRiplus=m_pDES->szShowRii[(nLun-1)%16];
		// RiXorKi
		m_strRiXorKi=m_pDES->szRiXorKi[nLun-1];
		// FRiKi
		m_strFRiKi=m_pDES->szFRiKi[nLun-1];
		// FSbox
		m_strFSbox=m_pDES->szFSbox[nLun-1];

		UpdateData(FALSE);
	}


}
