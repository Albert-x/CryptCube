//����MFC��̵�ʱ��ʱ��������CString��CStringA��CStringW֮���໥ת�������⣬Ҳ��chat�ַ�����wchar_t�ַ����໥ת�������⡣
//����һЩ����֮���໥ת���ĺ���

/*�÷���ʾ

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
// CStringתCStringA
//
#ifndef CStrT2CStrA
#ifdef _UNICODE
#define CStrT2CStrA(cstr) CStrW2CStrA((cstr))
#else
#define CStrT2CStrA(cstr) (cstr)
#endif
#endif


/////////////////////////////////////////////////////////////////////////////
// CStringתCStringW
//
#ifndef CStrT2CStrW
#ifdef _UNICODE
#define CStrT2CStrW(cstr) (cstr)
#else
#define CStrT2CStrW(cstr) CStrA2CStrW((cstr))
#endif
#endif


/////////////////////////////////////////////////////////////////////////////
// CStringAתCString
//
#ifndef CStrA2CStrT
#ifdef _UNICODE
#define CStrA2CStrT(cstr) CStrA2CStrW((cstr))
#else
#define CStrA2CStrT(cstr) (cstr)
#endif
#endif


///////////////////////////////////////////////////////////////////////////////
// CStringWתCString
//
#ifndef CStrW2CStrT
#ifdef _UNICODE
#define CStrW2CStrT(cstr) (cstr)
#else
#define CStrW2CStrT(cstr) CStrW2CStrA((cstr))
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
// CStringAתCStringW
//
CStringW CStrA2CStrW(const CStringA &cstrSrcA);


///////////////////////////////////////////////////////////////////////////////
// CStringWתCStringA
//
CStringA CStrW2CStrA(const CStringW &cstrSrcW);





///////////////////////////////////////////////////////////////////////////////
// Textת��Ϊʮ�����Ʊ���
//
CString Text2AnsiHex(const CString &strText);

CString Text2UnicodeHex(const CString &strText);

CString Text2UniBigEndHex(const CString &strText);

CString Text2Utf8(const CString &strText);

CString Text2Utf7(const CString &strText);


///////////////////////////////////////////////////////////////////////////////
// ʮ�����Ʊ���ת��ΪText
//
CString AnsiHex2Text(const CString &strHex);

CString UnicodeHex2Text(const CString &strHex);

CString UniBigEndHex2Text(const CString &strHex);

CString Utf82Text(const CString &strHex);

CString Utf72Text(const CString &strHex);


///////////////////////////////////////////////////////////////////////////////
//�ж��ַ����Ƿ�ֻ��ʮ��������0123456789ABCDEFabcdef 
//����ֵΪ-1ʱ����ʾ����ʮ�������룬���򷵻ص�һ�������ַ�λ��
//
int CStrCheckHex(const CString &strHex);


///////////////////////////////////////////////////////////////////////////////
//�ж��ַ����Ƿ�ֻ��0123456789
//����ֵΪ-1ʱ����ʾ�������֣����򷵻ص�һ�������ַ�λ��
//
int CStrCheckNumber(const CString &strNumber);

///////////////////////////////////////////////////////////////////////////////
//�ж��ַ����Ƿ�ֻ����ĸa-z A-Z
//����ֵΪ-1ʱ����ʾ������ĸ�����򷵻ص�һ�������ַ�λ��
//
int CStrCheckAlphabet(const CString &strAlphabet);

//�����ļ���HASHֵ
CString GetFileHashMD5(CString strFilePath);
CString GetFileHashMD2(CString strFilePath);
CString GetFileHashSHA1(CString strFilePath);
CString GetFileHashSHA(CString strFilePath);
//CString GetFileHashSHA512(CString strFilePath);

//���ַ�������Base64����
CString Text2Base64(const CString &strText);
CString Base642Text(const CString &strAscii);