#pragma once
#include "shockwaveflash1.h"


// CFlashEcc �Ի���

class CFlashEcc : public CDialog
{
	DECLARE_DYNAMIC(CFlashEcc)

public:
	CFlashEcc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlashEcc();

// �Ի�������
	enum { IDD = IDD_FLASH_ECC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//CShockwaveflash1 m_flashShow;
	CShockwaveflash1 m_flashShow;
};
