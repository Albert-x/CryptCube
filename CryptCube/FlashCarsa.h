#pragma once
#include "shockwaveflash1.h"


// FlashCarsa �Ի���

class FlashCarsa : public CDialog
{
	DECLARE_DYNAMIC(FlashCarsa)

public:
	FlashCarsa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashCarsa();

// �Ի�������
	enum { IDD = IDD_FLASH_CARSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
