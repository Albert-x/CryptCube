#pragma once
#include "Form.h"

// BookLesson ������ͼ

class BookLesson : public CForm
{
	DECLARE_DYNCREATE(BookLesson)

public:
	BookLesson();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~BookLesson();
	enum { IDD = IDD_LESSON };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


