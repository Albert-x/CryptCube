// PublicKeyECC.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "PublicKeyECCForm.h"
#include <math.h>

// CPublicKeyECCForm

IMPLEMENT_DYNCREATE(CPublicKeyECCForm, CForm)

CPublicKeyECCForm::CPublicKeyECCForm()
	: CForm(CPublicKeyECCForm::IDD)
	, m_p(0)
	, m_a(0)
	, m_b(0)
	, m_sure(0)
{

}

CPublicKeyECCForm::~CPublicKeyECCForm()
{
}

void CPublicKeyECCForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_CRTST_A, m_ctrlComboA);
	//DDX_CBString(pDX, IDC_CRTST_A, m_strComboA);
	//DDX_Control(pDX, IDC_CRTST_B, m_ctrlComboB);
	//DDX_CBString(pDX, IDC_CRTST_B, m_strComboB);
	//DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	//DDX_CBString(pDX, IDC_CRTST_Q, m_strComboQ);
	DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	DDX_CBIndex(pDX, IDC_CRTST_Q, m_p);

	DDX_Text(pDX, IDC_EDIT5, m_a);
	DDX_Text(pDX, IDC_EDIT6, m_b);
	DDX_Text(pDX, IDC_GX1, G.x);
	DDX_Text(pDX, IDC_GY1, G.y);
}

BEGIN_MESSAGE_MAP(CPublicKeyECCForm, CForm)
	ON_BN_CLICKED(IDC_SURE, &CPublicKeyECCForm::OnBnClickedSure)
	ON_BN_CLICKED(IDC_PUBLIC, &CPublicKeyECCForm::OnBnClickedPublic)
	ON_BN_CLICKED(IDC_EN, &CPublicKeyECCForm::OnBnClickedEn)
	ON_BN_CLICKED(IDC_DE, &CPublicKeyECCForm::OnBnClickedDe)
END_MESSAGE_MAP()


// CPublicKeyECCForm 诊断

#ifdef _DEBUG
void CPublicKeyECCForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPublicKeyECCForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPublicKeyECCForm 消息处理程序


void CPublicKeyECCForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	m_ctrlComboQ.AddString(_T("127"));
	m_p=127;
	m_ctrlComboQ.SetCurSel(0);
	G.x=0;
	G.y=0;
	m_bInThread=FALSE;

	m_pECC = new ECC();

	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)InitComboBox,this);// 初始化素数Q、A
	UpdateData(FALSE);	

}


// 多线程方式初始化素数Q、本原元素A下拉框和私钥X的下拉框
UINT CPublicKeyECCForm::InitComboBox(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyECCForm * pThisForm = (CPublicKeyECCForm *) param; 

	// 开始子线程时禁用下拉框
	//pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	//pThisForm->m_ctrlComboB.EnableWindow(FALSE);
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);

	int i= 0;

	// 填充Q下拉框的数据为127-10000的素数
	CString strTemp;
	for(i=131;i<=10000;i++)
	{
		if(pThisForm->m_pECC->testprime(i))
		{
			strTemp.Format(_T("%d"),i);
			pThisForm->m_ctrlComboQ.AddString(strTemp);
		}
	}

	for(i=0;i<=256;i++)
	{
		if(pThisForm->m_pECC->testprime(i))
		{
			strTemp.Format(_T("%d"),i);
			//pThisForm->m_ctrlComboA.AddString(strTemp);
			//pThisForm->m_ctrlComboB.AddString(strTemp);
		}
	}


//	pThisForm->SetComboBoxAX(127);

//	pThisForm->DoDH();


	// 恢复下拉框
	//pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	//pThisForm->m_ctrlComboB.EnableWindow(TRUE);
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	return 0; 
}

void CPublicKeyECCForm::OnBnClickedSure()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL a_flag,b_flag,x_flag,y_flag;
	m_a=GetDlgItemInt(IDC_EDIT5,&a_flag);
	m_b=GetDlgItemInt(IDC_EDIT6,&b_flag);
	if( a_flag==0 || b_flag==0 )
	{
		MessageBox("(a,b)值不合法！");
		m_sure=0;
		return;
	}
	m_p=GetDlgItemInt(IDC_CRTST_Q );
	G.x=GetDlgItemInt(IDC_GX1,&x_flag);
	G.y=GetDlgItemInt(IDC_GY1,&y_flag);
	if( x_flag==0 || y_flag==0 )
	{
		MessageBox("G(x,y)值不合法！");
		m_sure=0;
		return;
	}

	if(0==m_pECC->testprime(m_p))
	{
		MessageBox("p不是素数，请重新输入！");
		m_sure=0;
		return;
	}

	long temp;
	temp=(4*(m_pECC->powmod(m_a,3,m_p))+27*(m_pECC->powmod(m_b,2,m_p)))%m_p;
	if(0==temp)
	{
		MessageBox("(4a^3+27b^2)mod p =0,请重新输入a,b！");
		m_sure=0;
		return;
	}
	long result1,result2;

	result1=(G.x*G.x*G.x+m_a*G.x+m_b)%m_p;
	result2=G.y*G.y%m_p;

	if(result1 != result2)
	{
		MessageBox("G(x,y)不在Ep(a,b)上！");
		m_sure=0;
		return;
	}
	m_sure=1;

	return;		
}


void CPublicKeyECCForm::OnBnClickedPublic()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_sure==0)
	{
		MessageBox("请确定全局公开量！");
		return;
	}

	long n;
	BOOL flag; 
	n=GetDlgItemInt(IDC_N,&flag);
	if(flag==0)
	{
		MessageBox("n值不合法！");
		return;
	}

	if( n<0 || n>=m_p)
	{
		MessageBox("n的取值在[0,p)之间！");
		return;
	}
	point P;
	P=m_pECC->multipy(G,n,m_a,m_b,m_p);
	SetDlgItemInt(IDC_N1,n);
	SetDlgItemInt(IDC_GX,G.x);
	SetDlgItemInt(IDC_GY,G.y);
	SetDlgItemInt(IDC_PAX,P.x);
	SetDlgItemInt(IDC_PAY,P.y);
	return;
}

void CPublicKeyECCForm::OnBnClickedEn()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_sure==0)
	{
		MessageBox("请确定全局公开量！");
		return;
	}

	long m,k;
	point P;
	BOOL m_flag,k_flag,x_flag,y_flag; 

	m=GetDlgItemInt(IDC_M,&m_flag);
	k=GetDlgItemInt(IDC_K,&k_flag);
	P.x=GetDlgItemInt(IDC_PX,&x_flag);
	P.y=GetDlgItemInt(IDC_PY,&y_flag);

	if( m_flag==0 || m>=m_p || m<0 )
	{
		MessageBox("m值不合法！");
		return;
	}

	if( k_flag==0 || k>=m_p || k<0 )
	{
		MessageBox("k值不合法！");
		return;
	}

	long result1,result2;
	result1=((P.x*P.x*P.x)+(m_a*P.x)+m_b)%m_p;
	result2=(P.y*P.y)%m_p;

	if( x_flag=0 || y_flag==0 || result1!=result2 )
	{
		MessageBox("P(x,y)值不合法！");
		return;
	}
	point Pm;
	long y;

	if(11*m>m_p) 
	{
		MessageBox("明文不能转换为Ep[a,b]上的点！");
		return;
	}

	for(int j=0;j<10;j++)
	{
		Pm.x=10*m+j;
		y=(Pm.x*Pm.x*Pm.x+Pm.x*m_p+m_b)%m_p;
		if(m_pECC->powmod(y,(m_p-1)/2,m_p)==1)
			break;
	}
	Pm.y=m_pECC->SquareRoot(Pm.x,m_p);	

	SetDlgItemInt(IDC_PMX,Pm.x);
	SetDlgItemInt(IDC_PMY,Pm.y);

	SetDlgItemInt(IDC_K1,k);
	SetDlgItemInt(IDC_GX2,G.x);
	SetDlgItemInt(IDC_GY2,G.y);

	point C1,C2;
	C1=m_pECC->multipy(G,k,m_a,m_b,m_p);
	C2=m_pECC->multipy(P,k,m_a,m_b,m_p);
	C2=m_pECC->add(Pm,C2,m_a,m_b,m_p);
	SetDlgItemInt(IDC_ECX,C1.x);
	SetDlgItemInt(IDC_ECY,C1.y);

	SetDlgItemInt(IDC_EPMX,Pm.x);
	SetDlgItemInt(IDC_EPMY,Pm.y);
	SetDlgItemInt(IDC_K2,k);
	SetDlgItemInt(IDC_EPX,P.x);
	SetDlgItemInt(IDC_EPY,P.y);
	SetDlgItemInt(IDC_ECX1,C2.x);
	SetDlgItemInt(IDC_ECY1,C2.y);

	return;
}

void CPublicKeyECCForm::OnBnClickedDe()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_sure==0)
	{
		MessageBox("请确定全局公开量！");
		return;
	}
	point C1,C2;
	BOOL x1_flag,x2_flag,y1_flag,y2_flag,n_flag; 
    long n;
	n=GetDlgItemInt(IDC_N2,&n_flag);
	C1.x=GetDlgItemInt(IDC_DCX,&x1_flag);
	C1.y=GetDlgItemInt(IDC_DCY,&y1_flag);
	C2.x=GetDlgItemInt(IDC_DCX1,&x2_flag);
	C2.y=GetDlgItemInt(IDC_DCY1,&y2_flag);

	if( x1_flag==0 || x2_flag==0 || y1_flag==0 || y2_flag==0)
	{
		MessageBox("密文不合法！");
		return;		
	}
	if( n_flag==0 || n<0 || n>=m_p )
	{
		MessageBox("私钥n值不合法！");
		return;		
	}

	/*
	long result1,result2,result3,result4;
	result1=((C1.x*C1.x*C1.x)+(m_a*C1.x)+m_b)%m_p;
	result2=(C1.y*C1.y)%m_p;
	result3=((C2.x*C2.x*C2.x)+(m_a*C2.x)+m_b)%m_p;
	result4=(C2.y*C2.y)%m_p;
	if( result1!=result2 )
	{
		MessageBox("C1(x,y)不在Ep[a,b]上！");
		return;
	}
	if( result3!=result4 )
	{
		MessageBox("C2(x,y)不在Ep[a,b]上！");
		return;
	}*/
	
	
	SetDlgItemInt(IDC_PDCX,C1.x);
	SetDlgItemInt(IDC_PDCY,C1.y);
	SetDlgItemInt(IDC_PDCX1,C2.x);
	SetDlgItemInt(IDC_PDCY1,C2.y);
	SetDlgItemInt(IDC_N3,n);

	point r;
	int m;
	r=m_pECC->multipy(C1,n,m_a,m_b,m_p);
	r=m_pECC->subtract(C2,r,m_a,m_b,m_p);
	m=r.x/10;

	SetDlgItemInt(IDC_PMX1,r.x);
	SetDlgItemInt(IDC_PMY1,r.y);
	SetDlgItemInt(IDC_M1,m);

	return;
}
