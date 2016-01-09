// HashSHA1Lun.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSHA1Lun.h"
#include "afxdialogex.h"
extern ULONG aa1[10];
extern ULONG A1[90];
extern ULONG A2[90];
extern ULONG B1[90];
extern ULONG B2[90];
extern ULONG C1[90];
extern ULONG C2[90];
extern ULONG D1[90];
extern ULONG D2[90];
extern ULONG E1[90];
extern ULONG E2[90];
extern ULONG W1[90];
const unsigned K[] = 	{ 				// Constants defined for SHA-1
								0x5A827999,
								0x6ED9EBA1,
								0x8F1BBCDC,
								0xCA62C1D6
							};
// HashSHA1Lun 对话框

IMPLEMENT_DYNAMIC(HashSHA1Lun, CDialogEx)

HashSHA1Lun::HashSHA1Lun(CWnd* pParent /*=NULL*/)
	: CDialogEx(HashSHA1Lun::IDD, pParent)
{

	m_l1 = _T("");
	//  m_l2 = _T("");
	m_l10 = _T("");
	m_l11 = _T("");
	m_l12 = _T("");
	m_l13 = _T("");
	m_l14 = _T("");
	m_l15 = _T("");
	m_l16 = _T("");
	m_l17 = _T("");
	m_l18 = _T("");
	m_l19 = _T("");
	m_l2 = _T("");
	m_l20 = _T("");
	m_l21 = _T("");
	m_l22 = _T("");
	m_l23 = _T("");
	m_l24 = _T("");
	m_l25 = _T("");
	m_l3 = _T("");
	m_l4 = _T("");
	//  m_l5 = _T("");
	//  m_l6 = _T("");
	m_l6 = _T("");
	m_l7 = _T("");
	m_l8 = _T("");
	m_l9 = _T("");
}

HashSHA1Lun::~HashSHA1Lun()
{
}

void HashSHA1Lun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_l1);
	DDX_Text(pDX, IDC_EDIT10, m_l10);
	DDX_Text(pDX, IDC_EDIT11, m_l11);
	DDX_Text(pDX, IDC_EDIT12, m_l12);
	DDX_Text(pDX, IDC_EDIT13, m_l13);
	DDX_Text(pDX, IDC_EDIT14, m_l14);
	DDX_Text(pDX, IDC_EDIT15, m_l15);
	DDX_Text(pDX, IDC_EDIT16, m_l16);
	DDX_Text(pDX, IDC_EDIT17, m_l17);
	DDX_Text(pDX, IDC_EDIT18, m_l18);
	DDX_Text(pDX, IDC_EDIT19, m_l19);
	DDX_Text(pDX, IDC_EDIT2, m_l2);
	DDX_Text(pDX, IDC_EDIT20, m_l20);
	DDX_Text(pDX, IDC_EDIT21, m_l21);
	DDX_Text(pDX, IDC_EDIT22, m_l22);
	DDX_Text(pDX, IDC_EDIT23, m_l23);
	DDX_Text(pDX, IDC_EDIT24, m_l24);
	DDX_Text(pDX, IDC_EDIT25, m_l25);
	DDX_Text(pDX, IDC_EDIT3, m_l3);
	DDX_Text(pDX, IDC_EDIT4, m_l4);
	DDX_Text(pDX, IDC_EDIT6, m_l6);
	DDX_Text(pDX, IDC_EDIT7, m_l7);
	DDX_Text(pDX, IDC_EDIT8, m_l8);
	DDX_Text(pDX, IDC_EDIT9, m_l9);
}


BEGIN_MESSAGE_MAP(HashSHA1Lun, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &HashSHA1Lun::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &HashSHA1Lun::OnBnClickedButton2)
END_MESSAGE_MAP()


// HashSHA1Lun 消息处理程序
void HashSHA1Lun::init(void)
{
	CString strTemp;
	strTemp.Format(_T("1"));
	GetDlgItem(IDC_EDIT1)->SetWindowText(strTemp);
}

BOOL HashSHA1Lun::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString strTemp;
	strTemp.Format(_T("1"));
	GetDlgItem(IDC_EDIT1)->SetWindowText(strTemp);
	GetDlgItem(IDC_EDIT2)->SetWindowText(strTemp);
	GetDlgItem(IDC_EDIT1)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT8)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT9)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT10)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT11)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT12)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT13)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT14)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT15)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT16)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT17)-> EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT18)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT19)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT20)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT21)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT22)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT23)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT24)-> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT25)-> EnableWindow(FALSE);
	UpdateData(TRUE);
	m_bInitControl1= TRUE;
	m_l3.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);
	m_l13.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);
	m_l4.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[0]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);
	m_l22.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);
	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
   
	UpdateData(FALSE);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void HashSHA1Lun::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if(_ttoi(m_l1)>1)m_l1.Format(_T("%d"),_ttoi(m_l1)-1);
	else m_l1.Format(_T("%d"),80);
	init();
	UpdateData(FALSE);
	OnEnChangeEdit1sha1Page();
}

void HashSHA1Lun::OnBnClickedButton2()
{
	UpdateData(TRUE);
	if(_ttoi(m_l1)<80)m_l1.Format(_T("%d"),_ttoi(m_l1)+1);
	else m_l1.Format(_T("%d"),1);
	init();
	UpdateData(FALSE);
	OnEnChangeEdit1sha1Page();
}

void HashSHA1Lun::OnEnChangeEdit1sha1Page(void)
{
	if(TRUE == m_bInitControl1)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_l1);
		if(nLun > 80)
		{
			nLun = 80;
		}

		 if(nLun < 1)
		{
			nLun = 1;
		}
		m_l1.Format(_T("%d"), nLun);	
		lun();
		go();
		UpdateData(FALSE);
}

}

	void HashSHA1Lun::lun(void)
	{
		UpdateData(TRUE);
		int nLun = _ttoi(m_l1);
		int mLun=1;
		if(nLun > 80)
		{
			nLun = 80;
		}

		 if(nLun < 1)
		{
			nLun = 1;
		}

	   if(mLun > 4||nLun>=60)
		{
			mLun = 4;
		}
	   else if(nLun>=40&&nLun<=60)
		{
			mLun =3;
		}
		else if(nLun>=20&&nLun<=40)
		{
			mLun =2;
		}
		 
	    else if(mLun < 1||nLun<=20)
		{
			mLun = 1;
		}
		m_l2.Format(_T("%d"), mLun);	 	 
		UpdateData(FALSE);
	}


	void HashSHA1Lun::go(void)
	{
		UpdateData(TRUE);
	int f= _ttoi(m_l1); //1~80
	#pragma region name
		switch(f)
		{
		case 1:
	m_l3.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[0]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;

		case 2:
	m_l3.Format("%08X",A1[1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;
	
	case 3:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 4:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 5:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 6:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 7:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 8:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 9:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 10:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 11:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 12:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 13:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 14:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 15:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 16:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 17:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 18:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 19:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[0]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 20:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 21:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;

		case 22:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;
	
	case 23:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 24:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 25:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 26:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 27:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 28:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 29:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 30:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 31:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 32:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 33:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 34:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 35:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 36:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 37:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 38:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 39:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 40:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 41:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;

		case 42:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;
	
	case 43:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 44:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 45:
		m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[1]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 46:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 47:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 48:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 49:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 50:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 51:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 52:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 53:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 54:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 55:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 56:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 57:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 58:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 59:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[2]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 60:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 61:
	m_l3.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[0]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[0]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[0]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[0]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[0]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[0]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[0]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[0]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[0]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[0]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[0]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;

		case 62:
	m_l3.Format("%08X",A1[1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
	break;
	
	case 63:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 64:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 65:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 66:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 67:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 68:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 69:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 70:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);
		break;
			case 71:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 72:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 73:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 74:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 75:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 76:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 77:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

    m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 78:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 79:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
			case 80:
	m_l3.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_l3);
	m_l9.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_l9);
	m_l10.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_l10);
	m_l11.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_l11);
	m_l12.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_l12);

	m_l13.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT13)->SetWindowText(m_l13);
	m_l14.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_l14);
	m_l15.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_l15);
	m_l16.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_l16);
	m_l17.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT17)->SetWindowText(m_l17);

	m_l4.Format("%08X",A2[f-1]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_l4);
	m_l6.Format("%08X",A1[f-1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_l6);
	m_l7.Format("%08X",B1[f-1]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_l7);
	m_l8.Format("%08X",C1[f-1]);
	GetDlgItem(IDC_EDIT8)->SetWindowText(m_l8);
	m_l18.Format("%08X",D1[f-1]);
	GetDlgItem(IDC_EDIT18)->SetWindowText(m_l18);
	m_l21.Format("%08X",E1[f-1]);
	GetDlgItem(IDC_EDIT21)->SetWindowText(m_l21);
	m_l20.Format("%08X",W1[f-1]);
	GetDlgItem(IDC_EDIT20)->SetWindowText(m_l20);

	m_l22.Format("%08X",B2[f-1]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_l22);
	m_l23.Format("%08X",D2[f-1]);
	GetDlgItem(IDC_EDIT23)->SetWindowText(m_l23);
	m_l24.Format("%08X",C2[f-1]);
	GetDlgItem(IDC_EDIT24)->SetWindowText(m_l24);
	m_l25.Format("%08X",E2[f-1]);
	GetDlgItem(IDC_EDIT25)->SetWindowText(m_l25);

	m_l19.Format("%08X",K[3]);
	GetDlgItem(IDC_EDIT19)->SetWindowText(m_l19);

		break;
	
				}
		#pragma endregion</SPAN>
				UpdateData(FALSE);


	}
