// SelectTerm.cpp : 实现文件
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
int search::judge2(string a)//判断字符串第一位是否为数字
{
	char p[100];
	a.copy(p,a.size(),0);
	if((p[0]>='1')&&(p[0]<='9'))
		return 0;
	else
		return 1;
}
string search::read2()//查找用户输入的词汇是否存在
{
	//getline(cin,str);
	ifstream fin;
	fin.open("flashSource\\MyIndex.txt");
	if(!fin) return "ERROR";
    string x="";//文档读取的每一行的字符串赋值给x
    string value="";//返回值
    while(getline(fin,x))
    {
		if(x==str)//如果与用户输入的相同
		{
			getline(fin,value);
			return value;//返回
		}
		getline(fin,value);
	}
	fin.clear();
	fin.close();
    return "0";
}
int search::display(string va)//词语意思
{
	ifstream fin;
	fin.open("flashSource\\MyExplain.txt");//("G:\\Explain.txt");
	if(!fin) return 0;//cout<<"Error!"<<endl;//改为return "ERROR!";
	string x;//从文档中读取的每一行的值赋值给x
	while(getline(fin,x))
    {
		if(x==va)//若x是之前返回的值
		{
			getline(fin,x);
			while(judge2(x))//当x首位不是数字时循环
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
	string x,value;//value为返回值
	char p[140],q[140];
	str.copy(p,str.size(),0);//用户输入的字符串转成数组p
	ifstream fin;
	fin.open("flashSource\\MyIndex.txt");
	if(!fin) return 0;
	while(getline(fin,x))
    {
		x.copy(q,x.size(),0);//读取文件每一行的值到数组q
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
// CSelectTerm 对话框


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


// CSelectTerm 消息处理程序


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
	a.TrimRight();//去掉字符串末尾的空格
	t.str=a;
	t2.str=a.MakeLower();//字符串转换成小写
	t3.str=a.MakeUpper();//字符串转换成大写
	if(t.str!="")
	{
		if(t.judge2(t.str)==1)//不为数字
		{
		int sh=t.read();
		if(t.str!=t2.str)
			t2.read();
		if(t.str!=t3.str)
			t3.read();
		if(sh==0)
			MessageBox("读取文档出错,错误1");//SetDlgItemText(IDC_STATIC,"读取文档出错!");错误1为read()
		else
		{
			ttt=ttt+"stop";
			CString strTmp;
			int n=1;
			AfxExtractSubString( strTmp,(LPCTSTR)ttt,0,',');
			while(strTmp!="stop")//当为stop停止循环，ttt是以逗号分隔开的字符串，传到IDC_LIST1上
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

void CSelectTerm::OnLbnSelchangeList1()//将IDC_LIST1中选中的值传到IDC_EDIT1上
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
	a.TrimRight();//去掉字符串末尾的空格
	search st;
	st.str=a;
	if(st.str!="") 
	{
		string v;
		v=st.read2();
		if(v=="0")
			SetDlgItemText(IDC_EDIT3,"找不到!");
		else if(v=="ERROR")
			MessageBox("读取文档出错，错误2");//错误2为read2()
		else
		{
			int sh=st.display(v);
			if (sh==0)
				MessageBox("读取文档出错,错误3");//SetDlgItemText(IDC_STATIC,"读取文档出错!");错误3为display()
			else//显示词汇解释
			{
			SetDlgItemText(IDC_EDIT3,sss);
			sss="";
			}
		}
	}
}


void CSelectTerm::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a;
	GetDlgItemText(IDC_EDIT1,a);
	a.TrimRight();//去掉字符串末尾的空格
	search st;
	st.str=a;
	if(st.str!="") 
	{
		string v;
		v=st.read2();
		if(v=="0")
			SetDlgItemText(IDC_EDIT3,"找不到!");
		else if(v=="ERROR")
			MessageBox("读取文档出错，错误2");//错误2为read2()
		else
		{
			int sh=st.display(v);
			if (sh==0)
				MessageBox("读取文档出错,错误3");//SetDlgItemText(IDC_STATIC,"读取文档出错!");错误3为display()
			else//显示词汇解释
			{
			SetDlgItemText(IDC_EDIT3,sss);
			sss="";
			}
		}
	}
}
