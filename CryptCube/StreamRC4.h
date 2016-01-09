#pragma once

#include <memory.h>
#include <assert.h>
#include <afxwin.h>


class RC4
{
public:

	RC4();
	~RC4();

	//! ȫ�ֱ������洢��Կ
	unsigned char* g_Key;
	//! ȫ�ֱ�������Կ����
	unsigned int g_KeyLen;
	//! ȫ�ֱ�����S-Box
	int *g_SBox;
	//! SBoxԪ�ظ���
	unsigned int g_SBoxSize;

	///////////�м���̼�¼////////////
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
