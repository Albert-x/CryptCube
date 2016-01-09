// SHA1.cpp: implementation of the SHA1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HashSHA1.h"
#ifdef _DEBUG
#undef THIS_FILE
int Y=0;
unsigned int m[64];
ULONG M[16]; //***************************************************//
ULONG aa1[10];
ULONG a[10];
CString result;
ULONG A1[90];
ULONG A2[90];
ULONG B1[90];
ULONG B2[90];
ULONG C1[90];
ULONG C2[90];
ULONG D1[90];
ULONG D2[90];
ULONG E1[90];
ULONG E2[90];
ULONG W1[90];
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SHA1::SHA1()
{
	SHAInit();
}

SHA1::~SHA1()
{
}

void SHA1::SHAInit()
{
	Length_Low			= 0;
	Length_High			= 0;
	Message_Block_Index	= 0;

	H[0]		= 0x67452301;
	H[1]		= 0xEFCDAB89;
	H[2]		= 0x98BADCFE;
	H[3]		= 0x10325476;
	H[4]		= 0xC3D2E1F0;// 初始化算法的几个常量，魔术数  
	
}

// space of lpSHACode_Output must be >= 20 bytes;
bool SHA1::SHA_GO( const unsigned char *lpData_Input, unsigned char *lpSHACode_Output,unsigned int len )
{
	if (lpData_Input == NULL || lpSHACode_Output == NULL)
		return false;

	//SHAInit();

	// One times analyse 64Bytes, 512 bits.
	int nInputLen = len;
	int nDealDataLen = 0;							//	the length of can-deal-data, this times;
	for(int pos=0 ; pos<=nInputLen ; pos+=64)
	{
		if (nInputLen - pos >= 64)
		{
			nDealDataLen = 64;						// input-data is enough fill 64bytes,
			memset(Message_Block, 0, sizeof(Message_Block));
			memcpy(Message_Block, lpData_Input + pos, nDealDataLen);

			AddDataLen(nDealDataLen);
			ProcessMessageBlock();
			AddDataLen(0);
		}
		else
		{
			nDealDataLen = nInputLen - pos;			//	input-data isn't enough fill 64bytes,need fill 0x8000000000 and lenth of real-data.
			memset(Message_Block, 0, sizeof(Message_Block));
			memcpy(Message_Block, lpData_Input + pos, nDealDataLen);

			AddDataLen(nDealDataLen);
			PadMessage();
		}
		
	}


	return true;
}

void SHA1::AddDataLen(int nDealDataLen)//nDealDataLen是每一轮处理的字节数，基本上前面的都是64，有所不同的是最后一块未知长度
{
	Message_Block_Index = nDealDataLen;

	if ((Length_Low += ((unsigned int)nDealDataLen << 3)) < ((unsigned int)nDealDataLen << 3))//64字节是2^6，左移三位就是2^9=512位，超过2^32位时
	{                                                                                         //高位进位1位，低位重新计算
		Length_High++;//高位进一位
	}
	Length_High += ((unsigned int)nDealDataLen >> 29);
}


/*
 *	ProcessMessageBlock
 *
 *	Description:
 *		This function will process the next 512 bits of the message
 *		stored in the Message_Block array.
 *
 *	Parameters:
 *		None.
 *
 *	Returns:
 *		Nothing.
 *
 *	Comments:
 *		Many of the variable names in this function, especially the single
 *	 	character names, were used because those were the names used
 *	  	in the publication.
 *
 */
/*! 
     内部函数，对一个64bit内存块进行摘要(杂凑)处理， 
      hash  存放计算hash结果的的数组 
     block 要计算的处理得内存块 
 */  
void SHA1::ProcessMessageBlock()
{
	const unsigned K[] = 	{ 				// Constants defined for SHA-1
								0x5A827999,
								0x6ED9EBA1,
								0x8F1BBCDC,
								0xCA62C1D6
							};
	int 		t;							 
	unsigned 	temp;						
	unsigned	W[80];					// 分组
	unsigned	A, B, C, D, E;				//常量

	/*
	 *处理
	 */
	for(t = 0; t < 16; t++)
	{
		W[t] = ((unsigned) Message_Block[t * 4]) << 24;
		W[t] |= ((unsigned) Message_Block[t * 4 + 1]) << 16;
		W[t] |= ((unsigned) Message_Block[t * 4 + 2]) << 8;
		W[t] |= ((unsigned) Message_Block[t * 4 + 3]);
		W1[t]=W[t];
		M[t]=W[t];
	}

	for(t = 16; t < 80; t++)
	{
	   W[t] = CircularShift(1,W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
	   W1[t]=W[t];
	}

	A = H[0];
	B = H[1];
	C = H[2];
	D = H[3];
	E = H[4];

	for(t = 0; t < 20; t++)
	{
		A1[t]=A;
	    B1[t]=B;
	    C1[t]=C;
	    D1[t]=D;
	    E1[t]=E;
		temp = CircularShift(5,A) + ((B & C) | ((~B) & D)) + E + W[t] + K[0];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = CircularShift(30,B);
		B = A;
		A = temp;
		A2[t]=A;
		B2[t]=B;
		C2[t]=C;
		D2[t]=D;
		E2[t]=E;
		
	}

	for(t = 20; t < 40; t++)
	{
		A1[t]=A;
	    B1[t]=B;
	    C1[t]=C;
	    D1[t]=D;
	    E1[t]=E;
		temp = CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[1];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = CircularShift(30,B);
		B = A;
		A = temp;
		A2[t]=A;
		B2[t]=B;
		C2[t]=C;
		D2[t]=D;
		E2[t]=E;
	}

	for(t = 40; t < 60; t++)
	{
		A1[t]=A;
	    B1[t]=B;
	    C1[t]=C;
	    D1[t]=D;
	    E1[t]=E;
		temp = CircularShift(5,A) +
		 	   ((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = CircularShift(30,B);
		B = A;
		A = temp;
		A2[t]=A;
		B2[t]=B;
		C2[t]=C;
		D2[t]=D;
		E2[t]=E;
	}

	for(t = 60; t < 80; t++)
	{
		A1[t]=A;
	    B1[t]=B;
	    C1[t]=C;
	    D1[t]=D;
	    E1[t]=E;
		temp = CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[3];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = CircularShift(30,B);
		B = A;
		A = temp;
		A2[t]=A;
	    B2[t]=B;
	    C2[t]=C;
	    D2[t]=D;
	    E2[t]=E;
	}
	aa1[0]=A & 0xFFFFFFFF;
	aa1[1]=B & 0xFFFFFFFF;
	aa1[2]=C & 0xFFFFFFFF;
	aa1[3]=D & 0xFFFFFFFF;
	aa1[4]=E & 0xFFFFFFFF;
	H[0] = (H[0] + A) & 0xFFFFFFFF;
	H[1] = (H[1] + B) & 0xFFFFFFFF;
	H[2] = (H[2] + C) & 0xFFFFFFFF;
	H[3] = (H[3] + D) & 0xFFFFFFFF;
	H[4] = (H[4] + E) & 0xFFFFFFFF;
	a[5]=H[0];
	a[6]=H[1];
	a[7]=H[2];
	a[8]=H[3];
	a[9]=H[4];
	aa1[5]=H[0];
	aa1[6]=H[1];
	aa1[7]=H[2];
	aa1[8]=H[3];
	aa1[9]=H[4];

	
}

/*
 *	PadMessage
 *
 *	Description:
 *		According to the standard, the message must be padded to an even
 *		512 bits.  The first padding bit must be a '1'.  The last 64 bits
 *		represent the length of the original message.  All bits in between
 *		should be 0.  This function will pad the message according to those
 *		rules by filling the message_block array accordingly.  It will also
 *		call ProcessMessageBlock() appropriately.  When it returns, it
 *		can be assumed that the message digest has been computed.
 *
 *	Parameters:
 *		None.
 *
 *	Returns:
 *		Nothing.
 *
 *	Comments:
 *
 */
void SHA1::PadMessage()
{
	/*
	 *	Check to see if the current message block is too small to hold
	 *	the initial padding bits and length.  If so, we will pad the
	 *	block, process it, and then continue padding into a second block.
	 */
	if (Message_Block_Index > 55) //大于55表示不够补64位，即不够补8个字节，所以此组先补1，,00000到64字节，然后放入HASH处理
	{                             //开辟下一组块，用于补0到56字节，最后8字节放数据长度的二进制表示
		Message_Block[Message_Block_Index++] = 0x80;
		while(Message_Block_Index < 64)
		{
			Message_Block[Message_Block_Index++] = 0;
		}

		ProcessMessageBlock();

		while(Message_Block_Index < 56)
		{
			Message_Block[Message_Block_Index++] = 0;
		}
	}
	else
	{
		Message_Block[Message_Block_Index++] = 0x80;
		while(Message_Block_Index < 56)
		{
			Message_Block[Message_Block_Index++] = 0;
		}

	}

	/*
	 *	补最后8位进入块数组
	 */
	Message_Block[56] = (Length_High >> 24) & 0xFF;
	Message_Block[57] = (Length_High >> 16) & 0xFF;
	Message_Block[58] = (Length_High >> 8) & 0xFF;
	Message_Block[59] = (Length_High) & 0xFF;
	Message_Block[60] = (Length_Low >> 24) & 0xFF;
	Message_Block[61] = (Length_Low >> 16) & 0xFF;
	Message_Block[62] = (Length_Low >> 8) & 0xFF;
	Message_Block[63] = (Length_Low) & 0xFF;

	ProcessMessageBlock();
}


/*
 *	CircularShift
 *
 *	Description:
 *		This member function will perform a circular shifting operation.
 *
 *	Parameters:
 *		bits: [in]
 *			The number of bits to shift (1-31)
 *		word: [in]
 *			The value to shift (assumes a 32-bit integer)
 *
 *	Returns:
 *		The shifted value.
 *
 *	Comments:
 *
 */
unsigned SHA1::CircularShift(int bits, unsigned word)
{
	return ((word << bits) & 0xFFFFFFFF) | ((word & 0xFFFFFFFF) >> (32-bits));
}
