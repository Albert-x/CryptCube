// SelectTerm.cpp : ʵ���ļ�
#include "stdafx.h"
#include "CryptCube.h"
#include "SelectTerm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
CString sss="";
CString ttt="";
class search
{
public:
	string str;
	int judge2(string);
	int display(string);
	string read2();
	int read();
};
int search::judge2(string a)//�ж��ַ�����һλ�Ƿ�Ϊ����
{
	char p[100];
	a.copy(p,a.size(),0);
	if((p[0]>='1')&&(p[0]<='9'))
		return 0;
	else
		return 1;
}
string search::read2()//�����û�����Ĵʻ��Ƿ����
{
	//getline(cin,str);
	ifstream fin;
	fin.open("flashSource\\MyIndex.txt");
	if(!fin) return "ERROR";
    string x="";//�ĵ���ȡ��ÿһ�е��ַ�����ֵ��x
    string value="";//����ֵ
    while(getline(fin,x))
    {
		if(x==str)//������û��������ͬ
		{
			getline(fin,value);
			return value;//����
		}
		getline(fin,value);
	}
	fin.clear();
	fin.close();
    return "0";
}
int search::display(string va)//������˼
{
	ifstream fin;
	fin.open("flashSource\\MyExplain.txt");//("G:\\Explain.txt");
	if(!fin) return 0;//cout<<"Error!"<<endl;//��Ϊreturn "ERROR!";
	string x;//���ĵ��ж�ȡ��ÿһ�е�ֵ��ֵ��x
	while(getline(fin,x))
    {
		if(x==va)//��x��֮ǰ���ص�ֵ
		{
			getline(fin,x);
			while(judge2(x))//��x��λ��������ʱѭ��
			{
			sss=sss+x.c_str()+"\r\n";
			getline(fin,x);
			}
			break;
		}
	}
	fin.clear();
	fin.close();
	return 1;
}
int search::read()
{
	string x,value;//valueΪ����ֵ
	char p[140],q[140];
	str.copy(p,str.size(),0);//�û�������ַ���ת������p
	ifstream fin;
	fin.open("flashSource\\MyIndex.txt");
	if(!fin) return 0;
	while(getline(fin,x))
    {
		x.copy(q,x.size(),0);//��ȡ�ļ�ÿһ�е�ֵ������q
		int i=0;
		if(p[i]==q[i])
		{
			getline(fin,value);
			while(p[i]==q[i])
			{
				i++;
				if(i==str.length())
					ttt=ttt+x.c_str()+",";
			}			
		}
	}
	fin.clear();
	fin.close();
	return 1;
}
// CSelectTerm �Ի���


IMPLEMENT_DYNCREATE(CSelectTerm, CForm)


CSelectTerm::CSelectTerm()
: CForm(CSelectTerm::IDD)
{

}

CSelectTerm::~CSelectTerm()
{
}

void CSelectTerm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectTerm, CForm)
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CSelectTerm::OnEnChangeEdit1)
	ON_LBN_SELCHANGE(IDC_LIST3, &CSelectTerm::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSelectTerm::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CSelectTerm::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectTerm ��Ϣ�������


#ifdef _DEBUG
void CSelectTerm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectTerm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG
//////////////////////////////////
HCURSOR CSelectTerm::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSelectTerm::OnEnChangeEdit1()
{   
	CListBox *p=(CListBox*)GetDlgItem(IDC_LIST3);
	p->ResetContent();
	search t,t2,t3;
	CString a;
	GetDlgItemText(IDC_EDIT1,a);
	a.TrimRight();//ȥ���ַ���ĩβ�Ŀո�
	t.str=a;
	t2.str=a.MakeLower();//�ַ���ת����Сд
	t3.str=a.MakeUpper();//�ַ���ת���ɴ�д
	if(t.str!="")
	{
		if(t.judge2(t.str)==1)//��Ϊ����
		{
		int sh=t.read();
		if(t.str!=t2.str)
			t2.read();
		if(t.str!=t3.str)
			t3.read();
		if(sh==0)
			MessageBox("��ȡ�ĵ�����,����1");//SetDlgItemText(IDC_STATIC,"��ȡ�ĵ�����!");����1Ϊread()
		else
		{
			ttt=ttt+"stop";
			CString strTmp;
			int n=1;
			AfxExtractSubString( strTmp,(LPCTSTR)ttt,0,',');
			while(strTmp!="stop")//��Ϊstopֹͣѭ����ttt���Զ��ŷָ������ַ���������IDC_LIST1��
			{
				p->AddString(strTmp);
				AfxExtractSubString( strTmp,ttt,n,',');
				n++;
			}
		}
		}
	}
	ttt="";
}

void CSelectTerm::OnLbnSelchangeList1()//��IDC_LIST1��ѡ�е�ֵ����IDC_EDIT1��
{

	CListBox *p=(CListBox*)GetDlgItem(IDC_LIST3);
	int cur=p->GetCurSel();
	if(cur>=0)
    {
		CString cs;
		p->GetText(cur,cs);
		SetDlgItemText(IDC_EDIT1,cs);
    }
}



void CSelectTerm::OnBnClickedButton1()
{
	CString a;
	GetDlgItemText(IDC_EDIT1,a);
	a.TrimRight();//ȥ���ַ���ĩβ�Ŀո�
	search st;
	st.str=a;
	if(st.str!="") 
	{
		string v;
		v=st.read2();
		if(v=="0")
			SetDlgItemText(IDC_EDIT3,"�Ҳ���!");
		else if(v=="ERROR")
			MessageBox("��ȡ�ĵ���������2");//����2Ϊread2()
		else
		{
			int sh=st.display(v);
			if (sh==0)
				MessageBox("��ȡ�ĵ�����,����3");//SetDlgItemText(IDC_STATIC,"��ȡ�ĵ�����!");����3Ϊdisplay()
			else//��ʾ�ʻ����
			{
			SetDlgItemText(IDC_EDIT3,sss);
			sss="";
			}
		}
	}
}


void CSelectTerm::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString a;
	GetDlgItemText(IDC_EDIT1,a);
	a.TrimRight();//ȥ���ַ���ĩβ�Ŀո�
	search st;
	st.str=a;
	if(st.str!="") 
	{
		string v;
		v=st.read2();
		if(v=="0")
			SetDlgItemText(IDC_EDIT3,"�Ҳ���!");
		else if(v=="ERROR")
			MessageBox("��ȡ�ĵ���������2");//����2Ϊread2()
		else
		{
			int sh=st.display(v);
			if (sh==0)
				MessageBox("��ȡ�ĵ�����,����3");//SetDlgItemText(IDC_STATIC,"��ȡ�ĵ�����!");����3Ϊdisplay()
			else//��ʾ�ʻ����
			{
			SetDlgItemText(IDC_EDIT3,sss);
			sss="";
			}
		}
	}
}
