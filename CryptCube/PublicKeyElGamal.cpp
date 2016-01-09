// PublicKeyElGamalForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PublicKeyElGamal.h"


/****************************************
int Mod(int x, int y , int m) ;
�˺�������ģ�ظ�ƽ�����㷨���ټ�����ȡģ 
��Ҫ��yת��2���� �� �ڴ�ͨ��ģ2,��2,����
y����bitλ�ϵ�ֵ 
****************************************/

ElGamal::ElGamal()
{
	k=0;
}


int ElGamal::Mod(int x,int y,int m){//ģƽ��������
    int a,b;
    a=1;
    b=x;
    while( y ){
		if( y % 2 == 1 )
			a = a * b % m ;
		y /= 2 ;
		b = b * b % m ;
    }
    return a;
}

/**********************************************
int Inverse(int a , int b , int &x , int &y) ; 
�������������Ԫ�ģ��õ�����չ��ŷ������㷨         
ͨ�����㷨�õ�����    a_1*a+b_1*b=1 ; a_1����
a mod b  ����Ԫ 
***********************************************/ 
int ElGamal::Inverse(int a,int b,int &a_1,int &b_1)    
{
	int t,d;
	if (b==0) { a_1=1; b_1=0; return a; }
	d=Inverse(b,a%b,a_1,b_1);
	t=a_1;
	a_1=b_1;
	b_1=t-a/b*b_1;
	return d;
}

void ElGamal::Encry(int p,int a,int d,int m,int k)
{
   // y = Mod( a , d , p ) ;
    enk = Mod( d , k , p ) ;
    c1 = Mod( a , k , p ) ;
    c2 = enk * m % p ;
}

void ElGamal::Decry(int c1,int c2,int d,int p)
{

    dek = Mod ( c1 , d , p ) ;
    Inverse( dek , p ,a_1 , b_1 ) ;
    a_1 = ( a_1 + p ) % p ; 
    dek2 = a_1 ;
    m = c2 * dek2 % p ;
}


void ElGamal::initPrimeRoot()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}



void ElGamal::cal(int n)
{
    int t=n,i;
	c=0;
    for(i=0;p[i]*p[i]<=n;i++)
    {
        if(n%p[i]==0)
        {
            pr[c]=p[i];
            while(n%p[i]==0) n/=p[i];
            c++;
        }
    }
    if(n>1)
    {
        pr[c]=n;
        c++;
    }
}


int ElGamal::quick_mod(int a,int b,int m)
{
    int ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}


int ElGamal::isPrimeUInt( unsigned int m )
{
    if (m == 1)
        return 0;
    else if (m <= 0)
        return 0;
    else if (m == 2)
        return 1;
    else
    {
        for (unsigned int i = 2; i < m; i++)
        {
            if (m%i == 0)
                return 0;
        }
        return 1;
    }
}


