#include "stdafx.h"
#include "PublicKeyRSA.h"
#include <complex>

#define SWAP(a, b, temp) { \
				temp = a;	a = b;	b = temp; }

#define BUFSIZE 256*256

//!������˽Կd����
struct pKeyset
{
	unsigned int set[ MAX_NUM ];
	unsigned int size;
}pset;

//! ���湫��˽Կ��
struct pPairkey
{
	unsigned int d;
	unsigned int e;
	unsigned int n;
}pairkey;





/******************************************************************************/
//	���ƣ�isPrime
//	���ܣ��ж��������Ƿ���
//  ������m: ��a; n: ��b
//	���أ�m��n���ʷ���true; ���򷵻�false

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
		//���iΪ������Լ��������false
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
//	���ƣ�MakePrivatedKeyd
//	���ܣ�������Q��Q����˽Կd
//  ������uiP: ����P; uiQ: ����Q
//	���أ�˽Կd

/******************************************************************************/
unsigned int MakePrivatedKeyd( unsigned int uiP, unsigned int uiQ )
{
	unsigned int i=0;

	//! �õ�������z���ʵ���( ˽Կd�ļ��� )
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
//	���ƣ�MakePairKey
//	���ܣ�����RSA����˽Կ��
//  ������uiP: ����P; uiQ: ����Q; uiD: ˽Կd
//	���أ��������

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
//	���ƣ�GetPairKey
//	���ܣ������ṩ�ӿڣ���ù���˽Կ��
//  ������uiP: ����P; uiQ: ����Q; uiD: ˽Կd
//	���أ�

/******************************************************************************/
unsigned int GetPairKey( unsigned int &d, unsigned int &e )
{
	d = pairkey.d;
	e = pairkey.e;
	
	return pairkey.n;
}

/******************************************************************************/
//	���ƣ�GetPrivateKeyd
//	���ܣ������ṩ�ӿڣ����û�ѡ��ID����˽Կd
//  ������iWhich: �û�ѡ��˽Կd��ID
//	���أ�˽Կdֵ

/******************************************************************************/
unsigned int GetPrivateKeyd( unsigned int iWhich )
{
	if( pset.size >= iWhich )
		return pset.set[ iWhich ];
	else
		return 0;
}

/******************************************************************************/
//	���ƣ�rsa_encrypt
//	���ܣ�RSA��������
//  ������n: ��Կn; e: ��Կe; mw: ��������; iLength: ���ĳ���; cw: �������
//	���أ���

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
//	���ƣ�rsa_decrypt
//	���ܣ�RSA��������
//  ������n: ˽Կn; d: ˽Կd; cw: ����; cLength: ���ĳ���; mw: �������
//	���أ���

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
//	���ƣ�isPrimeUInt
//	���ܣ��ж�m�Ƿ�������
//  ������m ���жϵ���
//	���أ�1��m������
//			0��m��������

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
//	���ƣ�CreateD
//	���ܣ����� e*d = 1 mod(mod)�����d 
//  ������input��e mod
//			output��d
//	���أ�1��Create d success
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
//	���ƣ�EncryptUInt
//	���ܣ�����һ��unsigned int
//  ������input��n, e  public key
//			m  ����
//			output��c	����
//	���أ�1��success
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
//	���ƣ�DecryptUInt
//	���ܣ�����һ��unsigned int
//  ������input��n, d  ˽Կ
//			c  ����
//			output��m	����
//	���أ�1��success
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
