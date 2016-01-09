// PublicKeyRSAForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "PublicKeyRSAForm.h"
#include "PublicKeyRSA.h"

// CPublicKeyRSAForm

IMPLEMENT_DYNCREATE(CPublicKeyRSAForm, CForm)

CPublicKeyRSAForm::CPublicKeyRSAForm()
	: CForm(CPublicKeyRSAForm::IDD)
	, m_strComboP(_T("13"))
	, m_strComboQ(_T("17"))
{

}

CPublicKeyRSAForm::~CPublicKeyRSAForm()
{
}

void CPublicKeyRSAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CRTST_P, m_ctrlComboP);
	DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	DDX_Control(pDX, IDC_CRTST_E, m_ctrlComboE);
	DDX_CBString(pDX, IDC_CRTST_P, m_strComboP);
	DDX_CBString(pDX, IDC_CRTST_Q, m_strComboQ);
	DDX_CBString(pDX, IDC_CRTST_E, m_strComboE);
	DDX_Text(pDX, IDC_SHOW_P, m_strEditP);
	DDX_Text(pDX, IDC_SHOW_Q, m_strEditQ);
	DDX_Text(pDX, IDC_CRTST_PK_E, m_strPKe);
	DDX_Text(pDX, IDC_CRTST_PK_N, m_strPKn);
	DDX_Text(pDX, IDC_CRTST_SK_D, m_strSKd);
	DDX_Text(pDX, IDC_CRTST_SK_N, m_strSKn);
	DDX_Text(pDX, IDC_SHOW_E, m_strEditE);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_E, m_strShowPKe);
	DDX_Text(pDX, IDC_EDIT_SHOW_PK_N, m_strShowPKn);
	DDX_Text(pDX, IDC_EDIT_SHOW_SK_D, m_strShowSKd);
	DDX_Text(pDX, IDC_EDIT_SHOW_SK_N, m_strShowSKn);
	DDX_Text(pDX, IDC_EDIT_EN_PK_N, m_strEnPKn);
	DDX_Text(pDX, IDC_EDIT_EN_PK_E, m_strEnPKe);
	DDX_Text(pDX, IDC_EDIT_DE_SK_N, m_strDeSKn);
	DDX_Text(pDX, IDC_EDIT_DE_SK_D, m_strDeSKd);
	DDX_Text(pDX, IDC_EDIT_SHOW_P, m_strShowP);
	DDX_Text(pDX, IDC_EDIT_SHOW_Q, m_strShowQ);
	DDX_Text(pDX, IDC_EDIT_SHOW_N, m_strShowN);
	DDX_Text(pDX, IDC_EDIT_SHOW_P2, m_strShowP2);
	DDX_Text(pDX, IDC_EDIT_SHOW_Q2, m_strShowQ2);
	DDX_Text(pDX, IDC_EDIT_SHOW_N2, m_strShowN2);
	DDX_Text(pDX, IDC_EDIT_SHOW_D, m_strShowD);
	DDX_Text(pDX, IDC_EDIT_PLAIN, m_strPlain);
	DDX_Text(pDX, IDC_EDIT_CIPHER, m_strCipher);
	DDX_Text(pDX, IDC_EDIT_PLAIN_TO_CIPHER, m_strCipherResult);
	DDX_Text(pDX, IDC_EDIT_CIPHER_TO_PLAIN, m_strPlainResult);
	DDX_Text(pDX, IDC_EDIT_PLAIN_M, m_strPlainM);
	DDX_Text(pDX, IDC_EDIT_PLAIN_E, m_strPlainE);
	DDX_Text(pDX, IDC_EDIT_PLAIN_N, m_strPlainN);
	DDX_Text(pDX, IDC_EDIT_CIPHER_C, m_strCipherC);
	DDX_Text(pDX, IDC_EDIT_CIPHER_D, m_strCipherD);
	DDX_Text(pDX, IDC_EDIT_CIPHER_N, m_strCipherN);

}

BEGIN_MESSAGE_MAP(CPublicKeyRSAForm, CForm)
	ON_CBN_SELCHANGE(IDC_CRTST_P, &CPublicKeyRSAForm::OnCbnSelchangeCrtstP)
	
	ON_CBN_SELCHANGE(IDC_CRTST_Q, &CPublicKeyRSAForm::OnCbnSelchangeCrtstQ)
	ON_CBN_DROPDOWN(IDC_CRTST_P, &CPublicKeyRSAForm::OnCbnDropdownCrtstP)
	ON_CBN_KILLFOCUS(IDC_CRTST_P, &CPublicKeyRSAForm::OnCbnKillfocusCrtstP)
	ON_CBN_DROPDOWN(IDC_CRTST_Q, &CPublicKeyRSAForm::OnCbnDropdownCrtstQ)
	ON_CBN_KILLFOCUS(IDC_CRTST_Q, &CPublicKeyRSAForm::OnCbnKillfocusCrtstQ)
	ON_CBN_SELCHANGE(IDC_CRTST_E, &CPublicKeyRSAForm::OnCbnSelchangeCrtstE)
	ON_MESSAGE(WM_UPDATEMY_DATA, CPublicKeyRSAForm::OnUpdateMyData)

	ON_EN_CHANGE(IDC_EDIT_PLAIN, &CPublicKeyRSAForm::OnEnChangeEditPlain)
	ON_EN_CHANGE(IDC_EDIT_CIPHER, &CPublicKeyRSAForm::OnEnChangeEditCipher)
END_MESSAGE_MAP()


// CPublicKeyRSAForm 诊断

#ifdef _DEBUG
void CPublicKeyRSAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CPublicKeyRSAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG



LRESULT  CPublicKeyRSAForm::OnUpdateMyData(WPARAM wParam, LPARAM lParam)
{
    UpdateData(FALSE);
    return 0;
}

void CPublicKeyRSAForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	InitComboBox();// 初始化素数P、Q

	m_bInThread=FALSE;

	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)RandomE,this);

	UpdateData(FALSE);	

	

}




// CPublicKeyRSAForm 消息处理程序

// 初始化素数P、Q
void CPublicKeyRSAForm::InitComboBox()
{
	m_ctrlComboP.ResetContent();	
	m_ctrlComboQ.ResetContent();	

	CString strTemp;
	for(int i=0;i<=251;i++)
	{
		if(isPrimeUInt(i))
		{
			strTemp.Format(_T("%d"),i);
			m_ctrlComboP.AddString(strTemp);//填充0-251的素数
			m_ctrlComboQ.AddString(strTemp);//填充0-251的素数
		}
	}
}




// 多线程方式计算
UINT CPublicKeyRSAForm::RandomE(LPVOID param)
{


	
	srand((unsigned)time(NULL)*1000); 

	CPublicKeyRSAForm * pThisForm = (CPublicKeyRSAForm *) param; 


	// 进入线程标志
	// 防止鼠标滚动导致多个线程被激活
	if(FALSE == pThisForm->m_bInThread)pThisForm->m_bInThread=TRUE;
	else return 0;


	// 开始子线程时禁用下拉框
	pThisForm->m_ctrlComboP.EnableWindow(FALSE);
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);

	// 清空KEY
	pThisForm->EmptyKey();
	pThisForm->PostMessage(WM_UPDATEMY_DATA);

	CString strTempQ = pThisForm->m_strComboQ;
	CString strTempP = pThisForm->m_strComboP;

	UINT temp = (_ttoi(strTempP) - 1)* (_ttoi(strTempQ) - 1);


	pThisForm->m_ctrlComboE.ResetContent();				//清空下拉列表
	UINT i = 0, j = 0;
	CString str;
	for ( i = 2; i<temp; i++)				//列举出复合条件的数字
	{
		if (1!=gcd(i, temp))
		{
			continue;
		}
		str.Format(_T("%d"), i);
		pThisForm->m_ctrlComboE.InsertString(j, str);
		j ++;
	}
	

	pThisForm->m_strComboQ = strTempQ;
	pThisForm->m_strComboP = strTempP;


	i = rand()%j;

	if(pThisForm->m_ctrlComboE.GetCurSel()==-1)// 
	{
	pThisForm->m_ctrlComboE.SetCurSel(i);
	pThisForm->m_ctrlComboE.GetLBText(pThisForm->m_ctrlComboE.GetCurSel(),pThisForm->m_strComboE);
	pThisForm->DoRSA();
	pThisForm->Encrypt();
	pThisForm->Decrypt();
	pThisForm->PostMessage(WM_UPDATEMY_DATA);
	}


	// 恢复下拉框
	pThisForm->m_ctrlComboP.EnableWindow(TRUE);
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);

	// 结束线程标志
	pThisForm->m_bInThread=FALSE;

	return 0; 

}


// 清空界面数据
void CPublicKeyRSAForm::EmptyKey()
{

	m_strPKe.Empty();
	m_strPKn.Empty();
	m_strSKd.Empty();
	m_strSKn.Empty();

	m_strEditP.Empty();
	m_strEditQ.Empty();
	m_strEditE.Empty();

	// “演示”的中间过程
	m_strShowP.Empty();
	m_strShowQ.Empty();
	m_strShowN.Empty();
	m_strShowP2.Empty();
	m_strShowQ2.Empty();
	m_strShowN2.Empty();
	m_strShowD.Empty();

	// “演示”的公钥、私钥
	m_strShowPKe.Empty();
	m_strShowPKn.Empty();
	m_strShowSKd.Empty();
	m_strShowSKn.Empty();

	////////////////////////////////////
	// “加密”的公钥、明文
	m_strEnPKn.Empty();
	m_strEnPKe.Empty();

	// “加密”的中间过程
	m_strPlainM.Empty();
	m_strPlainE.Empty();
	m_strPlainN.Empty();

	// “加密”后的密文
	m_strCipherResult.Empty();
	

	////////////////////////////////////
	// “解密”的公钥、明文
	m_strDeSKn.Empty();
	m_strDeSKd.Empty();

	// “解密”的中间过程
	m_strCipherC.Empty();
	m_strCipherD.Empty();
	m_strCipherN.Empty();

	// “解密后”的明文
	m_strPlainResult.Empty();



}

void CPublicKeyRSAForm::DoRSA()
{

	// 计算公钥私钥
	e = _ttoi(m_strComboE);
	n =_ttoi(m_strComboP) * _ttoi(m_strComboQ);
	UINT temp= (_ttoi(m_strComboP) - 1)* (_ttoi(m_strComboQ) - 1);
	CreateD(e, temp, &d);




	// 顶部公钥私钥展示
	m_strPKe.Format(_T("%d"), e);
	m_strPKn.Format(_T("%d"), n);
	m_strSKd.Format(_T("%d"), d);
	m_strSKn.Format(_T("%d"), n);

	// 中间过程展示
	m_strEditP=m_strComboP;
	m_strEditQ=m_strComboQ;
	m_strEditE=m_strComboE;

	m_strShowPKe.Format(_T("%d"), e);
	m_strShowPKn.Format(_T("%d"), n);
	m_strShowSKd.Format(_T("%d"), d);
	m_strShowSKn.Format(_T("%d"), n);

	m_strShowP=m_strComboP;
	m_strShowQ=m_strComboQ;
	m_strShowN.Format(_T("%d"), n);

	m_strShowP2.Format(_T("%d"), _ttoi(m_strComboP) - 1);
	m_strShowQ2.Format(_T("%d"), _ttoi(m_strComboQ) - 1);
	m_strShowN2.Format(_T("%d"), temp);
	m_strShowD.Format(_T("%d"), d);

	//加密的公钥
	m_strEnPKn.Format(_T("%d"), n);
	m_strEnPKe.Format(_T("%d"), e);

	//解密的私钥
	m_strDeSKn.Format(_T("%d"), n);
	m_strDeSKd.Format(_T("%d"), d);


}


void CPublicKeyRSAForm::Encrypt()
{

	if(m_strPlain.IsEmpty() || m_strEnPKn.IsEmpty() || m_strEnPKe.IsEmpty()) return;
	if((UINT)_ttoi(m_strPlain) >= n)
	{
		m_strPlain.Format(_T("%d"), n-1);
	}

	// 开始加密
	UINT enc_m, enc_c;
	enc_m=_ttoi(m_strPlain);
	EncryptUInt(n, e, enc_m, &enc_c);

	// 中间过程
	m_strPlainM=m_strPlain;
	m_strPlainE.Format(_T("%d"), e);
	m_strPlainN.Format(_T("%d"), n);

	// 密文
	//m_strCipher.Format(_T("%d"), enc_c);
	m_strCipherResult.Format(_T("%d"), enc_c);

}


void CPublicKeyRSAForm::Decrypt()
{

	if(m_strCipher.IsEmpty()||m_strDeSKn.IsEmpty() || m_strDeSKd.IsEmpty()) return;
	if((UINT)_ttoi(m_strCipher) >= n)
	{
		m_strCipher.Format(_T("%d"), n-1);
	}
	// 开始解密
	UINT dec_c, dec_m;
	dec_c=_ttoi(m_strCipher);
	DecryptUInt(n, d, dec_c, &dec_m);

	// 中间过程
	m_strCipherC = m_strCipher;
	m_strCipherD.Format(_T("%d"), d);
	m_strCipherN.Format(_T("%d"), n);

	// 明文
	//m_strPlain.Format(_T("%d"), dec_m);
	m_strPlainResult.Format(_T("%d"), dec_m);


}


void CPublicKeyRSAForm::OnCbnSelchangeCrtstP()
{
	UpdateData(TRUE);
	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)RandomE,this);
	UpdateData(FALSE);
}

void CPublicKeyRSAForm::OnCbnSelchangeCrtstQ()
{
	UpdateData(TRUE);
	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)RandomE,this);
	UpdateData(FALSE);
}


void CPublicKeyRSAForm::OnCbnSelchangeCrtstE()
{
	UpdateData(TRUE);
	DoRSA();
	Encrypt();
	Decrypt();
	UpdateData(FALSE);
}



void CPublicKeyRSAForm::OnEnChangeEditPlain()
{
	UpdateData(TRUE);
	if(m_strPlain.IsEmpty())
	{
		m_strPlainM.Empty();
		m_strPlainE.Empty();
		m_strPlainN.Empty();
		m_strCipherResult.Empty();
		
	}
	else Encrypt();
	UpdateData(FALSE);
}

void CPublicKeyRSAForm::OnEnChangeEditCipher()
{

	UpdateData(TRUE);
	if(m_strCipher.IsEmpty())
	{
		m_strCipherC.Empty();
		m_strCipherD.Empty();
		m_strCipherN.Empty();
		m_strPlainResult.Empty();
	}
	else Decrypt();
	UpdateData(FALSE);
}



////////////////////////////////////////////////////////////////////////////////////////////
//以下两个事件处理P、Q下拉框不能同时出现相同的，不能同时出现2和3。

void CPublicKeyRSAForm::OnCbnDropdownCrtstP()
{
	UpdateData(TRUE);
	m_ctrlComboP.DeleteString(m_ctrlComboP.FindStringExact(0,m_strComboQ));
	if(_T("2") == m_strComboQ) m_ctrlComboP.DeleteString(m_ctrlComboP.FindStringExact(0,_T("3")));
	if(_T("3") == m_strComboQ) m_ctrlComboP.DeleteString(m_ctrlComboP.FindStringExact(0,_T("2")));


}

void CPublicKeyRSAForm::OnCbnDropdownCrtstQ()
{
	UpdateData(TRUE);
	
	m_ctrlComboQ.DeleteString(m_ctrlComboQ.FindStringExact(0,m_strComboP));
	if(_T("3") == m_strComboP) m_ctrlComboQ.DeleteString(m_ctrlComboQ.FindStringExact(0,_T("2")));
	if(_T("2") == m_strComboP) m_ctrlComboQ.DeleteString(m_ctrlComboQ.FindStringExact(0,_T("3")));

}


void CPublicKeyRSAForm::OnCbnKillfocusCrtstP()
{
	UpdateData(TRUE);

	
	if(_T("3") == m_strComboQ) m_ctrlComboP.InsertString(0,_T("2"));
	if(_T("2") == m_strComboQ) m_ctrlComboP.InsertString(0,_T("3"));
	m_ctrlComboP.InsertString(m_ctrlComboQ.GetCurSel(),m_strComboQ);
}




void CPublicKeyRSAForm::OnCbnKillfocusCrtstQ()
{
	UpdateData(TRUE);
	
	if(_T("2") == m_strComboP) m_ctrlComboQ.InsertString(0,_T("3"));
	if(_T("3") == m_strComboP) m_ctrlComboQ.InsertString(0,_T("2"));
	m_ctrlComboQ.InsertString(m_ctrlComboP.GetCurSel(),m_strComboP);
}


