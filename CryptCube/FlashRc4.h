#pragma once
#include "shockwaveflash1.h"


// FlashRc4 �Ի���

class FlashRc4 : public CDialog
{
	DECLARE_DYNAMIC(FlashRc4)

public:
	FlashRc4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashRc4();
	virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_FLASH_RC4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
