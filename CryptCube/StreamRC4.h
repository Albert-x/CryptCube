#pragma once

#include <memory.h>
#include <assert.h>
#include <afxwin.h>


class RC4
{
public:

	RC4();
	~RC4();

	//! 全局变量，存储密钥
	unsigned char* g_Key;
	//! 全局变量，密钥长度
	unsigned int g_KeyLen;
	//! 全局变量，S-Box
	int *g_SBox;
	//! SBox元素个数
	unsigned int g_SBoxSize;

	///////////中间过程记录////////////
	int m_SBoxChushi[256];
	int m_SBoxZhihuan[256];
	int m_KBox[256];

	unsigned char m_Plain[2048];
	unsigned char m_Deidai[2048];




	////////////////////////////////////


	void SetKey( unsigned char* key, int nKeyLen );
	void Setup();
	void Encrypt( unsigned char *pData, int nLength );

};
