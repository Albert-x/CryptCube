// HashSum.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSum.h"
#include "afxdialogex.h"

extern ULONG n[4][16];
extern ULONG aa[4];
// CHashSum �Ի���

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


// CHashSum ��Ϣ�������


void CHashSum::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

BOOL CHashSum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
}
void CHashSum::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}





void CHashSum::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
