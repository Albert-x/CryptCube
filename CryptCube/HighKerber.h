#pragma once

#include "shockwaveflash1.h"

// CHighKerber �Ի���

class CHighKerber : public CDialog
{
	DECLARE_DYNAMIC(CHighKerber)

public:
	CHighKerber(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHighKerber();

// �Ի�������
	enum { IDD = IDD_KERBER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
};
