// QR_Encode.h

#if !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
#define AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// 纠错等级
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

// 模式
#define QR_MODE_NUMERAL		0 // 数字数据
#define QR_MODE_ALPHABET	1 // 字母数据
#define QR_MODE_8BIT		2 // 8位字节数据
#define QR_MODE_KANJI		3 // 中国/日本汉字数据

// 版本
#define QR_VRESION_S	0 // 1 ~ 9
#define QR_VRESION_M	1 // 10 ~ 26
#define QR_VRESION_L	2 // 27 ~ 40

#define MAX_ALLCODEWORD		3706 // 最大的码字总数（版本40）
#define MAX_DATACODEWORD	2956 // 最大的数据码字数（版本40，纠错等级L的情况）
#define MAX_CODEBLOCK		 153 // 码块数最大值
#define MAX_MODULESIZE		 177 // 最大模块数（行，列都为177，版本40）

// 边缘宽
#define QR_MARGIN	1


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
	int ncRSBlock;		// 纠错码块数
	int ncAllCodeWord;	// 码字数
	int ncDataCodeWord;	// 数据码字数

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////
// QR码版本信息

typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	   // 版本信息(1~40)
	int ncAllCodeWord; // 总码字数

	// (0 = L, 1 = M, 2 = Q, 3 = H) 
	int ncDataCodeWord[4];	// 四个不同的级别数据码字数

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
	int m_nLevel;		// 纠错等级
	int m_nVersion;		// 版本（1~40）
	BOOL m_bAutoExtent;	// 自动扩展
	int m_nMaskingNo;	// 掩模

public:
	int m_nSymbleSize;
	BYTE m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]

private:
	int m_ncDataCodeWordBit; // 数据码字Bit
	BYTE m_byDataCodeWord[MAX_DATACODEWORD]; // 数据码字

	int m_ncDataBlock; //码块数
	BYTE m_byBlockMode[MAX_DATACODEWORD];
	int m_nBlockLength[MAX_DATACODEWORD];

	int m_ncAllCodeWord; // 总码字数
	BYTE m_byAllCodeWord[MAX_ALLCODEWORD]; // 码字
	BYTE m_byRSWork[MAX_CODEBLOCK]; // 纠错码字

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
