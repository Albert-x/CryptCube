#pragma once



// CForm ������ͼ

class CForm : public CFormView
{
	DECLARE_DYNCREATE(CForm)

protected:
	CForm(UINT nIDTemplate = NULL);           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CForm();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnInitialUpdate();
};


