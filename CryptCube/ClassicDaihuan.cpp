#include "stdafx.h"
#include "ClassicDaihuan.h"


// 单表置换加密
CString ClassicDaihuanEncrypt(CString strPlainText,CString strAlphabetList)

{
	CString strCipherText;

	for (int i = 0; i < strPlainText.GetLength(); i++)
	{

		TCHAR cPlainChar = strPlainText.GetAt(i);

		if(_T('a')<= cPlainChar && cPlainChar <= _T('z')) strCipherText+=strAlphabetList.GetAt(cPlainChar - _T('a'));
	
		else if(_T('A')<= cPlainChar && cPlainChar <= _T('Z'))	strCipherText.AppendFormat(_T("%c"),strAlphabetList.Find(cPlainChar) + _T('a'));
		
		else strCipherText.AppendFormat(_T("%c"),cPlainChar);
		
	}

	return strCipherText;
}


// 单表置换解密
CString ClassicDaihuanDecrypt(CString strCipherText,CString strAlphabetList)
{
	CString strPlainText;

	for (int i = 0; i < strCipherText.GetLength(); i++)
	{

		TCHAR cCipherChar = strCipherText.GetAt(i);

		if(_T('a')<= cCipherChar && cCipherChar <= _T('z'))	strPlainText+=strAlphabetList.GetAt(cCipherChar - _T('a'));

		else if(_T('A')<= cCipherChar && cCipherChar <= _T('Z'))	strPlainText.AppendFormat(_T("%c"),strAlphabetList.Find(cCipherChar) + _T('a'));
		
		else strPlainText.AppendFormat(_T("%c"),cCipherChar);
		
	}

	return strPlainText;
}