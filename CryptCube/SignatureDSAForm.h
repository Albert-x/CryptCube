#pragma once

#include "Form.h"
#include "PublicKeyECCForm.h"
// CSignatureDSAForm 窗体视图

class CSignatureDSAForm : public CForm
{
	DECLARE_DYNCREATE(CSignatureDSAForm)

public:
	CSignatureDSAForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CSignatureDSAForm();

public:
	enum { IDD = IDD_SIGNATURE_DSA };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	long m_p;
	long m_q;
	long m_g;
	long m_x;
	long m_y;
	ECC *m_pDSA;
	long m_gg;
	long m_xx;
	long m_qq;
	afx_msg void OnBnClickedButton3();
	long m_k;
	long m_r;
	long m_s;
	long m_signG;
	long m_signK;
	long m_signP;
	long m_signQ;
	long m_sK;
	long m_sH;
	long m_sX;
	long m_sR;
	long m_sQ;
	long m_wS;
	long m_wQ;
	long m_w;
	long m_u1M;
	long m_u1W;
	long m_u1Q;
	long m_u1;
	long m_u2R;
	long m_u2W;
	long m_u2Q;
	long m_u2;
	long m_vG;
	long m_vU1;
	long m_vY;
	long m_vU2;
	long m_vP;
	long m_vQ;
	long m_v;
	afx_msg void OnBnClickedButton7();
	long m_M;
};


