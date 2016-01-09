#include "StdAfx.h"
#include "StreamRC4.h"

RC4::RC4(void)
{

}

RC4::~RC4(void)
{
}


/******************************************************************************/
//	名称：SetKey
//	功能：设置加密密钥
//  参数：key: 指向加密密钥指针；nKeyLen: 密钥长度
//	返回：无
//  备注：使用Setup前必须调用SetKey设置加/解密密钥

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
//	名称：Setup
//	功能：密钥安装阶段：生成置换S-Box
//  参数：无
//	返回：无
//  备注：使用Crypt前必须调用Setup函数初始化加密环境

/******************************************************************************/
void RC4::Setup()
{
	unsigned int i,j,k;
	int tmp;

	//! 密钥为空
	if( !g_Key || g_KeyLen == 0 ) return;

	g_SBox = new int[ g_SBoxSize ];
	assert( NULL != g_SBox );

	ZeroMemory( g_SBox, g_SBoxSize );

	//! 用0~255填充S-Box
	for( i=0; i<g_SBoxSize; i++ )
	{
		g_SBox[i] = i;
		/////////////记录初始SBox///////////
		m_SBoxChushi[i] = g_SBox[i];
		////////////////////////////////////
	}



	//! 生成置换S-Box
	//! 通过将s-Box中的每一个元素与S-Box中的另一个元素交换一次的方式，打乱S-Box中数字的排列顺序
	//! 由密钥循环填充256数组，生成K-Box
	j = k = 0;
	for( i=0; i<g_SBoxSize; ++i )
	{
		tmp = g_SBox[i];
		j = ( j + tmp + g_Key[k] ) % g_SBoxSize;
		g_SBox[i] = g_SBox[j];
		g_SBox[j] = tmp;
		/////////////记录KBox////////////////
		
		m_KBox[i]=g_Key[k];
		/////////////////////////////////////
		if( ++k >= g_KeyLen ) k=0;

	}

	for( i=0; i<g_SBoxSize; ++i )
	{

		/////////////记录置换SBox///////////
		m_SBoxZhihuan[i]=g_SBox[i];
		////////////////////////////////////
	}
}

/******************************************************************************/
//	名称：Encrypt
//	功能：1. 密钥安装阶段：为每一个待加密的字节生成一个伪随机数;
//		  2. 加/解密
//  参数：pData: 指向待加/解密数据；nLength: 数据长度
//	返回：无
//  备注：使用Crypt前必须调用RandomKey函数初始化加密环境

/******************************************************************************/
void RC4::Encrypt( unsigned char *pData, int nLength )
{
	int i,j,k,R,tmp;
	i=j=k=0;




	for( i=0; i<nLength; ++i )
	{
		j = ( j + 1 ) % g_SBoxSize;
		k = ( k + g_SBox[j] ) % g_SBoxSize;

		//! 将转换S-Box中的第j个元素和第k个元素交换
		tmp = g_SBox[j];
		g_SBox[j] = g_SBox[k];
		g_SBox[k] = tmp;

		//! 生成随机数R
		R = g_SBox[( g_SBox[j] + g_SBox[k] ) % g_SBoxSize];

		///////////////记录迭代值///////////
		m_Plain[i]=pData[i];
		m_Deidai[i]=R;
		////////////////////////////////////

		//! 数据与随机数进行异或运算
		pData[i] ^= R;
	}


	//! 加/解密操作完成，释放内存空间
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