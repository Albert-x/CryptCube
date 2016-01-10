// SignatureDSAForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "SignatureDSAForm.h"
#include <math.h>
//#include "PublicKeyECC.h"
#include "PublicKeyECCForm.h"
// CSignatureDSAForm

IMPLEMENT_DYNCREATE(CSignatureDSAForm, CForm)

CSignatureDSAForm::CSignatureDSAForm()
	: CForm(CSignatureDSAForm::IDD)
	, m_p(0)
	, m_q(0)
	, m_g(0)
	, m_x(0)
	, m_y(0)
	, m_gg()
	, m_xx()
	, m_qq()
	, m_k(0)
	, m_r(0)
	, m_s(0)
	, m_signG(0)
	, m_signK(0)
	, m_signP(0)
	, m_signQ(0)
	, m_sK(0)
	, m_sH(0)
	, m_sX(0)
	, m_sR(0)
	, m_sQ(0)
	, m_wS(0)
	, m_wQ(0)
	, m_w(0)
	, m_u1M(0)
	, m_u1W(0)
	, m_u1Q(0)
	, m_u1(0)
	, m_u2R(0)
	, m_u2W(0)
	, m_u2Q(0)
	, m_u2(0)
	, m_vG(0)
	, m_vU1(0)
	, m_vY(0)
	, m_vU2(0)
	, m_vP(0)
	, m_vQ(0)
	, m_v(0)
	, m_M(0)
{

}

CSignatureDSAForm::~CSignatureDSAForm()
{
}

void CSignatureDSAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P, m_p);
	DDX_Text(pDX, IDC_Q, m_q);
	DDX_Text(pDX, IDC_P2, m_g);
	DDX_Text(pDX, IDC_XA, m_x);
	DDX_Text(pDX, IDC_YA1, m_y);
	DDX_Text(pDX, IDC_GA, m_gg);
	DDX_Text(pDX, IDC_EAXA, m_xx);
	DDX_Text(pDX, IDC_AMQ, m_qq);
	DDX_Text(pDX, IDC_XB, m_k);
	DDX_Text(pDX, IDC_XB2, m_r);
	DDX_Text(pDX, IDC_XB3, m_s);
	DDX_Text(pDX, IDC_EDIT2, m_signG);
	DDX_Text(pDX, IDC_EDIT3, m_signK);
	DDX_Text(pDX, IDC_EDIT69, m_signP);
	DDX_Text(pDX, IDC_EDIT4, m_signQ);
	DDX_Text(pDX, IDC_EDIT6, m_sK);
	DDX_Text(pDX, IDC_EDIT7, m_sH);
	DDX_Text(pDX, IDC_EDIT8, m_sX);
	DDX_Text(pDX, IDC_EDIT9, m_sR);
	DDX_Text(pDX, IDC_EDIT10, m_sQ);
	DDX_Text(pDX, IDC_EDIT11, m_wS);
	DDX_Text(pDX, IDC_EDIT12, m_wQ);
	DDX_Text(pDX, IDC_EDIT13, m_w);
	DDX_Text(pDX, IDC_EDIT14, m_u1M);
	DDX_Text(pDX, IDC_EDIT15, m_u1W);
	DDX_Text(pDX, IDC_EDIT16, m_u1Q);
	DDX_Text(pDX, IDC_EDIT17, m_u1);
	DDX_Text(pDX, IDC_EDIT70, m_u2R);
	DDX_Text(pDX, IDC_EDIT71, m_u2W);
	DDX_Text(pDX, IDC_EDIT72, m_u2Q);
	DDX_Text(pDX, IDC_EDIT73, m_u2);
	DDX_Text(pDX, IDC_EDIT19, m_vG);
	DDX_Text(pDX, IDC_EDIT20, m_vU1);
	DDX_Text(pDX, IDC_EDIT21, m_vY);
	DDX_Text(pDX, IDC_EDIT22, m_vU2);
	DDX_Text(pDX, IDC_EDIT23, m_vP);
	DDX_Text(pDX, IDC_EDIT24, m_vQ);
	DDX_Text(pDX, IDC_EDIT25, m_v);
	DDX_Text(pDX, IDC_EDIT5, m_M);
}

BEGIN_MESSAGE_MAP(CSignatureDSAForm, CForm)
	ON_BN_CLICKED(IDC_BUTTON6, &CSignatureDSAForm::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CSignatureDSAForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CSignatureDSAForm::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSignatureDSAForm::OnBnClickedButton8)
END_MESSAGE_MAP()


// CSignatureDSAForm 诊断

#ifdef _DEBUG
void CSignatureDSAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CSignatureDSAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CSignatureDSAForm 消息处理程序



void CSignatureDSAForm::OnBnClickedButton8()
{
	BOOL p_flag,q_flag;
	m_p=GetDlgItemInt(IDC_P,&p_flag);
	m_q=GetDlgItemInt(IDC_Q,&q_flag);
	if( p_flag==0 || q_flag==0 )
	{
		MessageBox("(a,b)值不合法！");
		//m_sure=0;
		return;
	}
	if (m_p < 4 || m_q < 4)
	{
		{
			MessageBox("p、q为大于3的素数！");
			//m_sure=0;
			return;
		}
	}
	if(0==m_pDSA->testprime(m_p))
	{
		MessageBox("p不是素数，请重新输入！");
		//m_sure=0;
		return;
	}
	if (0 == m_pDSA->testprime(m_q))
	{
		MessageBox("q不是素数，请重新输入！！");
		//m_sure=0;
		return;
	}

}
void CSignatureDSAForm::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_pECC = new ECC();
	UpdateData();
	if (m_p < 4 || m_q < 4)
	{
		{
			MessageBox("p、q为大于3的素数！");
			//m_sure=0;
			return;
		}
	}
	m_gg=m_g;
	m_xx=m_x;
	m_qq=m_q;
	m_y=m_pDSA->powmod(m_g,m_x,m_p);
	UpdateData(FALSE);
}

void CSignatureDSAForm::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if (m_p == 0 || m_p == 1 || m_q == 0 || m_q == 1)
	{
		MessageBox("请输入素数p,q！");
		return;
	}
	long temp1,temp2;
	m_signG=m_g;
	m_signK=m_k;
	m_signP=m_p;
	m_signQ=m_q;
	temp1=m_pDSA->powmod(m_g,m_k,m_p);
	m_r=temp1%m_q;
	m_sK=m_k;
	m_sH=m_M;
	m_sX=m_x;
	m_sR=m_r;
	m_sQ=m_q;
	//k^-1mod q
	temp2=m_pDSA->modNUm(m_k,m_q);
	m_s=(m_M+m_x*m_r)*temp2%m_q;
	UpdateData(FALSE);
}

void CSignatureDSAForm::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	long temp;
	UpdateData();
	if (m_p == 0 || m_p == 1 || m_q == 0 || m_q == 1)
	{
		MessageBox("请输入素数p,q！");
		return;
	}
	m_wS=m_s;
	m_wQ=m_q;
	m_w=m_pDSA->modNUm(m_s,m_q);
	m_u1M=m_M;
	m_u1W=m_w;
	m_u1Q=m_q;
	m_u1=m_M*m_w%m_q;
	m_u2R=m_r;
	m_u2W=m_w;
	m_u2Q=m_q;
	m_u2=m_r*m_w%m_q;
	m_vG=m_g;
	m_vP=m_p;
	m_vQ=m_q;
	m_vY=m_y;
	m_vU1=m_u1;
	m_vU2=m_u2;
	temp=m_pDSA->powmod(m_g,m_u1,m_p)*m_pDSA->powmod(m_y,m_u2,m_p);
	m_v=temp%m_p%m_q;
	UpdateData(FALSE);
}
