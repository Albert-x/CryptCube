#pragma once
#include "Form.h"

// BookLesson 窗体视图

class BookLesson : public CForm
{
	DECLARE_DYNCREATE(BookLesson)

public:
	BookLesson();           // 动态创建所使用的受保护的构造函数
	virtual ~BookLesson();
	enum { IDD = IDD_LESSON };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


