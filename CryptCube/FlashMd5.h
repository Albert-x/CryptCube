#pragma once
#include "shockwaveflash1.h"


// FlashMd5 �Ի���

class FlashMd5 : public CDialog
{
	DECLARE_DYNAMIC(FlashMd5)

public:
	FlashMd5(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashMd5();

// �Ի�������
	enum { IDD = IDD_FLASH_MD5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
