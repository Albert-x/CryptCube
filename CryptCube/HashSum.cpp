// HashSum.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSum.h"
#include "afxdialogex.h"

extern ULONG n[4][16];
extern ULONG aa[4];
// CHashSum 对话框

IMPLEMENT_DYNAMIC(CHashSum, CDialogEx)

	CHashSum::CHashSum(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHashSum::IDD, pParent)
	, m_digist(_T(""))
	, m_ca1(_T(""))
	, m_cb1(_T(""))
	, m_cc1(_T(""))
	, m_cd1(_T(""))
	, m_ca2(_T(""))
	, m_cb2(_T(""))
	, m_cc2(_T(""))
	, m_cd2(_T(""))
	, m_ca3(_T(""))
	, m_cb3(_T(""))
	, m_cc3(_T(""))
	, m_cd3(_T(""))
{

}

CHashSum::~CHashSum()
{
}

void CHashSum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_digist);
	DDX_Text(pDX, IDC_EDIT2, m_ca1);
	DDX_Text(pDX, IDC_EDIT3, m_cb1);
	DDX_Text(pDX, IDC_EDIT4, m_cc1);
	DDX_Text(pDX, IDC_EDIT69, m_cd1);
	DDX_Text(pDX, IDC_EDIT5, m_ca2);
	DDX_Text(pDX, IDC_EDIT6, m_cb2);
	DDX_Text(pDX, IDC_EDIT7, m_cc2);
	DDX_Text(pDX, IDC_EDIT91, m_cd2);
	DDX_Text(pDX, IDC_EDIT9, m_ca3);
	DDX_Text(pDX, IDC_EDIT10, m_cb3);
	DDX_Text(pDX, IDC_EDIT11, m_cc3);
	DDX_Text(pDX, IDC_EDIT92, m_cd3);
}


BEGIN_MESSAGE_MAP(CHashSum, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CHashSum::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CHashSum::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CHashSum::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CHashSum 消息处理程序


void CHashSum::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

BOOL CHashSum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_digist);
	m_ca2.Format("%08X",aa[0]);
	GetDlgItem(IDC_EDIT5)->SetWindowText(m_ca2);
	m_cb2.Format("%08X",aa[1]);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_cb2);
	m_cc2.Format("%08X",aa[2]);
	GetDlgItem(IDC_EDIT7)->SetWindowText(m_cc2);
	m_cd2.Format("%08X",aa[3]);
	GetDlgItem(IDC_EDIT91)->SetWindowText(m_cd2);

	m_ca1.Format("%08X",n[3][12]);
	GetDlgItem(IDC_EDIT2)->SetWindowText(m_ca1);
	m_cb1.Format("%08X",n[3][15]); 
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_cb1);
	m_cc1.Format("%08X",n[3][14]); 
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_cc1);
	m_cd1.Format("%08X",n[3][13]);
	GetDlgItem(IDC_EDIT69)->SetWindowText(m_cd1);

	m_ca3.Format("%08X",n[3][12]+aa[0]);
	GetDlgItem(IDC_EDIT9)->SetWindowText(m_ca3);
	m_cb3.Format("%08X",n[3][15]+aa[1]); 
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_cb3);
	m_cc3.Format("%08X",n[3][14]+aa[2]); 
	GetDlgItem(IDC_EDIT11)->SetWindowText(m_cc3);
	m_cd3.Format("%08X",n[3][13]+aa[3]);
	GetDlgItem(IDC_EDIT92)->SetWindowText(m_cd3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CHashSum::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}





void CHashSum::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
