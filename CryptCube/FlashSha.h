#pragma once
#include "shockwaveflash1.h"


// FlashSha �Ի���

class FlashSha : public CDialog
{
	DECLARE_DYNAMIC(FlashSha)

public:
	FlashSha(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashSha();

// �Ի�������
	enum { IDD = IDD_FLASH_SHA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
