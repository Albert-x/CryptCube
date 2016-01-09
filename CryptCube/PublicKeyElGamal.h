#pragma once


#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;


#define N 10000

class ElGamal
{
public:
	ElGamal();
	bool prime[N];
	int p[N];
	int pr[N];
	int k,c,y;
	int c1,c2,enk,dek,dek2,m,a_1,b_1;

	void initPrimeRoot();
	void cal(int n);
	int quick_mod(int a,int b,int m);
	int Mod(int x,int y,int m);
	int Inverse(int a,int b,int &a_1,int &b_1);
	void Encry(int p,int a,int d,int m,int k);
	void Decry(int c1,int c2,int d,int p);
	int	isPrimeUInt( unsigned int m );

};
