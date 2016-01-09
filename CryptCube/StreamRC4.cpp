#include "StdAfx.h"
#include "StreamRC4.h"

RC4::RC4(void)
{

}

RC4::~RC4(void)
{
}


/******************************************************************************/
//	���ƣ�SetKey
//	���ܣ����ü�����Կ
//  ������key: ָ�������Կָ�룻nKeyLen: ��Կ����
//	���أ���
//  ��ע��ʹ��Setupǰ�������SetKey���ü�/������Կ

/******************************************************************************/
void RC4::SetKey( unsigned char* key, int nKeyLen )
{
	if( key == NULL || nKeyLen == 0 )
		return;

	g_KeyLen = nKeyLen;
	g_Key = new unsigned char[ nKeyLen ];
	assert( NULL != g_Key );
	if( NULL == g_Key )
	{
		return;
	}

	for( int i = 0; i < nKeyLen; ++i )
	{
		g_Key[i] = key[i];
	}
}

/******************************************************************************/
//	���ƣ�Setup
//	���ܣ���Կ��װ�׶Σ������û�S-Box
//  ��������
//	���أ���
//  ��ע��ʹ��Cryptǰ�������Setup������ʼ�����ܻ���

/******************************************************************************/
void RC4::Setup()
{
	unsigned int i,j,k;
	int tmp;

	//! ��ԿΪ��
	if( !g_Key || g_KeyLen == 0 ) return;

	g_SBox = new int[ g_SBoxSize ];
	assert( NULL != g_SBox );

	ZeroMemory( g_SBox, g_SBoxSize );

	//! ��0~255���S-Box
	for( i=0; i<g_SBoxSize; i++ )
	{
		g_SBox[i] = i;
		/////////////��¼��ʼSBox///////////
		m_SBoxChushi[i] = g_SBox[i];
		////////////////////////////////////
	}



	//! �����û�S-Box
	//! ͨ����s-Box�е�ÿһ��Ԫ����S-Box�е���һ��Ԫ�ؽ���һ�εķ�ʽ������S-Box�����ֵ�����˳��
	//! ����Կѭ�����256���飬����K-Box
	j = k = 0;
	for( i=0; i<g_SBoxSize; ++i )
	{
		tmp = g_SBox[i];
		j = ( j + tmp + g_Key[k] ) % g_SBoxSize;
		g_SBox[i] = g_SBox[j];
		g_SBox[j] = tmp;
		/////////////��¼KBox////////////////
		
		m_KBox[i]=g_Key[k];
		/////////////////////////////////////
		if( ++k >= g_KeyLen ) k=0;

	}

	for( i=0; i<g_SBoxSize; ++i )
	{

		/////////////��¼�û�SBox///////////
		m_SBoxZhihuan[i]=g_SBox[i];
		////////////////////////////////////
	}
}

/******************************************************************************/
//	���ƣ�Encrypt
//	���ܣ�1. ��Կ��װ�׶Σ�Ϊÿһ�������ܵ��ֽ�����һ��α�����;
//		  2. ��/����
//  ������pData: ָ�����/�������ݣ�nLength: ���ݳ���
//	���أ���
//  ��ע��ʹ��Cryptǰ�������RandomKey������ʼ�����ܻ���

/******************************************************************************/
void RC4::Encrypt( unsigned char *pData, int nLength )
{
	int i,j,k,R,tmp;
	i=j=k=0;




	for( i=0; i<nLength; ++i )
	{
		j = ( j + 1 ) % g_SBoxSize;
		k = ( k + g_SBox[j] ) % g_SBoxSize;

		//! ��ת��S-Box�еĵ�j��Ԫ�غ͵�k��Ԫ�ؽ���
		tmp = g_SBox[j];
		g_SBox[j] = g_SBox[k];
		g_SBox[k] = tmp;

		//! ���������R
		R = g_SBox[( g_SBox[j] + g_SBox[k] ) % g_SBoxSize];

		///////////////��¼����ֵ///////////
		m_Plain[i]=pData[i];
		m_Deidai[i]=R;
		////////////////////////////////////

		//! ����������������������
		pData[i] ^= R;
	}


	//! ��/���ܲ�����ɣ��ͷ��ڴ�ռ�
	if( g_SBox != NULL )
	{
		delete [] g_SBox;
		g_SBox = NULL;
	}
	if( g_Key != NULL )
	{
		delete [] g_Key;
		g_Key = NULL;
	}
}