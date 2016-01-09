// PublicKeyDH.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "PublicKeyDHForm.h"

#define WM_UPDATEMY_DATA WM_USER + 501
// CPublicKeyDHForm

IMPLEMENT_DYNCREATE(CPublicKeyDHForm, CForm)

CPublicKeyDHForm::CPublicKeyDHForm()
	: CForm(CPublicKeyDHForm::IDD)
{

}

CPublicKeyDHForm::~CPublicKeyDHForm()
{
}

void CPublicKeyDHForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	DDX_Control(pDX, IDC_CRTST_A, m_ctrlComboA);
	DDX_Control(pDX, IDC_CRTST_XA, m_ctrlComboXA);
	DDX_Control(pDX, IDC_CRTST_XB, m_ctrlComboXB);
	DDX_CBString(pDX, IDC_CRTST_Q, m_strComboQ);
	DDX_CBString(pDX, IDC_CRTST_A, m_strComboA);
	DDX_CBString(pDX, IDC_CRTST_XA, m_strComboXA);
	DDX_CBString(pDX, IDC_CRTST_XB, m_strComboXB);

	DDX_Text(pDX, IDC_GA, m_strUserAA);
	DDX_Text(pDX, IDC_EAXA, m_strUserAXa);
	DDX_Text(pDX, IDC_AMQ, m_strUserAQ);
	DDX_Text(pDX, IDC_YA, m_strUserAYa);

	DDX_Text(pDX, IDC_GB, m_strUserBA);
	DDX_Text(pDX, IDC_EBXB, m_strUserBXb);
	DDX_Text(pDX, IDC_BMQ, m_strUserBQ);
	DDX_Text(pDX, IDC_YB, m_strUserBYb);

	DDX_Text(pDX, IDC_KYB, m_strPubUserAYb);
	DDX_Text(pDX, IDC_KXA, m_strPubUserAXa);
	DDX_Text(pDX, IDC_KMQ, m_strPubUserAQ);
	DDX_Text(pDX, IDC_KA, m_strPubUserAK);

	DDX_Text(pDX, IDC_KYA, m_strPubUserBYa);
	DDX_Text(pDX, IDC_KXB, m_strPubUserBXb);
	DDX_Text(pDX, IDC_KMQ1, m_strPubUserBQ);
	DDX_Text(pDX, IDC_KB, m_strPubUserBK);

}

BEGIN_MESSAGE_MAP(CPublicKeyDHForm, CForm)
	ON_MESSAGE(WM_UPDATEMY_DATA, CPublicKeyDHForm::OnUpdateMyData)
	ON_CBN_SELCHANGE(IDC_CRTST_Q, &CPublicKeyDHForm::OnCbnSelchangeCrtstQ)
	ON_CBN_SELCHANGE(IDC_CRTST_A, &CPublicKeyDHForm::OnCbnSelchangeCrtstA)
	ON_CBN_SELCHANGE(IDC_CRTST_XA, &CPublicKeyDHForm::OnCbnSelchangeCrtstXa)
	ON_CBN_SELCHANGE(IDC_CRTST_XB, &CPublicKeyDHForm::OnCbnSelchangeCrtstXb)
END_MESSAGE_MAP()


// CPublicKeyDHForm ���

#ifdef _DEBUG
void CPublicKeyDHForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPublicKeyDHForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPublicKeyDHForm ��Ϣ�������


void CPublicKeyDHForm::OnInitialUpdate()
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
UINT CPublicKeyDHForm::InitComboBox(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyDHForm * pThisForm = (CPublicKeyDHForm *) param; 

	// ��ʼ���߳�ʱ����������
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboXA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboXB.EnableWindow(FALSE);

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



	pThisForm->DoDH();


	// �ָ�������
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboXA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboXB.EnableWindow(TRUE);

	return 0; 
}


// ���̷߳�ʽΪ��ԭԪ��A�������˽ԿX�������������
UINT CPublicKeyDHForm::SetComboBoxThread(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyDHForm * pThisForm = (CPublicKeyDHForm *) param; 

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
	pThisForm->m_ctrlComboXA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboXB.EnableWindow(FALSE);

	CString strTemp = pThisForm->m_strComboQ;

	pThisForm->SetComboBoxAX(_ttoi(strTemp));

	pThisForm->m_strComboQ=strTemp;
	
	pThisForm->DoDH();
	
	
	// �ָ�������
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboXA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboXB.EnableWindow(TRUE);

	// �����̱߳�־
	pThisForm->m_bInThread=FALSE;

	return 0; 
}


// ����ѡ�������qΪ��ԭԪ���������˽ԿX�������������
void CPublicKeyDHForm::SetComboBoxAX(int q)
{

	m_ctrlComboA.ResetContent();
	m_ctrlComboXA.ResetContent();
	m_ctrlComboXB.ResetContent();
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
		m_ctrlComboXA.AddString(strTemp);
		m_ctrlComboXB.AddString(strTemp);
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

	nrand = rand() % nX;
	m_ctrlComboXA.SetCurSel(nrand);
	m_ctrlComboXA.GetLBText(m_ctrlComboXA.GetCurSel(),m_strComboXA);

	nrand = rand() % nX;
	m_ctrlComboXB.SetCurSel(nrand);
	m_ctrlComboXB.GetLBText(m_ctrlComboXB.GetCurSel(),m_strComboXB);

	PostMessage(WM_UPDATEMY_DATA);
}


void CPublicKeyDHForm::DoDH()
{

	m_strUserAA=m_strComboA;
	m_strUserAXa=m_strComboXA;
	m_strUserAQ=m_strComboQ;
	m_strUserAYa.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strComboA),_ttoi(m_strComboXA),_ttoi(m_strComboQ)));

	m_strUserBA=m_strComboA;
	m_strUserBXb=m_strComboXB;
	m_strUserBQ=m_strComboQ;
	m_strUserBYb.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strComboA),_ttoi(m_strComboXB),_ttoi(m_strComboQ)));

	m_strPubUserAYb=m_strUserBYb;
	m_strPubUserAXa=m_strComboXA;
	m_strPubUserAQ=m_strComboQ;
	m_strPubUserAK.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strPubUserAYb),_ttoi(m_strComboXA),_ttoi(m_strComboQ)));

	m_strPubUserBYa=m_strUserAYa;
	m_strPubUserBXb=m_strComboXB;
	m_strPubUserBQ=m_strComboQ;
	m_strPubUserBK.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strPubUserBYa),_ttoi(m_strComboXB),_ttoi(m_strComboQ)));

}


// ��ս�������
void CPublicKeyDHForm::EmptyKey()
{

	m_strUserAA.Empty();
	m_strUserAXa.Empty();
	m_strUserAQ.Empty();
	m_strUserAYa.Empty();

	m_strUserBA.Empty();
	m_strUserBXb.Empty();
	m_strUserBQ.Empty();
	m_strUserBYb.Empty();

	m_strPubUserAYb.Empty();
	m_strPubUserAXa.Empty();
	m_strPubUserAQ.Empty();
	m_strPubUserAK.Empty();

	m_strPubUserBYa.Empty();
	m_strPubUserBXb.Empty();
	m_strPubUserBQ.Empty();
	m_strPubUserBK.Empty();

}



LRESULT  CPublicKeyDHForm::OnUpdateMyData(WPARAM wParam, LPARAM lParam)
{
    UpdateData(FALSE);
    return 0;
}




void CPublicKeyDHForm::OnCbnSelchangeCrtstQ()
{
	UpdateData(TRUE);
	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)SetComboBoxThread,this);
	UpdateData(FALSE);
}

void CPublicKeyDHForm::OnCbnSelchangeCrtstA()
{
	UpdateData(TRUE);
	DoDH(); //
	UpdateData(FALSE);
}

void CPublicKeyDHForm::OnCbnSelchangeCrtstXa()
{
	UpdateData(TRUE);
	DoDH(); //
	UpdateData(FALSE);
}

void CPublicKeyDHForm::OnCbnSelchangeCrtstXb()
{
	UpdateData(TRUE);
	DoDH();
	UpdateData(FALSE);
}
