

#include "stdafx.h"
#include "BlockDES.h"



DES::DES()
{
	memset(szCiphertextRaw,0,64);
	memset(szPlaintextRaw,0,64);
	memset(szCiphertextInBytes,0,8);
	memset(szPlaintextInBytes,0,8);
	memset(szCiphertextInBinary,0,65);
	memset(szCiphertextInHex,0,17);
	memset(szPlaintext,0,9);
	memset(szFCiphertextAnyLength,0,8192);
	memset(szCiphertextInHex,0,8192);

	memset(szShow56Key,0,15);

}
DES::~DES()
{
}

void DES::InitializeKey(char* srcBytes,unsigned int keyN)
{
	//convert 8 char-bytes key to 64 binary-bits
	char sz_64key[64] = {0};
	Bytes2Bits(srcBytes,sz_64key,64);
	//PC 1
	char sz_56key[56] = {0};
	for(int k=0;k<56;k++)
	{
		sz_56key[k] = sz_64key[PC1_Table[k]-1];
	}
	/////////////////////////记录56位密钥的十六进制///////////////////////////

	Bits2Hex(szShow56Key,sz_56key,56);

	//////////////////////////////////////////////////////////////////////////
	
	CreateSubKey(sz_56key,keyN);
}

void DES::CreateSubKey(char* sz_56key,unsigned int keyN)
{
	char szTmpL[28] = {0};
	char szTmpR[28] = {0};
	char szCi[28] = {0};
	char szDi[28] = {0};
	memcpy(szTmpL,sz_56key,28);
	memcpy(szTmpR,sz_56key + 28,28);

	for(int i=0;i<16;i++)
	{
		//shift to left
		//Left 28 bits
		memcpy(szCi,szTmpL + Shift_Table[i],28 - Shift_Table[i]);
		memcpy(szCi + 28 - Shift_Table[i],szTmpL,Shift_Table[i]);

		//Right 28 bits
		memcpy(szDi,szTmpR + Shift_Table[i],28 - Shift_Table[i]);
		memcpy(szDi + 28 - Shift_Table[i],szTmpR,Shift_Table[i]);

		//permuted choice 48 bits key
		char szTmp56[56] = {0};
		memcpy(szTmp56,szCi,28);
		memcpy(szTmp56 + 28,szDi,28);
		for(int j=0;j<48;j++)
		{
			szSubKeys[keyN][i][j] = szTmp56[PC2_Table[j]-1];
		}
		//Evaluate new szTmpL and szTmpR
		memcpy(szTmpL,szCi,28);
		memcpy(szTmpR,szDi,28);

		/////////////////记录 16组Ci+1、Di+1、子密钥的十六进制/////////////////////

		memset(szShowCi[i],0,8);
		memset(szShowDi[i],0,8);
		Bits2Hex(szShowCi[i],szCi,28);
		szShowCi[i][7]= '\0';
		Bits2Hex(szShowDi[i],szDi,28);
		szShowDi[i][7]= '\0';

		memset(szShowSubKeys[i],0,13);
		Bits2Hex(szShowSubKeys[i],szSubKeys[keyN][i],48);
		szShowSubKeys[i][12]= '\0';

		//////////////////////////////////////////////////////////////////////////
	}
}

void DES::EncryptData(char* _srcBytes,unsigned int keyN)
{
	char szSrcBits[64] = {0};
	char sz_IP[64] = {0};
	char sz_Li[32] = {0};
	char sz_Ri[32] = {0};
	char sz_Final64[64] = {0};

	Bytes2Bits(_srcBytes,szSrcBits,64);
	//IP
	InitialPermuteData(szSrcBits,sz_IP);
	memcpy(sz_Li,sz_IP,32);
	memcpy(sz_Ri,sz_IP + 32,32);

	for(int i=0;i<16;i++)
	{
		FunctionF(sz_Li,sz_Ri,i,keyN);
	}
	//so D=LR

	memcpy(sz_Final64,sz_Ri,32);
	memcpy(sz_Final64 + 32,sz_Li,32);

	///////////////////////终结置换前的密文十六进制///////////////////////////
	memset(szShowEnd,0,17);
	Bits2Hex(szShowEnd,sz_Final64,64);
	szShowEnd[16]= '\0';
	//////////////////////////////////////////////////////////////////////////

	//~IP
	for(int j=0;j<64;j++)
	{
		szCiphertextRaw[j] = sz_Final64[IPR_Table[j]-1];
	}
	Bits2Bytes(szCiphertextInBytes,szCiphertextRaw,64);
}

void DES::DecryptData(char* _srcBytes,unsigned int keyN)
{
	char szSrcBits[64] = {0};
	char sz_IP[64] = {0};
	char sz_Li[32] = {0};
	char sz_Ri[32] = {0};
	char sz_Final64[64] = {0};
	Bytes2Bits(_srcBytes,szSrcBits,64);
	//IP --- return is sz_IP
	InitialPermuteData(szSrcBits,sz_IP);
	//divide the 64 bits data to two parts
	memcpy(sz_Ri,sz_IP,32); //exchange L to R
	memcpy(sz_Li,sz_IP + 32,32);  //exchange R to L
	//16 rounds F and xor and exchange
	for(int i=0;i<16;i++)
	{
		FunctionF(sz_Ri,sz_Li,15-i,keyN);
	}
	memcpy(sz_Final64,sz_Li,32);
	memcpy(sz_Final64 + 32,sz_Ri,32);
	// ~IP
	for(int j=0;j<64;j++)
	{
		szPlaintextRaw[j] = sz_Final64[IPR_Table[j]-1];
	}
	Bits2Bytes(szPlaintextInBytes,szPlaintextRaw,64);
}

void DES::FunctionF(char* sz_Li,char* sz_Ri,unsigned int iKey,unsigned int keyN)
{

	//////////////////////////记录 16组Li、Ri的十六进制///////////////////
	memset(szShowLi[iKey],0,9);
	memset(szShowRi[iKey],0,9);
	Bits2Hex(szShowLi[iKey],sz_Li,32);
	szShowLi[iKey][8]= '\0';
	Bits2Hex(szShowRi[iKey],sz_Ri,32);
	szShowRi[iKey][8]= '\0';
	//////////////////////////////////////////////////////////////////////////

	char sz_48R[48] = {0};
	char sz_xor48[48] = {0};
	char sz_P32[32] = {0};
	char sz_Rii[32] = {0};
	char sz_Key[48] = {0};
	char s_Compress32[32] = {0};
	memcpy(sz_Key,szSubKeys[keyN][iKey],48);
	ExpansionR(sz_Ri,sz_48R);
	XOR(sz_48R,sz_Key,48,sz_xor48);

	//////////////////////////记录 16组F函数RiXorKi的十六进制/////////////////
	memset(szRiXorKi[iKey],0,13);
	Bits2Hex(szRiXorKi[iKey],sz_xor48,48);
	szRiXorKi[iKey][12]= '\0';
	//////////////////////////////////////////////////////////////////////////

	CompressFuncS(sz_xor48,s_Compress32);

	//////////////////////////记录 16组F函数结果的十六进制/////////////////
	memset(szFSbox[iKey],0,9);
	Bits2Hex(szFSbox[iKey],s_Compress32,32);
	szFSbox[iKey][8]= '\0';
	//////////////////////////////////////////////////////////////////////////

	PermutationP(s_Compress32,sz_P32);

	//////////////////////////记录 16组F函数结果的十六进制/////////////////
	memset(szFRiKi[iKey],0,9);
	Bits2Hex(szFRiKi[iKey],sz_P32,32);
	szFRiKi[iKey][8]= '\0';
	//////////////////////////////////////////////////////////////////////////

	XOR(sz_P32,sz_Li,32,sz_Rii);
	memcpy(sz_Li,sz_Ri,32);
	memcpy(sz_Ri,sz_Rii,32);

	//////////////////////////记录 16组Li+1、Ri+1的十六进制///////////////////
	memset(szShowLii[iKey],0,9);
	memset(szShowRii[iKey],0,9);
	Bits2Hex(szShowLii[iKey],sz_Li,32);
	szShowLii[iKey][8]= '\0';
	Bits2Hex(szShowRii[iKey],sz_Ri,32);
	szShowRii[iKey][8]= '\0';
	//////////////////////////////////////////////////////////////////////////

}

void DES::InitialPermuteData(char* _src,char* _dst)
{
	//IP
	for(int i=0;i<64;i++)
	{
		_dst[i] = _src[IP_Table[i]-1];
	}

	/////////////////记录 初始置换后的明文 十六进制/////////////////////
	memset(szShowInput,0,17);
	Bits2Hex(szShowInput,_dst,64);
	szShowInput[16]= '\0';
	//////////////////////////////////////////////////////////////////////////
}

void DES::ExpansionR(char* _src,char* _dst)
{
	for(int i=0;i<48;i++)
	{
		_dst[i] = _src[E_Table[i]-1];
	}
}

void DES::XOR(char* szParam1,char* szParam2, unsigned int uiParamLength, char* szReturnValueBuffer)
{
	for(unsigned int i=0; i<uiParamLength; i++)
	{
		szReturnValueBuffer[i] = szParam1[i] ^ szParam2[i];
	}
}

void DES::CompressFuncS(char* _src48, char* _dst32)
{
	char bTemp[8][6]={0};
	char dstBits[4]={0};
	for(int i=0;i<8;i++)
	{
		memcpy(bTemp[i],_src48+i*6,6);
		int iX = (bTemp[i][0])*2 + (bTemp[i][5]);
		int iY = 0;
		for(int j=1;j<5;j++)
		{
			iY += bTemp[i][j]<<(4-j);
		}
		Int2Bits(S_Box[i][iX][iY], dstBits);
		memcpy(_dst32 + i * 4, dstBits, 4);
	}

}

void DES::PermutationP(char* _src,char* _dst)
{
	for(int i=0;i<32;i++)
	{
		_dst[i] = _src[P_Table[i]-1];
	}
}

void DES::Bytes2Bits(char *srcBytes, char* dstBits, unsigned int sizeBits)
{
	for(unsigned int i=0; i < sizeBits; i++)
		dstBits[i] = ((srcBytes[i>>3]<<(i&7)) & 128)>>7;
}

void DES::Bits2Bytes(char *dstBytes, char* srcBits, unsigned int sizeBits)
{
	memset(dstBytes,0,sizeBits>>3);
	for(unsigned int i=0; i < sizeBits; i++)
		dstBytes[i>>3] |= (srcBits[i] << (7 - (i & 7)));
}

void DES::Int2Bits(unsigned int _src, char* dstBits)
{
	for(unsigned int i=0; i < 4; i++)
		dstBits[i] = ((_src<<i) & 8)>>3;
}

void DES::Bits2Hex(char *dstHex, char* srcBits, unsigned int sizeBits)
{
	memset(dstHex,0,sizeBits>>2);
	for(unsigned int i=0; i < sizeBits; i++) //convert to int 0-15
		dstHex[i>>2] += (srcBits[i] << (3 - (i & 3)));
	for(unsigned int j=0;j < (sizeBits>>2);j++)
		dstHex[j] += dstHex[j] > 9 ? 55 : 48; //convert to char '0'-'F'
}

void DES::Hex2Bits(char *srcHex, char* dstBits, unsigned int sizeBits)
{
	memset(dstBits,0,sizeBits);
	for(unsigned int i=0;i < (sizeBits>>2);i++)
		srcHex[i] -= srcHex[i] > 64 ? 55 : 48; //convert to char int 0-15
	for(unsigned int j=0; j < sizeBits; j++) 
		dstBits[j] = ((srcHex[j>>2]<<(j&3)) & 15) >> 3;

}

char* DES::GetCiphertextInBinary()
{
	for(unsigned int i=0;i<64;i++)
	{
		szCiphertextInBinary[i] = szCiphertextRaw[i] + 48; // from int(0) to char('0') and int1 to char('1')
	}
	szCiphertextInBinary[64] = '\0';
	return szCiphertextInBinary;
}

char* DES::GetCiphertextInHex()
{
	Bits2Hex(szCiphertextInHex,szCiphertextRaw,64);
	szCiphertextInHex[16] = '\0';
	return szCiphertextInHex;
}

char* DES::GetCiphertextInBytes()
{
	return szCiphertextInBytes;
}

char* DES::GetPlaintext()
{
	memcpy(szPlaintext,szPlaintextInBytes,8);
	szPlaintext[8] = '\0';
	return szPlaintext;
}

char* DES::GetCiphertextAnyLength()
{
	return szFCiphertextAnyLength;
}

char* DES::GetPlaintextAnyLength()
{
	return szFPlaintextAnyLength;
}

void DES::EncryptAnyLength(char* _srcBytes,unsigned int _bytesLength,unsigned int keyN)
{
	if(_bytesLength == 8)
	{
		EncryptData(_srcBytes,keyN);
		memcpy(szFCiphertextAnyLength,szCiphertextInBytes,8);
		szFCiphertextAnyLength[8] = '\0';
	}
	else if(_bytesLength < 8)
	{
		char _temp8bytes[8] = {0};
		memcpy(_temp8bytes,_srcBytes,_bytesLength);
		EncryptData(_temp8bytes,keyN);
		memcpy(szFCiphertextAnyLength,szCiphertextInBytes,8);
		szFCiphertextAnyLength[8] = '\0';
	}
	else if(_bytesLength > 8)
	{
		int iParts = _bytesLength>>3;
		int iResidue = _bytesLength % 8;
		char szLast8Bits[8] = {0};
		for(int i=0;i<iParts;i++)
		{
			memcpy(szLast8Bits,_srcBytes + (i<<3),8);
			EncryptData(szLast8Bits,keyN);
			memcpy(szFCiphertextAnyLength + (i<<3),szCiphertextInBytes,8);
		}
		memset(szLast8Bits,0,8);
		memcpy(szLast8Bits,_srcBytes + (iParts<<3),iResidue);

		EncryptData(szLast8Bits,keyN);
		memcpy(szFCiphertextAnyLength + (iParts<<3),szCiphertextInBytes,8);
		szFCiphertextAnyLength[((iParts+1)<<3)] = '\0';
	}
}

void DES::DecryptAnyLength(char* _srcBytes,unsigned int _bytesLength, unsigned int keyN)
{
	if(_bytesLength == 8)
	{
		DecryptData(_srcBytes,keyN);
		memcpy(szFPlaintextAnyLength,szPlaintextInBytes,8);
		szFPlaintextAnyLength[8] = '\0';
	}
	else if(_bytesLength < 8)
	{
		char _temp8bytes[8] = {0};
		memcpy(_temp8bytes,_srcBytes,8);
		DecryptData(_temp8bytes,keyN);
		memcpy(szFPlaintextAnyLength,szPlaintextInBytes,_bytesLength);
		szFPlaintextAnyLength[_bytesLength] = '\0';
	}
	else if(_bytesLength > 8)
	{
		int iParts = _bytesLength>>3;
		int iResidue = _bytesLength % 8;
		char szLast8Bits[8] = {0};
		for(int i=0;i<iParts;i++)
		{
			memcpy(szLast8Bits,_srcBytes + (i<<3),8);
			DecryptData(szLast8Bits,keyN);
			memcpy(szFPlaintextAnyLength + (i<<3),szPlaintextInBytes,8);
		}
		if(iResidue != 0)
		{
			memset(szLast8Bits,0,8);
			memcpy(szLast8Bits,_srcBytes + (iParts<<3),8);
			DecryptData(szLast8Bits,keyN);
			memcpy(szFPlaintextAnyLength + (iParts<<3),szPlaintextInBytes,iResidue);
		}
		szFPlaintextAnyLength[_bytesLength] = '\0';
	}
}