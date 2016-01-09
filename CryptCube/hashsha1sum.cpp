// HashSHA1Sum.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSHA1Sum.h"
#include "afxdialogex.h"
extern ULONG aa1[10];
extern ULONG a[10];
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

// HashSHA1Sum 对话框

IMPLEMENT_DYNAMIC(HashSHA1Sum, CDialogEx)

HashSHA1Sum::HashSHA1Sum(CWnd* pParent /*=NULL*/)
	: CDialogEx(HashSHA1Sum::IDD, pParent)
{

	m_digist = _T("");
	m_a1 = _T("");
	m_a2 = _T("");
	m_a3 = _T("");
	m_a4 = _T("");
	m_a5 = _T("");
	m_b1 = _T("");
	m_b2 = _T("");
	m_b3 = _T("");
	m_b4 = _T("");
	m_b5 = _T("");
	m_c1 = _T("");
	m_c2 = _T("");
	m_c3 = _T("");
	m_c4 = _T("");
	m_c5 = _T("");
}

HashSHA1Sum::~HashSHA1Sum()
{
}

void HashSHA1Sum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_digist);
	DDX_Text(pDX, IDC_EDIT2, m_a1);
	DDX_Text(pDX, IDC_EDIT5, m_a2);
	DDX_Text(pDX, IDC_EDIT4, m_a3);
	DDX_Text(pDX, IDC_EDIT6, m_a4);
	DDX_Text(pDX, IDC_EDIT7, m_a5);
	DDX_Text(pDX, IDC_EDIT8, m_b1);
	DDX_Text(pDX, IDC_EDIT3, m_b2);
	DDX_Text(pDX, IDC_EDIT9, m_b3);
	DDX_Text(pDX, IDC_EDIT10, m_b4);
	DDX_Text(pDX, IDC_EDIT13, m_b5);
	DDX_Text(pDX, IDC_EDIT12, m_c1);
	DDX_Text(pDX, IDC_EDIT11, m_c2);
	DDX_Text(pDX, IDC_EDIT14, m_c3);
	DDX_Text(pDX, IDC_EDIT15, m_c4);
	DDX_Text(pDX, IDC_EDIT16, m_c5);
}


BEGIN_MESSAGE_MAP(HashSHA1Sum, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &HashSHA1Sum::OnBnClickedCancel)
END_MESSAGE_MAP()


// HashSHA1Sum 消息处理程序


void HashSHA1Sum::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL HashSHA1Sum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

UpdateData(TRUE);
	m_b1.Format("67452301");
	m_b2.Format("efcdab89");	
	m_b3.Format("98badcfe");
	m_b4.Format("10325476");
	m_b5.Format("c3d2e1f0");

	m_a1.Format("%08X",A2[79]);
	GetDlgItem(IDC_EDIT2)->SetWindowText(m_a1);
	m_a2.Format("%08X",B2[79]);
	GetDlgItem(IDC_EDIT5)->SetWindowText(m_a2);
	m_a3.Format("%08X",C2[79]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_a3);
	m_a4.Format("%08X",D2[79]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_a4);
	m_a5.Format("%08X",E2[79]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_a5);

	m_c1.Format("%08X",aa1[5]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_c1);
	m_c2.Format("%08X",aa1[6]);
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_c2);
	m_c3.Format("%08X",aa1[7]);
	GetDlgItem(IDC_EDIT14)->SetWindowText(m_c3);
	m_c4.Format("%08X",aa1[8]);
	GetDlgItem(IDC_EDIT15)->SetWindowText(m_c4);
	m_c5.Format("%08X",aa1[9]);
	GetDlgItem(IDC_EDIT16)->SetWindowText(m_c5);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
