#pragma once
#include "shockwaveflash1.h"


// FlashDsa �Ի���

class FlashDsa : public CDialog
{
	DECLARE_DYNAMIC(FlashDsa)

public:
	FlashDsa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashDsa();

// �Ի�������
	enum { IDD = IDD_FLASH_DSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
