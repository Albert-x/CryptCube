#pragma once
#include "shockwaveflash1.h"


// FlashDes �Ի���

class FlashDes : public CDialog
{
	DECLARE_DYNAMIC(FlashDes)

public:
	FlashDes(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FlashDes();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CShockwaveflash1 m_flashShow;
	afx_msg void OnBnClickedCancel();
};
