// CodeRandomForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeRandomForm.h"
#include "CStringConvert.h"


// CCodeRandomForm

IMPLEMENT_DYNCREATE(CCodeRandomForm, CForm)

CCodeRandomForm::CCodeRandomForm()
	: CForm(CCodeRandomForm::IDD)
	, m_strPassLength(_T(""))
	, m_strPassAmount(_T(""))
	, m_bCheckUppercase(TRUE)
	, m_bCheckLowercase(TRUE)
	, m_bCheckNumber(FALSE)
	, m_bCheckCharacter(FALSE)
	, m_bCheckHex(FALSE)
	, m_bCheckBin(FALSE)
	, m_strPassCustom(_T(""))
	, m_bCheckCustom(FALSE)
	, m_strPass(_T(""))
{
}

CCodeRandomForm::~CCodeRandomForm()
{
}

void CCodeRandomForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_PASS_LEN, m_strPassLength);
	DDX_CBString(pDX, IDC_COMBO_PASS_AMOUNT, m_strPassAmount);
	DDX_Control(pDX, IDC_COMBO_PASS_LEN, m_pComboPassLength);
	DDX_Check(pDX, IDC_CHECK_UPPERCASE, m_bCheckUppercase);
	DDX_Check(pDX, IDC_CHECK_LOWERCASE, m_bCheckLowercase);
	DDX_Check(pDX, IDC_CHECK_NUMBER, m_bCheckNumber);
	DDX_Check(pDX, IDC_CHECK_CHARACTER, m_bCheckCharacter);
	DDX_Check(pDX, IDC_CHECK_HEX, m_bCheckHex);
	DDX_Check(pDX, IDC_CHECK_BIN, m_bCheckBin);
	DDX_Control(pDX, IDC_CHECK_UPPERCASE, m_btnCheckUppercase);
	DDX_Control(pDX, IDC_CHECK_LOWERCASE, m_btnCheckLowercase);
	DDX_Control(pDX, IDC_CHECK_NUMBER, m_btnCheckNumber);
	DDX_Control(pDX, IDC_CHECK_CHARACTER, m_btnCheckCharacter);
	DDX_Control(pDX, IDC_CHECK_HEX, m_btnCheckHex);
	DDX_Control(pDX, IDC_CHECK_BIN, m_btnCheckBin);
	DDX_Control(pDX, IDC_COMBO_PASS_AMOUNT, m_pComboPassAmount);
	DDX_Control(pDX, IDC_EDIT_PASSCUSTOM, m_editPassCustom);
	DDX_Text(pDX, IDC_EDIT_PASSCUSTOM, m_strPassCustom);
	DDV_MaxChars(pDX, m_strPassCustom, 100);
	DDX_Control(pDX, IDC_CHECK_PASSCUSTOM, m_btnCheckCustom);
	DDX_Check(pDX, IDC_CHECK_PASSCUSTOM, m_bCheckCustom);
	DDX_Text(pDX, IDC_EDIT_PASS, m_strPass);
	DDX_Control(pDX, IDC_EDIT_PASS, m_editPass);
	DDX_Control(pDX, ID_PASS_GENERATE, m_btnPassGenerate);
}

BEGIN_MESSAGE_MAP(CCodeRandomForm, CForm)
	ON_BN_CLICKED(ID_PASS_GENERATE, &CCodeRandomForm::OnBnClickedPassGenerate)
	ON_BN_CLICKED(IDC_CHECK_HEX, &CCodeRandomForm::OnBnClickedCheckHex)
	ON_BN_CLICKED(IDC_CHECK_BIN, &CCodeRandomForm::OnBnClickedCheckBin)
	ON_CBN_EDITCHANGE(IDC_COMBO_PASS_LEN, &CCodeRandomForm::OnCbnEditchangeComboPassLength)
	ON_CBN_EDITCHANGE(IDC_COMBO_PASS_AMOUNT, &CCodeRandomForm::OnCbnEditchangeComboPassAmount)
	ON_BN_CLICKED(IDC_CHECK_PASSCUSTOM, &CCodeRandomForm::OnBnClickedCheckPasscustom)
END_MESSAGE_MAP()


// CCodeRandomForm ���

#ifdef _DEBUG
void CCodeRandomForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeRandomForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeRandomForm ��Ϣ�������

//��ʼ��Form
void CCodeRandomForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();

	//�����̵߳ķ�����ʼ��Combobox����
	CWinThread *pPassLengthThread= AfxBeginThread((AFX_THREADPROC)InitComboboxPassLength,this);
	CWinThread *pPassAmountThread= AfxBeginThread((AFX_THREADPROC)InitComboboxPassAmount,this);
}


// ������������ĵ�CTRL+A��ݼ��޷���Ӧ������
BOOL CCodeRandomForm::PreTranslateMessage(MSG* pMsg)
{

	if(WM_KEYDOWN == pMsg->message && _T('A') == pMsg->wParam && HIBYTE(GetKeyState(VK_CONTROL)))
	{
		// ���� m_editPass��CTRL+A
		if(GetFocus()->GetSafeHwnd() == m_editPass.m_hWnd)
		{
			m_editPass.SetSel(0, -1);
			return CFormView::PreTranslateMessage(pMsg);
		}
	}
	return CForm::PreTranslateMessage(pMsg);
}


//��ʼ�����볤�ȵ��̣߳�Ϊ���볤�����������ó�ʼֵ
UINT CCodeRandomForm::InitComboboxPassLength(LPVOID param)
{
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param; 
	CString strTemp;
	int nCombobox=1;

	pThisForm->m_pComboPassLength.ResetContent();

	for(int i=0;i<=12;i++)
	{
		strTemp.Format(_T("%d"),nCombobox*=2);
		pThisForm->m_pComboPassLength.InsertString(i,strTemp);
	}
	pThisForm->m_pComboPassLength.SetCurSel(3);
	return 0; 
}

//��ʼ������������������߳�
UINT CCodeRandomForm::InitComboboxPassAmount(LPVOID param)
{
	//�������߳��Ǿ�̬��Ա�������޷�ֱ�ӷ��ʳ�Ա������
	//���Դ���һ����CxxxxxForm * ��pThisForm��ָ��ָ���Form��
	//ʹ��pThisForm->����ʽ��ȡ��Ա�����ͷǾ�̬������
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param; 
	CString strTemp;

	pThisForm->m_pComboPassAmount.ResetContent();

	for(int i=1;i<=10;i++)
	{
		strTemp.Format(_T("%d"),i);
		pThisForm->m_pComboPassAmount.InsertString(i-1,strTemp);
	}
	pThisForm->m_pComboPassAmount.SetCurSel(0);
	return 0; 
}


//�á����볤�������ֻ����������
void CCodeRandomForm::OnCbnEditchangeComboPassLength()
{
	UpdateData();
	for (int i = 0; i < m_strPassLength.GetLength(); i++)//��������ַ����з����֣���ֱ��ɾ��
	{
		if (m_strPassLength.GetAt(i) < _T('0') || m_strPassLength.GetAt(i) > _T('9'))
		{
			m_strPassLength.Delete(i);
			m_pComboPassLength.SetWindowText(m_strPassLength);
			m_pComboPassLength.SetEditSel(i,i);

		}
	}
	if(_T('0') == m_strPassLength)//������ĵ�һ���ַ�Ϊ0���Զ��ĳ�1
	{
		m_strPassLength=_T('1');
		m_pComboPassLength.SetWindowText(m_strPassLength);
	}
}

// �á��������������ֻ����������
void CCodeRandomForm::OnCbnEditchangeComboPassAmount()
{
	UpdateData();
	for (int i = 0; i < m_strPassAmount.GetLength(); i++)
	{
		if (m_strPassAmount.GetAt(i) < _T('0') || m_strPassAmount.GetAt(i) > _T('9'))
		{
			m_strPassAmount.Delete(i);
			m_pComboPassAmount.SetWindowText(m_strPassAmount);
			m_pComboPassAmount.SetEditSel(i,i);
		}
	}
	if(_T('0') == m_strPassAmount)//������ĵ�һ���ַ�Ϊ0���Զ��ĳ�1
	{
		m_strPassAmount=_T('1');
		m_pComboPassAmount.SetWindowText(m_strPassAmount);
	}
}

// ѡ�С�ʮ�����ơ���ѡ��󣬽���������ѡ��
void CCodeRandomForm::OnBnClickedCheckHex()
{
	UpdateData();//�ӿؼ���ȡ������
	if(TRUE == m_bCheckHex)
	{
		m_btnCheckUppercase.EnableWindow(FALSE);
		m_btnCheckLowercase.EnableWindow(FALSE);
		m_btnCheckNumber.EnableWindow(FALSE);
		m_btnCheckCharacter.EnableWindow(FALSE);
		m_btnCheckBin.EnableWindow(FALSE);
		m_btnCheckCustom.EnableWindow(FALSE);
		m_editPassCustom.EnableWindow(FALSE);
	}
	else
	{
		m_btnCheckUppercase.EnableWindow(TRUE);
		m_btnCheckLowercase.EnableWindow(TRUE);
		m_btnCheckNumber.EnableWindow(TRUE);
		m_btnCheckCharacter.EnableWindow(TRUE);
		m_btnCheckBin.EnableWindow(TRUE);
		m_btnCheckCustom.EnableWindow(TRUE);
		if(TRUE == m_bCheckCustom)
		{
			m_editPassCustom.EnableWindow(TRUE);
		}
		else
		{
			m_editPassCustom.EnableWindow(FALSE);
		}
	}
}


//ѡ�С������ơ���ѡ��󣬽���������ѡ��
void CCodeRandomForm::OnBnClickedCheckBin()
{
	UpdateData();//�ӿؼ���ȡ������
	if(TRUE == m_bCheckBin)
	{
		m_btnCheckUppercase.EnableWindow(FALSE);
		m_btnCheckLowercase.EnableWindow(FALSE);
		m_btnCheckNumber.EnableWindow(FALSE);
		m_btnCheckCharacter.EnableWindow(FALSE);
		m_btnCheckHex.EnableWindow(FALSE);
		m_btnCheckCustom.EnableWindow(FALSE);
		m_editPassCustom.EnableWindow(FALSE);
	}
	else
	{
		m_btnCheckUppercase.EnableWindow(TRUE);
		m_btnCheckLowercase.EnableWindow(TRUE);
		m_btnCheckNumber.EnableWindow(TRUE);
		m_btnCheckCharacter.EnableWindow(TRUE);
		m_btnCheckHex.EnableWindow(TRUE);
		m_btnCheckCustom.EnableWindow(TRUE);
		if(TRUE == m_bCheckCustom)
		{
			m_editPassCustom.EnableWindow(TRUE);
		}
		else
		{
			m_editPassCustom.EnableWindow(FALSE);
		}
	}
}



// ѡ�С��Զ����ַ�����ѡ������á��Զ����ַ��������
void CCodeRandomForm::OnBnClickedCheckPasscustom()
{
	UpdateData();// ��ȡ�ؼ��ϵ����ݵ�����
	if(TRUE == m_bCheckCustom)
	{
		m_editPassCustom.EnableWindow(TRUE);
	}
	else
	{
		m_editPassCustom.EnableWindow(FALSE);
	}
}



// ���¡����ɰ�ť��ִ���������ɵĲ���
void CCodeRandomForm::OnBnClickedPassGenerate()
{

	
	UpdateData();// ��ȡ�ؼ��ϵ����ݵ�����
	
	// ������볤�ȡ�������������ʷ��¼��������
	if(CB_ERR == m_pComboPassLength.FindStringExact(-1,m_strPassLength)) 
		m_pComboPassLength.InsertString(0,m_strPassLength);
	if(CB_ERR == m_pComboPassAmount.FindStringExact(-1,m_strPassAmount))
		m_pComboPassAmount.InsertString(0,m_strPassAmount);

	//ִ���������������߳�
	CWinThread *pPassGenerateThread= AfxBeginThread((AFX_THREADPROC)PassGenerate,this);

}


//ִ��������������߳�
UINT CCodeRandomForm::PassGenerate(LPVOID param)
{
	//�������߳��Ǿ�̬��Ա�������޷�ֱ�ӷ��ʳ�Ա������
	//���Դ���һ����CxxxxxForm * ��pThisForm��ָ��ָ���Form��
	//ʹ��pThisForm->����ʽ��ȡ��Ա�����ͷǾ�̬������
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param;

	//���á����ɡ���ť
	pThisForm->m_btnPassGenerate.EnableWindow(FALSE);


	// ��ʼ���������
	srand((unsigned)time(NULL)); 

	// �������
	pThisForm->m_strPass=_T("");

	// ������ѭ���������벢�û��з�����
	for(int i=0;i<_ttoi(pThisForm->m_strPassAmount);i++)
	{
		pThisForm->m_strPass += RandomCode(
			_ttoi(pThisForm->m_strPassLength),pThisForm->m_bCheckHex, pThisForm->m_bCheckBin,
			pThisForm->m_bCheckCharacter, pThisForm->m_bCheckUppercase,
			pThisForm->m_bCheckLowercase, pThisForm->m_bCheckNumber,
			pThisForm->m_bCheckCustom, pThisForm->m_strPassCustom);

		pThisForm->m_strPass += _T("\r\n");
	}

	// ������һ�����з�
	pThisForm->m_strPass.TrimRight(_T("\r\n"));

	// �ڿؼ�����ʾ����
	pThisForm->m_editPass.SetWindowText(pThisForm->m_strPass);

	// �����ı������·�
	pThisForm->m_editPass.LineScroll(pThisForm->m_editPass.GetLineCount());

	//Sleep(100);
	// �ָ������ɡ���ť
	pThisForm->m_btnPassGenerate.EnableWindow(TRUE);

	return 0;
}


// �����ȡһ���ַ���
CString CCodeRandomForm::RandomCode(int nlength,BOOL bHex ,
		BOOL bBin ,BOOL bCharacter ,BOOL bUppercase ,BOOL bLowercase ,
		BOOL bNumber ,BOOL bCustom ,CString strCustom)
{
	CString strCode;

	// ������Ҫ�ĳ���ѭ������ַ�����
	for(int i = 0;i<nlength;i++)
	{
		strCode += GetChar(bHex,bBin,bCharacter,bUppercase,bLowercase,bNumber,bCustom,strCustom);
	}
	return strCode;
}


// ���ݲ���Ҫ��������һ���ַ�
CString CCodeRandomForm::GetChar(BOOL bHex ,
		BOOL bBin ,BOOL bCharacter ,BOOL bUppercase ,BOOL bLowercase ,
		BOOL bNumber ,BOOL bCustom ,CString strCustom)
{
	CString strChar= _T(""); // һ�����ַ���������¼��ѡ���ַ�
	CString strArrayCharacter = _T("`~!@#$%^&*()_+-={}|[]\\:;\"'<>?,./"); //��ѡ��32�����̷���
	CString strArrayUppercase = _T("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); // ��ѡ��26����д��ĸ
	CString strArrayLowercase = _T("abcdefghijklmnopqrstuvwxyz"); // ��ѡ��26��Сд��ĸ
	CString strArrayNumber = _T("0123456789"); // ��ѡ��10�����ַ���
	CString strArrayHex = _T("0123456789ABCDEF"); // ��ѡ��16��ʮ�����Ʒ���
	CString strArrayBin = _T("01"); // ��ѡ��2�������Ʒ���

	// ���ݲ������ñ�ѡ�ַ���ӵ��ַ���strChar
	if(bCharacter) strChar+=strArrayCharacter;
	if(bUppercase) strChar+=strArrayUppercase;
	if(bLowercase) strChar+=strArrayLowercase;
	if(bNumber) strChar+=strArrayNumber;
	if(bCustom) strChar+=strCustom;
	if(bHex) strChar=strArrayHex;
	if(bBin) strChar=strArrayBin;
	if(_T("") == strChar) return _T("");// ����ѡ�ַ���strCharΪ�գ����ؿ��ַ���

	CStringW strCharW = CStrT2CStrW(strChar);//��UNICOD��ʽ�����ִ����Ա�֤ANSI���뷽ʽ���޷��Զ��������ַ�
	return CStrW2CStrT(strCharW.Mid( rand() % strCharW.GetLength() ,1));// ���򷵻�һ������ַ���
}


