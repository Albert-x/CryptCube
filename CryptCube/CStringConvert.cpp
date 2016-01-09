#include "stdafx.h"
#include "CStringConvert.h"


///////////////////////////////////////////////////////////////////////////////
// CStringA转CStringW
//
CStringW CStrA2CStrW(const CStringA &cstrSrcA)
{
	int len = MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len];
	memset(wstr, 0, len*sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, wstr, len);
	CStringW cstrDestW = wstr;
	delete[] wstr;

	return cstrDestW;
}


///////////////////////////////////////////////////////////////////////////////
// CStringW转CStringA
//
CStringA CStrW2CStrA(const CStringW &cstrSrcW)
{
	int len = WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, NULL, 0, NULL, NULL);
	char *str = new char[len];
	memset(str, 0, len);
	WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, str, len, NULL, NULL);
	CStringA cstrDestA = str;
	delete[] str;

	return cstrDestA;
}



///////////////////////////////////////////////////////////////////////////////
// Text转换为十六进制编码
//

// 将字符串转换成以ANSI方式保存的十六进制字符串
CString Text2AnsiHex(const CString &strText)
{

	// 用ANSI的CString接受数据
	CStringA strTextA = CStrT2CStrA(strText);

	// 设置一个ANSI的CString保存转换后的十六进制字符串
	CStringA strResultA;

	// 用“字节”型数据分析字符串
	BYTE *binText = (BYTE*)(LPCSTR)strTextA;

	// 一个字节一个字节的输出十六进制数据
	for( int i = 0; i < strTextA.GetLength(); ++i )
	{
		// 让转换后的字符两个两个的显示出来
		strResultA.AppendFormat("%02X" ,binText[i]);
	}

	// 返回结果
	return CStrA2CStrT(strResultA);

}

// 将字符串转换成以Unicode方式保存的十六进制字符串
CString Text2UnicodeHex(const CString &strText)
{
	// 用Unicode的CString接受数据
	CStringW strTextW = CStrT2CStrW(strText);

	// 设置一个Unicode的CString保存转换后的十六进制字符串
	CStringW strResultW;

	// 用“字”型数据分析字符串
	WORD *binText = (WORD*)(LPCWSTR)strTextW;

	// 一个字一个字的输出十六进制数据
	for( int i = 0; i < strTextW.GetLength(); ++i )
	{
		// 高低位互换
		WORD binUnicode = (binText[i] << 8 | binText[i] >> 8); 
		// 让转换后的字符四个四个的显示出来
		strResultW.AppendFormat(L"%04X" ,binUnicode);

	}

	// 返回结果
	return CStrW2CStrT(strResultW);
}

// 将字符串转换成以UniBigEnd方式保存的十六进制字符串
CString Text2UniBigEndHex(const CString &strText)
{
	//用Unicode的CString接受数据
	CStringW strTextW = CStrT2CStrW(strText);

	// 设置一个Unicode的CString保存转换后的十六进制字符串
	CStringW strResultW;

	// 用“字”型数据分析字符串
	WORD *binText = (WORD*)(LPCWSTR)strTextW;

	// 一个字一个字的输出十六进制数据
	for( int i = 0; i < strTextW.GetLength(); ++i )
	{
		// 让转换后的字符四个四个的显示出来
		strResultW.AppendFormat(L"%04X" ,binText[i]);
	}

	// 返回结果
	return CStrW2CStrT(strResultW);
}

// 将字符串转换成以Utf8方式保存的十六进制字符串
CString Text2Utf8(const CString &strText)
{
	// 用Unicode的CString接受数据
	CStringW strTextW = CStrT2CStrW(strText);

	// 计算字符串长度
	int len = WideCharToMultiByte(CP_UTF8, 0, LPCWSTR(strTextW), -1, NULL, 0, NULL, NULL);

	// 设置一个ANSI类型的字符数组保存Utf8结果
	char *str = new char[len];
	memset(str, 0, len);

	// 将Unicode的源字符串转换成Utf8编码方式的ANSI类型字符串
	WideCharToMultiByte(CP_UTF8, 0, LPCWSTR(strTextW), -1, str, len, NULL, NULL);

	//设置一个ANSI类型的CString存储转换后的Utf8编码方式的字符串。
	CStringA strTextA = str;

	//销毁中间字符串
	delete[] str;

	//设置一个ANSI类型的CString存储转换后的十六进制字符串
	CStringA strResultA;

	// 用“字节”型数据分析字符串
	BYTE *binText = (BYTE*)(LPCSTR)strTextA;

	// 一个字节一个字节的输出十六进制数据
	for( int i = 0; i < len-1; ++i )
	{
		// 让转换后的字符两个两个的显示出来
		strResultA.AppendFormat("%02X" ,binText[i]);
	}

	// 返回结果
	return CStrA2CStrT(strResultA);
}

// 将字符串转换成以Utf7方式保存的十六进制字符串
CString Text2Utf7(const CString &strText)
{
	// 用Unicode的CString接受数据
	CStringW strTextW = CStrT2CStrW(strText);

	// 计算字符串长度
	int len = WideCharToMultiByte(CP_UTF7, 0, LPCWSTR(strTextW), -1, NULL, 0, NULL, NULL);

	// 设置一个ANSI类型的字符数组保存Utf8结果
	char *str = new char[len];
	memset(str, 0, len);

	// 将Unicode的源字符串转换成Utf8编码方式的ANSI类型字符串
	WideCharToMultiByte(CP_UTF7, 0, LPCWSTR(strTextW), -1, str, len, NULL, NULL);

	//设置一个ANSI类型的CString存储转换后的Utf8编码方式的字符串。
	CStringA strTextA = str;

	//销毁中间字符串
	delete[] str;

	//设置一个ANSI类型的CString存储转换后的十六进制字符串
	CStringA strResultA;

	// 用“字节”型数据分析字符串
	BYTE *binText = (BYTE*)(LPCSTR)strTextA;

	// 一个字节一个字节的输出十六进制数据
	for( int i = 0; i < len-1; ++i )
	{
		// 让转换后的字符两个两个的显示出来
		strResultA.AppendFormat("%02X" ,binText[i]);
	}

	// 返回结果
	return CStrA2CStrT(strResultA);
}


///////////////////////////////////////////////////////////////////////////////
// 十六进制编码转换为Text
//

// 将十六进制以ansi的方式转换成字符串
CString AnsiHex2Text(const CString &strHex)
{

	CStringA strResultA;
	
	for( int i = 0; i < strHex.GetLength(); i+=2 )
	{
		CString strTemp=strHex.Mid(i,2);
		int nhex = _tcstoul(strTemp, 0, 16);
		strResultA.AppendFormat("%c",nhex);
		
	}

	return CStrA2CStrT(strResultA);

}

// 将十六进制以unicode的方式转换成字符串
CString UnicodeHex2Text(const CString &strHex)
{
	CStringW strResultW;
	
	for( int i = 0; i < strHex.GetLength(); i+=4 )
	{
		CString strTemp=strHex.Mid(i,4);
		CString strTempLitteEnd= strTemp.Mid(2,2);//高地位互换
		strTempLitteEnd.AppendFormat(_T("%s"),strTemp.Mid(0,2));

		int nhex = _tcstoul(strTempLitteEnd, 0, 16);
		strResultW.AppendFormat(L"%c",nhex);
		
	}

	return CStrW2CStrT(strResultW);
}


// 将十六进制以unicodebigend的方式转换成字符串
CString UniBigEndHex2Text(const CString &strHex)
{
	CStringW strResultW;
	
	for( int i = 0; i < strHex.GetLength(); i+=4 )
	{
		CString strTemp=strHex.Mid(i,4);
		int nhex = _tcstoul(strTemp, 0, 16);
		strResultW.AppendFormat(L"%c",nhex);
		
	}

	return CStrW2CStrT(strResultW);
}


CString Utf82Text(const CString &strHex)
{
	return strHex;
}

CString Utf72Text(const CString &strHex)
{
	return strHex;
}



///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有十六进制码0123456789ABCDEFabcdef 
//返回值为-1时，表示符合十六进制码，否则返回第一个错误字符位置
//
int CStrCheckHex(const CString &strHex)
{

	for (int i = 0; i < strHex.GetLength(); i++)//一个字符一个字符地判断
	{
		if (strHex.GetAt(i) < _T('0') || strHex.GetAt(i) > _T('9'))//若输入的字符是数字，则无需再判断是否是字母
		{
			if(strHex.GetAt(i) < _T('A') || strHex.GetAt(i) > _T('F'))
			{
				if(strHex.GetAt(i) < _T('a') || strHex.GetAt(i) > _T('f'))
				{
					if(strHex.GetAt(i)!=_T(' '))
						return i;
				}
			}
		}
	}
	return -1;

}

///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有数字字符0123456789
//返回值为-1时，表示符合十六进制码，否则返回第一个错误字符位置
//
int CStrCheckNumber(const CString &strNumber)
{

	for (int i = 0; i < strNumber.GetLength(); i++)//一个字符一个字符地判断
	{
		if (strNumber.GetAt(i) < _T('0') || strNumber.GetAt(i) > _T('9'))//若输入的字符是数字，则无需再判断是否是字母
		{
			if(strNumber.GetAt(i)!=_T(' '))
				return i;
		}
	}
	return -1;

}

///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有字母a-z A-Z
//返回值为-1时，表示符合字母，否则返回第一个错误字符位置
//
int CStrCheckAlphabet(const CString &strAlphabet)
{

	for (int i = 0; i < strAlphabet.GetLength(); i++)//一个字符一个字符地判断
	{
		TCHAR c = strAlphabet.GetAt(i);
		if (!(_T('A')<= c && c <= _T('Z') || _T('a')<= c && c <= _T('z')))
		{
			if(strAlphabet.GetAt(i)!=_T(' '))
				return i;
		}
	}
	return -1;

}



CString GetFileHashMD5(CString strFilePath)
{

	return strFilePath;
}

CString GetFileHashCRC32(CString strFilePath)
{
	return strFilePath;
}

CString GetFileHashSHA1(CString strFilePath)
{
	return strFilePath;
}

CString GetFileHashSHA256(CString strFilePath)
{
	return strFilePath;
}

CString GetFileHashSHA512(CString strFilePath)
{
	return strFilePath;
}



