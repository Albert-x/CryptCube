#include "stdafx.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "PublicKeyECC.h"
#include <math.h>

#define random(min,max) (rand()%(max+1-min)+min)

long ECC::invmod(long a,long b)
{
	long s0=1,s1=0,s2,q,t,b0;
	b0=b;
	while(b)
	{
		q=a/b;
		s2=s0-q*s1;
		if(s2>=0)
			s2=s2%b0;
		else
			s2=b0-(-s2)%b0;
		s0=s1;
		s1=s2;
		t=b;
		b=a%b;
		a=t;	
	}
	if(1==a)
		return s0;
	else if(-1==a)
		return b0-s0;
	else 
		return 0;
}
point ECC::add(point p1,point p2,long a,long b,long p)
{
	point p3;
	long x1,x2,x3,y1,y2,y3,m;
	x1=p1.x;
	y1=p1.y;
	x2=p2.x;
	y2=p2.y;
	
	if( x1==x2 && y1==-y2 )
	{
		p3.x=inf;
		p3.y=inf;
		return p3;
	}
	if( p1.x==inf && p1.y==inf )
		return p2;
	if( p2.x==inf && p2.y==inf )
		return p1;
	if( x2!=x1)
		m=((y2-y1)*invmod(x2-x1,p))%p;
	else
		m=((3*x1*x1+a)%p*invmod(2*y1,p))%p;
	if(m<0)
		m=m+p;
	x3=(m*m-x1-x2)%p;
	y3=(m*(x1-x3)-y1)%p;
	if(x3<0)
		x3+=p;
	if(y3<0)
		y3+=p;
	p3.x=x3;
	p3.y=y3;
	return p3;
}


point ECC::subtract(point p1,point p2,long a,long b,long p)
{
	point p3;
	p2.y = -p2.y;
	p3=add(p1,p2,a,b,p);
	return p3;
}


point ECC::multipy(point p,long m,long a,long b,long n)
{
	point q;
	q.x=inf;
	q.y=inf;

	while(m)
	{
		if(m%2)
			q=add(q,p,a,b,n);
		p=add(p,p,a,b,n);
		m=m>>1;
	}
	return q;	
}


int ECC::testprime(long n)
{
	long i,j,s,t,a,y;

	srand((unsigned)time(NULL));


	if(n%2==0)	return 0;

	s=0;
	t=n-1;
	while(t%2==0)
	{
		t=t/2;
		s++;
	}
	for(i=0;i<10;i++)
	{
		a=random(2,n-2);
		y=powmod(a,t,n);

		if(y!=1&&y!=n-1)
		{
			j=1;
			while(j<s && y!=n-1)
			{
				y=(y*y)%n;
				if(1==y) return 0;

				j++;
			}
			if(y!=n-1) return 0;
		}
	}
	return 1;
}

long ECC::powmod(long a, long b, long m)
{
	long A=1;
	while(b!=0)
	{
		if(b%2) A=(A*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return A;
}

long ECC::SquareRoot(long x,long p)
{
	long s,t,y,x_inv,n,b;
	s=p-1;
	t=0;
	n=0;
	while(s%2==0)
	{
		s=s/2;
		t++;
	}
	while(powmod(n,(p-1)/2,p)==1)
		n++;
	b=powmod(n,s,p);
	y=powmod(x,(s+1)/2,p);
	x_inv=invmod(x,p);
	while(t-2>=0)
	{
		if(powmod(x_inv*y*y,(long)pow((long double)2,t-2),p)==p-1)
			y=y*(long)pow((long double)b,pow((long double)2,t-2));
		t--;
	}
	return y;
}
long ECC::modNUm(long b3,long a3)
{

	long q,a1,a2,b1,b2,t1,t2,t3,m;
	m=a3;
	a1=b2=1;
	a2=b1=0;
	long result;
	while(1)
	{
		if(0==b3)
		{
			//SetDlgItemText(IDC_RESULT2,"²»´æÔÚ¡£");
			return 0;		
		}
		if(1==b3) 
		{
			if(b2<0)
				b2+=m;
			result=b2;
			//cout<<result;
			return result;
		}
		q=a3/b3;
		t1=a1-q*b1,t2=a2-q*b2,t3=a3-q*b3;
		a1=b1,a2=b2,a3=b3;
		b1=t1,b2=t2,b3=t3;
	}
}			