#pragma once
#include "shockwaveflash1.h"


// CFlashIdea �Ի���

class CFlashIdea : public CDialog
{
	DECLARE_DYNAMIC(CFlashIdea)

public:
	CFlashIdea(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlashIdea();

// �Ի�������
	enum { IDD = IDD_FLASH_IDEA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
