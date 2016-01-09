// CodeCalcForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeCalcForm.h"
#include "Euclid.h"
#include "XTIME.h"
#include "GF.h"
#include "QUICK_MOD.h"
#include "PublicKeyRSAForm.h"
#include "PublicKeyRSA.h"
// CCodeCalcForm

IMPLEMENT_DYNCREATE(CCodeCalcForm, CForm)

CCodeCalcForm::CCodeCalcForm()
	: CForm(CCodeCalcForm::IDD)
{

}

CCodeCalcForm::~CCodeCalcForm()
{
}

void CCodeCalcForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeCalcForm, CForm)
	ON_BN_CLICKED(IDC_BUTTON2, &CCodeCalcForm::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCodeCalcForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CCodeCalcForm::OnBnClickedButton9)
	
END_MESSAGE_MAP()


// CCodeCalcForm 诊断

#ifdef _DEBUG
void CCodeCalcForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeCalcForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeCalcForm 消息处理程序


void CCodeCalcForm::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int uID;
	uID=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO4);
	if(uID==IDC_RADIO1)
	{
		Euclid euclid;
		euclid.DoModal();
	}
	else if(uID==IDC_RADIO3)
	{
		XTIME xtime;
		xtime.DoModal();
	}
	else if(uID==IDC_RADIO4)
	{
		GF gf;
		gf.DoModal();
	}
	else
		MessageBox("请选择算法！");
	
}
void CCodeCalcForm::OnBnClickedButton2()
{
	int uID;
	uID=GetCheckedRadioButton(IDC_RADIO5,IDC_RADIO7);
	if(uID==IDC_RADIO5)
	{
		QUICK_MOD quick;
		quick.DoModal();
	}
	else if(uID==IDC_RADIO6)
	{
		Euclid euclid;
		euclid.DoModal();
	}
	
	else
		MessageBox("请选择算法！");

}
void CCodeCalcForm::OnBnClickedButton9()
{
	int uID;
	uID=GetCheckedRadioButton(IDC_RADIO8,IDC_RADIO9);
	if(uID==IDC_RADIO8)
	{
		XTIME xtime;
		xtime.DoModal();
	}
	else if(uID==IDC_RADIO9)
	{
		GF gf;
		gf.DoModal();
	}
	else
		MessageBox("请选择算法！");
}
