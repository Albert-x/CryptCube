#include "stdafx.h"
#include "BlockIDEA.h"
#define BUFSIZE 256

void  IDEA::string_for_4(char c[],int num,unsigned short d1[])//将明文转分组 转换成 4组 16进制的
{
	int i=0,j=0;
	int b[8]={0};//用来储存一个字符转换成二进制的数值
	int b1[4][16];
	if(num>=8)
	{
		for(j=0;j<8;j=j+2) //将每一个明文字母转换为二进制数 
		{ 
			chang1(c[j+1],b); 
			for(i=0;i<8;i++) 
				b1[j/2][i]=b[i]; 
			chang1(c[j],b); 
			for(i=0;i<8;i++) 
				b1[j/2][8+i]=b[i]; 
		} 
		for(i=0;i<4;i++) 
			d1[i]=(unsigned short)chang2(b1[i],d1[i]); //将 16 位的二进制数转换为十进制 数 
	}
	else
	{
		int num1=0;
		for(num1=0;num1+num<8;num1++)
		{
			c[num+num1]='0';
		}
		for(j=0;j<8;j=j+2) //将每一个明文字母转换为二进制数 
		{ 
			chang1(c[j+1],b); 
			for(i=0;i<8;i++) 
				b1[j/2][i]=b[i]; 
			chang1(c[j],b); 
			for(i=0;i<8;i++) 
				b1[j/2][8+i]=b[i]; 
		} 
		for(i=0;i<4;i++) 
			d1[i]=(unsigned short)chang2(b1[i],d1[i]); //将 16 位的二进制数转换为十进制 数 
	}
}


void IDEA::Result_For_Two(char x[][8],char y[][8],unsigned short d1[])//将结果转换成2进制
{
	int g[16]={0}; 
	int i=0,j=0;
	for(j=0;j<4;j++) 
	{
		chang3(d1[j],g); 
		for(i=0;i<8;i++) 
		{
			if(g[i+8]==0)
				x[j][7-i]='0';
			if(g[i+8]==1)
				x[j][7-i]='1';
		}
		for(i=0;i<8;i++)
		{
			if(g[i]==0)
				y[j][7-i]='0';
			if(g[i]==1)
				y[j][7-i]='1';
		}
	}
}

void IDEA::Result_For_16(unsigned short d1[],char a[])//将结果转换成16进制
{
	char c[5];
	int i=0,j=0;
	for(i=0;i<4;i++)
	{
		chang5(d1[i],c);
		for( j=i*4;j<4*(i+1);j++)
		{
			if(c[j%4]==' ')
			{
				c[j%4]='0';
			}
			a[j]=c[j%4];
		}
	}
}
void IDEA::S16_For_10(unsigned short d1[],char a[])
{
	int i=0,j=4;
	char a1[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a1[j]=a[i*4+j];
		}
		chang6(d1[i],a1);//将十六进制数转换成十进制的数
	}
}
void IDEA::S10_For_String(char x[][8],char y[][8],char M[] )//将十进制变成字符
{
	int a1[4],a2[4];
	int i=0,j=0;
	int a3[8],a4[8];
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			a3[j]=x[i][j];
			a4[j]=y[i][j];
		}
		a1[i]=chang4(a3); //将一串二进制数转换成十进制数 
		a2[i]=chang4(a4); //将一串二进制数转换成十进制数 
	}
	for(i=0;i<8;)
	{
		M[i]=a1[i/2];
		M[i+1]=a2[i/2];
		i=i+2;
	}

}
word16 IDEA::inv(word16 x)
{
	word16 d0,d1;
	word16 q,y;
	if(x<=1)
		return x;                                              //1的乘法逆元是1，2(16)+1的乘法逆元是2(16)+1
	d1=(word16)(0x10001/x);                                    //利用大淤求一术中的dk求乘法逆元
	y=(word16)(0x10001%x);
	if(y==1)
		return low16(1-d1);
	d0=1;
	do{
		q=x/y;
		x=x%y;
		d0+=q*d1;
		if(x==1)
			return d0;
		q=y/x;
		y=y%x;
		d1+=q*d0;
	}while(y!=1);
	return low16(1-d1);
}

void IDEA::en_key_idea(word16 *userkey,word16 *Z)
{
	int i,j;
	/*shifts*/
	for(j=0;j<8;j++)
		Z[j]=*userkey++;
	for(i=0;j<KEYLEN;j++){
		i++;
		Z[i+7]=((Z[i&7]<<9)|(Z[(i+1)&7]>>7));
		Z+=i&8;
		i&=7;
	}
}

void IDEA::de_key_idea(word16 *Z,word16 *DK)
{
	int j;
	word16 t1,t2,t3;
	DK+=52;
	t1=inv(*Z++);
	t2=-*Z++;
	t3=-*Z++;
	*--DK=inv(*Z++);
	*--DK=t3;
	*--DK=t2;
	*--DK=t1;
	for(j=1;j<ROUNDS;j++){
		t1=*Z++;
		*--DK=*Z++;
		*--DK=t1;
		t1=inv(*Z++);
		t2=-*Z++;
		t3=-*Z++;
		*--DK=inv(*Z++);
		*--DK=t2;
		*--DK=t3;
		*--DK=t1;
	}
	t1=*Z++;
	*--DK=*Z++;
	*--DK=t1;
	t1=inv(*Z++);
	t2=-*Z++;
	t3=-*Z++;
	*--DK=inv(*Z++);
	*--DK=t3;
	*--DK=t2;
	*--DK=t1;
}

word16 IDEA::mul(word16 a,word16 b)
{
	word32 p;
	if(a){
		if(b){
			p=(word32)a*b;
			b=(word16)(low16(p));                                     //低16位
			a=(word16)(p>>16);                                        //高16位
			return b-a+(b<a);
		}
		else
			return 1-a;
	}
	else
		return 1-b;
}

#define MUL(x,y) (x=mul(x,y))

void IDEA::cipher_idea(word16 in[4],word16 out[4],IDEAkey Z,word16 Inter[][4],word16 Last[])
{
	word16 x1,x2,x3,x4,s2,s3,r=ROUNDS;
	x1=*in++;
	x2=*in++;
	x3=*in++;
	x4=*in;
	Inter[0][0]=x1;
	Inter[0][1]=x2;
	Inter[0][2]=x3;
	Inter[0][3]=x4;
	int i=1;
	do{			//8轮变换
			///////////////////////////////////////////
			usLunX[i-1][0]=x1;
			usLunX[i-1][1]=x2;
			usLunX[i-1][2]=x3;
			usLunX[i-1][3]=x4;
			///////////////////////////////////////////

			///////////////////////////////////////////
			usLunZ[i-1][0]=*Z;
			///////////////////////////////////////////

		MUL(x1,*Z++);

			///////////////////////////////////////////
			usLunZ[i-1][1]=*Z;
			///////////////////////////////////////////

		x2+=*Z++;

			///////////////////////////////////////////
			usLunZ[i-1][2]=*Z;
			///////////////////////////////////////////

		x3+=*Z++;

			///////////////////////////////////////////
			usLunZ[i-1][3]=*Z;
			///////////////////////////////////////////

		MUL(x4,*Z++);
		s3=x3;
		x3^=x1;

			///////////////////////////////////////////
			usLunZ[i-1][4]=*Z;
			///////////////////////////////////////////

		MUL(x3,*Z++);
		s2=x2;
		x2^=x4;
		x2+=x3;

			///////////////////////////////////////////
			usLunZ[i-1][5]=*Z;
			///////////////////////////////////////////

		MUL(x2,*Z++);
		x3+=x2;
		x1^=x2;
		x4^=x3;
		x2^=s3;
		x3^=s2;
		Inter[i][0]=x1;
		Inter[i][1]=x2;
		Inter[i][2]=x3;
		Inter[i][3]=x4;

			///////////////////////////////////////////
			usLunW[i-1][0]=x1;
			usLunW[i-1][1]=x2;
			usLunW[i-1][2]=x3;
			usLunW[i-1][3]=x4;
			///////////////////////////////////////////

		i++;
	}while(--r);

			///////////////////////////////////////////
			usZuihouW[0]=x1;
			usZuihouW[1]=x2;
			usZuihouW[2]=x3;
			usZuihouW[3]=x4;
			///////////////////////////////////////////

			///////////////////////////////////////////
			usZuihouZ[0]=*Z;
			///////////////////////////////////////////

	MUL(x1,*Z++);   	
	Last[0]=x1;                                        //输出变换
	*out++=x1;
			///////////////////////////////////////////
			usZuihouZ[1]=*Z;
			///////////////////////////////////////////
	*out++=(x3+*Z++);
	Z--;
	Last[1]=x3+*Z++;

			///////////////////////////////////////////
			usZuihouZ[2]=*Z;
			///////////////////////////////////////////
	*out++=(x2+*Z++);
		Z--;

	Last[2]=x2+*Z++;
			///////////////////////////////////////////
			usZuihouZ[3]=*Z;
			///////////////////////////////////////////
	MUL(x4,*Z);
	Last[3]=x4;

			///////////////////////////////////////////
			usZuihouY[0]=Last[0];
			usZuihouY[1]=Last[1];
			usZuihouY[2]=Last[2];
			usZuihouY[3]=Last[3];
			///////////////////////////////////////////
	*out=x4;
}





void IDEA::chang1(char c,int b[8]) //将一个字母转换成二进制数 
{ 
	int i=0; 
	int d=c; 
	while(d!=0) 
	{ 
		b[i++]=d%2; 
		d=d/2; 
	} 
} 
long IDEA::chang2(int d[],long n) //将一串 16 位的二进制数转换成一个十进制数 
{ 
	int i; 
	for(i=0;i<16;i++) 
		n=n+d[i]*(int)pow(2.0,i); 
	return n; 
} 
void IDEA::chang3(long x,int d[]) //将一个十进制数装换成二进制数 
{
	int i=0; 
	while(x!=0) 
	{ 
		d[i++]=x%2; 
		x=x/2; 
	} 
} 
int IDEA::chang4(int d[]) //将一串二进制数转换成十进制数 
{ 
	int i,n=0; 
	for(i=0;i<8;i++) 
		n=n+d[i]*(int)pow(2.0,i); 
	return n; 
} 
void IDEA::chang5(int d,char a[])//将十进制数转换成十六进制的数
{

	//sprintf(a, "%4X", d);
	sprintf_s(a,5, "%4X", d);


}
void IDEA::chang6(int d,char a[])//将十六进制数转换成十进制的数
{
	int b=0;
	for(int i=0;i<4;i++)
	{	
		if(a[i]=='0')
			b=0;
		if(a[i]=='1')
			b=(int)pow(16.0,4-i);
		if(a[i]=='2')
			b=(int)pow(16.0,4-i)*2;
		if(a[i]=='3')
			b=(int)pow(16.0,4-i)*3;
		if(a[i]=='4')
			b=(int)pow(16.0,4-i)*4;
		if(a[i]=='5')
			b=(int)pow(16.0,4-i)*5;
		if(a[i]=='6')
			b=(int)pow(16.0,4-i)*6;
		if(a[i]=='7')
			b=(int)pow(16.0,4-i)*7;
		if(a[i]=='8')
			b=(int)pow(16.0,4-i)*8;
		if(a[i]=='9')
			b=(int)pow(16.0,4-i)*92;
		if(a[i]=='A'||a[i]=='A')
			b=(int)pow(16.0,4-i)*10;
		if(a[i]=='B'||a[i]=='b')
			b=(int)pow(16.0,4-i)*11;
		if(a[i]=='C'||a[i]=='c')
			b=(int)pow(16.0,4-i)*12;
		if(a[i]=='D'||a[i]=='d')
			b=(int)pow(16.0,4-i)*13;
		if(a[i]=='E'||a[i]=='e')
			b=(int)pow(16.0,4-i)*14;
		if(a[i]=='F'||a[i]=='f')
			b=(int)pow(16.0,4-i)*15;
		d=d+b;
	}

}
void IDEA::chang7(int d[][16],unsigned short a[])//将二进制数转换成十六进制的数
{
	int i=0,j=0;
	for(j=0;j<4;j++)
	{
		for(i=0;i<16;i++)
		{
			

		}
	}
}


BOOL IDEA::WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)//宽字符转换短字符
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,NULL,0,NULL,FALSE);
	if(dwSize < dwMinSize)
	{
		return FALSE;
	}
	WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,lpszStr,dwSize,NULL,FALSE);
	return TRUE;
}
BOOL IDEA::MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)//短字符转换宽字符
{
	// Get the required size of the buffer that receives the Unicode 
	// string. 
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, NULL, 0);

	if(dwSize < dwMinSize)
	{
		return FALSE;
	}
	// Convert headers from ASCII to Unicode.
	MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);  
	return TRUE;
}

