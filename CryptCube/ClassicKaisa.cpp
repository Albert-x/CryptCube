#include "stdafx.h"
#include "ClassicKaisa.h"


// 获取一个凯撒加密后的字符
TCHAR GetClassicKaisaChar(TCHAR cPlainChar,int nKey)
{
	TCHAR cCipherChar;

	if(_T('A')<= cPlainChar && cPlainChar <= _T('Z'))	
	{
		cCipherChar=(cPlainChar - nKey +_T('A'))%26 +_T('a');
	
	}
	else if(_T('a')<= cPlainChar && cPlainChar <= _T('z'))
	{
		cCipherChar=(cPlainChar + nKey -_T('a'))%26 +_T('A');

	}
	
	else
	{
		cCipherChar=cPlainChar;
	}

	return cCipherChar;
}


// 把一串字符做凯撒加密
CString ClassicKaisaEncrypt(CString strPlainText,int nKey)
{
	CString strCipherText;

	for (int i = 0; i < strPlainText.GetLength(); i++)
	{
		strCipherText+=GetClassicKaisaChar(strPlainText.GetAt(i),nKey);
	}

	return strCipherText;
}


// 把一串字符做凯撒解密，其实完全可以用加密算法，
// 单独写一个解密算法只为装B，呵呵。

CString ClassicKaisaDecrypt(CString strCipherText,int nKey)
{
	CString strPlainText;

	for (int i = 0; i < strCipherText.GetLength(); i++)
	{
		strPlainText+=GetClassicKaisaChar(strCipherText.GetAt(i),nKey);
	}

	return strPlainText;
}