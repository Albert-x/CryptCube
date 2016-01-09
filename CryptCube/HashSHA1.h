// SHA1.h: interface for the SHA1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHA1_H__FA3D2CBF_2553_46DA_9EA2_30220107670D__INCLUDED_)
#define AFX_SHA1_H__FA3D2CBF_2553_46DA_9EA2_30220107670D__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include<string.h>
#include<stdio.h>



class SHA1  
{
public:
	SHA1();
		virtual ~SHA1();
		bool SHA_GO( const unsigned char *lpData_Input, unsigned char *lpSHACode_Output,unsigned int len);
		unsigned int H[5];// Message digest buffers
		int prog;
	private:
							
		unsigned int Length_Low;				// Message length in bits
		unsigned int Length_High;			// Message length in bits
		unsigned char Message_Block[64];	// 512-bit message blocks
		int Message_Block_Index;				// Index into message block array
	private:
		void SHAInit();
		void AddDataLen(int nDealDataLen);

		// Process the next 512 bits of the message
		void ProcessMessageBlock();

		// Pads the current message block to 512 bits
		void PadMessage();

		// Performs a circular left shift operation
		inline unsigned CircularShift(int bits, unsigned word);




};

#endif // !defined(AFX_SHA1_H__FA3D2CBF_2553_46DA_9EA2_30220107670D__INCLUDED_)
