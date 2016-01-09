// XTIME.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "XTIME.h"


// XTIME 对话框

IMPLEMENT_DYNAMIC(XTIME, CDialog)

XTIME::XTIME(CWnd* pParent /*=NULL*/)
	: CDialog(XTIME::IDD, pParent)
{
	//SetBackgroundColor(RGB(255,255,255));
}

XTIME::~XTIME()
{
}

void XTIME::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XTIME, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &XTIME::OnBnClickedButton1)
	ON_WM_ERASEBKGND()  
    ON_WM_CTLCOLOR() 
	ON_BN_CLICKED(IDC_RETURN, &XTIME::OnBnClickedReturn)
END_MESSAGE_MAP()


// XTIME 消息处理程序

void XTIME::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a;
	GetDlgItemText(IDC_NUM,a);
	if(a.GetLength()>2)
	{
		MessageBox("该参数不在GF(2^8)中！");
		return;
	}
	a.MakeLower();
	for(int i=0;i<a.GetLength();i++)
	{
		CString ch; 
		ch=a.GetAt(i);
		if(!((ch<="9" && ch>="0" )||(ch<="f"  && ch>= "a")))
		{
			MessageBox("请输入16进制数！");
			return;
		}
	}
	long int num1,num2,num3;
	CString a1=NULL;
	CString a2=NULL;
	CString a3=NULL;
	CString r=NULL;
	CString m="100011011";
	num1=strtol(a,NULL,16);
	num2=num1<<1;
	while(num1)
	{
		if(num1%2) a1="1"+a1;
		else a1="0"+a1;
		num1=num1>>1;
	}
	for(int j=a1.GetLength();j<8;j++)
	{
		a1="0"+a1;
	}
	a2=a1+"0";


	//SetDlgItemInt(IDC_RESULT,num1);
	SetDlgItemText(IDC_NUM1,a1);
	if(num2>=256)
	{
		num3=num2^283;
		SetDlgItemText(IDC_RESULT,change(num3));
		num2=num2^256;
		while(num3)
		{
			if(num3%2) a3="1"+a3;
			else a3="0"+a3;
			num3=num3>>1;
		}
		for(int j=a3.GetLength();j<8;j++)
		{
			a3="0"+a3;
		}

		SetDlgItemText(IDC_NUM3,m);
		SetDlgItemText(IDC_NUM4,a3);
	}
	else
	{
		num3=num2;
		SetDlgItemText(IDC_RESULT,change(num3));
		SetDlgItemText(IDC_NUM3,NULL);
		SetDlgItemText(IDC_NUM4,NULL);
	}

	SetDlgItemText(IDC_NUM2,a2);

}
CString XTIME::change(int num)
{
	CString str=NULL;
	CString t1=NULL;
	int r,m;
	r=num/16;
	m=num%16;
	switch(r)
	{
	case 10:
		str=str+"A";
		break;
	case 11:
		str=str+"B";
		break;
	case 12:
		str=str+"C";
		break;
	case 13:
		str=str+"D";
		break;
	case 14:
		str=str+"E";
		break;
	case 15:
		str=str+"F";
		break;
	default:
		t1.Format("%d", r);
	}
	str=str+t1;

	switch(m)
	{
	case 10:
		str=str+"A";
		break;
	case 11:
		str=str+"B";
		break;
	case 12:
		str=str+"C";
		break;
	case 13:
		str=str+"D";
		break;
	case 14:
		str=str+"E";
		break;
	case 15:
		str=str+"F";
		break;
	default:
		t1.Format("%d", m);
		str=str+t1;
	}


	return str;
}
BOOL XTIME::OnEraseBkgnd(CDC* pDC)   
{  
  // TODO: Add your message handler code here and/or call default  
  CRect rcClient;  
  GetClientRect(rcClient);  
  pDC->FillRect(rcClient, &m_BkBrush);  
  return TRUE;  
  
  //return CDialog::OnEraseBkgnd(pDC);  
}  
  

HBRUSH XTIME::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   
{  
  HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);  
      
  // TODO: Change any attributes of the DC here  
  //  
  {      
    CRect rcCtrl;     
    pWnd->GetWindowRect( &rcCtrl ); //获取控件位置     
    ScreenToClient( &rcCtrl ); //转换到对话框     
      
    //获取ClientDC     
    CDC *pBkDC = GetDC();      
      
    //拷贝背景     
   pDC->BitBlt(0, 0, rcCtrl.Width(), rcCtrl.Height(),pBkDC, rcCtrl.left, rcCtrl.top, WHITENESS);      
      
    //清理工作     
    ReleaseDC( pBkDC ); //释放ClientDC     
      
    //添加其他代码     
    //     
      
    pDC->SetBkMode(TRANSPARENT); //背景透明模式     
    hbr = (HBRUSH)GetStockObject(NULL_BRUSH); //     
  }   
    
  // TODO: Return a different brush if the default is not desired  
  return hbr;  
}  


void XTIME::OnBnClickedReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_NUM,"");
	SetDlgItemText(IDC_NUM1,"");
	SetDlgItemText(IDC_NUM2,"");
	SetDlgItemText(IDC_NUM3,"");
	SetDlgItemText(IDC_NUM4,"");
	SetDlgItemText(IDC_RESULT,"");
}
