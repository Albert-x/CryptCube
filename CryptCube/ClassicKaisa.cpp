#include "stdafx.h"
#include "ClassicKaisa.h"


// ��ȡһ���������ܺ���ַ�
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


// ��һ���ַ�����������
CString ClassicKaisaEncrypt(CString strPlainText,int nKey)
{
	CString strCipherText;

	for (int i = 0; i < strPlainText.GetLength(); i++)
	{
		strCipherText+=GetClassicKaisaChar(strPlainText.GetAt(i),nKey);
	}

	return strCipherText;
}


// ��һ���ַ����������ܣ���ʵ��ȫ�����ü����㷨��
// ����дһ�������㷨ֻΪװB���Ǻǡ�

CString ClassicKaisaDecrypt(CString strCipherText,int nKey)
{
	CString strPlainText;

	for (int i = 0; i < strCipherText.GetLength(); i++)
	{
		strPlainText+=GetClassicKaisaChar(strCipherText.GetAt(i),nKey);
	}

	return strPlainText;
}