#pragma once
#include "shockwaveflash1.h"


// FlashAffine �Ի���

class FlashAffine : public CDialog
{
	DECLARE_DYNAMIC(FlashAffine)

public:
	FlashAffine(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashAffine();

// �Ի�������
	enum { IDD = IDD_FLASH_AFFINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
