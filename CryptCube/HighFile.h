#pragma once

#include "Form.h"
// HighFile �Ի���

class HighFile : public CForm
{
	DECLARE_DYNCREATE(HighFile)

public:
	HighFile();   // ��׼���캯��
	virtual ~HighFile();

// �Ի�������
	enum { IDD = IDD_HIGH_FILE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFile();
};
