#pragma once

#define MAX_NUM		63001
#define MAX_PRIME	251

//! ·µ»Ø´úÂë
#define OK					100
#define ERROR_NOEACHPRIME	101
#define ERROR_NOPUBLICKEY	102
#define	ERROR_GENERROR		103

#define FILEPATHSIZE	255

typedef struct __Path
{
	char	SourceFilePath[FILEPATHSIZE];
	char	DestinationFilePath[FILEPATHSIZE];
} path, *ppath;

typedef struct __Key
{
	UINT	e;
	UINT	n;
}key, *pkey;

typedef struct __Param
{
	path paramPath;
	key paramKey;
}param, *pparam;

bool isPrime( unsigned int m, unsigned int n );
int gcd(unsigned int a, unsigned int b);
int	isPrimeUInt( unsigned int m );
int CreateD( unsigned int e, unsigned int mod, unsigned int *d);
int EncryptUInt(UINT n, UINT e, UINT m, UINT *c);
int DecryptUInt(UINT n, UINT d, UINT c, UINT *m);


unsigned int MakePrivatedKeyd( unsigned int uiP, unsigned int uiQ );
unsigned int GetPrivateKeyd( unsigned int iWhich );
unsigned int MakePairkey( unsigned int uiP, unsigned int uiQ, unsigned int uiD );
unsigned int GetPairKey( unsigned int &d, unsigned int &e );
void rsa_encrypt( UINT n, UINT e, char *mw, int iLength, UINT *&cw );
void rsa_decrypt( UINT n, UINT d, UINT *&cw, UINT cLength, char *mw );
