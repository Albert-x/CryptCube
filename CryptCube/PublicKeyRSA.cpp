#include "stdafx.h"
#include "PublicKeyRSA.h"
#include <complex>

#define SWAP(a, b, temp) { \
				temp = a;	a = b;	b = temp; }

#define BUFSIZE 256*256

//!　保存私钥d集合
struct pKeyset
{
	unsigned int set[ MAX_NUM ];
	unsigned int size;
}pset;

//! 保存公、私钥对
struct pPairkey
{
	unsigned int d;
	unsigned int e;
	unsigned int n;
}pairkey;





/******************************************************************************/
//	名称：isPrime
//	功能：判断两个数是否互质
//  参数：m: 数a; n: 数b
//	返回：m、n互质返回true; 否则返回false

/******************************************************************************/
bool isPrime( unsigned int m, unsigned int n )
{
	unsigned int i=0;

	if( m<2 || n<2 )
		return false;

	unsigned int tem = ( m > n ) ? n : m;
	for( i=2; i<=tem ; i++ )
	{
		bool mFlag = true;
		bool nFlag = true;
		if( m % i == 0 )
			mFlag = false;
		if( n % i == 0 )
			nFlag = false;
		//如果i为两数公约数，返回false
		if( !mFlag && !nFlag )		
			return false;
	}
	return true;
}


int gcd(unsigned int a, unsigned int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs((int)(a - b)), min(a, b));
}

/******************************************************************************/
//	名称：MakePrivatedKeyd
//	功能：由素数Q、Q生成私钥d
//  参数：uiP: 素数P; uiQ: 素数Q
//	返回：私钥d

/******************************************************************************/
unsigned int MakePrivatedKeyd( unsigned int uiP, unsigned int uiQ )
{
	unsigned int i=0;

	//! 得到所有与z互质的数( 私钥d的集合 )
	unsigned int z = ( uiP -1 ) * ( uiQ -1 );
	pset.size = 0;
	for( i=0; i<z; i++ )
	{
		if( isPrime( i, z ) )
		{
			pset.set[ pset.size++ ] = i;
		}
	}

	return pset.size;
}

/******************************************************************************/
//	名称：MakePairKey
//	功能：生成RSA公、私钥对
//  参数：uiP: 素数P; uiQ: 素数Q; uiD: 私钥d
//	返回：错误代码

/******************************************************************************/
unsigned int MakePairkey( unsigned int uiP, unsigned int uiQ, unsigned int uiD )
{
	bool bFlag = true;
	unsigned int i = 0, e;
	unsigned int z = ( uiP-1 ) * ( uiQ-1 );
	unsigned int d = pset.set[uiD];

	if( !isPrime( z, d ) )
		return ERROR_NOEACHPRIME;

	for( i=2; i<z; i++ )
	{
		if( (i*d)%z == 1 )
		{
			e = i;
			bFlag = false;
		}
	}
	if( bFlag )
		return ERROR_NOPUBLICKEY;

	if( (d*e)%z != 1 )
		ERROR_GENERROR;

	pairkey.d = d;
	pairkey.e = e;
	pairkey.n = uiP * uiQ;

	return OK;
}

/******************************************************************************/
//	名称：GetPairKey
//	功能：对外提供接口，获得公、私钥对
//  参数：uiP: 素数P; uiQ: 素数Q; uiD: 私钥d
//	返回：

/******************************************************************************/
unsigned int GetPairKey( unsigned int &d, unsigned int &e )
{
	d = pairkey.d;
	e = pairkey.e;
	
	return pairkey.n;
}

/******************************************************************************/
//	名称：GetPrivateKeyd
//	功能：对外提供接口，由用户选择ID得以私钥d
//  参数：iWhich: 用户选择私钥d的ID
//	返回：私钥d值

/******************************************************************************/
unsigned int GetPrivateKeyd( unsigned int iWhich )
{
	if( pset.size >= iWhich )
		return pset.set[ iWhich ];
	else
		return 0;
}

/******************************************************************************/
//	名称：rsa_encrypt
//	功能：RSA加密运算
//  参数：n: 公钥n; e: 公钥e; mw: 加密明文; iLength: 明文长度; cw: 密文输出
//	返回：无

/******************************************************************************/
void rsa_encrypt( UINT n, UINT e, char *mw, int mLength, UINT *&cw )
{	
	int i=0;
	UINT j=0;
	long temInt = 0;

	for( i=0; i<mLength; i++ )
	{
		temInt = mw[i];
		if( e!=0 )
		{
			for( j=1; j<e; j++ )
			{
				temInt = ( temInt * mw[i] ) % n;
			}
		}
		else
		{
			temInt = 1;
		}

		cw[i] = (int)temInt;
	}
}

/******************************************************************************/
//	名称：rsa_decrypt
//	功能：RSA解密运算
//  参数：n: 私钥n; d: 私钥d; cw: 密文; cLength: 密文长度; mw: 明文输出
//	返回：无

/******************************************************************************/
void rsa_decrypt( UINT n, UINT d, UINT *&cw, UINT cLength, char *mw )
{
	UINT i=0, j=0;
	long temInt = 0;

	for( i=0; i<cLength/4; ++i )
	{
		mw[i] = 0;
		temInt = cw[i];

		if( d != 0 )
		{
			for( j=1; j<d; j++ )
			{
				temInt = (long)( temInt * cw[i] ) % n;
			}
		}
		else
		{
			temInt = 1;
		}

		mw[i] = (char)temInt;
	}
}

/******************************************************************************/
//	名称：isPrimeUInt
//	功能：判断m是否是素数
//  参数：m 待判断的数
//	返回：1：m是素数
//			0：m不是素数

/******************************************************************************/
int isPrimeUInt( unsigned int m )
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

/******************************************************************************/
//	名称：CreateD
//	功能：根据 e*d = 1 mod(mod)计算出d 
//  参数：input：e mod
//			output：d
//	返回：1：Create d success
//			other: exception 

/******************************************************************************/
int CreateD( unsigned int e, unsigned int mod, unsigned int *d )
{
	unsigned int i = 0;
	if(!isPrime(mod, e))
	{
		return 0;
	}
	
	for(i =2; i< mod; i++)
	{
		if ((e * i) % mod == 1)
		{
			*d = i;
			return 1;
		}
	}
	return 0;
}


/******************************************************************************/
//	名称：EncryptUInt
//	功能：加密一个unsigned int
//  参数：input：n, e  public key
//			m  明文
//			output：c	密文
//	返回：1：success
//			other: exception 

/******************************************************************************/
int EncryptUInt( UINT n, UINT e, UINT m, UINT *c )
{
	UINT i = 0;
	long temInt = m;
	if ( n == 0 || e == 0 )
	{
		return 0;
	}
	for( i=1; i<e; i++ )
	{
		temInt = ( temInt * m ) % n;
	}
	*c = (UINT)temInt;
	return 1;
}

/******************************************************************************/
//	名称：DecryptUInt
//	功能：解密一个unsigned int
//  参数：input：n, d  私钥
//			c  密文
//			output：m	明文
//	返回：1：success
//			other: exception 

/******************************************************************************/
int DecryptUInt( UINT n, UINT d, UINT c, UINT *m )
{
	UINT i = 0;
	long temInt = c;
	if ( n == 0 || d == 0 )
	{
		return 0;
	}
	for( i=1; i<d; i++ )
	{
		temInt = (long)( temInt * c ) % n;
	}
	*m = (UINT)temInt;
	return 1;
}
