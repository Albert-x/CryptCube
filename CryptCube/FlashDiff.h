#pragma once
#include "shockwaveflash1.h"


// FlashDiff �Ի���

class FlashDiff : public CDialog
{
	DECLARE_DYNAMIC(FlashDiff)

public:
	FlashDiff(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashDiff();

// �Ի�������
	enum { IDD = IDD_FLASH_DIFF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
