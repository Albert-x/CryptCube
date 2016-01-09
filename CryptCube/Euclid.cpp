// Euclid.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "Euclid.h"
#include "PublicKeyECC.h"

// Euclid 对话框

IMPLEMENT_DYNAMIC(Euclid, CDialog)

Euclid::Euclid(CWnd* pParent /*=NULL*/)
: CDialog(Euclid::IDD, pParent)
{

}

Euclid::~Euclid()
{
}

void Euclid::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Euclid, CDialog)
	//ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()  
    ON_WM_CTLCOLOR() 
	ON_BN_CLICKED(IDC_BUTTON4, &Euclid::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &Euclid::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON10, &Euclid::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Euclid::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON2, &Euclid::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &Euclid::OnBnClickedButton12)
END_MESSAGE_MAP()




void Euclid::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_M,"");
	SetDlgItemText(IDC_N,"");
	SetDlgItemText(IDC_RESULT1,"");
	SetDlgItemText(IDC_PLAY1,"");
}

void Euclid::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int m,n,result;

	m=GetDlgItemInt(IDC_M);
	n=GetDlgItemInt(IDC_N);

	if ( n==0 && m==0 )
	{
		MessageBox("参数不能同时为0！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		
		return ;
	}
	if(n>9999||m>9999)
	{
		MessageBox("参数大于9999，请重新输入！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		return ;
	}
	if(n<0||m<0) 
	{
		MessageBox("参数不能为负数！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		return ;
	}

	else 
	{
		result=gcd(m,n);	
		SetDlgItemInt(IDC_RESULT1,result);
		return ;
	}
}
int Euclid::gcd(int a, int b)
{
	if(b>a)
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}
	if(0==b) return a;
	else return gcd(b,a%b);

}



void Euclid::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	int q,a1,a2,a3,b1,b2,b3,t1,t2,t3,m;

	b3=GetDlgItemInt(IDC_B);
	a3=m=GetDlgItemInt(IDC_MM);

	if ( a3==0  )
	{
		MessageBox("m值不能为0！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		
		return ;
	}

	if(a3>9999||b3>9999)
	{
		MessageBox("参数大于9999，请重新输入！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		

		return ;
	}

	if(a3<0||b3<0) 
	{
		MessageBox("参数不能为负数！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		

		return ;
	}

	if(b3>a3)
	{
		MessageBox("b必须小于m！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		
		return ;
	}
	else
	{
		a1=b2=1;
		a2=b1=0;
		CString result;

		while(1)
		{

			if(0==b3)
			{
				SetDlgItemText(IDC_RESULT2,"不存在。");
				return;		
			}
			if(1==b3) 
			{
				if(b2<0) b2+=m;
				result.Format(TEXT("%d"),b2);
				SetDlgItemText(IDC_RESULT2,result);
				return;
			}

			q=a3/b3;
			t1=a1-q*b1,t2=a2-q*b2,t3=a3-q*b3;
			a1=b1,a2=b2,a3=b3;
			b1=t1,b2=t2,b3=t3;
		}

	}


}

void Euclid::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_B,"");
	SetDlgItemText(IDC_MM,"");
	SetDlgItemText(IDC_RESULT2,"");
	SetDlgItemText(IDC_PLAY2,"");
}

void Euclid::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int a,b,c,r;

	a=GetDlgItemInt(IDC_M);
	b=GetDlgItemInt(IDC_N);

	if ( a==0 && b==0 )
	{
		MessageBox("参数不能同时为0！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		SetDlgItemText(IDC_PLAY1,"");

		return ;
	}
	if(a>9999||b>9999)
	{
		MessageBox("参数大于9999，请重新输入！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		SetDlgItemText(IDC_PLAY1,"");

		return ;
	}
	if(a<0||b<0) 
	{
		MessageBox("参数不能为负数！");
		SetDlgItemText(IDC_N, "");
		SetDlgItemText(IDC_M, "");
		SetDlgItemText(IDC_RESULT1,"");
		SetDlgItemText(IDC_PLAY1,"");

		return ;
	}
	else
	{
		if(b>a)
		{
			a=a+b;
			b=a-b;
			a=a-b;
		}
		if(b==0)
		{
			SetDlgItemInt(IDC_RESULT1,a);
			SetDlgItemText(IDC_PLAY1,"0可以被所有非零整数整除！");
			return ;
		}
		r=a%b;
		c=a/b;

		CString show,A,B,C,R;

		A.Format(TEXT("%d"),a);
		B.Format(TEXT("%d"),b);
		C.Format(TEXT("%d"),c);
		R.Format(TEXT("%d"),r);

		show=A+"="+C+"×"+B+"+"+R+"\t\t  gcd("+B+","+R+")\r\n";

		while(r)
		{
			a=b;
			b=r;
			r=a%b;
			c=a/b;

			A.Format(TEXT("%d"),a);
			B.Format(TEXT("%d"),b);
			C.Format(TEXT("%d"),c);
			R.Format(TEXT("%d"),r);

			show +=A+"="+C+"×"+B+"+"+R+"\t\t  gcd("+B+","+R+")\r\n";

		}
		SetDlgItemText(IDC_RESULT1,B);
		SetDlgItemText(IDC_PLAY1,show);
		return ;

	}
}

void Euclid::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	int q,a1,a2,a3,b1,b2,b3,t1,t2,t3,m,i,i1;

	b3=GetDlgItemInt(IDC_B);
	a3=m=GetDlgItemInt(IDC_MM);

	if ( a3==0 )
	{
		MessageBox("m值不能为0！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		SetDlgItemText(IDC_PLAY2,"");

		return ;
	}

	if(a3>9999||b3>9999)
	{
		MessageBox("参数大于9999，请重新输入！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		SetDlgItemText(IDC_PLAY2,"");

		return ;
	}

	if(a3<0||b3<0) 
	{
		MessageBox("参数不能为负数！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		SetDlgItemText(IDC_PLAY2,"");

		return ;
	}

	if(b3>a3)
	{
		MessageBox("b必须小于m！");
		SetDlgItemText(IDC_B, "");
		SetDlgItemText(IDC_MM, "");
		SetDlgItemText(IDC_RESULT2,"");
		SetDlgItemText(IDC_PLAY2,"");

		return ;
	}
	else
	{
		a1=b2=1;
		a2=b1=0;
		i=-1;
		i1=0;
		CString result;
		CString show,Q,A1,A2,A3,B1,B2,B3,I,I1;
		Q="--";
		I.Format(TEXT("%d"),i);
		I1.Format(TEXT("%d"),i1);
		A1.Format(TEXT("%d"),a1);
		A2.Format(TEXT("%d"),a2);
		A3.Format(TEXT("%d"),a3);
		B1.Format(TEXT("%d"),b1);
		B2.Format(TEXT("%d"),b2);
		B3.Format(TEXT("%d"),b3);
		
		show="i\tr\tq\tx\ty\t\r\n"+I+"\t"+A3+"\t"+Q+"\t"+A1+"\t"+A2+"\r\n"+I1+"\t"+B3+"\t"+Q+"\t"+B1+"\t"+B2+"\r\n";
		
		


		while(1)
		{

			if(0==b3)
			{
				SetDlgItemText(IDC_RESULT2,"不存在。");
				return;		
			}
			if(1==b3) 
			{
				if(b2<0)
				{
					b2=b2+m;
					result.Format(TEXT("%d"),b2);
					//show=show+"\r\n \r\n"+"B2为负数，将其转换为对应的正整数,所以乘法逆元为B2+m="+result;
				}
				result.Format(TEXT("%d"),b2);
				SetDlgItemText(IDC_RESULT2,result);
				SetDlgItemText(IDC_PLAY2,show);
				return;
			}

			q=a3/b3;
			t1=a1-q*b1,t2=a2-q*b2,t3=a3-q*b3;
			a1=b1,a2=b2,a3=b3;
			b1=t1,b2=t2,b3=t3;
			i1++;
			Q.Format(TEXT("%d"),q);
			//A1.Format(TEXT("%d"),a1);
			//A2.Format(TEXT("%d"),a2);
			//A3.Format(TEXT("%d"),a3);
			B1.Format(TEXT("%d"),b1);
			B2.Format(TEXT("%d"),b2);
			B3.Format(TEXT("%d"),b3);
			I1.Format(TEXT("%d"),i1);

			show+=I1+"\t"+B3+"\t"+Q+"\t"+B1+"\t"+B2+"\r\n";


		}

	}

}

/*void Euclid::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect   rc;   GetClientRect( &rc );
		CPaintDC dc(this);   
		dc.FillSolidRect(&rc, RGB(208,223,240));   
		dc.FillRect(rc, &m_BkBrush);
		CDialog::OnPaint();

	}
	

}*/

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Euclid::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
BOOL Euclid::OnEraseBkgnd(CDC* pDC)   
{  
  // TODO: Add your message handler code here and/or call default  
  CRect rcClient;  
  GetClientRect(rcClient);  
  pDC->FillRect(rcClient, &m_BkBrush);  
  return TRUE;  
  
  //return CDialog::OnEraseBkgnd(pDC);  
}  
  

HBRUSH Euclid::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   
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