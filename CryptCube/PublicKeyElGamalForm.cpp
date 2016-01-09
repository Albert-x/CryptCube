// PublicKeyElGamalForm.cpp : 实现文件
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


// CPublicKeyElGamalForm 诊断

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


// CPublicKeyElGamalForm 消息处理程序

void CPublicKeyElGamalForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	m_ctrlComboQ.AddString(_T("127"));
	m_strComboQ=_T("127");
	m_ctrlComboQ.SetCurSel(0);

	m_pElGamal = new ElGamal();

	m_bInThread=FALSE;

	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)InitComboBox,this);// 初始化素数Q、A
	UpdateData(FALSE);	

}


// 多线程方式初始化素数Q、本原元素A下拉框和私钥X的下拉框
UINT CPublicKeyElGamalForm::InitComboBox(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyElGamalForm * pThisForm = (CPublicKeyElGamalForm *) param; 

	// 开始子线程时禁用下拉框
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboX.EnableWindow(FALSE);

	// 填充Q下拉框的数据为127-10000的素数
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


	// 恢复下拉框
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboX.EnableWindow(TRUE);
	return 0; 
}



// 多线程方式为本原元素A下拉框和私钥X下拉框添加内容
UINT CPublicKeyElGamalForm::SetComboBoxThread(LPVOID param)
{
	
	srand((unsigned)time(NULL)*1000); 
	CPublicKeyElGamalForm * pThisForm = (CPublicKeyElGamalForm *) param; 

	// 进入线程标志
	// 防止鼠标滚动导致多个线程被激活
	if(FALSE == pThisForm->m_bInThread)pThisForm->m_bInThread=TRUE;
	else return 0;


	// 清空KEY
	pThisForm->EmptyKey();
	pThisForm->PostMessage(WM_UPDATEMY_DATA);



	// 开始子线程时禁用下拉框
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboX.EnableWindow(FALSE);

	CString strTemp = pThisForm->m_strComboQ;

	pThisForm->SetComboBoxAX(_ttoi(strTemp));

	pThisForm->m_strComboQ=strTemp;
	
	pThisForm->DoElGamal();
	
	
	// 恢复下拉框
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboX.EnableWindow(TRUE);

	// 结束线程标志
	pThisForm->m_bInThread=FALSE;

	return 0; 
}


// 根据选择的素数q为本原元素下拉框和私钥X下拉框添加内容
void CPublicKeyElGamalForm::SetComboBoxAX(int q)
{

	m_ctrlComboA.ResetContent();
	m_ctrlComboX.ResetContent();

	CString strTemp;
	int nX = 0, nA = 0,t;

	// 初始化本原根存存储空间
	m_pElGamal->initPrimeRoot();
	m_pElGamal->cal(q-1);

	// 循环添加本原元素A下拉框和私钥X下拉框添加内容
	for(int i=2;i<q-1;i++)
	{

		// 私钥X下拉框内容
		strTemp.Format(_T("%d"),i);
		m_ctrlComboX.AddString(strTemp);
		nX++;// 累计私钥数量

		// 本原根内容
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
			nA++; // 累计本原元素数量
		}

	}


	// 为本原元素和私钥生成随机数

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
	// 生成公钥Y 
	m_strY.Format(_T("%d"), m_pElGamal->Mod(_ttoi(m_strComboA),_ttoi(m_strComboX),_ttoi(m_strComboQ)));

	// 中间过程显示 
	m_strShowQ=m_strComboQ;
	m_strShowA=m_strComboA;
	m_strShowX=m_strComboX;
	m_strShowQ2=m_strComboQ;
	m_strShowA2=m_strComboA;
	m_strShowX2=m_strComboX;
	m_strShowY=m_strY;

	// 加密区域显示Q A Y X 
	m_strEnQ=m_strComboQ;
	m_strEnA=m_strComboA;
	m_strEnY=m_strY;
	m_strEnX=m_strComboX;

	// 解密区域显示Q X 
	m_strDeQ=m_strComboQ;
	m_strDeX=m_strComboX;

	Encrypt();// 加密
	Decrypt();// 解密


}






void CPublicKeyElGamalForm::Encrypt()
{

	// 明文为空不进行计算
	if(m_strEnM.IsEmpty()) return;

	// 限制明文比q小
	if(_ttoi(m_strEnM) >= _ttoi(m_strComboQ))
	{
		m_strEnM.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}

	// 加密过程
	m_pElGamal->Encry(_ttoi(m_strComboQ),_ttoi(m_strComboA),_ttoi(m_strY),_ttoi(m_strEnM),_ttoi(m_strComboX));
	m_strC1.Format(_T("%d"),m_pElGamal->c1);
	m_strC2.Format(_T("%d"),m_pElGamal->c2);
	m_strEnK.Format(_T("%d"), m_pElGamal->enk);

	// 显示中间加密过程
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

	// 密文为空不进行计算
	if(m_strDeC1.IsEmpty()||m_strDeC2.IsEmpty()) return;

	// 限制密文比q小
	if(_ttoi(m_strDeC1) >= _ttoi(m_strComboQ))
	{
		m_strDeC1.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}
	if(_ttoi(m_strDeC2) >= _ttoi(m_strComboQ))
	{
		m_strDeC2.Format(_T("%d"), _ttoi(m_strComboQ)-1);
	}

	// 解密过程
	m_pElGamal->Decry(_ttoi(m_strDeC1),_ttoi(m_strDeC2),_ttoi(m_strComboX),_ttoi(m_strComboQ));
	m_strM.Format(_T("%d"),m_pElGamal->m);
	m_strDeK.Format(_T("%d"),m_pElGamal->dek);
	m_strDeK2.Format(_T("%d"),m_pElGamal->dek2);

	// 显示中间解密过程
	m_strDeC3=m_strDeC1;
	m_strDeX2=m_strComboX;
	m_strDeQ2=m_strComboQ;
	m_strDeK3=m_strDeK2;
	m_strDeC4=m_strDeC2;
	m_strDeM=m_strM;
	
}


// 清空界面数据
void CPublicKeyElGamalForm::EmptyKey()
{

	// 公钥Y
	m_strY.Empty();

	// 公钥中间过程
	m_strShowQ.Empty();
	m_strShowA.Empty();
	m_strShowX.Empty();
	m_strShowQ2.Empty();
	m_strShowA2.Empty();
	m_strShowX2.Empty();
	m_strShowY.Empty();

	// 加密过程

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

	// 解密过程

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
	DoElGamal(); // 执行公钥Y计算过程
	UpdateData(FALSE);
}

void CPublicKeyElGamalForm::OnCbnSelchangeCrtstX()
{
	UpdateData(TRUE);
	DoElGamal(); // 执行公钥Y计算过程
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
	else Encrypt();// 加密
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
	else Decrypt();// 解密
	UpdateData(FALSE);
}

void CPublicKeyElGamalForm::OnEnChangeEditCipher2()
{
	OnEnChangeEditCipher1();
}
