#pragma once
#include "shockwaveflash1.h"


// FlashAes �Ի���

class FlashAes : public CDialog
{
	DECLARE_DYNAMIC(FlashAes)

public:
	FlashAes(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashAes();

// �Ի�������
	enum { IDD = IDD_FLASH_AES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
