#pragma once
#include "shockwaveflash1.h"


// CFlashElg �Ի���

class CFlashElg : public CDialog
{
	DECLARE_DYNAMIC(CFlashElg)

public:
	CFlashElg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlashElg();

// �Ի�������
	enum { IDD = IDD_FLASH_ELG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
