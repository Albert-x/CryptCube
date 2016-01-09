// FouDIG.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "FouDIG.h"
#include "afxdialogex.h"

extern ULONG aa[4];
extern ULONG n[4][16];
extern ULONG m[16];
// CFouDIG 对话框

IMPLEMENT_DYNAMIC(CFouDIG, CDialogEx)

	CFouDIG::CFouDIG(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFouDIG::IDD, pParent)
	, m_strPage1(_T(""))
	, m_strPage2(_T(""))
	, m_5F(_T(""))
	, m_5G(_T(""))
{

	m_a1 = _T("");
	m_a2 = _T("");
	m_b1 = _T("");
	m_b2 = _T("");
	m_c1 = _T("");
	m_c2 = _T("");
	m_d1 = _T("");
	m_d2 = _T("");
	m_1F = _T("");
	m_1G = _T("");
	m_1H = _T("");
	m_1I = _T("");
	m_2F = _T("");
	m_2H = _T("");
	m_2G = _T("");
	m_2I = _T("");
	m_3F = _T("");
	m_3G = _T("");
	m_3H = _T("");
	m_3I = _T("");
	m_4F = _T("");
	m_4G = _T("");
	m_4H = _T("");
	m_4I = _T("");
	m_ca1 = _T("");
	m_cb = _T("");
	m_ca2 = _T("");
	m_cf = _T("");
	m_cm = _T("");
	m_ct = _T("");
	m_cs = _T("");
}

CFouDIG::~CFouDIG()
{
}

void CFouDIG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1_MD5_PAGE, m_strPage1);
	DDX_Text(pDX, IDC_EDIT2_MD5_PAGE, m_strPage2);
	DDX_Text(pDX, IDC_EDIT1_A1, m_a1);
	DDX_Text(pDX, IDC_EDIT1_A2, m_a2);
	DDX_Text(pDX, IDC_EDIT2_B1, m_b1);
	DDX_Text(pDX, IDC_EDIT2_B2, m_b2);
	DDX_Text(pDX, IDC_EDIT3_C1, m_c1);
	DDX_Text(pDX, IDC_EDIT3_C2, m_c2);
	DDX_Text(pDX, IDC_EDIT4_D1, m_d1);
	DDX_Text(pDX, IDC_EDIT4_D2, m_d2);
	DDX_Text(pDX, IDC_EDIT1_F, m_1F);
	DDX_Text(pDX, IDC_EDIT1_G, m_1G);
	DDX_Text(pDX, IDC_EDIT1_H, m_1H);
	DDX_Text(pDX, IDC_EDIT1_I, m_1I);
	DDX_Text(pDX, IDC_EDIT2_F, m_2F);
	//  DDX_Control(pDX, IDC_EDIT2_G, m_2G);
	DDX_Text(pDX, IDC_EDIT2_H, m_2H);
	DDX_Text(pDX, IDC_EDIT2_G, m_2G);
	DDX_Text(pDX, IDC_EDIT2_I, m_2I);
	DDX_Text(pDX, IDC_EDIT3_F, m_3F);
	DDX_Text(pDX, IDC_EDIT3_G, m_3G);
	DDX_Text(pDX, IDC_EDIT3_H, m_3H);
	DDX_Text(pDX, IDC_EDIT3_I, m_3I);
	DDX_Text(pDX, IDC_EDIT4_F, m_4F);
	DDX_Text(pDX, IDC_EDIT4_G, m_4G);
	DDX_Text(pDX, IDC_EDIT4_H, m_4H);
	DDX_Text(pDX, IDC_EDIT4_I, m_4I);
	DDX_Text(pDX, IDC_EDIT1_CA1, m_ca1);
	DDX_Text(pDX, IDC_EDIT2_CB, m_cb);
	DDX_Text(pDX, IDC_EDIT3_cA2, m_ca2);
	//  DDX_Control(pDX, IDC_EDIT4_CF, m_cf);
	DDX_Text(pDX, IDC_EDIT4_CF, m_cf);
	DDX_Text(pDX, IDC_EDIT5_CM, m_cm);
	DDX_Text(pDX, IDC_EDIT6_CT, m_ct);
	DDX_Text(pDX, IDC_EDIT7_CS, m_cs);
	DDX_Text(pDX, IDC_EDIT5_F, m_5F);
	DDX_Text(pDX, IDC_EDIT5_G, m_5G);
}


BEGIN_MESSAGE_MAP(CFouDIG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFouDIG::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CFouDIG::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT8, &CFouDIG::OnEnChangeEdit8)
	//	ON_BN_CLICKED(IDC_BUTTON1, &CFouDIG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1_PREV, &CFouDIG::OnBnClickedButton1Prev)
	ON_BN_CLICKED(IDC_BUTTON1_NEXT, &CFouDIG::OnBnClickedButton1Next)
	ON_EN_CHANGE(IDC_EDIT1_MD5_PAGE, &CFouDIG::OnEnChangeEdit1Md5Page)
	ON_BN_CLICKED(IDC_BUTTON2_PREV, &CFouDIG::OnBnClickedButton2Prev)
	ON_EN_CHANGE(IDC_EDIT2_MD5_PAGE, &CFouDIG::OnEnChangeEdit2Md5Page)
	ON_BN_CLICKED(IDC_BUTTON2_NEXT, &CFouDIG::OnBnClickedButton2Next)
	//ON_EN_CHANGE(IDC_EDIT72, &CFouDIG::OnEnChangeEdit72)
	//ON_BN_CLICKED(IDC_BUTTON2, &CFouDIG::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON3, &CFouDIG::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT5_CM, &CFouDIG::OnEnChangeEdit5Cm)
	ON_EN_CHANGE(IDC_EDIT2_CB, &CFouDIG::OnEnChangeEdit2Cb)
	ON_EN_CHANGE(IDC_EDIT4_I, &CFouDIG::OnEnChangeEdit4I)
END_MESSAGE_MAP()

BOOL CFouDIG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strTemp;
	//m_strPage1=_T("1");
	//m_strPage2=_T("1");
	strTemp.Format(_T("1"));
	GetDlgItem(IDC_EDIT1_MD5_PAGE)->SetWindowText(strTemp);
	GetDlgItem(IDC_EDIT2_MD5_PAGE)->SetWindowText(strTemp);

	strTemp.Format(_T("1"));
	GetDlgItem(IDC_STATIC1)->SetWindowText(strTemp);//
	strTemp.Format(_T("F"));
	GetDlgItem(IDC_STATIC2)->SetWindowText(strTemp);
	strTemp.Format(_T("(x & y)|(~x&z)"));
	GetDlgItem(IDC_STATIC3)->SetWindowText(strTemp);
	strTemp.Format(_T("1"));
	GetDlgItem(IDC_STATIC4)->SetWindowText(strTemp);
	strTemp.Format(_T("FF"));
	GetDlgItem(IDC_STATIC5)->SetWindowText(strTemp);
	strTemp.Format(_T("F"));
	GetDlgItem(IDC_STATIC6)->SetWindowText(strTemp);

	GetDlgItem(IDC_STATIC_B)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1_G)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2_G)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3_G)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4_G)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5_G)-> EnableWindow(FALSE);

	GetDlgItem(IDC_STATIC_C)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1_H)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2_H)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3_H)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4_H)-> EnableWindow(FALSE);

	GetDlgItem(IDC_STATIC_D)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1_I)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2_I)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3_I)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4_I)-> EnableWindow(FALSE);
	m_bInitControl1= TRUE;
	m_bInitControl2= TRUE;

	m_a1.Format("%08X",aa[0]);
	GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
	m_b1.Format("%08X",aa[1]);
	GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
	m_c1.Format("%08X",aa[2]);
	GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
	m_d1.Format("%08X",aa[3]);
	GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

	m_a2.Format("%08X",n[0][0]);
	GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
	m_b2.Format("%08X",aa[1]);
	GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
	m_c2.Format("%08X",aa[2]);
	GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
	m_d2.Format("%08X",aa[3]);
	GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);


	XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[0],MD5_S11,MD5_T01,1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE

}
// CFouDIG 消息处理程序


void CFouDIG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CFouDIG::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CFouDIG::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CFouDIG::init(void)
{
	m_strPage2.Format(_T("%d"),1);
}


void CFouDIG::OnBnClickedButton1Prev()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(_ttoi(m_strPage1)>1)m_strPage1.Format(_T("%d"),_ttoi(m_strPage1)-1);
	else m_strPage1.Format(_T("%d"),4);

	init();
	UpdateData(FALSE);
	OnEnChangeEdit1Md5Page();
}



void CFouDIG::OnBnClickedButton1Next()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(_ttoi(m_strPage1)<4) m_strPage1.Format(_T("%d"),_ttoi(m_strPage1)+1);
	else m_strPage1.Format(_T("%d"),1);

	init();
	UpdateData(FALSE);
	OnEnChangeEdit1Md5Page();
}


void CFouDIG::OnEnChangeEdit1Md5Page()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if(TRUE == m_bInitControl1)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strPage1);

		if(nLun > 4)
		{
			nLun = 4;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strPage1.Format(_T("%d"), nLun);

		UpdateData(FALSE);
		//m_strPage1.
		SlowLun1(nLun);

	}
}



void CFouDIG::OnBnClickedButton2Prev()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(_ttoi(m_strPage2)>1)m_strPage2.Format(_T("%d"),_ttoi(m_strPage2)-1);
	else m_strPage2.Format(_T("%d"),16);

	UpdateData(FALSE);
	OnEnChangeEdit2Md5Page();
}

void CFouDIG::OnBnClickedButton2Next()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(_ttoi(m_strPage2)<16) m_strPage2.Format(_T("%d"),_ttoi(m_strPage2)+1);
	else m_strPage2.Format(_T("%d"),1);
	UpdateData(FALSE);
	OnEnChangeEdit2Md5Page();
}

void CFouDIG::OnEnChangeEdit2Md5Page()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不 
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if(TRUE == m_bInitControl2)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strPage2);
		int nLun2= _ttoi(m_strPage1);
		if(nLun > 16)
		{
			nLun = 16;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strPage2.Format(_T("%d"), nLun);
		//m_strPage2=FALSE;

		UpdateData(FALSE);

		SlowLun2(nLun,nLun2);

	}
}


void CFouDIG::XX(unsigned long A, unsigned long B, unsigned long C, unsigned long D, unsigned long x, int S, unsigned long T, int lun)
{
	if(lun==1)
	{	m_cb.Format("%08X",B);
	GetDlgItem(IDC_EDIT2_CB)->SetWindowText(m_cb);//B
	ULONG F= X(B,C,D,lun);
	m_cf.Format("%08X",F);
	GetDlgItem(IDC_EDIT4_CF)->SetWindowText(m_cf);//F
	m_ca2.Format("%08X",A);
	GetDlgItem(IDC_EDIT3_cA2)->SetWindowText(m_ca2);//A1

	A += F + x + T;
	m_cm.Format("%08X",x);
	GetDlgItem(IDC_EDIT5_CM)->SetWindowText(m_cm);//X
	m_ct.Format("%08X",T);
	GetDlgItem(IDC_EDIT6_CT)->SetWindowText(m_ct);//T
	m_cs.Format("%d",S);
	GetDlgItem(IDC_EDIT7_CS)->SetWindowText(m_cs);//S

	A = RotateLeft1(A, S);
	A += B;

	m_ca1.Format("%08X",A);
	GetDlgItem(IDC_EDIT1_CA1)->SetWindowText(m_ca1);//A2
	}
	else if(lun==2)
	{
		m_cb.Format("%08X",B);
		GetDlgItem(IDC_EDIT2_CB)->SetWindowText(m_cb);//B
		ULONG G= X(B,C,D,lun);
		m_cf.Format("%08X",G);
		GetDlgItem(IDC_EDIT4_CF)->SetWindowText(m_cf);//F
		m_ca2.Format("%08X",A);
		GetDlgItem(IDC_EDIT3_cA2)->SetWindowText(m_ca2);//A1

		A += G + x + T;
		m_cm.Format("%08X",x);
		GetDlgItem(IDC_EDIT5_CM)->SetWindowText(m_cm);//X
		m_ct.Format("%08X",T);
		GetDlgItem(IDC_EDIT6_CT)->SetWindowText(m_ct);//T
		m_cs.Format("%d",S);
		GetDlgItem(IDC_EDIT7_CS)->SetWindowText(m_cs);//S

		A = RotateLeft1(A, S);
		A += B;

		m_ca1.Format("%08X",A);
		GetDlgItem(IDC_EDIT1_CA1)->SetWindowText(m_ca1);//A2
	}
	else if(lun==3)
	{
		m_cb.Format("%08X",B);
		GetDlgItem(IDC_EDIT2_CB)->SetWindowText(m_cb);//B
		ULONG H= X(B,C,D,lun);
		m_cf.Format("%08X",H);
		GetDlgItem(IDC_EDIT4_CF)->SetWindowText(m_cf);//F
		m_ca2.Format("%08X",A);
		GetDlgItem(IDC_EDIT3_cA2)->SetWindowText(m_ca2);//A1

		A +=H + x + T;
		m_cm.Format("%08X",x);
		GetDlgItem(IDC_EDIT5_CM)->SetWindowText(m_cm);//X
		m_ct.Format("%08X",T);
		GetDlgItem(IDC_EDIT6_CT)->SetWindowText(m_ct);//T
		m_cs.Format("%d",S);
		GetDlgItem(IDC_EDIT7_CS)->SetWindowText(m_cs);//S

		A = RotateLeft1(A, S);
		A += B;

		m_ca1.Format("%08X",A);
		GetDlgItem(IDC_EDIT1_CA1)->SetWindowText(m_ca1);//A2
	}
	else
	{
		m_cb.Format("%08X",B);
		GetDlgItem(IDC_EDIT2_CB)->SetWindowText(m_cb);//B
		ULONG I= X(B,C,D,lun);
		m_cf.Format("%08X",I);
		GetDlgItem(IDC_EDIT4_CF)->SetWindowText(m_cf);//F
		m_ca2.Format("%08X",A);
		GetDlgItem(IDC_EDIT3_cA2)->SetWindowText(m_ca2);//A1

		A +=I + x + T;
		m_cm.Format("%08X",x);
		GetDlgItem(IDC_EDIT5_CM)->SetWindowText(m_cm);//X
		m_ct.Format("%08X",T);
		GetDlgItem(IDC_EDIT6_CT)->SetWindowText(m_ct);//T
		m_cs.Format("%d",S);
		GetDlgItem(IDC_EDIT7_CS)->SetWindowText(m_cs);//S

		A = RotateLeft1(A, S);
		A += B;

		m_ca1.Format("%08X",A);
		GetDlgItem(IDC_EDIT1_CA1)->SetWindowText(m_ca1);//A2
	}
}

ULONG CFouDIG::X(unsigned long B, unsigned long C, unsigned long D, int lun)//逻辑函数
{
	if(lun==1)
	{
		m_1F.Format("%08X",B);
		GetDlgItem(IDC_EDIT1_F)->SetWindowText(m_1F);//B1
		m_2F.Format("%08X",C);
		GetDlgItem(IDC_EDIT2_F)->SetWindowText(m_2F);//C
		m_3F.Format("%08X",B);
		GetDlgItem(IDC_EDIT3_F)->SetWindowText(m_3F);//B2
		m_4F.Format("%08X",D);
		GetDlgItem(IDC_EDIT4_F)->SetWindowText(m_4F);//D
		ULONG F=(B & C) | (~B & D);
		m_5F.Format("%08X",F);
		GetDlgItem(IDC_EDIT5_F)->SetWindowText(m_5F);//F
		return F;
	}
	else if(lun==2)
	{
		m_1G.Format("%08X",B);
		GetDlgItem(IDC_EDIT1_G)->SetWindowText(m_1G);//B 
		m_2G.Format("%08X",D);
		GetDlgItem(IDC_EDIT2_G)->SetWindowText(m_2G);//D1
		m_3G.Format("%08X",C);
		GetDlgItem(IDC_EDIT3_G)->SetWindowText(m_3G);//C
		m_4G.Format("%08X",D);
		GetDlgItem(IDC_EDIT4_G)->SetWindowText(m_4G);//D2
		ULONG G=(B & D) | (C & ~D);
		m_5G.Format("%08X",G);
		GetDlgItem(IDC_EDIT5_G)->SetWindowText(m_5G);//G
		return G;
	}
	else if(lun==3)
	{
		m_1H.Format("%08X",B);
		GetDlgItem(IDC_EDIT1_H)->SetWindowText(m_1H);//B 
		m_2H.Format("%08X",C);
		GetDlgItem(IDC_EDIT2_H)->SetWindowText(m_2H);//C
		m_3H.Format("%08X",D);
		GetDlgItem(IDC_EDIT3_H)->SetWindowText(m_3H);//D

		ULONG H=(B ^ C ^ D);
		m_4H.Format("%08X",H);
		GetDlgItem(IDC_EDIT4_H)->SetWindowText(m_4H);//H
		return H;
	}
	else 
	{
		m_1I.Format("%08X",C);
		GetDlgItem(IDC_EDIT1_I)->SetWindowText(m_1I);//C 
		m_2I.Format("%08X",B);
		GetDlgItem(IDC_EDIT2_I)->SetWindowText(m_2I);//B
		m_3I.Format("%08X",D);
		GetDlgItem(IDC_EDIT3_I)->SetWindowText(m_3I);//D

		ULONG I=(C ^ (B | ~D));
		m_4I.Format("%08X",I);
		GetDlgItem(IDC_EDIT4_I)->SetWindowText(m_4I);//H
		return I;
	}
}
void CFouDIG::SlowLun2(int f=1,int ff=1)
{

	if(ff==1)
	{
#pragma region name
		switch(f)
		{
		case 1:
			m_a1.Format("%08X",aa[0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",aa[3]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",aa[3]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);

			//逻辑函数
			//X(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),ff);
			//操作程序		
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[0],MD5_S11,MD5_T01,ff);
			break;
		case 2:
			m_a1.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",aa[3]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			//逻辑函数
			//X(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),ff);
			//操作程序		
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[1],MD5_S12,MD5_T02,ff);
			break;
		case 3:
			m_a1.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			//逻辑函数
			//X(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),ff);
			//操作程序		
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[2],MD5_S13,MD5_T03,ff);
			break;
		case 4:
			m_a1.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",aa[1]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",aa[2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			//逻辑函数
			//X(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),ff);
			//操作程序		
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[3],MD5_S14,MD5_T04,ff);
			break;
		case 5:
			m_a1.Format("%08X",n[0][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			//逻辑函数
			//X(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),ff);
			//操作程序		
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[4],MD5_S11,MD5_T05,ff);
			break;
		case 6:
			m_a1.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[5],MD5_S12,MD5_T06,ff);
			break;
		case 7:
			m_a1.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[6],MD5_S12,MD5_T06,ff);
			break;
		case 8:
			m_a1.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[7],MD5_S14,MD5_T08,ff);
			break;
		case 9:
			m_a1.Format("%08X",n[0][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[8],MD5_S11,MD5_T09,ff);
			break;
		case 10:
			m_a1.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[9],MD5_S12,MD5_T10,ff);
			break;
		case 11:
			m_a1.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[10],MD5_S13,MD5_T11,ff);
			break;
		case 12:
			m_a1.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[11],MD5_S14,MD5_T12,ff);
			break;
		case 13:
			m_a1.Format("%08X",n[0][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[12],MD5_S11,MD5_T13,ff);
			break;
		case 14:
			m_a1.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[13],MD5_S12,MD5_T14,ff);
			break;
		case 15:
			m_a1.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[14],MD5_S13,MD5_T15,ff);
			break;
		case 16:
			m_a1.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[15],MD5_S14,MD5_T16,ff);
			break;
		}
#pragma endregion</SPAN>
	}
	else if(ff==2)
	{
#pragma region name
		switch(f)
		{
		case 1:
			m_a1.Format("%08X",n[0][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[1],MD5_S21,MD5_T17,ff);
			break;
		case 2:
			m_a1.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[0][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[6],MD5_S22,MD5_T18,ff);

			break;
		case 3:
			m_a1.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[0][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[11],MD5_S23,MD5_T19,ff);

			break;
		case 4:
			m_a1.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[0][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[0],MD5_S24,MD5_T20,ff);

			break;
		case 5:
			m_a1.Format("%08X",n[1][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[5],MD5_S21,MD5_T21,ff);

			break;
		case 6:
			m_a1.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[10],MD5_S22,MD5_T22,ff);

			break;
		case 7:
			m_a1.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[15],MD5_S23,MD5_T23,ff);

			break;
		case 8:
			m_a1.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[4],MD5_S24,MD5_T24,ff);

			break;
		case 9:
			m_a1.Format("%08X",n[1][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[9],MD5_S21,MD5_T25,ff);

			break;
		case 10:
			m_a1.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[14],MD5_S22,MD5_T26,ff);

			break;
		case 11:
			m_a1.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[3],MD5_S23,MD5_T27,ff);

			break;
		case 12:
			m_a1.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[8],MD5_S24,MD5_T28,ff);

			break;
		case 13:
			m_a1.Format("%08X",n[1][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[13],MD5_S21,MD5_T29,ff);

			break;
		case 14:
			m_a1.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[2],MD5_S22,MD5_T30,ff);

			break;
		case 15:
			m_a1.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[7],MD5_S23,MD5_T31,ff);

			break;
		case 16:
			m_a1.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[12],MD5_S24,MD5_T32,ff);

			break;
		}
#pragma endregion</SPAN>
	}
	else if(ff==3)
	{
#pragma region name
		switch(f)
		{
		case 1:
			m_a1.Format("%08X",n[1][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[5],MD5_S31,MD5_T33,ff);

			break;
		case 2:
			m_a1.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[1][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[8],MD5_S32,MD5_T34,ff);

			break;
		case 3:
			m_a1.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[1][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[11],MD5_S33,MD5_T35,ff);

			break;
		case 4:
			m_a1.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[1][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[14],MD5_S34,MD5_T36,ff);

			break;
		case 5:
			m_a1.Format("%08X",n[2][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[1],MD5_S31,MD5_T37,ff);

			break;
		case 6:
			m_a1.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[4],MD5_S32,MD5_T38,ff);

			break;
		case 7:
			m_a1.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[7],MD5_S33,MD5_T39,ff);

			break;
		case 8:
			m_a1.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[10],MD5_S34,MD5_T40,ff);

			break;
		case 9:
			m_a1.Format("%08X",n[2][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[13],MD5_S31,MD5_T41,ff);

			break;
		case 10:
			m_a1.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[0],MD5_S32,MD5_T42,ff);

			break;
		case 11:
			m_a1.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[3],MD5_S33,MD5_T43,ff);

			break;
		case 12:
			m_a1.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[6],MD5_S34,MD5_T44,ff);

			break;
		case 13:
			m_a1.Format("%08X",n[2][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[9],MD5_S31,MD5_T45,ff);
			break;
		case 14:
			m_a1.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[12],MD5_S32,MD5_T46,ff);

			break;
		case 15:
			m_a1.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[15],MD5_S33,MD5_T47,ff);

			break;
		case 16:
			m_a1.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[2],MD5_S34,MD5_T48,ff);

			break;
		}
#pragma endregion</SPAN>
	}
	else 
	{
#pragma region name
		switch(f)
		{
		case 1:
			m_a1.Format("%08X",n[2][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[0],MD5_S41,MD5_T49,ff);

			break;
		case 2:
			m_a1.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[2][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[7],MD5_S42,MD5_T50,ff);

			break;
		case 3:
			m_a1.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[2][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[14],MD5_S43,MD5_T51,ff);

			break;
		case 4:
			m_a1.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[2][15]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[5],MD5_S44,MD5_T52,ff);

			break;
		case 5:
			m_a1.Format("%08X",n[3][0]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[12],MD5_S41,MD5_T53,ff);

			break;
		case 6:
			m_a1.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][1]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[3],MD5_S42,MD5_T54,ff);

			break;
		case 7:
			m_a1.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][2]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[10],MD5_S43,MD5_T55,ff);

			break;
		case 8:
			m_a1.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][3]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[1],MD5_S44,MD5_T56,ff);

			break;
		case 9:
			m_a1.Format("%08X",n[3][4]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[8],MD5_S41,MD5_T57,ff);

			break;
		case 10:
			m_a1.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][5]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[15],MD5_S42,MD5_T58,ff);

			break;
		case 11:
			m_a1.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][6]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[6],MD5_S43,MD5_T59,ff);

			break;
		case 12:
			m_a1.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][7]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[13],MD5_S44,MD5_T60,ff);

			break;
		case 13:
			m_a1.Format("%08X",n[3][8]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[4],MD5_S41,MD5_T61,ff);

			break;
		case 14:
			m_a1.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][9]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),m[11],MD5_S42,MD5_T62,ff);

			break;
		case 15:
			m_a1.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][10]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
			XX(strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),strtoul(m_b1,0,16),m[2],MD5_S43,MD5_T63,ff);

			break;
		case 16:
			m_a1.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
			m_b1.Format("%08X",n[3][11]);
			GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
			m_c1.Format("%08X",n[3][14]);
			GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
			m_d1.Format("%08X",n[3][13]);
			GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

			m_a2.Format("%08X",n[3][12]);
			GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
			m_b2.Format("%08X",n[3][15]);
			GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
			m_c2.Format("%08X",n[3][14]);
			GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
			m_d2.Format("%08X",n[3][13]);
			GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);	
			XX(strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),strtoul(m_a1,0,16),m[9],MD5_S44,MD5_T64,ff);

			break;
		}
#pragma endregion</SPAN>
	}

}

void CFouDIG::SlowLun1(int f=1)
{
	CString strTemp;
	//m_lMD5[4]

	if(1==f)
	{//第一轮
#pragma region name
		//m_strPage2=(_T("1"));
		strTemp.Format(_T("1"));
		GetDlgItem(IDC_STATIC1)->SetWindowText(strTemp);
		strTemp.Format(_T("F"));
		GetDlgItem(IDC_STATIC2)->SetWindowText(strTemp);
		strTemp.Format(_T("(x & y)|(~x&z)"));
		GetDlgItem(IDC_STATIC3)->SetWindowText(strTemp);
		strTemp.Format(_T("1"));
		GetDlgItem(IDC_STATIC4)->SetWindowText(strTemp);
		strTemp.Format(_T("FF"));
		GetDlgItem(IDC_STATIC5)->SetWindowText(strTemp);
		strTemp.Format(_T("F"));
		GetDlgItem(IDC_STATIC6)->SetWindowText(strTemp);

		GetDlgItem(IDC_STATIC_A)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1_F)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2_F)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3_F)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4_F)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT5_F)-> EnableWindow(TRUE);

		GetDlgItem(IDC_STATIC_B)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_G)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_C)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_H)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_D)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_I)-> EnableWindow(FALSE);

		m_a1.Format("%08X",aa[0]);
		GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
		m_b1.Format("%08X",aa[1]);
		GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
		m_c1.Format("%08X",aa[2]);
		GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
		m_d1.Format("%08X",aa[3]);
		GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

		m_a2.Format("%08X",n[0][0]);
		GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
		m_b2.Format("%08X",aa[1]);
		GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
		m_c2.Format("%08X",aa[2]);
		GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
		m_d2.Format("%08X",aa[3]);
		GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
		XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[0],MD5_S11,MD5_T01,f);
#pragma endregion </SPAN>

	}
	else if(2==f)
	{//第二轮
#pragma region name
		strTemp.Format(_T("2"));
		GetDlgItem(IDC_STATIC1)->SetWindowText(strTemp);
		strTemp.Format(_T("G"));
		GetDlgItem(IDC_STATIC2)->SetWindowText(strTemp);
		strTemp.Format(_T("(x & z)|(y&~z)"));
		GetDlgItem(IDC_STATIC3)->SetWindowText(strTemp);
		strTemp.Format(_T("2"));
		GetDlgItem(IDC_STATIC4)->SetWindowText(strTemp);
		strTemp.Format(_T("GG"));
		GetDlgItem(IDC_STATIC5)->SetWindowText(strTemp);
		strTemp.Format(_T("G"));
		GetDlgItem(IDC_STATIC6)->SetWindowText(strTemp);

		GetDlgItem(IDC_STATIC_A)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_F)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_B)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1_G)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2_G)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3_G)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4_G)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT5_G)-> EnableWindow(TRUE);

		GetDlgItem(IDC_STATIC_C)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_H)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_D)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_I)-> EnableWindow(FALSE);



		m_a1.Format("%08X",n[0][12]);
		GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
		m_b1.Format("%08X",n[0][15]);
		GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
		m_c1.Format("%08X",n[0][14]);
		GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
		m_d1.Format("%08X",n[0][13]);
		GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

		m_a2.Format("%08X",n[1][0]);
		GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
		m_b2.Format("%08X",n[0][15]);
		GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
		m_c2.Format("%08X",n[0][14]);
		GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
		m_d2.Format("%08X",n[0][13]);
		GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
		XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[1],MD5_S21,MD5_T17,f);

#pragma endregion </SPAN>  

	}
	else if(3==f)
	{
#pragma region name
		strTemp.Format(_T("3"));
		GetDlgItem(IDC_STATIC1)->SetWindowText(strTemp);
		strTemp.Format(_T("H"));
		GetDlgItem(IDC_STATIC2)->SetWindowText(strTemp);
		strTemp.Format(_T("x⊕y⊕z"));
		GetDlgItem(IDC_STATIC3)->SetWindowText(strTemp);
		strTemp.Format(_T("3"));
		GetDlgItem(IDC_STATIC4)->SetWindowText(strTemp);
		strTemp.Format(_T("HH"));
		GetDlgItem(IDC_STATIC5)->SetWindowText(strTemp);
		strTemp.Format(_T("H"));
		GetDlgItem(IDC_STATIC6)->SetWindowText(strTemp);

		GetDlgItem(IDC_STATIC_A)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_F)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_B)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_G)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_C)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1_H)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2_H)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3_H)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4_H)-> EnableWindow(TRUE);

		GetDlgItem(IDC_STATIC_D)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_I)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_I)-> EnableWindow(FALSE);



		m_a1.Format("%08X",n[1][12]);
		GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
		m_b1.Format("%08X",n[1][15]);
		GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
		m_c1.Format("%08X",n[1][14]);
		GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
		m_d1.Format("%08X",n[1][13]);
		GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

		m_a2.Format("%08X",n[2][0]);
		GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
		m_b2.Format("%08X",n[1][15]);
		GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
		m_c2.Format("%08X",n[1][14]);
		GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
		m_d2.Format("%08X",n[1][13]);
		GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
		XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[5],MD5_S31,MD5_T33,f);

#pragma  endregion </SPAN>
	}
	else
	{
#pragma region name
		strTemp.Format(_T("4"));
		GetDlgItem(IDC_STATIC1)->SetWindowText(strTemp);
		strTemp.Format(_T("I"));
		GetDlgItem(IDC_STATIC2)->SetWindowText(strTemp);
		strTemp.Format(_T("y⊕(x&~z)"));
		GetDlgItem(IDC_STATIC3)->SetWindowText(strTemp);
		strTemp.Format(_T("4"));
		GetDlgItem(IDC_STATIC4)->SetWindowText(strTemp);
		strTemp.Format(_T("II"));
		GetDlgItem(IDC_STATIC5)->SetWindowText(strTemp);
		strTemp.Format(_T("I"));
		GetDlgItem(IDC_STATIC6)->SetWindowText(strTemp);

		GetDlgItem(IDC_STATIC_A)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_F)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_F)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_B)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_G)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5_G)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_C)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT1_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3_H)-> EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4_H)-> EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_D)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1_I)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2_I)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3_I)-> EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4_I)-> EnableWindow(TRUE);

		m_a1.Format("%08X",n[2][12]);
		GetDlgItem(IDC_EDIT1_A1)->SetWindowText(m_a1);
		m_b1.Format("%08X",n[2][15]);
		GetDlgItem(IDC_EDIT2_B1)->SetWindowText(m_b1); 
		m_c1.Format("%08X",n[2][14]);
		GetDlgItem(IDC_EDIT3_C1)->SetWindowText(m_c1);
		m_d1.Format("%08X",n[2][13]);
		GetDlgItem(IDC_EDIT4_D1)->SetWindowText(m_d1);

		m_a2.Format("%08X",n[3][0]);
		GetDlgItem(IDC_EDIT1_A2)->SetWindowText(m_a2);
		m_b2.Format("%08X",n[2][15]);
		GetDlgItem(IDC_EDIT2_B2)->SetWindowText(m_b2); 
		m_c2.Format("%08X",n[2][14]);
		GetDlgItem(IDC_EDIT3_C2)->SetWindowText(m_c2);
		m_d2.Format("%08X",n[2][13]);
		GetDlgItem(IDC_EDIT4_D2)->SetWindowText(m_d2);
		XX(strtoul(m_a1,0,16),strtoul(m_b1,0,16),strtoul(m_c1,0,16),strtoul(m_d1,0,16),m[0],MD5_S41,MD5_T49,f);


#pragma endregion </SPAN>
	}


}








void CFouDIG::OnEnChangeEdit5Cm()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CFouDIG::OnEnChangeEdit2Cb()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




//void CFouDIG::XX(unsigned long A, unsigned long B, unsigned long C, unsigned long D, unsigned long X, unsigned long S, unsigned long T)
//{
//}


//void CFouDIG::X(unsigned long B, unsigned long C, unsigned long D)
//{
//}








unsigned long CFouDIG::RotateLeft1(unsigned long x, int n)
{
	ASSERT( sizeof(x) == 4 );

	//rotate and return x
	return (x << n) | (x >> (32-n));
}


void CFouDIG::OnEnChangeEdit4I()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
