#pragma once



// CMyDialog ������ͼ

class CMyDialog : public CDialogEx
{
	DECLARE_DYNCREATE(CMyDialog)

protected:
	CMyDialog(UINT nIDTemplate = NULL, CWnd *pParent = NULL);
	virtual ~CMyDialog();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
};


