// PublicKeyElGamalForm.cpp : 实现文件
//

#include "stdafx.h"
#include "PublicKeyElGamal.h"


/****************************************
int Mod(int x, int y , int m) ;
此函数运用模重复平方计算法快速计算幂取模 
需要将y转成2进制 ， 在此通过模2,除2,来求
y各个bit位上的值 
****************************************/

ElGamal::ElGamal()
{
	k=0;
}


int ElGamal::Mod(int x,int y,int m){//模平方的运算
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
这个函数是求逆元的，用的是扩展的欧几里得算法         
通过此算法得到的是    a_1*a+b_1*b=1 ; a_1就是
a mod b  的逆元 
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


