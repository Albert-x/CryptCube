#pragma once
#include "shockwaveflash1.h"


// FlashHmac �Ի���

class FlashHmac : public CDialog
{
	DECLARE_DYNAMIC(FlashHmac)

public:
	FlashHmac(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashHmac();

// �Ի�������
	enum { IDD = IDD_HMAC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
