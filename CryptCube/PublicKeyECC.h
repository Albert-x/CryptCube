#pragma once

#define inf 1000000

struct point{long x;long y;};

enum  {ENCRYPT1,DECRYPT1};

class ECC
{
public:
	long invmod(long a,long b);
	point add(point p1,point p2,long a,long b,long p);
	point subtract(point p1,point p2,long a,long b,long p);
	point multipy(point p,long m,long a,long b,long n);
	int testprime(long n);
	long powmod(long a, long b, long m);
	long SquareRoot(long x,long p);
	long modNUm(long b3,long a3);
};
