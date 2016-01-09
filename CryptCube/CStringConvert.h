//在做MFC编程的时候，时常会碰到CString、CStringA、CStringW之间相互转换的问题，也即chat字符串与wchar_t字符串相互转换的问题。
//这是一些它们之间相互转换的函数

/*用法演示

CString  cstrName = TEXT("Hello Kitty");
    CStringA cstraName = CStrT2CStrA(cstrName);   //CString to CStringA
    CStringW cstrwName = CStrT2CStrW(cstrName);   //CString to CStringW
    ::MessageBoxA(NULL, cstraName, "CStringToolEx Test", MB_OK);
    ::MessageBoxW(NULL, cstrwName, L"CStringToolEx Test", MB_OK);

    CStringA cstraAddr = "Anhui Anqing";
    CString  cstrAddr  = CStrA2CStrT(cstraAddr);    //CStringA to CString
    CStringW cstrwAddr = CStrA2CStrW(cstraAddr);    //CStringA to CStringW
    ::MessageBox(NULL, cstrAddr, TEXT("CStringToolEx Test"), MB_OK);
    ::MessageBoxW(NULL, cstrwAddr, L"CStringToolEx Test", MB_OK);

    CStringW cstrwGender = L"Male";
    CString  cstrGender  = CStrW2CStrT(cstrwGender);   //CStringW to CString
    CStringA cstraGender = CStrW2CStrA(cstrwGender);   //CStringW to CStringA
    ::MessageBox(NULL, cstrGender, TEXT("CStringToolEx Test"), MB_OK);
    ::MessageBoxA(NULL, cstraGender, "CStringToolEx Test", MB_OK);
*/

#pragma once

#include  "CryptoAPIHash.h"
/////////////////////////////////////////////////////////////////////////////
// CString转CStringA
//
#ifndef CStrT2CStrA
#ifdef _UNICODE
#define CStrT2CStrA(cstr) CStrW2CStrA((cstr))
#else
#define CStrT2CStrA(cstr) (cstr)
#endif
#endif


/////////////////////////////////////////////////////////////////////////////
// CString转CStringW
//
#ifndef CStrT2CStrW
#ifdef _UNICODE
#define CStrT2CStrW(cstr) (cstr)
#else
#define CStrT2CStrW(cstr) CStrA2CStrW((cstr))
#endif
#endif


/////////////////////////////////////////////////////////////////////////////
// CStringA转CString
//
#ifndef CStrA2CStrT
#ifdef _UNICODE
#define CStrA2CStrT(cstr) CStrA2CStrW((cstr))
#else
#define CStrA2CStrT(cstr) (cstr)
#endif
#endif


///////////////////////////////////////////////////////////////////////////////
// CStringW转CString
//
#ifndef CStrW2CStrT
#ifdef _UNICODE
#define CStrW2CStrT(cstr) (cstr)
#else
#define CStrW2CStrT(cstr) CStrW2CStrA((cstr))
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
// CStringA转CStringW
//
CStringW CStrA2CStrW(const CStringA &cstrSrcA);


///////////////////////////////////////////////////////////////////////////////
// CStringW转CStringA
//
CStringA CStrW2CStrA(const CStringW &cstrSrcW);





///////////////////////////////////////////////////////////////////////////////
// Text转换为十六进制编码
//
CString Text2AnsiHex(const CString &strText);

CString Text2UnicodeHex(const CString &strText);

CString Text2UniBigEndHex(const CString &strText);

CString Text2Utf8(const CString &strText);

CString Text2Utf7(const CString &strText);


///////////////////////////////////////////////////////////////////////////////
// 十六进制编码转换为Text
//
CString AnsiHex2Text(const CString &strHex);

CString UnicodeHex2Text(const CString &strHex);

CString UniBigEndHex2Text(const CString &strHex);

CString Utf82Text(const CString &strHex);

CString Utf72Text(const CString &strHex);


///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有十六进制码0123456789ABCDEFabcdef 
//返回值为-1时，表示符合十六进制码，否则返回第一个错误字符位置
//
int CStrCheckHex(const CString &strHex);


///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有0123456789
//返回值为-1时，表示符合数字，否则返回第一个错误字符位置
//
int CStrCheckNumber(const CString &strNumber);

///////////////////////////////////////////////////////////////////////////////
//判断字符串是否只有字母a-z A-Z
//返回值为-1时，表示符合字母，否则返回第一个错误字符位置
//
int CStrCheckAlphabet(const CString &strAlphabet);

//计算文件的HASH值
CString GetFileHashMD5(CString strFilePath);
CString GetFileHashMD2(CString strFilePath);
CString GetFileHashSHA1(CString strFilePath);
CString GetFileHashSHA(CString strFilePath);
//CString GetFileHashSHA512(CString strFilePath);

//对字符串进行Base64编码
CString Text2Base64(const CString &strText);
CString Base642Text(const CString &strAscii);