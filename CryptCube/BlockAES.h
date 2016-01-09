
#pragma once

#include "stdafx.h"

class AES  
{
public:
	AES(unsigned char* key);
	virtual ~AES();
	unsigned char* Cipher(unsigned char* input);
	unsigned char* InvCipher(unsigned char* input);
	void* Cipher(void* input, int length=0);
	void* InvCipher(void* input, int length);

	unsigned char Sbox[256];
	unsigned char InvSbox[256];
	unsigned char w[11][4][4];

		///////////////////////////////////////////////////////
		/// 中间过程记录
		

		unsigned char szShowInput[4][4];

		unsigned char szShowChushi[4][4];

		unsigned char szShow9lun[4][4];

		unsigned char szShowZuihou[4][4];

		// 
		unsigned char sz9lunShowInput[9][4][4];
		unsigned char sz9lunShowSubBytes[9][4][4];
		unsigned char sz9lunShowShiftRows[9][4][4];
		unsigned char sz9lunShowMixColumns[9][4][4];
		unsigned char sz9lunShowWi[9][4][4];
		unsigned char sz9lunShowOutput[9][4][4];

		//unsigned char szZuihouShowInput[4][4];
		unsigned char szZuihouShowSubBytes[4][4];
		unsigned char szZuihouShowShiftRows[4][4];
		//unsigned char szZuihouShowWi[4][4];
		//unsigned char szZuihouShowOutput[4][4];



		////////////////////////////////////////////////////////

	void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
	unsigned char FFmul(unsigned char a, unsigned char b);

	void SubBytes(unsigned char state[][4]);
	void ShiftRows(unsigned char state[][4]);
	void MixColumns(unsigned char state[][4]);
	void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);

	void InvSubBytes(unsigned char state[][4]);
	void InvShiftRows(unsigned char state[][4]);
	void InvMixColumns(unsigned char state[][4]);

};
