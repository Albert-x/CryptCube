// PublicKeyElGamalForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "PublicKeyElGamalForm.h"
#define WM_UPDATEMY_DATA WM_USER + 501
#define WM_READMY_DATA WM_USER + 500

// CPublicKeyElGamalForm

IMPLEMENT_DYNCREATE(CPublicKeyElGamalForm, CForm)

CPublicKeyElGamalForm::CPublicKeyElGamalForm()
	: CForm(CPublicKeyElGamalForm::IDD)
{

}

CPublicKeyElGamalForm::~CPublicKeyElGamalForm()
{
}

void CPublicKeyElGamalForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	DDX_Control(pDX, IDC_CRTST_A, m_ctrlComboA);
	DDX_Control(pDX, IDC_CRTST_X, m_ctrlComboX);
	DDX_CBString(pDX, IDC_CRTST_Q, m_strComboQ);
	DDX_CBString(pDX, IDC_CRTST_A, m_strComboA);
	DDX_CBString(pDX, IDC_CRTST_X, m_strComboX);
	DDX_Text(pDX, IDC_CRTST_Y, m_strY);
	DDX_Text(pDX, IDC_SHOW_Q, m_strShowQ);
	DDX_Text(pDX, IDC_SHOW_A, m_strShowA);
	DDX_Text(pDX, IDC_SHOW_X, m_strShowX);
	DDX_Text(pDX, IDC_EDIT_SHOW_N2, m_strShowQ2);
	DDX_Text(pDX, IDC_EDIT_SHOW_N, m_strShowA2);
	DDX_Text(pDX, IDC_EDIT_SHOW_A, m_strShowX2);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_E, m_strShowY);
	DDX_Text(pDX, IDC_EDIT_PLAIN, m_strEnM);
	DDX_Text(pDX, IDC_EDIT_EN_PK_N, m_strEnQ);
	DDX_Text(pDX, IDC_EDIT_EN_PK_E, m_strEnA);
	DDX_Text(pDX, IDC_EDIT_EN_PK_E2, m_strEnY);
	DDX_Text(pDX, IDC_EDIT_EN_PK_E3, m_strEnX);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER, m_strEnC1);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E, m_strEnX2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M, m_strEnA2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_N, m_strEnQ2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER2, m_strEnK);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E2, m_strEnX3);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M2, m_strEnY2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_N2, m_strEnQ4);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER3, m_strEnC2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M3, m_strEnK2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E3, m_strEnM2);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_E2, m_strC1);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_E3, m_strC2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_N4, m_strEnQ5);
	DDX_Text(pDX, IDC_EDIT_CIPHER, m_strDeC1);
	DDX_Text(pDX, IDC_EDIT_DE_SK_N, m_strDeC2);
	DDX_Text(pDX, IDC_EDIT_DE_SK_D, m_strDeQ);
	DDX_Text(pDX, IDC_EDIT_DE_SK_D2, m_strDeX);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M5, m_strDeC3);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E5, m_strDeX2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_N3, m_strDeQ2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER5, m_strDeK);
	DDX_Text(pDX, IDC_EDIT_CIPHER_TO_PLAIN2, m_strDeK2);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M4, m_strDeK3);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E4, m_strDeC4);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER4, m_strDeM);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_E4, m_strM);
}

BEGIN_MESSAGE_MAP(CPublicKeyElGamalForm, CForm)
	ON_MESSAGE(WM_UPDATEMY_DATA, CPublicKeyElGamalForm::OnUpdateMyData)
	ON_MESSAGE(WM_READMY_DATA, CPublicKeyElGamalForm::OnReadMyData)
	ON_CBN_SELCHANGE(IDC_CRTST_Q, &CPublicKeyElGamalForm::OnCbnSelchangeCrtstQ)
	ON_CBN_SELCHANGE(IDC_CRTST_A, &CPublicKeyElGamalForm::OnCbnSelchangeCrtstA)
	ON_CBN_SELCHANGE(IDC_CRTST_X, &CPublicKeyElGamalForm::OnCbnSelchangeCrtstX)
	ON_EN_CHANGE(IDC_EDIT_PLAIN, &CPublicKeyElGamalForm::OnEnChangeEditPlain)
	ON_EN_CHANGE(IDC_EDIT_CIPHER, &CPublicKeyElGamalForm::OnEnChangeEditCipher1)
	ON_EN_CHANGE(IDC_EDIT_DE_SK_N, &CPublicKeyElGamalForm::OnEnChangeEditCipher2)
END_MESSAGE_MAP()


// CPublicKeyElGamalForm ���

#ifdef _DEBUG
void CPublicKeyElGamalForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPublicKeyElGamalForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPublicKeyElGamalForm ��Ϣ�������

void CPublicKeyElGamalForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	m_ctrlComboQ.AddString(_T("127"));
	m_strComboQ=_T("127");
	m_ctrlComboQ.SetCurSel(0);

	m_pElGamal = new ElGamal();

	m_bInThread=FALSE;

	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)InitComboBox,this);// ��ʼ������Q��A
	UpdateData(FALSE);	

}


// ���̷߳�ʽ��ʼ������Q����ԭԪ��A�������˽ԿX��������
UINT CPublicKeyElGamalForm::InitComboBox(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyElGamalForm * pThisForm = (CPublicKeyElGamalForm *) param; 

	// ��ʼ���߳�ʱ����������
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboX.EnableWindow(FALSE);

	// ���Q�����������Ϊ127-10000������
	CString strTemp;
	for(int i=131;i<=10000;i++)
	{
		if(pThisForm->m_pElGamal->isPrimeUInt(i))
		{
			strTemp.Format(_T("%d"),i);
			pThisForm->m_ctrlComboQ.AddString(strTemp);
		}
	}

	pThisForm->SetComboBoxAX(127);



	pThisForm->DoElGamal();


	// �ָ�������
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboX.EnableWindow(TRUE);
	return 0; 
}



// ���̷߳�ʽΪ��ԭԪ��A�������˽ԿX�������������
UINT CPublicKeyElGamalForm::SetComboBoxThread(LPVOID param)
{
	
	srand((unsigned)time(NULL)*1000); 
	CPublicKeyElGamalForm * pThisForm = (CPublicKeyElGamalForm *) param; 

	// �����̱߳�־
	// ��ֹ���������¶���̱߳�����
	if(FALSE == pThisForm->m_bInThread)pThisForm->m_bInThread=TRUE;
	else return 0;


	// ���KEY
	pThisForm->EmptyKey();
	pThisForm->PostMessage(WM_UPDATEMY_DATA);



	// ��ʼ���߳�ʱ����������
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboX.EnableWindow(FALSE);

	CString strTemp = pThisForm->m_strComboQ;

	pThisForm->SetComboBoxAX(_ttoi(strTemp));

	pThisForm->m_strComboQ=strTemp;
	
	pThisForm->DoElGamal();
	
	
	// �ָ�������
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboX.EnableWindow(TRUE);

	// �����̱߳�־
	pThisForm->m_bInThread=FALSE;

	return 0; 
}


// ����ѡ�������qΪ��ԭԪ���������˽ԿX�������������
void CPublicKeyElGamalForm::SetComboBoxAX(int q)
{

	m_ctrlComboA.ResetContent();
	m_ctrlComboX.ResetContent();

	CString strTemp;
	int nX = 0, nA = 0,t;

	// ��ʼ����ԭ����洢�ռ�
	m_pElGamal->initPrimeRoot();
	m_pElGamal->cal(q-1);

	// ѭ����ӱ�ԭԪ��A�������˽ԿX�������������
	for(int i=2;i<q-1;i++)
	{

		// ˽ԿX����������
		strTemp.Format(_T("%d"),i);
		m_ctrlComboX.AddString(strTemp);
		nX++;// �ۼ�˽Կ����

		// ��ԭ������
		bool flag=true;
		for(int k=0;k<m_pElGamal->c;k++)
		{
			t=(q-1)/m_pElGamal->pr[k];
			if(m_pElGamal->quick_mod(i,t,q)==1)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			strTemp.Format(_T("%d"),i);
			m_ctrlComboA.AddString(strTemp);
			nA++; // �ۼƱ�ԭԪ������
		}

	}


	// Ϊ��ԭԪ�غ�˽Կ���������

	int nrand = rand() % nA;
	m_ctrlComboA.SetCurSel(nrand);
	m_ctrlComboA.GetLBText(m_ctrlComboA.GetCurSel(),m_strComboA);

	int nrand2 = rand() % nX;
	m_ctrlComboX.SetCurSel(nrand2);
	m_ctrlComboX.GetLBText(m_ctrlComboX.GetCurSel(),m_strComboX);

	PostMessage(WM_UPDATEMY_DATA);
}




void CPublicKeyElGamalForm::DoElGamal()
{
	// ���ɹ�ԿY 
	m_strY.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strComboA),_ttoi(m_strComboX),_ttoi(m_strComboQ)));

	// �м������ʾ 
	m_strShowQ=m_strComboQ;
	m_strShowA=m_strComboA;
	m_strShowX=m_strComboX;
	m_strShowQ2=m_strComboQ;
	m_strShowA2=m_strComboA;
	m_strShowX2=m_strComboX;
	m_strShowY=m_strY;

	// ����������ʾQ A Y X 
	m_strEnQ=m_strComboQ;
	m_strEnA=m_strComboA;
	m_strEnY=m_strY;
	m_strEnX=m_strComboX;

	// ����������ʾQ X 
	m_strDeQ=m_strComboQ;
	m_strDeX=m_strComboX;

	Encrypt();// ����
	Decrypt();// ����


}






void CPublicKeyElGamalForm::Encrypt()
{

	// ����Ϊ�ղ����м���
	if(m_strEnM.IsEmpty()) return;

	// �������ı�qС
	if(_ttoi(m_strEnM) >= _ttoi(m_strComboQ))
	{
		m_strEnM.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}

	// ���ܹ���
	m_pElGamal->Encry(_ttoi(m_strComboQ),_ttoi(m_strComboA),_ttoi(m_strY),_ttoi(m_strEnM),_ttoi(m_strComboX));
	m_strC1.Format(_T("%d"),m_pElGamal->c1);
	m_strC2.Format(_T("%d"),m_pElGamal->c2);
	m_strEnK.Format(_T("%d"), m_pElGamal->enk);

	// ��ʾ�м���ܹ���
	m_strEnC1=m_strC1;
	m_strEnX2=m_strComboX;
	m_strEnA2=m_strComboA;
	m_strEnQ2=m_strComboQ;
	m_strEnX3=m_strComboX;
	m_strEnY2=m_strY;
	m_strEnQ4=m_strComboQ;
	m_strEnC2=m_strC2;
	m_strEnK2=m_strEnK;
	m_strEnM2=m_strEnM;
	m_strEnQ5=m_strComboQ;
}
void CPublicKeyElGamalForm::Decrypt()
{

	// ����Ϊ�ղ����м���
	if(m_strDeC1.IsEmpty()||m_strDeC2.IsEmpty()) return;

	// �������ı�qС
	if(_ttoi(m_strDeC1) >= _ttoi(m_strComboQ))
	{
		m_strDeC1.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}
	if(_ttoi(m_strDeC2) >= _ttoi(m_strComboQ))
	{
		m_strDeC2.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}

	// ���ܹ���
	m_pElGamal->Decry(_ttoi(m_strDeC1),_ttoi(m_strDeC2),_ttoi(m_strComboX),_ttoi(m_strComboQ));
	m_strM.Format(_T("%d"),m_pElGamal->m);
	m_strDeK.Format(_T("%d"),m_pElGamal->dek);
	m_strDeK2.Format(_T("%d"),m_pElGamal->dek2);

	// ��ʾ�м���ܹ���
	m_strDeC3=m_strDeC1;
	m_strDeX2=m_strComboX;
	m_strDeQ2=m_strComboQ;
	m_strDeK3=m_strDeK2;
	m_strDeC4=m_strDeC2;
	m_strDeM=m_strM;
	
}


// ��ս�������
void CPublicKeyElGamalForm::EmptyKey()
{

	// ��ԿY
	m_strY.Empty();

	// ��Կ�м����
	m_strShowQ.Empty();
	m_strShowA.Empty();
	m_strShowX.Empty();
	m_strShowQ2.Empty();
	m_strShowA2.Empty();
	m_strShowX2.Empty();
	m_strShowY.Empty();

	// ���ܹ���

	m_strEnQ.Empty();
	m_strEnA.Empty();
	m_strEnY.Empty();
	m_strEnX.Empty();
	m_strEnC1.Empty();
	m_strEnX2.Empty();
	m_strEnA2.Empty();
	m_strEnQ2.Empty();
	m_strEnK.Empty();
	m_strEnX3.Empty();
	m_strEnY2.Empty();
	m_strEnQ4.Empty();
	m_strEnC2.Empty();
	m_strEnK2.Empty();
	m_strEnM2.Empty();
	m_strC2.Empty();
	m_strC1.Empty();
	m_strEnQ5.Empty();

	// ���ܹ���

	m_strDeQ.Empty();
	m_strDeX.Empty();
	m_strDeC3.Empty();
	m_strDeX2.Empty();
	m_strDeQ2.Empty();
	m_strDeK.Empty();
	m_strDeK2.Empty();
	m_strDeK3.Empty();
	m_strDeC4.Empty();
	m_strDeM.Empty();
	m_strM.Empty();
}


LRESULT  CPublicKeyElGamalForm::OnUpdateMyData(WPARAM wParam, LPARAM lParam)
{
    UpdateData(FALSE);
    return 0;
}

LRESULT  CPublicKeyElGamalForm::OnReadMyData(WPARAM wParam, LPARAM lParam)
{
    UpdateData(TRUE);
    return 0;
}


void CPublicKeyElGamalForm::OnCbnSelchangeCrtstQ()
{
	UpdateData(TRUE);
	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)SetComboBoxThread,this);
	UpdateData(FALSE);
	
}



void CPublicKeyElGamalForm::OnCbnSelchangeCrtstA()
{
	
	UpdateData(TRUE);
	DoElGamal(); // ִ�й�ԿY�������
	UpdateData(FALSE);
}

void CPublicKeyElGamalForm::OnCbnSelchangeCrtstX()
{
	UpdateData(TRUE);
	DoElGamal(); // ִ�й�ԿY�������
	UpdateData(FALSE);
}


void CPublicKeyElGamalForm::OnEnChangeEditPlain()
{
	UpdateData(TRUE);
	if(m_strEnM.IsEmpty())
	{
		m_strEnC1.Empty();
		m_strEnX2.Empty();
		m_strEnA2.Empty();
		m_strEnQ2.Empty();
		m_strEnX3.Empty();
		m_strEnY2.Empty();
		m_strEnQ4.Empty();
		m_strEnC2.Empty();
		m_strEnK2.Empty();
		m_strEnM2.Empty();
		m_strEnQ5.Empty();
		m_strC1.Empty();
		m_strC2.Empty();
	}
	else Encrypt();// ����
	UpdateData(FALSE);
}

void CPublicKeyElGamalForm::OnEnChangeEditCipher1()
{
	UpdateData(TRUE);
	if(m_strDeC1.IsEmpty()||m_strDeC2.IsEmpty())
	{
	m_strDeC3.Empty();
	m_strDeX2.Empty();
	m_strDeQ2.Empty();
	m_strDeK3.Empty();
	m_strDeC4.Empty();
	m_strDeM.Empty();
	m_strM.Empty();
	}
	else Decrypt();// ����
	UpdateData(FALSE);
}

void CPublicKeyElGamalForm::OnEnChangeEditCipher2()
{
	OnEnChangeEditCipher1();
}
