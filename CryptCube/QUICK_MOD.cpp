// QUICK_MOD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "QUICK_MOD.h"
//#include "cstringt.h" 

// QUICK_MOD �Ի���

IMPLEMENT_DYNAMIC(QUICK_MOD, CDialog)

QUICK_MOD::QUICK_MOD(CWnd* pParent /*=NULL*/)
	: CDialog(QUICK_MOD::IDD, pParent)
{

}

QUICK_MOD::~QUICK_MOD()
{
}

void QUICK_MOD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QUICK_MOD, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &QUICK_MOD::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CAL_BUTTON, &QUICK_MOD::OnBnClickedCalButton)
	ON_BN_CLICKED(IDC_SHOW, &QUICK_MOD::OnBnClickedShow)
	ON_BN_CLICKED(IDC_REP, &QUICK_MOD::OnBnClickedRep)
	//ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
		//ON_WM_ERASEBKGND()  
   // ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// QUICK_MOD ��Ϣ�������

void QUICK_MOD::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}

void QUICK_MOD::OnBnClickedCalButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long a, b, m;
	long A=1;
	BOOL aa,bb,mm;
	a=GetDlgItemInt(IDC_A,&aa);
	b=GetDlgItemInt(IDC_B,&bb);
	m=GetDlgItemInt(IDC_M,&mm);
	if(aa==0 ||bb==0 || mm==0)
	{
		MessageBox("�����������������������");
		return;
	}
	if(a<0 || b<0 || m<0 || a==0)
	{
		MessageBox("a��(0,��)��b,m��[0,��)��");
		return;
	}
	while(b!=0)
	{
		if(b%2) A=(A*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	SetDlgItemInt(IDC_R,A);
}

void QUICK_MOD::OnBnClickedShow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long a, b, m;
	CString str1,str2,str3,str4;
	CString str11,str33,str44;
	str1="i   ";
	str2="bi  ";
	str3="a   ";
	str4="A   ";
	long A=1;
	int i=0;
	a=GetDlgItemInt(IDC_A);
	b=GetDlgItemInt(IDC_B);
	m=GetDlgItemInt(IDC_M);
	if(a==0 ||b==0 || m==0)
	{
		MessageBox("�����������������������");
		return;
	}
	while(b!=0)
	{
		if(b%2)
		{
			str2=str2+"1  ";

			A=(A*a)%m;

		}
		else
		{
			str2=str2+"0  ";
		}
		a=(a*a)%m;
		b=b>>1;
		str11.Format("%d",i);
		str33.Format("%d",a);
		str44.Format("%d",A);
		str1=str1+str11+"  ";
		str3=str3+str33+"  ";
		str4=str4+str44+"  ";
		i++;
	}
	str1=str1+"\r\n\r\n";
	str2=str2+"\r\n\r\n";
	str3=str3+"\r\n\r\n";
	str4=str4+"\t\n\r\n";



	SetDlgItemText(IDC_P,str1+str2+str3+str4);

}

void QUICK_MOD::OnBnClickedRep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_A,"");
	SetDlgItemText(IDC_B,"");
	SetDlgItemText(IDC_M,"");
	SetDlgItemText(IDC_P,"");
	SetDlgItemText(IDC_R,"");
}
/*BOOL QUICK_MOD::OnEraseBkgnd(CDC* pDC)   
{  
  // TODO: Add your message handler code here and/or call default  
  CRect rcClient;  
  GetClientRect(rcClient);  
  pDC->FillRect(rcClient, &m_BkBrush);  
  return TRUE;  
  
  //return CDialog::OnEraseBkgnd(pDC);  
}  
  */

BOOL QUICK_MOD::OnInitDialog()
{
	CDialog::OnInitDialog();
	

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
//	ASSERT((IDD_ABOUTBOX & 0xFFF0) == IDD_ABOUTBOX);
	//ASSERT(IDD_ABOUTBOX < 0xF000);
	/*
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDD_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDD_ABOUTBOX, strAboutMenu);
		}
	}*/

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//SkinH_Attach();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}



// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

/*void QUICK_MOD::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR QUICK_MOD::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}*/

