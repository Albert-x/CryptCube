#pragma once


#include <string>


// permuted choice table (PC1)
const static char PC1_Table[56] = {
	57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18,
	10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22,
	14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12,  4
};
// permuted choice key (PC2)
const static char PC2_Table[48] = {
	14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
	23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
	41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};
// number left rotations of pc1 
const static char Shift_Table[16] = {
	1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};
// initial permutation (IP)
const static char IP_Table[64] = {
	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17,  9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};
// expansion operation matrix (E)
const static char E_Table[48] = {
	32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
	8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1
};
// The (in)famous S-boxes 
const static char S_Box[8][4][16] = {
	// S1
	14,  4,	13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
	0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
	4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
	15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13,
	// S2 
	15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
	3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
	0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9,
	// S3 
	10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
	1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12,
	// S4 
	7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
	3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14,
	// S5 
	2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
	4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3,
	// S6 
	12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
	9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
	4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13,
	// S7 
	4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
	1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
	6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12,
	// S8 
	13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
	1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
	7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
	2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};
// 32-bit permutation function P used on the output of the S-boxes 
const static char P_Table[32] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23, 26, 5,  18, 31, 10,
	2,  8, 24, 14, 32, 27, 3,  9,  19, 13, 30, 6,  22, 11, 4,  25
};
// final permutation IP^-1 
const static char IPR_Table[64] = {
	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41,  9, 49, 17, 57, 25
};



class DES
{
public:
		//�๹�캯��
         DES(); 

		 //����������
        ~DES(); 

        //����:����16��28λ��key
        //����:Դ8λ���ַ���(key),���key�����0-1
        //���:����������private CreateSubKey���������char SubKeys[keyN][16][48]
        void InitializeKey(char* srcBytes,unsigned int keyN);

        //����:����8λ�ַ���
        //����:8λ�ַ���,ʹ��Key�����0-1
        //���:���������ܺ��������private szCiphertext[16]
        //      �û�ͨ������Ciphertext�õ�
        void EncryptData(char* _srcBytes,unsigned int keyN);

        //����:����16λʮ�������ַ���
        //����:16λʮ�������ַ���,ʹ��Key�����0-1
        //���:���������ܺ��������private szPlaintext[8]
        //      �û�ͨ������Plaintext�õ�
        void DecryptData(char* _srcBytes,unsigned int keyN);

        //����:�������ⳤ���ַ���
        //����:���ⳤ���ַ���,����,ʹ��Key�����0-1
        //���:���������ܺ��������private szFCiphertextAnyLength[8192]
        //      �û�ͨ������CiphertextAnyLength�õ�
        void EncryptAnyLength(char* _srcBytes,unsigned int _bytesLength,unsigned int keyN);

        //����:�������ⳤ��ʮ�������ַ���
        //����:���ⳤ���ַ���,����,ʹ��Key�����0-1
        //���:���������ܺ��������private szFPlaintextAnyLength[8192]
        //      �û�ͨ������PlaintextAnyLength�õ�
        void DecryptAnyLength(char* _srcBytes,unsigned int _bytesLength, unsigned int keyN);

		//����:Bytes��Bits��ת��,
        //����:���任�ַ���,���������Ż�����ָ��,Bits��������С
		void Bytes2Bits(char *srcBytes, char* dstBits, unsigned int sizeBits);

		//����:Bits��Bytes��ת��,
        //����:���任�ַ���,���������Ż�����ָ��,Bits��������С
		void Bits2Bytes(char *dstBytes, char* srcBits, unsigned int sizeBits);

		//����:Int��Bits��ת��,
        //����:���任�ַ���,���������Ż�����ָ��
		void Int2Bits(unsigned int srcByte, char* dstBits);
		
		//����:Bits��Hex��ת��
        //����:���任�ַ���,���������Ż�����ָ��,Bits��������С
		void Bits2Hex(char *dstHex, char* srcBits, unsigned int sizeBits);
		
		//����:Bits��Hex��ת��
        //����:���任�ַ���,���������Ż�����ָ��,Bits��������С
		void Hex2Bits(char *srcHex, char* dstBits, unsigned int sizeBits);

		//szCiphertextInBinary��get����
        char* GetCiphertextInBinary();

		//szCiphertextInHex��get����
		char* GetCiphertextInHex();

        //Ciphertext��get����
		char* GetCiphertextInBytes();

		//Plaintext��get����
        char* GetPlaintext();

        //CiphertextAnyLength��get����
		char* GetCiphertextAnyLength();

		//PlaintextAnyLength��get����
        char* GetPlaintextAnyLength();

        char szSubKeys[2][16][48];//����2��16��48λ��Կ,��2������3DES
		char szCiphertextRaw[64]; //�������������(64��Bits) int 0,1
		char szPlaintextRaw[64]; //�������������(64��Bits) int 0,1
		char szCiphertextInBytes[8];//����8λ����
        char szPlaintextInBytes[8];//����8λ�����ַ���

		char szCiphertextInBinary[65]; //�������������(64��Bits) char '0','1',���һλ��'\0'
		char szCiphertextInHex[17]; //����ʮ����������,���һλ��'\0'
		char szPlaintext[9];//����8λ�����ַ���,���һλ��'\0'

        char szFCiphertextAnyLength[8192];//���ⳤ������
        char szFPlaintextAnyLength[8192];//���ⳤ�������ַ���




		///////////////////////////////////////////////////////
		/// �м���̼�¼
		

		char szShow56Key[15];//�洢56λ��Կʮ�����ƣ����һλ��'\0'
		char szShowCi[16][8];//����Ciʮ�����ƣ����һλ��'\0'
		char szShowDi[16][8];//����Diʮ�����ƣ����һλ��'\0'
		char szShowSubKeys[16][13];//����16��48λ��Կʮ�����ƣ����һλ��'\0'
		char szShowInput[17];//�洢64λ��ʼ�û��������ʮ�����ƣ����һλ��'\0'
		char szShowLi[16][9];//����Liʮ�����ƣ����һλ��'\0'
		char szShowRi[16][9];//����Riʮ�����ƣ����һλ��'\0'
		char szShowLii[16][9];//����Li+1ʮ�����ƣ����һλ��'\0'
		char szShowRii[16][9];//����Ri+1ʮ�����ƣ����һλ��'\0'
		char szShowEnd[17];//����64λ�ս��û�ǰ������ʮ�����ƣ����һλ��'\0'
		char szRiXorKi[16][13];//����F����RiXorKi��ʮ�����ƣ����һλ��'\0'
		char szFSbox[16][9];//����F��������S��֮���ʮ�����ƣ����һλ��'\0'
		char szFRiKi[16][9];//����F���������ʮ�����ƣ����һλ��'\0'



		////////////////////////////////////////////////////////



		//����:��������Կ
        //����:����PC1�任��56λ�������ַ���,���ɵ�szSubKeys���0-1
        //���:��������char szSubKeys[16][48]
        void CreateSubKey(char* sz_56key,unsigned int keyN);

		//����:DES�е�F����,
        //����:��32λ,��32λ,key���(0-15),ʹ�õ�szSubKeys���0-1
        //���:���ڱ任����32λ
        void FunctionF(char* sz_Li,char* sz_Ri,unsigned int iKey,unsigned int keyN);

		//����:IP�任
        //����:�������ַ���,����������ָ��
        //���:�����ı�ڶ�������������
        void InitialPermuteData(char* _src,char* _dst);

		//����:����32λ������չλ48λ,
        //����:ԭ32λ�ַ���,��չ�������ָ��
        //���:�����ı�ڶ�������������
        void ExpansionR(char* _src,char* _dst);

		//����:�����,
        //����:�����Ĳ����ַ���1,�ַ���2,����������,����������ָ��
        //���: �����ı���ĸ�����������
        void XOR(char* szParam1,char* szParam2, unsigned int uiParamLength, char* szReturnValueBuffer);

		//����:S-BOX , ����ѹ��,
        //����:48λ�������ַ���,
        //���:���ؽ��:32λ�ַ���
        void CompressFuncS(char* _src48, char* _dst32);

		//����:IP��任,
        //����:���任�ַ���,����������ָ��
        //���:�����ı�ڶ�������������
        void PermutationP(char* _src,char* _dst);

};