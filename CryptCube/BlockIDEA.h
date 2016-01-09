#pragma once


#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 

                               
#define word16 unsigned short
#define word32 unsigned int
#define ROUNDS 8                                               //����
#define KEYLEN (6*ROUNDS+4)
#define low16(x) ((x)&0xffff)                                  //ȡ��16λ
typedef word16 IDEAkey[KEYLEN];
/*IDEA Algorithm functions*/

class IDEA  
{
public:

void en_key_idea(word16 userkey[8],IDEAkey Z);                 //���ɼ�������Կ
void de_key_idea(IDEAkey Z,IDEAkey DK);                        //���ɽ�������Կ
void cipher_idea(word16 in[4],word16 out[4],IDEAkey Z,word16 Inter[][4],word16 Last[]);//�����㷨
word16 inv(word16 x);                                          //��ģ2(16)+1�˷���Ԫ
word16 mul(word16 a,word16 b);                                 //ģ2(16)+1�˷�
void  string_for_4(char c[],int num,unsigned short d1[]);//������ת���ɶ������ٱ��ʮ����

void Result_For_Two(char x[][8],char y[][8],unsigned short d1[]);
void Result_For_16(unsigned short d1[],char a[]);//�����ת����16����
void S16_For_10(unsigned short d1[],char a[]);
void S10_For_String(char x[][8],char y[][8],char M[] );//ʮ����ת�����ַ�


void chang1(char c,int b[8]);
long chang2(int d[],long n) ;
void chang3(long x,int d[]) ;
int chang4(int d[]); //��һ����������ת����ʮ������ 
void chang5(int d,char a[]);//��һ����������ת����ʮ�����Ƶ���
void chang6(int d,char a[]);//��ʮ��������ת����ʮ���Ƶ���
void chang7(int d[][16],unsigned short a[]);//����������ת����ʮ�����Ƶ���

BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize);//���ַ�ת�����ַ�
BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//���ַ�ת�����ַ�

word16 usLunX[8][4];
word16 usLunZ[8][6];
word16 usLunW[8][4];

word16 usZuihouW[4];
word16 usZuihouZ[4];
word16 usZuihouY[4];


};
