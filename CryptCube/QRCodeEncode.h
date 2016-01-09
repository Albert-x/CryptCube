// QR_Encode.h

#if !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
#define AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// ����ȼ�
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

// ģʽ
#define QR_MODE_NUMERAL		0 // ��������
#define QR_MODE_ALPHABET	1 // ��ĸ����
#define QR_MODE_8BIT		2 // 8λ�ֽ�����
#define QR_MODE_KANJI		3 // �й�/�ձ���������

// �汾
#define QR_VRESION_S	0 // 1 ~ 9
#define QR_VRESION_M	1 // 10 ~ 26
#define QR_VRESION_L	2 // 27 ~ 40

#define MAX_ALLCODEWORD		3706 // ���������������汾40��
#define MAX_DATACODEWORD	2956 // �����������������汾40������ȼ�L�������
#define MAX_CODEBLOCK		 153 // ��������ֵ
#define MAX_MODULESIZE		 177 // ���ģ�������У��ж�Ϊ177���汾40��

// ��Ե��
#define QR_MARGIN	1


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
	int ncRSBlock;		// ���������
	int ncAllCodeWord;	// ������
	int ncDataCodeWord;	// ����������

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////
// QR��汾��Ϣ

typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	   // �汾��Ϣ(1~40)
	int ncAllCodeWord; // ��������

	// (0 = L, 1 = M, 2 = Q, 3 = H) 
	int ncDataCodeWord[4];	// �ĸ���ͬ�ļ�������������

	int ncAlignPoint;	// 
	int nAlignPoint[6];	//

	RS_BLOCKINFO RS_BlockInfo1[4]; // 
	RS_BLOCKINFO RS_BlockInfo2[4]; // 

} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/////////////////////////////////////////////////////////////////////////////
// CQR_Encode
class CQR_Encode
{
public:
	CQR_Encode();
	~CQR_Encode();

public:
	int m_nLevel;		// ����ȼ�
	int m_nVersion;		// �汾��1~40��
	BOOL m_bAutoExtent;	// �Զ���չ
	int m_nMaskingNo;	// ��ģ

public:
	int m_nSymbleSize;
	BYTE m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]

private:
	int m_ncDataCodeWordBit; // ��������Bit
	BYTE m_byDataCodeWord[MAX_DATACODEWORD]; // ��������

	int m_ncDataBlock; //�����
	BYTE m_byBlockMode[MAX_DATACODEWORD];
	int m_nBlockLength[MAX_DATACODEWORD];

	int m_ncAllCodeWord; // ��������
	BYTE m_byAllCodeWord[MAX_ALLCODEWORD]; // ����
	BYTE m_byRSWork[MAX_CODEBLOCK]; // ��������

public:
	BOOL EncodeData(int nLevel, int nVersion, BOOL bAutoExtent, int nMaskingNo, LPCSTR lpsSource, int ncSource = 0);

private:
	int GetEncodeVersion(int nVersion, LPCSTR lpsSource, int ncLength);
	BOOL EncodeSourceData(LPCSTR lpsSource, int ncLength, int nVerGroup);

	int GetBitLength(BYTE nMode, int ncData, int nVerGroup);

	int SetBitStream(int nIndex, WORD wData, int ncData);

	BOOL IsNumeralData(unsigned char c);
	BOOL IsAlphabetData(unsigned char c);
	BOOL IsKanjiData(unsigned char c1, unsigned char c2);

	BYTE AlphabetToBinaly(unsigned char c);
	WORD KanjiToBinaly(WORD wc);

	void GetRSCodeWord(LPBYTE lpbyRSWork, int ncDataCodeWord, int ncRSCodeWord);

private:
	void FormatModule();

	void SetFunctionModule();
	void SetFinderPattern(int x, int y);
	void SetAlignmentPattern(int x, int y);
	void SetVersionPattern();
	void SetCodeWordPattern();
	void SetMaskingPattern(int nPatternNo);
	void SetFormatInfoPattern(int nPatternNo);
	int CountPenalty();
};

/////////////////////////////////////////////////////////////////////////////

#endif // !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
