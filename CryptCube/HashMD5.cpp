// MD5Checksum.cpp: implementation of the MD5Checksum class.
//
//////////////////////////////////////////////////////////////////////



#include "stdafx.h"
#include "HashMD5.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
ULONG m[16]; //***************************************************//
ULONG n[4][16]; //***************************************************//
ULONG aa[4];//***************************************************//
#define new DEBUG_NEW
#endif
/*****************************************************************************************
FUNCTION:		MD5::GetMD5
DETAILS:		static, public
DESCRIPTION:	Gets the MD5 checksum for a specified file
RETURNS:		CString : the hexadecimal MD5 checksum for the specified file
ARGUMENTS:		CString& strFilePath : the full pathname of the specified file
NOTES:			Provides an interface to the MD5 class. 'strFilePath' name should 
				hold the full pathname of the file, eg C:\My Documents\Arcticle.txt.
				NB. If any problems occur with opening or reading this file, a CFileException
				will be thrown; callers of this function should be ready to catch this 
				exception.
*****************************************************************************************/
CString MD5::GetMD5(const CString& strFilePath)
{
	//open the file as a binary file in readonly mode, denying write access 
	CFile File(strFilePath, CFile::modeRead | CFile::shareDenyWrite | CFile::typeBinary);

	//the file has been successfully opened, so now get and return its checksum
	return GetMD5(File);
}


/*****************************************************************************************
FUNCTION:		MD5::GetMD5
DETAILS:		static, public
DESCRIPTION:	Gets the MD5 checksum for a specified file
RETURNS:		CString : the hexadecimal MD5 checksum for the specified file
ARGUMENTS:		CFile& File : the specified file
NOTES:			Provides an interface to the MD5 class. 'File' should be open in 
				binary readonly mode before calling this function. 
				NB. Callers of this function should be ready to catch any CFileException
				thrown by the CFile functions
*****************************************************************************************/
CString MD5::GetMD5(CFile& File)
{
	try
	{
		MD5 MD5Checksum;		//checksum object	
		int nLength = 0;				//number of bytes read from the file
		const int nBufferSize = 1024;	//checksum the file in blocks of 1024 bytes
		BYTE Buffer[nBufferSize];		//buffer for data read from the file

		//checksum the file in blocks of 1024 bytes
		while ((nLength = File.Read( Buffer, nBufferSize )) > 0 )
		{
			MD5Checksum.Update( Buffer, nLength );
		}

		//finalise the checksum and return it
		return MD5Checksum.Final();
	}

	//report any file exceptions in debug mode only
	catch (CFileException* e )
	{
		TRACE0("MD5::GetMD5: CFileException caught");	
		throw e;
	}
}


/*****************************************************************************************
FUNCTION:		MD5::GetMD5
DETAILS:		static, public
DESCRIPTION:	Gets the MD5 checksum for data in a BYTE array
RETURNS:		CString : the hexadecimal MD5 checksum for the specified data
ARGUMENTS:		BYTE* pBuf  :	pointer to the BYTE array
				UINT nLength :	number of BYTEs of data to be checksumed
NOTES:			Provides an interface to the MD5 class. Any data that can
				be cast to a BYTE array of known length can be checksummed by this
				function. Typically, CString and char arrays will be checksumed, 
				although this function can be used to check the integrity of any BYTE array. 
				A buffer of zero length can be checksummed; all buffers of zero length 
				will return the same checksum. 
*****************************************************************************************/
CString MD5::GetMD5(BYTE* pBuf, UINT nLength)
{
	//entry invariants
	AfxIsValidAddress(pBuf,nLength,FALSE);
	//calculate and return the checksum
	MD5 MD5Checksum;
	MD5Checksum.Update( pBuf, nLength );
	return MD5Checksum.Final();
}


/*****************************************************************************************
FUNCTION:		MD5::RotateLeft
DETAILS:		private
DESCRIPTION:	Rotates the bits in a 32 bit DWORD left by a specified amount
RETURNS:		The rotated DWORD 
ARGUMENTS:		DWORD x : the value to be rotated
				int n   : the number of bits to rotate by
*****************************************************************************************/
DWORD MD5::RotateLeft(DWORD x, int n)
{
	//check that DWORD is 4 bytes long - true in Visual C++ 6 and 32 bit Windows
	ASSERT( sizeof(x) == 4 );

	//rotate and return x
	return (x << n) | (x >> (32-n));
}


/*****************************************************************************************
FUNCTION:		MD5::FF
DETAILS:		protected
DESCRIPTION:	Implementation of basic MD5 transformation algorithm
RETURNS:		none
ARGUMENTS:		DWORD &A, B, C, D : Current (partial) checksum
				DWORD X           : Input data
				DWORD S			  : MD5_SXX Transformation constant
				DWORD T			  :	MD5_TXX Transformation constant
NOTES:			None
*****************************************************************************************/
void MD5::FF( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD F = (B & C) | (~B & D);
	A += F + X + T;
	A = RotateLeft(A, S);
	A += B;
}


/*****************************************************************************************
FUNCTION:		MD5::GG
DETAILS:		protected
DESCRIPTION:	Implementation of basic MD5 transformation algorithm
RETURNS:		none
ARGUMENTS:		DWORD &A, B, C, D : Current (partial) checksum
				DWORD X           : Input data
				DWORD S			  : MD5_SXX Transformation constant
				DWORD T			  :	MD5_TXX Transformation constant
NOTES:			None
*****************************************************************************************/
void MD5::GG( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD G = (B & D) | (C & ~D);
	A += G + X + T;
	A = RotateLeft(A, S);
	A += B;
}


/*****************************************************************************************
FUNCTION:		MD5::HH
DETAILS:		protected
DESCRIPTION:	Implementation of basic MD5 transformation algorithm
RETURNS:		none
ARGUMENTS:		DWORD &A, B, C, D : Current (partial) checksum
				DWORD X           : Input data
				DWORD S			  : MD5_SXX Transformation constant
				DWORD T			  :	MD5_TXX Transformation constant
NOTES:			None
*****************************************************************************************/
void MD5::HH( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD H = (B ^ C ^ D);
	A += H + X + T;
	A = RotateLeft(A, S);
	A += B;
}


/*****************************************************************************************
FUNCTION:		MD5::II
DETAILS:		protected
DESCRIPTION:	Implementation of basic MD5 transformation algorithm
RETURNS:		none
ARGUMENTS:		DWORD &A, B, C, D : Current (partial) checksum
				DWORD X           : Input data
				DWORD S			  : MD5_SXX Transformation constant
				DWORD T			  :	MD5_TXX Transformation constant
NOTES:			None
*****************************************************************************************/
void MD5::II( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD I = (C ^ (B | ~D));
	A += I + X + T;
	A = RotateLeft(A, S);
	A += B;
}


/*****************************************************************************************
FUNCTION:		MD5::ByteToDWord
DETAILS:		private
DESCRIPTION:	Transfers the data in an 8 bit array to a 32 bit array
RETURNS:		void
ARGUMENTS:		DWORD* Output : the 32 bit (unsigned long) destination array 
				BYTE* Input	  : the 8 bit (unsigned char) source array
				UINT nLength  : the number of 8 bit data items in the source array
NOTES:			Four BYTES from the input array are transferred to each DWORD entry
				of the output array. The first BYTE is transferred to the bits (0-7) 
				of the output DWORD, the second BYTE to bits 8-15 etc. 
				The algorithm assumes that the input array is a multiple of 4 bytes long
				so that there is a perfect fit into the array of 32 bit words.
*****************************************************************************************/
void MD5::ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength)
{
	//entry invariants
	ASSERT( nLength % 4 == 0 );
	ASSERT( AfxIsValidAddress(Output, nLength/4, TRUE) );
	ASSERT( AfxIsValidAddress(Input, nLength, FALSE) );

	//initialisations
	UINT i=0;	//index to Output array
	UINT j=0;	//index to Input array

	//transfer the data by shifting and copying
	for ( ; j < nLength; i++, j += 4)
	{
		Output[i] = (ULONG)Input[j]			| 
					(ULONG)Input[j+1] << 8	| 
					(ULONG)Input[j+2] << 16 | 
					(ULONG)Input[j+3] << 24;
	}
}

/*****************************************************************************************
FUNCTION:		MD5::Transform
DETAILS:		protected
DESCRIPTION:	MD5 basic transformation algorithm;  transforms 'm_lMD5'
RETURNS:		void
ARGUMENTS:		BYTE Block[64]
NOTES:			An MD5 checksum is calculated by four rounds of 'Transformation'.
				The MD5 checksum currently held in m_lMD5 is merged by the 
				transformation process with data passed in 'Block'.  
*****************************************************************************************/
void MD5::Transform(BYTE Block[64])
{
	//initialise local data with current checksum
	ULONG a = m_lMD5[0];
	ULONG b = m_lMD5[1];
	ULONG c = m_lMD5[2];
	ULONG d = m_lMD5[3];
	ULONG X[16];
	aa[0]=a;
	aa[1]=b;
	aa[2]=c;
	aa[3]=d;
	//copy BYTES from input 'Block' to an array of ULONGS 'X'
	ByteToDWord( X, Block, 64 );
for(int i=0;i<16;i++)                //**********************************
	m[i]=X[i];                         //**********************************
	//Perform Round 1 of the transformation
	FF (a, b, c, d, X[ 0], MD5_S11, MD5_T01); n[0][0]=a;
	FF (d, a, b, c, X[ 1], MD5_S12, MD5_T02); n[0][1]=d;
	FF (c, d, a, b, X[ 2], MD5_S13, MD5_T03); n[0][2]=c;
	FF (b, c, d, a, X[ 3], MD5_S14, MD5_T04); n[0][3]=b;//
	FF (a, b, c, d, X[ 4], MD5_S11, MD5_T05); n[0][4]=a;
	FF (d, a, b, c, X[ 5], MD5_S12, MD5_T06); n[0][5]=d;
	FF (c, d, a, b, X[ 6], MD5_S13, MD5_T07); n[0][6]=c;
	FF (b, c, d, a, X[ 7], MD5_S14, MD5_T08); n[0][7]=b;//
	FF (a, b, c, d, X[ 8], MD5_S11, MD5_T09); n[0][8]=a;
	FF (d, a, b, c, X[ 9], MD5_S12, MD5_T10); n[0][9]=d;
	FF (c, d, a, b, X[10], MD5_S13, MD5_T11); n[0][10]=c;
	FF (b, c, d, a, X[11], MD5_S14, MD5_T12); n[0][11]=b;//
	FF (a, b, c, d, X[12], MD5_S11, MD5_T13); n[0][12]=a;
	FF (d, a, b, c, X[13], MD5_S12, MD5_T14); n[0][13]=d;
	FF (c, d, a, b, X[14], MD5_S13, MD5_T15); n[0][14]=c;
	FF (b, c, d, a, X[15], MD5_S14, MD5_T16); n[0][15]=b;

	//Perform Round 2 of the transformation
	GG (a, b, c, d, X[ 1], MD5_S21, MD5_T17); n[1][0]=a;
	GG (d, a, b, c, X[ 6], MD5_S22, MD5_T18); n[1][1]=d;
	GG (c, d, a, b, X[11], MD5_S23, MD5_T19); n[1][2]=c;
	GG (b, c, d, a, X[ 0], MD5_S24, MD5_T20); n[1][3]=b;
	GG (a, b, c, d, X[ 5], MD5_S21, MD5_T21); n[1][4]=a;
	GG (d, a, b, c, X[10], MD5_S22, MD5_T22); n[1][5]=d;
	GG (c, d, a, b, X[15], MD5_S23, MD5_T23); n[1][6]=c;
	GG (b, c, d, a, X[ 4], MD5_S24, MD5_T24); n[1][7]=b;
	GG (a, b, c, d, X[ 9], MD5_S21, MD5_T25); n[1][8]=a;
	GG (d, a, b, c, X[14], MD5_S22, MD5_T26); n[1][9]=d;
	GG (c, d, a, b, X[ 3], MD5_S23, MD5_T27); n[1][10]=c;
	GG (b, c, d, a, X[ 8], MD5_S24, MD5_T28); n[1][11]=b;
	GG (a, b, c, d, X[13], MD5_S21, MD5_T29); n[1][12]=a;
	GG (d, a, b, c, X[ 2], MD5_S22, MD5_T30); n[1][13]=d;
	GG (c, d, a, b, X[ 7], MD5_S23, MD5_T31); n[1][14]=c;
	GG (b, c, d, a, X[12], MD5_S24, MD5_T32); n[1][15]=b;

	//Perform Round 3 of the transformation
	HH (a, b, c, d, X[ 5], MD5_S31, MD5_T33); n[2][0]=a;
	HH (d, a, b, c, X[ 8], MD5_S32, MD5_T34); n[2][1]=d;
	HH (c, d, a, b, X[11], MD5_S33, MD5_T35); n[2][2]=c;
	HH (b, c, d, a, X[14], MD5_S34, MD5_T36); n[2][3]=b;
	HH (a, b, c, d, X[ 1], MD5_S31, MD5_T37); n[2][4]=a;
	HH (d, a, b, c, X[ 4], MD5_S32, MD5_T38); n[2][5]=d;
	HH (c, d, a, b, X[ 7], MD5_S33, MD5_T39); n[2][6]=c;
	HH (b, c, d, a, X[10], MD5_S34, MD5_T40); n[2][7]=b;
	HH (a, b, c, d, X[13], MD5_S31, MD5_T41); n[2][8]=a;
	HH (d, a, b, c, X[ 0], MD5_S32, MD5_T42); n[2][9]=d;
	HH (c, d, a, b, X[ 3], MD5_S33, MD5_T43); n[2][10]=c;
	HH (b, c, d, a, X[ 6], MD5_S34, MD5_T44); n[2][11]=b;
	HH (a, b, c, d, X[ 9], MD5_S31, MD5_T45); n[2][12]=a;;
	HH (d, a, b, c, X[12], MD5_S32, MD5_T46); n[2][13]=d;
	HH (c, d, a, b, X[15], MD5_S33, MD5_T47); n[2][14]=c;
	HH (b, c, d, a, X[ 2], MD5_S34, MD5_T48); n[2][15]=b;

	//Perform Round 4 of the transformation
	II (a, b, c, d, X[ 0], MD5_S41, MD5_T49); n[3][0]=a;
	II (d, a, b, c, X[ 7], MD5_S42, MD5_T50); n[3][1]=d;
	II (c, d, a, b, X[14], MD5_S43, MD5_T51); n[3][2]=c;
	II (b, c, d, a, X[ 5], MD5_S44, MD5_T52); n[3][3]=b;
	II (a, b, c, d, X[12], MD5_S41, MD5_T53); n[3][4]=a;
	II (d, a, b, c, X[ 3], MD5_S42, MD5_T54); n[3][5]=d;
	II (c, d, a, b, X[10], MD5_S43, MD5_T55); n[3][6]=c;
	II (b, c, d, a, X[ 1], MD5_S44, MD5_T56); n[3][7]=b;
	II (a, b, c, d, X[ 8], MD5_S41, MD5_T57); n[3][8]=a;
	II (d, a, b, c, X[15], MD5_S42, MD5_T58); n[3][9]=d;
	II (c, d, a, b, X[ 6], MD5_S43, MD5_T59); n[3][10]=c;
	II (b, c, d, a, X[13], MD5_S44, MD5_T60); n[3][11]=b;
	II (a, b, c, d, X[ 4], MD5_S41, MD5_T61); n[3][12]=a;;
	II (d, a, b, c, X[11], MD5_S42, MD5_T62); n[3][13]=d;
	II (c, d, a, b, X[ 2], MD5_S43, MD5_T63); n[3][14]=c;
	II (b, c, d, a, X[ 9], MD5_S44, MD5_T64); n[3][15]=b;

	//add the transformed values to the current checksum
	m_lMD5[0] += a;
	m_lMD5[1] += b;
	m_lMD5[2] += c;
	m_lMD5[3] += d;
}


/*****************************************************************************************
CONSTRUCTOR:	MD5
DESCRIPTION:	Initialises member data
ARGUMENTS:		None
NOTES:			None
*****************************************************************************************/
MD5::MD5()
{
	// zero members
	memset( m_lpszBuffer, 0, 64 );
	m_nCount[0] = m_nCount[1] = 0;

	// Load magic state initialization constants
	m_lMD5[0] = MD5_INIT_STATE_0;
	m_lMD5[1] = MD5_INIT_STATE_1;
	m_lMD5[2] = MD5_INIT_STATE_2;
	m_lMD5[3] = MD5_INIT_STATE_3;
}

/*****************************************************************************************
FUNCTION:		MD5::DWordToByte
DETAILS:		private
DESCRIPTION:	Transfers the data in an 32 bit array to a 8 bit array
RETURNS:		void
ARGUMENTS:		BYTE* Output  : the 8 bit destination array 
				DWORD* Input  : the 32 bit source array
				UINT nLength  : the number of 8 bit data items in the source array
NOTES:			One DWORD from the input array is transferred into four BYTES 
				in the output array. The first (0-7) bits of the first DWORD are 
				transferred to the first output BYTE, bits bits 8-15 are transferred from
				the second BYTE etc. 
				
				The algorithm assumes that the output array is a multiple of 4 bytes long
				so that there is a perfect fit of 8 bit BYTES into the 32 bit DWORDs.
*****************************************************************************************/
void MD5::DWordToByte(BYTE* Output, DWORD* Input, UINT nLength )
{
	//entry invariants
	ASSERT( nLength % 4 == 0 );
	ASSERT( AfxIsValidAddress(Output, nLength, TRUE) );
	ASSERT( AfxIsValidAddress(Input, nLength/4, FALSE) );

	//transfer the data by shifting and copying
	UINT i = 0;
	UINT j = 0;
	for ( ; j < nLength; i++, j += 4) 
	{
		Output[j] =   (UCHAR)(Input[i] & 0xff);
		Output[j+1] = (UCHAR)((Input[i] >> 8) & 0xff);
		Output[j+2] = (UCHAR)((Input[i] >> 16) & 0xff);
		Output[j+3] = (UCHAR)((Input[i] >> 24) & 0xff);
	}
}


/*****************************************************************************************
FUNCTION:		MD5::Final最后一轮
DETAILS:		protected
DESCRIPTION:	Implementation of main MD5 checksum algorithm; ends the checksum calculation.
RETURNS:		CString : the final hexadecimal MD5 checksum result 
ARGUMENTS:		None
NOTES:			Performs the final MD5 checksum calculation ('Update' does most of the work,
				this function just finishes the calculation.) 
*****************************************************************************************/
CString MD5::Final()
{
	//Save number of bits
	BYTE Bits[8];
	DWordToByte( Bits, m_nCount, 8 );

	//Pad out to 56 mod 64.
	UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3f);
	UINT nPadLen = (nIndex < 56) ? (56 - nIndex) : (120 - nIndex);
	Update( PADDING, nPadLen );

	//Append length (before padding)
	Update( Bits, 8 );

	//Store final state in 'lpszMD5'
	const int nMD5Size = 16;
	unsigned char lpszMD5[ nMD5Size ];
	DWordToByte( lpszMD5, m_lMD5, nMD5Size );

	//Convert the hexadecimal checksum to a CString
	CString strMD5;
	for ( int i=0; i < nMD5Size; i++) 
	{
		CString Str;
		if (lpszMD5[i] == 0) {
			Str = CString(_T("00"));
		}
		else if (lpszMD5[i] <= 15) 	{
			Str.Format(_T("0%x"),lpszMD5[i]);
		}
		else {
			Str.Format(_T("%x"),lpszMD5[i]);
		}

		ASSERT( Str.GetLength() == 2 );
		strMD5 += Str;
	}
	ASSERT( strMD5.GetLength() == 32 );
	return strMD5;
}


/*****************************************************************************************
FUNCTION:		MD5::Update明文填充，明文分组
DETAILS:		protected
DESCRIPTION:	Implementation of main MD5 checksum algorithm
RETURNS:		void
ARGUMENTS:		BYTE* Input    : input block
				UINT nInputLen : length of input block
NOTES:			Computes the partial MD5 checksum for 'nInputLen' bytes of data in 'Input'
*****************************************************************************************/
void MD5::Update( BYTE* Input,	ULONG nInputLen )
{
	//Compute number of bytes mod 64
	UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3F);

	//Update number of bits
	if ( ( m_nCount[0] += nInputLen << 3 )  <  ( nInputLen << 3) )
	{
		m_nCount[1]++;
	}
	m_nCount[1] += (nInputLen >> 29);
	//Transform as many times as possible.
	UINT i=0;		
	UINT nPartLen = 64 - nIndex;
	if (nInputLen >= nPartLen) 	
	{
		memcpy( &m_lpszBuffer[nIndex], Input, nPartLen );
		//ByteToDWord( m,m_lpszBuffer, 64 );
		Transform( m_lpszBuffer );
		for (i = nPartLen; i + 63 < nInputLen; i += 64) 
		{
			Transform( &Input[i] );
		}
		nIndex = 0;
	} 
	else 
	{
			i = 0;
	}

	// Buffer remaining input
	memcpy( &m_lpszBuffer[nIndex], &Input[i], nInputLen-i);
}