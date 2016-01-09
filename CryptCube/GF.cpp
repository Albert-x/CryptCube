// GF.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "GF.h"


// GF 对话框

IMPLEMENT_DYNAMIC(GF, CDialog)

GF::GF(CWnd* pParent /*=NULL*/)
	: CDialog(GF::IDD, pParent)
{

}

GF::~GF()
{
}

void GF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GF, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &GF::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &GF::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &GF::OnBnClickedButton3)
	ON_WM_ERASEBKGND()  
    ON_WM_CTLCOLOR() 
END_MESSAGE_MAP()


// GF 消息处理程序

void GF::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,b;
	GetDlgItemText(IDC_A,a);
	GetDlgItemText(IDC_B,b);

	if(a.GetLength()>2 || b.GetLength()>2)
	{
		MessageBox("a或b不在GF(2^8)中！");
		return;
	}
	//a.MakeLower()
	//b.MakeLower();

	for(int i=0;i<a.GetLength();i++)
	{
		CString ch; 
		ch=a.GetAt(i);
		if(!((ch<="9" && ch>="0" )||(ch<="F"  && ch>= "A")))
		{
			MessageBox("请输入16进制数！");
			return;
		}
	}
	for(int i=0;i<a.GetLength();i++)
	{
		CString ch; 
		ch=a.GetAt(i);
		if(!((ch<="9" && ch>="0" )||(ch<="F"  && ch>= "A")))
		{
			MessageBox("请输入16进制数！");
			return;
		}
	}
	long int num1,num2,num3;
	num1=strtol(a,NULL,16);
	num2=strtol(b,NULL,16);
	num3=0;

	while(num2)
	{
		if(num2%2) 
			num3=num3^num1;
		num1=num1<<1;
		if(num1>=256)
			num1=num1^283;

		num2=num2>>1;
	}
	SetDlgItemText(IDC_R,change(num3));


}
CString GF::change(int num)
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
void GF::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,b;
	GetDlgItemText(IDC_A,a);
	GetDlgItemText(IDC_B,b);
	if(a.GetLength()>2 || b.GetLength()>2)
	{
		MessageBox("a或b不在GF(2^8)中！");
		return;
	}
	//a.MakeLower()
	//b.MakeLower();

	for(int i=0;i<a.GetLength();i++)
	{
		CString ch; 
		ch=a.GetAt(i);
		if(!((ch<="9" && ch>="0" )||(ch<="F"  && ch>= "A")))
		{
			MessageBox("请输入16进制数！");
			return;
		}
	}
	for(int i=0;i<a.GetLength();i++)
	{
		CString ch; 
		ch=a.GetAt(i);
		if(!((ch<="9" && ch>="0" )||(ch<="F"  && ch>= "A")))
		{
			MessageBox("请输入16进制数！");
			return;
		}
	}
	long int num1,num2,num3;
	num1=strtol(a,NULL,16);
	num2=strtol(b,NULL,16);
	num3=0;
	CString play=NULL;
	CString p1,p2,p3,aa,bb;
	aa="="+a+"·( ";
	int i=1;
	p1=change(i);

	//if(num2%2)
	//	aa=aa+"01";
	int j=0;
	while(num2)
	{

		if(num2%2) 
		{
			j++;
			num3=num3^num1;
			if(num2)
			{
				if(j==1)
					aa=aa+p1;
				else
					aa=aa+" xor "+p1;
			}
			bb=bb+change(num1);
			if(num2>1)
				bb=bb+" xor ";
		}
		i=i*2;
		p1=change(i);
		p2=change(num1);

		num1=num1<<1;
		if(num1>=256)
		{
			num1=num1^283;
		}
		p3=change(num1);
		if(num2>1)
			play=play+a+" · "+p1+" = xtime( "+p2+" )="+p3+"\r\n";
		num2=num2>>1;


	}
	aa=aa+" )\r\n";
	play=play+"\r\n"+a+"·"+b+aa+"        ="+bb+"\r\n        ="+change(num3);

	SetDlgItemText(IDC_SHOW,play);



}

void GF::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_A,"");
	SetDlgItemText(IDC_B,"");
	SetDlgItemText(IDC_R,"");
	SetDlgItemText(IDC_SHOW,"");
}
BOOL GF::OnEraseBkgnd(CDC* pDC)   
{  
  // TODO: Add your message handler code here and/or call default  
  CRect rcClient;  
  GetClientRect(rcClient);  
  pDC->FillRect(rcClient, &m_BkBrush);  
  return TRUE;  
  
  //return CDialog::OnEraseBkgnd(pDC);  
}  
  

HBRUSH GF::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   
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
