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

// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#include "RibbonBar.h"  

class CMainFrame : public CFrameWndEx
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

	//CString m_strClassicKaisa;
	//CString m_strClassicDaihuan;
	//CString m_strBlockDES;
	//CString m_strBlockAES;
	//CString m_strStreamRC4;
	//CString m_strPublicKeyRSA;
	//CString m_strPublicKeyDH;
	//CString m_strPublicKeyElGamal;
	//CString m_strPublicKeyECC;
	//CString m_strHashMD5;
	//CString m_strHashSHAForm;
	//CString m_strSignatureDSA;

// ����
public:
	void SwitchToForm(int nForm);

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnGetMinMaxInfo( MINMAXINFO FAR* lpMMI );
	

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CKofMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnMenuitemOpen();
	DECLARE_MESSAGE_MAP()

	void InitializeRibbon();
	BOOL CreateCaptionBar();
public:
	afx_msg void OnAppAbout();
	afx_msg void OnClassicKaisa();
	afx_msg void OnClassicDaihuan();
	afx_msg void OnBlockDes();
	afx_msg void OnBlockAes();
	afx_msg void OnBlockIdea();
	afx_msg void OnStreamRc4();
	afx_msg void OnPublickeyRsa();
	afx_msg void OnPublickeyElgamal();
	afx_msg void OnHashMd5();
	afx_msg void OnHashSha();
	afx_msg void OnWelcome();
	afx_msg void OnPublickeyDh();
	afx_msg void OnPublickeyEcc();
	afx_msg void OnAppDonate();
	afx_msg void OnAppWebsite();
	afx_msg void OnSignatureDsa();
	afx_msg void OnCodeRandom();
	afx_msg void OnEncryptString();
	afx_msg void OnCodeCalc();
	afx_msg void OnEncryptFile();
	afx_msg void OnCodeHash();
	afx_msg void OnCodeBase64();
	afx_msg void OnCodeString();
	afx_msg void OnCodeUrl();
	afx_msg void OnCodeColor();
	afx_msg void OnCodeQr();
	afx_msg void OnAppHelp();

	afx_msg void OnRsa();
	afx_msg void OnKaisa();
	afx_msg void OnDanbiao();
	afx_msg void OnDes();
	afx_msg void OnAes();
	afx_msg void OnIdea();
	afx_msg void OnElgamal();
	afx_msg void OnMd5();
	afx_msg void OnSha();
	afx_msg void OnRc4();
	afx_msg void OnDsa();
	afx_msg void OnDiffie();
	afx_msg void OnEcc();
	afx_msg void OnFSBH();
	afx_msg void OnHMAC();
	afx_msg void OnCASA();
	afx_msg void OnElg();


	//ϰ�����
	afx_msg void OnTest_DES();
	afx_msg void OnTest_DIFF();
	afx_msg void OnTest_HMAC();
	afx_msg void OnTest_MD5();
	afx_msg void OnTest_RSA();
	afx_msg void OnTest_SSL();
	//��������
	afx_msg void OnTerm();
	
	//�ο�����
	afx_msg void OnBook();
	afx_msg void OnExcise();
	afx_msg void OnClass();
	afx_msg void OnTheory();
	//�߼�
	afx_msg void OnHighKer();
	afx_msg void OnHighPki();
	afx_msg void OnHighEfs();
	afx_msg void OnHighOpen();
	afx_msg void OnHighPgp();
	afx_msg void OnHighSSL();
	afx_msg void OnHighFile();
	//�ɺ�ѧԺ
	afx_msg void OnKhan();
	afx_msg void OnStu();
};


