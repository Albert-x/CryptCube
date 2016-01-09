// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CryptCubeForm.h : CCryptCubeForm ��Ľӿ�
//


#pragma once

#include "Form.h"
class   CCryptCubeDoc;

class CCryptCubeForm : public CForm
{
public: // �������л�����
	CCryptCubeForm();
	DECLARE_DYNCREATE(CCryptCubeForm)

public:
	enum{ IDD = IDD_CRYPTCUBE_FORM };

// ����
public:
	CCryptCubeDoc* GetDocument() const;
	CImage m_Image;

// ����
public:

// ��д
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CCryptCubeForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();
	DECLARE_MESSAGE_MAP()
public:

};

#ifndef _DEBUG  // CryptCubeForm.cpp �еĵ��԰汾
inline CCryptCubeDoc* CCryptCubeForm::GetDocument() const
   { return reinterpret_cast<CCryptCubeDoc*>(m_pDocument); }
#endif

