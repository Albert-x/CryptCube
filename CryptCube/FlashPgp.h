#pragma once
#include "shockwaveflash1.h"


// CFlashPgp �Ի���

class CFlashPgp : public CDialog
{
	DECLARE_DYNAMIC(CFlashPgp)

public:
	CFlashPgp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlashPgp();

// �Ի�������
	enum { IDD = IDD_FLASH_PGP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
