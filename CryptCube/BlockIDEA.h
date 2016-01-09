#pragma once


#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 

                               
#define word16 unsigned short
#define word32 unsigned int
#define ROUNDS 8                                               //轮数
#define KEYLEN (6*ROUNDS+4)
#define low16(x) ((x)&0xffff)                                  //取低16位
typedef word16 IDEAkey[KEYLEN];
/*IDEA Algorithm functions*/

class IDEA  
{
public:

void en_key_idea(word16 userkey[8],IDEAkey Z);                 //生成加密子密钥
void de_key_idea(IDEAkey Z,IDEAkey DK);                        //生成解密子密钥
void cipher_idea(word16 in[4],word16 out[4],IDEAkey Z,word16 Inter[][4],word16 Last[]);//加密算法
word16 inv(word16 x);                                          //求模2(16)+1乘法逆元
word16 mul(word16 a,word16 b);                                 //模2(16)+1乘法
void  string_for_4(char c[],int num,unsigned short d1[]);//将明文转换成二进制再变成十进制

void Result_For_Two(char x[][8],char y[][8],unsigned short d1[]);
void Result_For_16(unsigned short d1[],char a[]);//将结果转换成16进制
void S16_For_10(unsigned short d1[],char a[]);
void S10_For_String(char x[][8],char y[][8],char M[] );//十进制转换成字符


void chang1(char c,int b[8]);
long chang2(int d[],long n) ;
void chang3(long x,int d[]) ;
int chang4(int d[]); //将一串二进制数转换成十进制数 
void chang5(int d,char a[]);//将一串二进制数转换成十六进制的数
void chang6(int d,char a[]);//将十六进制数转换成十进制的数
void chang7(int d[][16],unsigned short a[]);//将二进制数转换成十六进制的数

BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize);//宽字符转换短字符
BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//短字符转换宽字符

word16 usLunX[8][4];
word16 usLunZ[8][6];
word16 usLunW[8][4];

word16 usZuihouW[4];
word16 usZuihouZ[4];
word16 usZuihouY[4];


};
