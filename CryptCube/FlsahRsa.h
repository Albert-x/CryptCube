#pragma once
#include "shockwaveflash1.h"


// FlsahRsa �Ի���

class FlsahRsa : public CDialog
{
	DECLARE_DYNAMIC(FlsahRsa)

public:
	FlsahRsa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlsahRsa();

// �Ի�������
	enum { IDD = IDD_FLASH_RSA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
