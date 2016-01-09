#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeQrForm 窗体视图

class CCodeQrForm : public CForm
{
	DECLARE_DYNCREATE(CCodeQrForm)

public:
	CCodeQrForm();          
	virtual ~CCodeQrForm();

public:
	enum { IDD = IDD_CODE_QR };


// 诊断
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnDraw(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditQrString(); // 文本输入框数据改变执行的操作
	CString m_strQR;// 记录文本输入框里要生成二维码的数据

	// QR码显示相关
	int m_bDataEncoded;// 记录二维码是否被成功编码
	int m_nSymbleSize;
	CDC* m_pSymbleDC;
	CBitmap* m_pSymbleBitmap;
	CBitmap* m_pOldBitmap;

	// 二维码设置相关
	CComboBox m_comboLevel;
	CComboBox m_comboVersion;
	CStatic m_staticVersion;
	CButton m_checkAutoExtent;
	CComboBox m_comboMaskingNo;
	CStatic m_staticMaskingNo;
	CEdit m_editModuleSize;
	CSpinButtonCtrl m_spinModuleSize;
	CStatic m_staticBmpSize;
	CButton	m_buttonCopy;
	CButton	m_buttonSave;

	//文件的保存路径
	CString m_strSavePath;

	// 创建QR二维码图像
	void CreateQRImage();

	// 显示已创建的二维码图像
	void ShowQRImage();

	// //文本输入框
	CEdit m_editQR;

	afx_msg void OnSelChangeLevel();
	afx_msg void OnSelChangeVersion();
	afx_msg void OnAutoExtent();
	afx_msg void OnSelChangeMaskNo();
	afx_msg void OnChangeDrawSize();
	afx_msg void OnKillFocusDrawSize();
	afx_msg void OnCopy();
	afx_msg void OnSave();
	void ShowBitmapSize();
	void CopyImage(COleDataSource* pOleDataSource = NULL);
	void SaveAsImage();
	void SaveImage();

	CString m_strComboLevel; // 用来记录容错等级选择框的值
	
	CString m_strComboMaskingNo; // 用来记录掩模图案选择框的值

	CString m_strComboVersion;// 用来记录型号选择框的值

	CString m_strEditModuleSize;// 用来记录图像尺寸输入框的值

	BOOL m_bCheckAutoExtent; // 用来记录自动扩张复选框的值

	CString m_strStaticBmpSize; // 用来记录图像尺寸静态框的值

	CString m_strStaticMaskingNo; // 用来记录掩模图案选择框右边静态文本

	CString m_strStaticVersion; // 用来记录型号选择框右边静态文本

	BOOL m_bInitControl;
};


