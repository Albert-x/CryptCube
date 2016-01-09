#pragma once

#include "Form.h"
#include "afxwin.h"

// CCodeQrForm ������ͼ

class CCodeQrForm : public CForm
{
	DECLARE_DYNCREATE(CCodeQrForm)

public:
	CCodeQrForm();          
	virtual ~CCodeQrForm();

public:
	enum { IDD = IDD_CODE_QR };


// ���
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnDraw(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditQrString(); // �ı���������ݸı�ִ�еĲ���
	CString m_strQR;// ��¼�ı��������Ҫ���ɶ�ά�������

	// QR����ʾ���
	int m_bDataEncoded;// ��¼��ά���Ƿ񱻳ɹ�����
	int m_nSymbleSize;
	CDC* m_pSymbleDC;
	CBitmap* m_pSymbleBitmap;
	CBitmap* m_pOldBitmap;

	// ��ά���������
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

	//�ļ��ı���·��
	CString m_strSavePath;

	// ����QR��ά��ͼ��
	void CreateQRImage();

	// ��ʾ�Ѵ����Ķ�ά��ͼ��
	void ShowQRImage();

	// //�ı������
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

	CString m_strComboLevel; // ������¼�ݴ�ȼ�ѡ����ֵ
	
	CString m_strComboMaskingNo; // ������¼��ģͼ��ѡ����ֵ

	CString m_strComboVersion;// ������¼�ͺ�ѡ����ֵ

	CString m_strEditModuleSize;// ������¼ͼ��ߴ�������ֵ

	BOOL m_bCheckAutoExtent; // ������¼�Զ����Ÿ�ѡ���ֵ

	CString m_strStaticBmpSize; // ������¼ͼ��ߴ羲̬���ֵ

	CString m_strStaticMaskingNo; // ������¼��ģͼ��ѡ����ұ߾�̬�ı�

	CString m_strStaticVersion; // ������¼�ͺ�ѡ����ұ߾�̬�ı�

	BOOL m_bInitControl;
};


