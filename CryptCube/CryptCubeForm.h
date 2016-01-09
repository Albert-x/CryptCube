// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// CryptCubeForm.h : CCryptCubeForm 类的接口
//


#pragma once

#include "Form.h"
class   CCryptCubeDoc;

class CCryptCubeForm : public CForm
{
public: // 仅从序列化创建
	CCryptCubeForm();
	DECLARE_DYNCREATE(CCryptCubeForm)

public:
	enum{ IDD = IDD_CRYPTCUBE_FORM };

// 属性
public:
	CCryptCubeDoc* GetDocument() const;
	CImage m_Image;

// 操作
public:

// 重写
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CCryptCubeForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL ImageFromIDResource();
	DECLARE_MESSAGE_MAP()
public:

};

#ifndef _DEBUG  // CryptCubeForm.cpp 中的调试版本
inline CCryptCubeDoc* CCryptCubeForm::GetDocument() const
   { return reinterpret_cast<CCryptCubeDoc*>(m_pDocument); }
#endif

