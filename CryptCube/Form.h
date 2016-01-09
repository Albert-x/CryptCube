#pragma once



// CForm 窗体视图

class CForm : public CFormView
{
	DECLARE_DYNCREATE(CForm)

protected:
	CForm(UINT nIDTemplate = NULL);           // 动态创建所使用的受保护的构造函数
	virtual ~CForm();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnInitialUpdate();
};


